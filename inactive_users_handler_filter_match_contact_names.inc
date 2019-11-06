<?php

class inactive_users_handler_filter_match_contact_names extends views_handler_filter {

  /**
   * Options form subform for setting exposed filter options.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    $options = array(
      '0' => t('- None -'),
      '1' => t('Yes'),
      '2' => t('No'),
    );
    $form['civicrm_contact']['match_contact_names'] = array(
      '#type' => 'select',
      '#options' => $options,
    );
  }

  /**
   * Alters Views query when filter is used.
   */
  function query() {
    // make sure base table is included in the query
    $this->ensure_my_table();

    $real_field_name = $this->real_field;

    // get the value of the submitted filter
    $value = $this->view->exposed_data[$real_field_name];

    // finally, alter Views query
    if (is_numeric($value) && $value == 1) {
      $this->query->add_where_expression($this->options['group'],
        "civicrm_contact.first_name = civicrm_contact.last_name");
    }
    elseif (is_numeric($value) && $value == 2) {
      $this->query->add_where_expression($this->options['group'],
        "civicrm_contact.first_name != civicrm_contact.last_name");
    }
  }

}