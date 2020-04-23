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
<title> Easy Transfer | Shop Keeper Dashboard </title>
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
	$row;
	$Trx_ID = "Enter Trx ID";
	$trx_done1 = $trx_done2 = false;
	$trx_success = $trx_id_err = "";
	$trx_search_result1 = $trx_search_result2 = "";
	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
	    $valid = true;
		if (empty($_POST["trx_id"]) || $_POST["trx_id"]== "Enter Trx ID")
		{
		   $Trx_ID = "Enter Trx ID";
		   $trx_id_err = "*[Required]";
		   $valid = false; //false
		}else $Trx_ID = $_POST["trx_id"];
		if($valid){
			// variables
		//	$Trx_ID = $_POST["trx_id"];
			$sk_mobile_no = $_SESSION['mobile_no'];
			$query1 = ("SELECT * FROM shop_keeper_transactions_send WHERE trx_id='$Trx_ID'");
			$result1 = mysql_query($query1, $link2) or die("Error : " .mysql_error());
			$query2 = ("SELECT * FROM shop_keeper_transactions_receive WHERE trx_id='$Trx_ID'");
			$result2 = mysql_query($query2, $link2) or die("Error : " .mysql_error());
			if($result2){
				if(mysql_num_rows($result2) != 0){
					$trx_success = "Trx. Found..! || ";
					$trx_done2 = true;
					$trx_search_result2 = "Transaction is RECEIVED.";
				}
			}
			if($result1){
				if(mysql_num_rows($result1) != 0){
					$row = mysql_fetch_array($result1);
					$trx_success = "Trx. Found..! || ";
					$trx_done1 = true;
					$trx_search_result1 = "Transaction is SENT only. ";
				}
				else{
					$trx_success = "Trx. NOT Found..! || ";
				}
			}
		}
	}
	?>
    <div class="login">
          <div class="wrap">
				<div class="section group">
				   <div class="labout span_1_of_about">
					  <h3>Shop Keeper DashBoard Menu</h3>
					  <div class="testimonials">
							<div class="testi-item">
								  <blockquote class="testi-item_blockquote">
										<div class="header-top-white">
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
										<div class="header-top">
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
				    <h3>Main DashBoard View</h3>
					<div class="login">
						 <div class="wrap">
									<div id="loginbox" class="loginbox">
									<span class="error"> <?php echo $trx_success;?> </span>
										<?php 
										if($trx_done1 || $trx_done2){
										?>
										<span class="error"> <?php if($trx_done2){echo $trx_search_result2;} else echo $trx_search_result1;?> </span>
										<p id="login-form-username">
											<label for="modlgn_username">Trx. ID</label>
											<input id="trx_id" readonly="readonly" class="inputbox" size="18" autocomplete="off" value="<?php echo $row['trx_id'];?>">
										</p>
										<p id="login-form-username">
											<label for="modlgn_username">Receiver Mobile#</label>
											<input id="Receiver#" readonly="readonly" class="inputbox" size="18" autocomplete="off" value="<?php echo $row['receiver_mobile'];?>">
										</p>
										<p id="login-form-username">
											<label for="modlgn_username">Receiver CNIC</label>
											<input id="Receiver_cnic" readonly="readonly" class="inputbox" size="18" autocomplete="off" value="<?php echo $row['receiver_cnic'];?>">
										</p>
										<p id="login-form-username">
											<label for="modlgn_username">Sender Mobile#</label>
											<input id="Sender#" readonly="readonly" class="inputbox" size="18" autocomplete="off" value="<?php echo $row['sender_mobile'];?>">
										</p>
										<p id="login-form-username">
											<label for="modlgn_username">Sender CNIC</label>
											<input id="Sender_cnic" readonly="readonly" class="inputbox" size="18" autocomplete="off" value="<?php echo $row['sender_cnic'];?>">
										</p>
										<p id="login-form-username">
											<label for="modlgn_username">Trx. Amount</label>
											<input id="trx_amount" readonly="readonly" class="inputbox" size="18" autocomplete="off" value="<?php echo $row['trx_amount'];?>">
										</p>
										<p id="login-form-username">
											<label for="modlgn_username">Trx. Secret PIN Code</label>
											<input id="secret_pin" readonly="readonly" class="inputbox" size="18" autocomplete="off" value="<?php echo $row['security_pin'];?>">
										</p>
										<?php
											exit;
										}
										?>
										<form method="post" name="login" id="login-form" action="shopkeeper_dashboard.php">
											  <fieldset class="input">
												<p id="login-form-username">
												  <label for="modlgn_username">Search and Check Transaction <span class="error"> <?php echo $trx_id_err;?> </span></label>
												  <input id="trx_id" type="text" name="trx_id" class="inputbox" size="18" autocomplete="off" value="<?php echo $Trx_ID; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $Trx_ID; ?>';}">
												</p>
												<div class="remember">
													 <input type="submit" name="Submit" class="button" value="Search"><div class="clear"></div>
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