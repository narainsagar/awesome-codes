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
<title> Easy Transfer | Receive Money </title>
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
	$trx_done = false;
	$trx_id = $receiver_cnic  = $receiver_mobile = $sender_mobile = $trx_amount = $trx_pin = $trx_date = "";
	$current_balance = 0;
	$sk_mobile_no = $_SESSION['mobile_no'];
	$trx_success = $Receiver_cnic_Err = $Receiver_mobile_Err = $Trx_id_Err = $Amount_Err = $Pin_Err = "";
	// check current available balance.
	$query_t = ("SELECT available_balance FROM shop_keeper WHERE mobile_no='$sk_mobile_no'");
	$result_t = mysql_query($query_t, $link2) or die("Error : " .mysql_error());
	if($result_t){
		$row = mysql_fetch_array($result_t);
		$current_balance = $row['available_balance'];
	}
	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
	    $valid = true;
		if (empty($_POST["trx_id"]))
		{
		   $Trx_id_Err = "*[Required]";
		   $valid = false; //false
		}else $trx_id = $_POST["trx_id"];
		if (empty($_POST["receiver_cnic"]))
		{
		   $Receiver_cnic_Err = "*[Required]";
		   $valid = false; //false
		}else $receiver_cnic = $_POST["receiver_cnic"];
		if (empty($_POST["receiver_mobile"]))
		{
		   $Receiver_mobile_Err = "*[Required]";
		   $valid = false; //false
		}else $receiver_mobile = $_POST["receiver_mobile"];
		if (empty($_POST["trx_amount"]))
		{
		   $Amount_Err = "*[Required]";
		   $valid = false; //false
		}else $trx_amount = $_POST["trx_amount"];
		if (empty($_POST["trx_pin"]))
		{
		   $Pin_Err = "*[Required]";
		   $valid = false; //false
		}else $trx_pin = $_POST["trx_pin"];
		if($valid){
			// variables
			$trx_date = date("d-m-Y"); //date("d-m-Y h:i:sa");
			$query_t = ("SELECT * FROM shop_keeper_transactions_receive WHERE trx_id='$trx_id' and trx_amount='$trx_amount'");
			$result_t = mysql_query($query_t, $link2) or die("Error : " .mysql_error());
			if(mysql_num_rows($result_t) == 0){
					$query1 = ("SELECT * FROM shop_keeper_transactions_send WHERE trx_id='$trx_id' and receiver_cnic='$receiver_cnic' and receiver_mobile='$receiver_mobile' and trx_amount='$trx_amount' and security_pin='$trx_pin'");
					$result1 = mysql_query($query1, $link2) or die("Error : " .mysql_error());         // execute query
					if( $result1 ){
						if(mysql_num_rows($result1) != 0) {
								$flag=true;
								$row = mysql_fetch_array($result1);
								$sender_mobile = $row['sender_mobile'];
								if( $trx_id != $row['trx_id'] ){
									$Trx_id_Err = "*[Trx ID Invalid]";
									$flag = false;
								}
								if( $receiver_cnic != $row['receiver_cnic'] ){
									$Receiver_cnic_Err = "*[Receiver CNIC Invalid]";
									$flag = false;
								}
								if( $receiver_mobile != $row['receiver_mobile'] ){
									$Receiver_mobile_Err = "*[Receiver Mobile# Invalid]";
									$flag = false;
								}
								if( $trx_amount != $row['trx_amount'] ){
									$Amount_Err = "*[Trx Amount Invalid]";
									$flag = false;
								}
								if( $trx_pin != $row['security_pin'] ){
									$Pin_Err = "*[Trx Pin Code Invalid]";
									$flag = false;
								}
								if( $flag ){
									$query = ("INSERT INTO shop_keeper_transactions_receive ( trx_id, shop_keeper_mobile_no, trx_amount, trx_date ) VALUES ( '".$trx_id."', '".$sk_mobile_no."', '".$trx_amount."', '".$trx_date."' )");
									if( ! mysql_query($query,$link2)){
									  die("Error : " .mysql_error()); 
									}
									else{
										  // transaction-successfull..
										  $trx_success = "Transaction Received Successfull!";
										  // update current balance to new balance..
										  $current_balance = $current_balance + (($trx_amount*0.015)+($trx_amount));
										  $query_update = ("update shop_keeper set available_balance='$current_balance' where mobile_no='$sk_mobile_no'");
										  if( ! mysql_query($query_update,$link2)){
											  die("Error : " .mysql_error());
										  }
										  else{  // available balance successfully updated..
											 $trx_done = true;
										  }
									}
								}
						}
					}
			}  
			else{
				$trx_success = "Transaction Already Received!";
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
										<div class="header-top-white">
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
				    <h3>Receive Money</h3>
					<div class="login">
						 <div class="wrap">
								<span class="error">  <?php echo $trx_success; ?></span>
									<div id="loginbox" class="loginbox">
									 <?php 
										if($trx_done){
											 echo "<br/>";
											 echo "A message has been sent to Shopkeeper # ".$sk_mobile_no; 
											 echo "<br/>";
											 echo "A message has been sent to Sender # ".$sender_mobile; 
											 echo "<br/>";
											 echo "A message has been sent to Receiver # ".$receiver_mobile; 
											 echo "<br/>";?>
											 <p id="login-form-username">
													  <label for="modlgn_username">Your New Available Balance Is</label>
													  <input id="modlgn_username" readonly="readonly" value="<?php echo $current_balance;?>" class="inputbox" size="18" autocomplete="ff">
											 </p> <?php
											exit;
										}?>
										<form action="sk_receive.php" method="post" name="login" id="login-form">
											  <fieldset class="input">
												<p id="login-form-username">
													  <label for="modlgn_username">Your Current Available Balance Is</label>
													  <input id="modlgn_username" readonly="readonly" value="<?php echo $current_balance;?>" class="inputbox" size="18" autocomplete="ff">
											    </p>
												<p id="login-form-username">
												  <label for="modlgn_username">Trx ID <span class="error"><?php echo $Trx_id_Err;?></span></label>
												  <input id="trx_id" type="text" name="trx_id" class="inputbox" size="18" autocomplete="off">
												</p>
												<p id="login-form-username">
												  <label for="modlgn_username">Receiver CNIC <span class="error"><?php echo $Receiver_cnic_Err;?></span></label>
												  <input id="receiver_cnic" type="text" name="receiver_cnic" class="inputbox" size="18" autocomplete="off">
												</p>
												<p id="login-form-username">
												  <label for="modlgn_username">Receiver Mobile Number <span class="error"><?php echo $Receiver_mobile_Err;?></span></label>
												  <input id="receiver_mobile" type="text" name="receiver_mobile" class="inputbox" size="18" autocomplete="off">
												</p>
												<p id="login-form-username">
												  <label for="modlgn_username">Transaction Amount <span class="error"><?php echo $Amount_Err;?></span></label>
												  <input id="trx_amount" type="text" name="trx_amount" class="inputbox" size="18" autocomplete="off">
												</p>
												<p id="login-form-username">
												  <label for="modlgn_username">Secret Pin Code <span class="error"><?php echo $Pin_Err;?></span></label>
												  <input id="trx_pin" type="password" name="trx_pin" class="inputbox" size="18" autocomplete="off">
												</p>
												<div class="remember">
													 <input type="submit" name="Submit" class="button" value="Confirm & Receive"><div class="clear"></div>
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