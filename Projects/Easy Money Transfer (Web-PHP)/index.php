<?php 
include "app/config.php";
include "app/detect.php";

if ($page_name=='') {
	include $browser_t.'/index.php';
	}
elseif ($page_name=='index.php') {
	include $browser_t.'/index.php';
	}
elseif ($page_name=='login.php') {
	include $browser_t.'/login.php';
	}
elseif ($page_name=='register.php') {
	include $browser_t.'/register.php';
	}
elseif ($page_name=='about.html') {
	include $browser_t.'/about.html';
	}
elseif ($page_name=='contact.php') {
	include $browser_t.'/contact.php';
	}
elseif ($page_name=='signup-account.php') {
	include $browser_t.'/signup-account.php';
	}
elseif ($page_name=='contact-form.php') {
	include $browser_t.'/contact-form.php';
	}
elseif ($page_name=='login-account.php') {
	include $browser_t.'/login-account.php';
	}
elseif ($page_name=='shopkeeper_dashboard.php') {
	include $browser_t.'/shopkeeper_dashboard.php';
	}
elseif ($page_name=='sk_transfer.php') {
	include $browser_t.'/sk_transfer.php';
	}
elseif ($page_name=='sk_receive.php') {
	include $browser_t.'/sk_receive.php';
	}
elseif ($page_name=='sk_check.php') {
	include $browser_t.'/sk_check.php';
	}
elseif ($page_name=='sk_order.php') {
	include $browser_t.'/sk_order.php';
	}
elseif ($page_name=='sfo_dashboard.php') {
	include $browser_t.'/sfo_dashboard.php';
	}
elseif ($page_name=='sfo_login.php') {
	include $browser_t.'/sfo_login.php';
	}
elseif ($page_name=='sfo_transfer.php') {
	include $browser_t.'/sfo_transfer.php';
	}
elseif ($page_name=='sfo_receive.php') {
	include $browser_t.'/sfo_receive.php';
	}
elseif ($page_name=='sfo_check.php') {
	include $browser_t.'/sfo_check.php';
	}
elseif ($page_name=='sfo_order.php') {
	include $browser_t.'/sfo_order.php';
	}
elseif ($page_name=='logout.php') {
	include $browser_t.'/logout.php';
	}
elseif ($page_name=='sfo_dash.php') {
	include $browser_t.'/sfo_dash.php';
	}
else{
		include $browser_t;
		//.'/'.$page_name;
    }

?>
