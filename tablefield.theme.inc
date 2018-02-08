<?php
/**
 * @file
 * Theme fuunctions for table field.
 */

/**
 * Theme function for table view.
 */
function theme_tablefield_view($variables) {
  // Apply scope property to headers for accessibility.
  if (is_array($variables['header'])) {
    foreach ($variables['header'] as &$header) {
      $header['scope'] = 'col';
    }
  }

  // If the user has access to the csv export option, display it now.
  $export = '';
  if ($variables['export'] && user_access('export tablefield')) {
    $url = sprintf('tablefield/export/%s/%s/%s/%s/%s', $variables['entity_type'], $variables['entity_id'], $variables['field_name'], $variables['langcode'], $variables['delta']);
    $export = '<div id="tablefield-export-link-' . $variables['delta'] . '" class="tablefield-export-link">' . l(t('Export Table Data'), $url) . '</div>';
  }

  $table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => $variables['attributes'],
  );
  if(isset($variables['caption']) && !empty($variables['caption'])) {
    $table['caption'] = $variables['caption'];
  }

  $output  = '<div id="tablefield-wrapper-' . $variables['delta'] . '" class="tablefield-wrapper">';
  $output .= theme('table__tablefield', $table);
  $output .= $export;
  $output .= '</div>';

  return $output;
}
