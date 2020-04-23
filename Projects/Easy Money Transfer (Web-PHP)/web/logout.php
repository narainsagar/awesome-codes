<?php
session_start();
$LoginedPage = 0; 
if(isset($_SESSION['login_type']) && $_SESSION['login_type']=="SFO"){
	$LoginedPage = 1;
}
else if(isset($_SESSION['login_type']) && $_SESSION['login_type']=="ShopKeeper"){
	$LoginedPage = 2;
}

unset($_SESSION['login']);
$_SESSION = array();
while(!session_destroy()){}

if($LoginedPage == 1)
header("location: sfo_login.php");
else if ($LoginedPage == 2)
header("location: login.php");
else
header("location: index.php");
?>