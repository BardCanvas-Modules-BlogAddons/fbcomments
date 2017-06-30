<?php
/**
 * Pre template rendering
 *
 * @package    BardCanvas
 * @subpackage fbcomments
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 *
 * @var config   $config
 * @var module   $this_module
 * @var template $template
 *
 * @var post_record  $post
 * @var media_record $item
 */

use hng2_base\config;
use hng2_base\module;
use hng2_base\template;
use hng2_media\media_record;
use hng2_modules\posts\post_record;

global $settings, $template;

if( $template->layout == "admin" ) return;
if( $template->layout == "embeddable" ) return;

$app_id = $settings->get("modules:fbcomments.appid");
if( empty($app_id) ) return;

$template->page_extra_metas["fb:app_id"] = "<meta property='fb:app_id' content='$app_id'>";
