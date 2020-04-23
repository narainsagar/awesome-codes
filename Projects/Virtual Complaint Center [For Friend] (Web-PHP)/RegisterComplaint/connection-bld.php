<?php
$conn_err="Couldn't Connect to Database";

$mysql_host="localhost";
$mysql_user="root";
$mysql_pass="";

$mysql_db="hcidatabase";

$link2 = @mysql_connect($mysql_host, $mysql_user, $mysql_pass);

if($link2 && @mysql_select_db($mysql_db,$link2))
{
	//echo "Connection Successful"; 
	}
else 
{
	die($conn_err);
	}

/*
if(@mysql_connect($mysql_host,$mysql_user,$mysql_pass) && @mysql_select_db($mysql_db))
{
	//echo "Connection Successful"; 
	}
else 
{
	die($conn_err);
	}
*/	
	
?>