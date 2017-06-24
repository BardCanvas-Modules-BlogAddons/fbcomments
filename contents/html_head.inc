<?php
/**
 * Styles and scripts for the module
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

$lang = $settings->get("engine.default_language");
?>

<!-- fbcomments head -->
<script>
    (function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) return;
        js = d.createElement(s); js.id = id;
        js.src = "//connect.facebook.net/<?= $lang ?>/sdk.js#xfbml=1&version=v2.9&appId=<?= $app_id ?>";
        fjs.parentNode.insertBefore(js, fjs);
    }(document, 'script', 'facebook-jssdk'));
</script>

