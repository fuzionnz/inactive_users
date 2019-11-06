<?php

/**
 * @file
 * Views support for Inactive Users.
 */

/**
 * Implements hook_views_handlers().
 */
function inactive_users_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'inactive_users') . '/inc',
    ),
    'handlers' => array(
      'inactive_users_handler_filter_has_logged_in' => array(
        'parent' => 'views_handler_filter'
      ),
      'inactive_users_handler_field_has_logged_in' => array(
        'parent' => 'views_handler_field'
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function inactive_users_views_data_alter(&$data) {
  // Add filter to verify if account is banned. Doing this just to
  // provide better filter labels than "Yes/No" for Status.
  $data['users']['is_active'] = array(
    'real field' => 'status',
    'title' => t('Is Active'), // The item it appears as on the UI,
    'help' => t("Is this account active?"), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'active-blocked' => array(t('Active'), t('Banned')),
      ),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_boolean',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'output formats' => array(
        'active-blocked' => array(t('Active'), t('Banned')),
      ),
    ),
  );

  // Add filter to verify if account has logged in.
  $data['users']['has_logged_in'] = array(
    'real field' => 'login',
    'title' => t('Has Logged In'), // The item it appears as on the UI,
    'help' => t("Has this account been used?"), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'active-blocked' => array(t('Has logged in'), t('Never logged in')),
      ),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_boolean',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
  );

  // Add filter to check if CiviCRM contact match exists.
  $data['civicrm_contact']['has_contact'] = array(
    'real field' => 'id',
    'title' => t('Contact Exists'),
    'help' => t('Does this user have a CiviCRM contact?'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'inactive_users_handler_filter_has_contact',
      'allow empty' => TRUE,
    ),
  );

  // Add filter to check for email mismatch.
  $data['civicrm_email']['email_match'] = array(
    'real field' => 'email',
    'title' => t('Email Match'),
    'help' => t('Do the Drupal and CiviCRM emails match?'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'inactive_users_handler_filter_email_match',
      'allow empty' => TRUE,
    ),
  );

  if (isset($data['civicrm_contact']) && !isset($data['civicrm_contact']['match_contact_names'])) {
    $data['civicrm_contact']['match_contact_names'] = array(
      'real field' => 'match_contact_names',
      'title' => t('Matching First & Last Name'),
      'help' => t('Return contacts having first_name = last_name.'),
      'filter' => array(
        'handler' => 'inactive_users_handler_filter_match_contact_names',
      ),
    );
  }

  return $data;
}

/**
 * Views filter for has associated contact.
 */
class inactive_users_handler_filter_has_contact extends views_handler_filter_boolean_operator {
  function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    if ($this->value) {
      $this->query->add_where_expression($this->options['group'], "$field IS NOT NULL");
    }
    else {
      $this->query->add_where_expression($this->options['group'], "$field IS NULL");
    }
  }
}

/**
 * Views filter for email mismatch.
 *
 * Subquery to identify any email associated with the contact.
 *
 * Could do this separately for "primary emails match"? That's much simpler.
 */
class inactive_users_handler_filter_email_match extends views_handler_filter_boolean_operator {
  function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    if ($this->value) {
      $this->query->add_where_expression($this->options['group'], 'users.mail COLLATE utf8_unicode_ci IN (SELECT ' . $this->real_field . ' COLLATE utf8_unicode_ci FROM {' . $this->table_alias . '} WHERE contact_id = civicrm_uf_match.contact_id)');
    }
    else {
      $this->query->add_where_expression($this->options['group'], 'users.mail COLLATE utf8_unicode_ci NOT IN (SELECT ' . $this->real_field . ' COLLATE utf8_unicode_ci FROM {' . $this->table_alias . '} WHERE contact_id = civicrm_uf_match.contact_id)');
    }
  }
}
