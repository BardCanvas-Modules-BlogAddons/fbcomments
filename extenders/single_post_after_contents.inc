<?php
/**
 * Posts extender: contents to add after post contents
 * Called within a function, so no globals behind
 *
 * @package    BardCanvas
 * @subpackage fbcomments
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 * 
 * Imported globals:
 * @var post_record $post
 *
 * Trailing vars:
 * @var module $this_module    self (comments)
 * @var module $current_module posts
 */

use hng2_base\module;
use hng2_modules\posts\post_record;

global $post, $template, $language, $settings, $account, $config;

# If someone is overriding us...
if( $config->globals["modules:fbcomments.avoid_extension:posts/front/single_post_after_contents"] ) return;

if( $settings->get("modules:fbcomments.appid") == "" ) return;
if( $post->allow_comments == 0 ) return;

# We override the comments injection
$config->globals["modules:comments.avoid_extension:posts/front/single_post_after_contents"] = true;

$url    = $post->get_permalink(true);
$width  = $settings->get("modules:fbcomments.widget_width");
$amount = $settings->get("modules:fbcomments.amount_shown");

if( empty($width) )  $width = "100%";
if( empty($amount) ) $amount = 10;
?>

<!-- fbcomments -->

<div class="content_frame">
    
    <div class="fb-comments" data-href="<?= $url ?>" data-width="<?= $width ?>" data-numposts="<?= $amount ?>"></div>
    
</div>

