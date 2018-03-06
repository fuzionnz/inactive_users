<?php
/**
 * @file
 * inactive_users.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function inactive_users_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'users_inactive';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'users_inactive';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Inactive Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'display_name' => 'display_name',
    'mail' => 'mail',
    'name' => 'name',
    'created' => 'created',
    'access' => 'access',
    'login' => 'login',
    'status' => 'status',
    'rid' => 'rid',
    'cancel_node' => 'cancel_node',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'display_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cancel_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: CiviCRM Contacts: Contact ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'CID';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['display_name']['empty'] = '(no contact name)';
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 1;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'Drupal Email';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  /* Field: CiviCRM Email: Email Address */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['label'] = 'CiviCRM Email';
  $handler->display->display_options['fields']['email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['email']['location_type'] = '0';
  $handler->display->display_options['fields']['email']['location_op'] = '0';
  $handler->display->display_options['fields']['email']['is_primary'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'CiviCRM: [display_name] &lt;[email]&gt;<br>
Drupal: [name] &lt;[mail]&gt;<br>
';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d H:i';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['label'] = 'Accessed';
  $handler->display->display_options['fields']['access']['date_format'] = 'custom';
  $handler->display->display_options['fields']['access']['custom_date_format'] = 'Y-m-d H:i';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['date_format'] = 'custom';
  $handler->display->display_options['fields']['login']['custom_date_format'] = 'Y-m-d H:i';
  /* Field: User: Has Logged In */
  $handler->display->display_options['fields']['has_logged_in']['id'] = 'has_logged_in';
  $handler->display->display_options['fields']['has_logged_in']['table'] = 'users';
  $handler->display->display_options['fields']['has_logged_in']['field'] = 'has_logged_in';
  $handler->display->display_options['fields']['has_logged_in']['label'] = 'Logged In';
  $handler->display->display_options['fields']['has_logged_in']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['has_logged_in']['not'] = 0;
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: CiviCRM Contacts: Contact Exists */
  $handler->display->display_options['fields']['has_contact']['id'] = 'has_contact';
  $handler->display->display_options['fields']['has_contact']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['has_contact']['field'] = 'has_contact';
  $handler->display->display_options['fields']['has_contact']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['has_contact']['not'] = 0;
  /* Field: CiviCRM Email: Email Match */
  $handler->display->display_options['fields']['email_match']['id'] = 'email_match';
  $handler->display->display_options['fields']['email_match']['table'] = 'civicrm_email';
  $handler->display->display_options['fields']['email_match']['field'] = 'email_match';
  $handler->display->display_options['fields']['email_match']['type'] = 'true-false';
  $handler->display->display_options['fields']['email_match']['not'] = 0;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Cancel link */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = 'Cancel';
  $handler->display->display_options['fields']['cancel_node']['exclude'] = TRUE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Manage';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] [cancel_node]';
  /* Field: CiviCRM Drupal match table: Domain ID */
  $handler->display->display_options['fields']['domain_id']['id'] = 'domain_id';
  $handler->display->display_options['fields']['domain_id']['table'] = 'civicrm_uf_match';
  $handler->display->display_options['fields']['domain_id']['field'] = 'domain_id';
  $handler->display->display_options['fields']['domain_id']['separator'] = '';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';
  /* Filter criterion: User: Has Logged In */
  $handler->display->display_options['filters']['has_logged_in']['id'] = 'has_logged_in';
  $handler->display->display_options['filters']['has_logged_in']['table'] = 'users';
  $handler->display->display_options['filters']['has_logged_in']['field'] = 'has_logged_in';
  $handler->display->display_options['filters']['has_logged_in']['value'] = '0';
  $handler->display->display_options['filters']['has_logged_in']['exposed'] = TRUE;
  $handler->display->display_options['filters']['has_logged_in']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['has_logged_in']['expose']['label'] = 'Has Logged In';
  $handler->display->display_options['filters']['has_logged_in']['expose']['description'] = 'Has this account ever logged in?';
  $handler->display->display_options['filters']['has_logged_in']['expose']['operator'] = 'has_logged_in_op';
  $handler->display->display_options['filters']['has_logged_in']['expose']['identifier'] = 'has_logged_in';
  $handler->display->display_options['filters']['has_logged_in']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    8 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    15 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
  );
  /* Filter criterion: User: Is Active */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'users';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = 'All';
  $handler->display->display_options['filters']['is_active']['exposed'] = TRUE;
  $handler->display->display_options['filters']['is_active']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['is_active']['expose']['label'] = 'Is Active';
  $handler->display->display_options['filters']['is_active']['expose']['description'] = 'Is this account active or banned?';
  $handler->display->display_options['filters']['is_active']['expose']['operator'] = 'is_active_op';
  $handler->display->display_options['filters']['is_active']['expose']['identifier'] = 'active';
  $handler->display->display_options['filters']['is_active']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['is_active']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    8 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    15 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
  );
  /* Filter criterion: CiviCRM Contacts: Contact Exists */
  $handler->display->display_options['filters']['has_contact']['id'] = 'has_contact';
  $handler->display->display_options['filters']['has_contact']['table'] = 'civicrm_contact';
  $handler->display->display_options['filters']['has_contact']['field'] = 'has_contact';
  $handler->display->display_options['filters']['has_contact']['value'] = 'All';
  $handler->display->display_options['filters']['has_contact']['exposed'] = TRUE;
  $handler->display->display_options['filters']['has_contact']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['has_contact']['expose']['label'] = 'Contact Exists';
  $handler->display->display_options['filters']['has_contact']['expose']['description'] = 'Does user have CiviCRM contact?';
  $handler->display->display_options['filters']['has_contact']['expose']['operator'] = 'has_contact_op';
  $handler->display->display_options['filters']['has_contact']['expose']['identifier'] = 'has_contact';
  $handler->display->display_options['filters']['has_contact']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['has_contact']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    8 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    15 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    16 => 0,
  );
  /* Filter criterion: CiviCRM Email: Email Match */
  $handler->display->display_options['filters']['email_match']['id'] = 'email_match';
  $handler->display->display_options['filters']['email_match']['table'] = 'civicrm_email';
  $handler->display->display_options['filters']['email_match']['field'] = 'email_match';
  $handler->display->display_options['filters']['email_match']['exposed'] = TRUE;
  $handler->display->display_options['filters']['email_match']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['email_match']['expose']['label'] = 'Email Match';
  $handler->display->display_options['filters']['email_match']['expose']['operator'] = 'email_match_op';
  $handler->display->display_options['filters']['email_match']['expose']['identifier'] = 'email_match';
  $handler->display->display_options['filters']['email_match']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['email_match']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    14 => 0,
    11 => 0,
    13 => 0,
    15 => 0,
    12 => 0,
    8 => 0,
    10 => 0,
  );
  /* Filter criterion: CiviCRM Drupal match table: Domain ID */
  $handler->display->display_options['filters']['domain_id']['id'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['table'] = 'civicrm_uf_match';
  $handler->display->display_options['filters']['domain_id']['field'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['domain_id']['expose']['operator_id'] = 'domain_id_op';
  $handler->display->display_options['filters']['domain_id']['expose']['label'] = 'Domain ID';
  $handler->display->display_options['filters']['domain_id']['expose']['description'] = 'If using multisite: The domain id for the relevant domain';
  $handler->display->display_options['filters']['domain_id']['expose']['operator'] = 'domain_id_op';
  $handler->display->display_options['filters']['domain_id']['expose']['identifier'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    14 => 0,
    11 => 0,
    13 => 0,
    15 => 0,
    12 => 0,
    8 => 0,
    10 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/inactive';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Inactive Users';
  $handler->display->display_options['menu']['description'] = 'Users who are not active on the site';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-links';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['users_inactive'] = array(
    t('Master'),
    t('Inactive Users'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('User'),
    t('- Choose an operation -'),
    t('CID'),
    t('.'),
    t('Display Name'),
    t('(no contact name)'),
    t('Drupal Email'),
    t('CiviCRM Email'),
    t('Name'),
    t('CiviCRM: [display_name] &lt;[email]&gt;<br>
Drupal: [name] &lt;[mail]&gt;<br>
'),
    t('Created'),
    t('Accessed'),
    t('Last login'),
    t('Logged In'),
    t('Active'),
    t('Contact Exists'),
    t('Email Match'),
    t('Roles'),
    t('Cancel'),
    t('Manage'),
    t('[edit_node] [cancel_node]'),
    t('Domain ID'),
    t('Has Logged In'),
    t('Has this account ever logged in?'),
    t('Is Active'),
    t('Is this account active or banned?'),
    t('Does user have CiviCRM contact?'),
    t('If using multisite: The domain id for the relevant domain'),
    t('Page'),
  );
  $export['users_inactive'] = $view;

  return $export;
}
