<?php
function LoggedIn(){
	//session_start();
	$loggedIn = false;
	if(isset($_SESSION['login'])){
	   $loggedIn = true;
	}
	return $loggedIn;
}
?>