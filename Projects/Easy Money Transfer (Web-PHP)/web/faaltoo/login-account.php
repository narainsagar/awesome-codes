<?php
/*require 'connection-bld.php' ; */
$login_id = $_REQUEST['user_id'];
$login_passwrd = $_REQUEST['user_password'];

// create database connection..
 $mysql_host='localhost';
 $mysql_user='root';
 $mysql_pass='';
 $mysql_db='CN_PROJECT';
 $link2 = @mysql_connect($mysql_host, $mysql_user, $mysql_pass) or die("connection problem ....");
 @mysql_select_db($mysql_db,$link2) or die("database problem ....");
  
$query1 = ("SELECT * FROM shop_keeper WHERE mobile_no='$login_id' and passwd='$login_passwrd'"); // query to check user  registered. 
$result1 = mysql_query($query1, $link2) or die("query1 problem..");        // execute query
if( $result1 ){
     // AUTHENTICATED..!! VALID SHOPKEEPER ID and PASSWRD.
     if(mysql_num_rows($result1) == 0) {
	        $query2 = ("SELECT mobile_no FROM shop_keeper WHERE mobile_no='$login_id'"); // query to check user  forgot passwd. 
			$result2 = mysql_query($query2, $link2) or die("query1 problem..");        // execute query
			if($result2){
				if(mysql_num_rows($result2) == 0){
					// not registered yet/invalid user..
						echo "Sorry..!! Not a Registered User..";
				}
				else{
						// email exist.. but password not matched.
					   echo "Sorry..!! your Password is wrong.. Kindly visit forgot Password.";
				}
			}
	 }
     else{
        echo "Valid User- Welcome..!!";
		$login = true;
		$row = mysql_fetch_array($result1);
		session_start();
		$_SESSION['login'] = $login;
		$_SESSION['login_id'] = $login_id;
		$_SESSION['login_pass'] = $login_passwrd;
		$_SESSION['full_name'] = $row['full_name'];
		$_SESSION['mobile_no'] = $row['mobile_no'];
		$_SESSION['SFO_mobile_no'] = $row['SFO_mobile_no'];
		$_SESSION['cnic_no'] = $row['cnic_no'];
		$_SESSION['email_id'] = $row['email_id'];
		$_SESSION['passwd'] = $row['passwd'];
		$_SESSION['shop_name'] = $row['shop_name'];
		$_SESSION['address'] = $row['address'];
		$_SESSION['city_name'] = $row['city_name'];
		$_SESSION['country_name'] = $row['country_name'];
		$_SESSION['security_question'] = $row['security_question'];
		$_SESSION['security_ans'] = $row['security_ans'];
		$_SESSION['transaction_pin'] = $row['transaction_pin'];
		$_SESSION['available_balance'] = $row['available_balance'];
		header("location: shopkeeper_dashboard.php");
     }
}
?>