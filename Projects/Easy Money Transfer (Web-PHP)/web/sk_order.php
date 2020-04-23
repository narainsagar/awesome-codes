<?php 
require 'session.php';
require 'loggedIn.php';
if(!LoggedIn()){
//echo "Sorry..!! You are not Logged in...";
//exit;
	header("Location: login.php");
	exit;
}
?>
<!DOCTYPE HTML>
<html>
<head>
<title> Easy Transfer | Order Balance </title>
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
	         <div class="col_1_of_2 span_1_of_2"> 
				<ul class="f-list">
				  <a href="index.php"><img src="web/images/mainlogo.png"></a> 
				  <a href="index.php"><span class="f-text"> EASY TRANSFER </span></a> 
				</ul>
				<div class="clear"></div>
			</div>
			 <div class="cssmenu">
				<ul>
					<li><a href="shopkeeper_dashboard.php">Home</a></li> |  
					<li><a href="">Welcome <?php echo $_SESSION['full_name']; ?></a></li> |
					<li><a href="logout.php">Logout</a></li>
				</ul>
			</div>
			<div class="clear"></div>
 		</div>
	</div>
	<?php
	require 'connection-bld.php';
	$current_balance = 0;
	$trx_success = $Order_Amount_Err = $sk_mobile_no = $sfo_mobile_no = "";
	$sk_mobile_no = $_SESSION['mobile_no'];
	$query_t = ("SELECT * FROM shop_keeper WHERE mobile_no='$sk_mobile_no'");
	$result_t = mysql_query($query_t, $link2) or die("Error : " .mysql_error());
	if($result_t){
		if(mysql_num_rows($result_t)>0){
			$row = mysql_fetch_array($result_t);
			$current_balance = $row['available_balance'];
			$sfo_mobile_no = $row['SFO_mobile_no'];
		}
	}		 
	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
	    $valid = true;
		if (empty($_POST["order_amount"]))
		{
		   $Order_Amount_Err = "*[Required]";
		   $valid = false; //false
		}
		if($valid){
			// variables
			$order_amount = $_POST["order_amount"];
			$available_balance = $current_balance;																																		
			$order_date = date("d-m-Y");
			$query = ("INSERT INTO shop_keeper_orders ( shop_keeper_mobile_no, sfo_mobile_no, available_balance ,order_amount, order_date ) VALUES ( '".$sk_mobile_no."', '".$sfo_mobile_no."', '".$available_balance."', '".$order_amount."', '".$order_date."' )");
			if( ! mysql_query($query,$link2)){
	          die("Error : " .mysql_error()); 
			}
			else{
				  // Order Sent-successfull..
				  echo "Order Sent Successfull!";
				  $trx_success = "Order Sent Successfull!";
			}  
		}
	}
	?>
    <div class="login">
          <div class="wrap">
			<!--	<ul class="breadcrumb breadcrumb__t"><a class="home" href="#">Home</a>  / About</ul> -->
				<div class="section group">
				   <div class="labout span_1_of_about">
					  <h3>Shop Keeper DashBoard Menu</h3>
					  <div class="testimonials">
							<div class="testi-item">
								  <blockquote class="testi-item_blockquote">
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font" >
											     <a href="shopkeeper_dashboard.php">Main View</a>
											  </ul>
											</div>
										</div>
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font" >
											     <a href="sk_transfer.php">Transfer Money</a>
											  </ul>
											</div>
										</div>
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font" >
											     <a href="sk_receive.php">Receive Money</a>
											  </ul>
											</div>
										</div>
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font" >
											     <a href="sk_check.php">Check Balance</a>
											  </ul>
											</div>
										</div>
										<div class="header-top-white">
											<div class="wrap">
											  <ul class="options-font" >
											     <a href="sk_order.php">Order Balance</a>
											  </ul>
											</div>
										</div>
										<!--
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font" >
											     <a href="sk_history.php">View History</a>		
											  </ul>
											</div>
										</div>
										-->
										<div class="clear"></div>										
								  </blockquote>	  						 
							</div>
				       </div>
			    </div>
				<div class="cont span_2_of_about">
				    <h3>Order Balance</h3>
					<div class="login">
						 <div class="wrap">
								<span class="error"> <?php echo $trx_success;?> </span>
									<div id="loginbox" class="loginbox">
										<form action="sk_order.php" method="post" name="login" id="login-form">
											  <fieldset class="input">
												<p id="login-form-username">
												  <label for="modlgn_username">Your Current Balance Is</label>
												  <input id="modlgn_username" readonly="readonly" value="<?php echo $current_balance;?>" class="inputbox" size="18" autocomplete="ff">
												</p>
												<p id="login-form-username">
												  <label for="modlgn_username">Order New Amount <span class="error"> <?php echo $Order_Amount_Err;?> </span></label>
												  <input id="order_amount" type="text" name="order_amount" class="inputbox" size="18" autocomplete="off">
												</p>
												<div class="remember">
													 <input type="submit" name="Submit" class="button" value="Confirm & Order"><div class="clear"></div>
												 </div>
											  </fieldset>
										 </form>
									</div>	
						 </div>
					</div>   
			    </div>
			    <div class="clear"></div>	
		  </div>
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