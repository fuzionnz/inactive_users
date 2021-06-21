<?php

namespace Drupal\inactive_users\Plugin\views\filter;

use Drupal\views\Plugin\views\display\DisplayPluginBase;
use Drupal\views\Plugin\views\filter\BooleanOperator;
use Drupal\views\ViewExecutable;

/**
 * Views filter for email mismatch.
 *
 * Subquery to identify any email associated with the contact
 *
 * @ingroup views_filter_handlers
 *
 * @ViewsFilter("email_match_views_filter")
 */

class EmailMatchViewsFilter extends BooleanOperator {

  function query() {
    $this->ensureMyTable();
    if ($this->value) {
      $this->query->addWhereExpression($this->options['group'], 'users_field_data.mail COLLATE utf8mb4_general_ci  IN (SELECT ' . $this->realField . ' COLLATE utf8mb4_general_ci FROM {' . $this->table . '} WHERE contact_id = civicrm_uf_match.contact_id)');
    }
    else {
      $this->query->addWhereExpression($this->options['group'], 'users_field_data.mail COLLATE utf8mb4_general_ci  NOT IN (SELECT ' . $this->realField . ' COLLATE utf8mb4_general_ci FROM {' . $this->table . '} WHERE contact_id = civicrm_uf_match.contact_id)');
    }
  }
}