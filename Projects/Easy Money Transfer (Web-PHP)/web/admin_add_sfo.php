<?php 
require 'session.php';
require 'loggedIn.php';
if(!LoggedIn()){
//echo "Sorry..!! You are not Logged in...";
//exit;
	header("Location: sfo_login.php");
	exit;
}
?>
<!DOCTYPE HTML>
<html>
<head>
<title> Easy Transfer | Tranfer Money </title>
<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link href="web/css/style1.css" rel="stylesheet" type="text/css" media="all" />
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
					<li><a href="sfo_dashboard.php">Home</a></li> |  
					<li><a href="sfo_dashboard.php">Welcome <?php echo $_SESSION['full_name']; ?></a></li> |
					<li><a href="logout.php">Logout</a></li>
				</ul>
			</div>
			<div class="clear"></div>
 		</div>
	</div>
	<?php
	require 'connection-bld.php';
	$requested_order = false;
	$current_balance = 0;
	$sk_mobile = $sfo_mobile_no = $trx_pin = $trx_amount = "";
	$trx_done = false;
	$trx_success = $sk_mobile_Err = $Amount_Err = $Pin_Err = "";
	$sfo_mobile_no = $_SESSION['mobile_no'];
	// check current available balance.
	$query_t = ("SELECT available_balance FROM sfo WHERE mobile_no='$sfo_mobile_no'");
	$result_t = mysql_query($query_t, $link2) or die("Error : " .mysql_error());
	if($result_t){
		$row = mysql_fetch_array($result_t);
		$current_balance = $row['available_balance'];
	}
	if(isset($_SESSION['clicked'])){
		$_POST["sk_mobile"] = $_SESSION['smobile'];
		$_POST["trx_amount"] = $_SESSION['order_bal'];
		$_SERVER["REQUEST_METHOD"] = "POST";
		unset($_SESSION['smobile']);
		unset($_SESSION['order_bal']);
		unset($_SESSION['clicked']);
		$_SESSION['requested_order'] = true;
	}
	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
	    $valid = true;
		if (empty($_POST["sk_mobile"]))
		{
		   $sk_mobile_Err = "*[Required]";
		   $valid = false; //false
		}else $sk_mobile = $_POST["sk_mobile"];
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
			// check current available balance.
			$query_tt = ("SELECT * FROM shop_keeper WHERE mobile_no='$sk_mobile'");
			$result_tt = mysql_query($query_tt, $link2) or die("Error : " .mysql_error());
			if($result_tt){
				if( mysql_num_rows($result_tt)>0 ){ // valid shopkeeper
					$sk_row = mysql_fetch_array($result_tt);
					if((($trx_amount*0.030)+($trx_amount)) <= $current_balance){ // balance is available_ transaction proceed..
						$query = ("INSERT INTO sfo_transactions ( sfo_mobile_no, shop_keeper_mobile_no, transac_amount, transac_date ) VALUES ( '".$sfo_mobile_no."', '".$sk_mobile."', '".$trx_amount."', '".$trx_date."' )");
						if( ! mysql_query($query,$link2)){
						  die("Error : " .mysql_error()); 
						}
						else{   // transaction-successfull..
							//  echo "Transaction Successfull!";
							  $trx_success = "Transaction Successfull!";
							  $order_st=true;
							  //update order_status to True;
							  if(isset($_SESSION['requested_order'])){
								  $query_update_order_status = ("update shop_keeper_orders set order_status='$order_st' where SFO_mobile_no='$sfo_mobile_no' and shop_keeper_mobile_no='$sk_mobile' and order_amount='$trx_amount'");
								  if( ! mysql_query($query_update_order_status,$link2))
									die("Error : " .mysql_error());
								  else{
								     // success..
									 unset($_SESSION['requested_order']);
								  }
							  }
							  // update current balance to new balance.. // both SFo and SK.
							  $current_balance = $current_balance - (($trx_amount*0.030)+($trx_amount));
							  $sk_bal = $sk_row['available_balance'];
							  $sk_bal = $sk_bal+(($trx_amount*0.030)+($trx_amount));
							  $query_update = ("update sfo set available_balance='$current_balance' where mobile_no='$sfo_mobile_no'");
							  $query_update2 = ("update shop_keeper set available_balance='$sk_bal' where mobile_no='$sk_mobile'");
							  if( ! ( mysql_query($query_update,$link2) && mysql_query($query_update2,$link2)) ){
								  die("Error : " .mysql_error());
							  }
							  else{
								// available balance successfully updated.. both SK and SFO
								 $trx_done = true;
							  }
						}
					} 
					else{
						$trx_success = "Sorry.! you have not sufficient balance.";
					}
				}
				else{
					$trx_success = "Sorry.! Shopkeeper mobile # is Invalid.";
				}
			}				
		}
	}
	?>
    <div class="login">
          <div class="wrap">
			<!--	<ul class="breadcrumb breadcrumb__t"><a class="home" href="#">Home</a>  / About</ul> -->
				<div class="section group">
				   <div class="labout span_1_of_about">
					  <h3>SFO DashBoard</h3>
					  <div class="testimonials">
							<div class="testi-item">
								  <blockquote class="testi-item_blockquote">
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font">
											     <a href="sfo_dashboard.php">Main View</a>
											  </ul>
											</div>
										</div>
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font-white" >
											     <a href="sfo_transfer.php">Transfer Money</a>
											  </ul>
											</div>
										</div>
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font" >
											     <a href="sfo_check.php">Check Balance</a>
											  </ul>
											</div>
										</div>
										
										<div class="clear"></div>										
								  </blockquote>
							</div>
				       </div>
			    </div>
				<div class="cont span_2_of_about">
				    <h3>Transfer Money</h3>
					<div class="login">
						 <div class="wrap">
								<span class="error">  <?php echo $trx_success; ?></span>
								<div id="loginbox" class="loginbox">
								  <?php 
									if($trx_done){
										 echo "<br/>";
										 echo "A message has been sent to SFO # ".$sfo_mobile_no; 
										 echo "<br/>";
										 echo "A message has been sent to Shopkeeper # ".$sk_mobile; 
										 echo "<br/>";
										 ?>
										 <p id="login-form-username">
												  <label for="modlgn_username">Your New Available Balance Is</label>
												  <input id="modlgn_username" readonly="readonly" value="<?php echo $current_balance;?>" class="inputbox" size="18" autocomplete="ff">
										 </p> <?php
										exit;
									}?>
										<form method="POST" name="login" id="login-form" action="sfo_transfer.php">
											  <fieldset class="input">
												<p id="login-form-username">
												  <label for="modlgn_username">Your Current Available Balance Is</label>
												  <input id="modlgn_username" readonly="readonly" value="<?php echo $current_balance;?>" class="inputbox" size="18" autocomplete="ff">
												</p>
												<p id="login-form-username">
												  <label for="modlgn_username">Shopkeeper Mobile Number <span class="error"><?php echo $sk_mobile_Err;?></span></label>
												  <input id="sk_mobile" type="text" name="sk_mobile" value="<?php echo $sk_mobile;?>" class="inputbox" size="18" autocomplete="off">
												</p>
												<p id="login-form-username">
												  <label for="modlgn_username">Transaction Amount <span class="error"><?php echo $Amount_Err;?></span></label>
												  <input id="trx_amount" type="text" name="trx_amount" value="<?php echo $trx_amount;?>" class="inputbox" size="18" autocomplete="off">
												</p>
												<p id="login-form-password">
												  <label for="modlgn_passwd">Your Trx Pin Code <span class="error"><?php echo $Pin_Err;?></span></label>
												  <input id="trx_pin" type="password" name="trx_pin" value="<?php echo $trx_pin;?>" class="inputbox" size="18" autocomplete="off">
												</p>
												<div class="remember">
													 <input type="submit" name="Submit" class="button" value="Confirm & Send"><div class="clear"></div>
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