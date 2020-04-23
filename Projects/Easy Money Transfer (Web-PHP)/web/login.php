<?php
session_start();
if( isset($_SESSION['login']) && $_SESSION['login_type'] == "SFO" ){
header("location: sfo_dashboard.php");
}
else if( isset($_SESSION['login']) && $_SESSION['login_type'] == "ShopKeeper" ){
header("location: shopkeeper_dashboard.php");
}
?>
<!DOCTYPE HTML>
<html>
<head>
<title> Easy Money Transfer| Log In </title>
<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link href="web/css/style.css" rel="stylesheet" type="text/css" media="all" />
<link href="web/css/form.css" rel="stylesheet" type="text/css" media="all" />
<link href='http://fonts.googleapis.com/css?family=Exo+2' rel='stylesheet' type='text/css'>
<script type="text/javascript" src="web/js/jquery1.min.js"></script>
<!-- start menu -->
<link href="web/css/megamenu.css" rel="stylesheet" type="text/css" media="all" />
<script type="text/javascript" src="web/js/megamenu.js"></script>
<script>$(document).ready(function(){$(".megamenu").megamenu();});</script>
<!--start slider -->
    <link rel="stylesheet" href="web/css/fwslider.css" media="all">
    <script src="web/js/jquery-ui.min.js"></script>
    <script src="web/js/css3-mediaqueries.js"></script>
    <script src="web/js/fwslider.js"></script>
<!--end slider -->
<script src="web/js/jquery.easydropdown.js"></script>
<style>
.error {color: #FF0000;}
</style>
</head>
<body>
     <div class="header-top">
	   <div class="wrap"> 
	          <!--   <div class="logo">
					<a class="active" href="index.php"><img src="web/images/logo.png" alt=""/></a>
				</div> -->
			<div class="col_1_of_2 span_1_of_2"> 
				<ul class="f-list">
				  <a href="index.php"><img src="web/images/mainlogo.png"></a> 
				  <a href="index.php"><span class="f-text"> EASY TRANSFER </span></a> 
				</ul>
				<div class="clear"></div>
			</div>
			 <div class="cssmenu">
				<ul>
					<li><a href="index.php">Home</a></li> |  
					<li><a href="login.php">ShopKeeper Account</a></li> |
					<li><a href="sfo_login.php">SFO Account</a></li>
				</ul>
			</div>
			<div class="clear"></div>
 		</div>
	</div>
<?php
$trx_success = $Login_Id_Err = $Login_Pass_Err = "";
if ($_SERVER["REQUEST_METHOD"] == "POST")
{   require 'connection-bld.php' ; 
	$valid = true;
	if (empty($_REQUEST['user_id']))
	{
	   $Login_Id_Err = "*[Required]";
	   $valid = false; //false
	}
	if (empty($_REQUEST['user_password']))
	{
	   $Login_Pass_Err = "*[Required]";
	   $valid = false; //false
	}
	if($valid){
		$login_id = $_REQUEST['user_id'];
		$login_passwrd = $_REQUEST['user_password'];  
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
							    $trx_success = "Sorry..!! Not a Registered User..";
								echo "Sorry..!! Not a Registered User..";
						}
						else{
								// email exist.. but password not matched.
							   $trx_success = "Sorry..!! your Password is wrong.. Kindly visit forgot Password.";
							   echo "Sorry..!! your Password is wrong.. Kindly visit forgot Password.";
						}
					}
			 }
			 else{
			//	echo "Valid User- Welcome..!!";
				$trx_success = "Login Successfull.!";
				$login = true;
				$row = mysql_fetch_array($result1);
				session_start();
				$_SESSION['login'] = $login;
				$_SESSION['login_type'] = "ShopKeeper";
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
	}
}
?>
        <div class="login">
          	<div class="wrap">
			   <div class="col_1_of_login span_1_of_login">
					<h4 class="title">New Customers</h4>
					<p>Time Value of Money One might know that time is one of the most valuable assets in our lives. In the financial world the value of money is linked to time, So make a account here and easily transfer money to your relative within no time.</p>
					<div class="button1">
					   <a href="register.php"><input type="submit" name="Submit" value="Create an Account"></a>
					 </div>
					 <div class="clear"></div>
				</div>
				<div class="col_1_of_login span_1_of_login">
				<div class="login-title">
	           		<h4 class="title">Registered Customers</h4>
					<div id="loginbox" class="loginbox">
					 <span class="error"> <?php echo $trx_success;?> </span>
						<form action="login.php" method="post" name="login" id="login-form">
						  <fieldset class="input">
						    <p id="login-form-username">
						      <label for="modlgn_username">Log In ID <span class="error"> <?php echo $Login_Id_Err;?> </span></label>
						      <input id="modlgn_username" type="text" name="user_id" class="inputbox" size="18" autocomplete="off">
						    </p>
						    <p id="login-form-password">
						      <label for="modlgn_passwd">Password <span class="error"> <?php echo $Login_Pass_Err;?> </span></label>
						      <input id="modlgn_passwd" type="password" name="user_password" class="inputbox" size="18" autocomplete="off">
						    </p>
						    <div class="remember">
							    <p id="login-form-remember">
							      <label for="modlgn_remember"><a href="forgot.php">Forget Your Password ? </a></label>
							   </p>
							    <input type="submit" name="Submit" class="button" value="Login"><div class="clear"></div>
							 </div>
						  </fieldset>
						 </form>
					</div>
			    </div>
				</div>
				<div class="clear"></div>
			</div>
		</div>
		
     <div class="footer">
		<div class="footer-top">
			<div class="wrap">
			  <div class="section group example">
				<div class="col_1_of_2 span_1_of_2">
					<ul class="f-list">
					  <li><img src="web/images/3.png"><span class="f-text">CONTACT US: +92-312-3841914 </span><div class="clear"></div></li>
					</ul>
				</div>
				<div class="clear"></div>
		      </div>
			</div>
		</div>
		<div class="footer-bottom">
			<div class="wrap">
	             <div class="copy">
				    <p>Copyright © 2014, NUCES. All Rights Reserved.</p>
					<p>Developed & Designed by <a href="https://www.facebook.com/dharamsolutions/">Dharam Solutions Inc.</p>
		         </div>
				<div class="f-list2">
				 <ul>
					<li class="active"><a href="about.html">About Us</a></li> |
					<li><a href="#">Terms and Conditions</a></li> |
					<li><a href="contact.php">Contact Us</a></li> 
				 </ul>
			    </div>
			    <div class="clear"></div>
		      </div>
	     </div>
	</div>
</body>
</html>