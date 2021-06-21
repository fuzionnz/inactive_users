<?php

/**
 * @file
 * Views support for Inactive Users.
 */

/**
 * Implements hook_views_data().
 */
function inactive_users_views_data_alter(&$data) {
  // Add filter to check for email mismatch.
  $data['civicrm_email']['email_match'] = [
    'real field' => 'email',
    'title' => t('Email Match'),
    'help' => t('Do the Drupal and CiviCRM emails match?'),
    'field' => [
      'id' => 'boolean',
      'click sortable' => TRUE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort',
    ],
    'filter' => [
      'title' => t('Email Match'),
      'help' => t('Do the Drupal and CiviCRM emails match?.'),
      'field' => 'email',
      'id' => 'email_match_views_filter',
    ],
  ];

  return $data;
}
