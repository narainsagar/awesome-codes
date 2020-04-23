<!DOCTYPE HTML>
<html>
<head>
<title> Easy Money Transfer | Contact Us </title>
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
					<li><a href="index.php">Home</a></li> |  
					<li><a href="login.php">ShopKeeper Account</a></li> |
					<li><a href="sfo_login.php">SFO Account</a></li>
				</ul>
			</div>
			<div class="clear"></div>
 		</div>
	</div>
<?php
$form_status = "";		
if ($_SERVER["REQUEST_METHOD"] == "POST")
{	
	$userName=$_REQUEST['userName'];
	$userEmail=$_REQUEST['userEmail'];
	$userPhone=$_REQUEST['userPhone'];
	$userMsg=$_REQUEST['userMsg'];
	$subject = "Message from ".$userName; 
	$message = '<html><head><title>'.$subject.'</title></head><body><table><tr><td>Email id :  </td><td> '.$userEmail.'</td></tr>
<tr><td>Phone No : </td><td> '.$userPhone.'</td></tr><tr><td>Name : </td><td> '.$userName.'</td></tr><tr><td>Says : </td><td> '.$userMsg.'</td>
</tr></table></body></html>';
	//$message = "Email id :  ".$userEmail. "\r\nPhone No : ".$userPhone."\r\nName : ".$userName."\r\nSays : ".$userMsg;
	$to=$email_id;
	$headers = "From: " . strip_tags($userEmail) . "\r\n";
	$headers .= "Reply-To: ". strip_tags($userEmail) . "\r\n";
	//$headers .= "CC: susan@example.com\r\n";
	$headers .= "MIME-Version: 1.0\r\n";
	$headers .= "Content-Type: text/html; charset=ISO-8859-1\r\n";
	if(!mail($to, $subject, $message, $headers)){
	  $mail_status='no';
	  $form_status = "[ ERROR OCCURRED IN SUBMITTING FORM ]";
    }else{
	  $form_status = "[ YOUR FORM HAS BEEN SUBMITTED SUCESSFULLY ]";
	  $mail_status='yes';
    } 
}
?>	
    <div class="login">
		<div class="wrap">
		   <h4 class="title">Contact Us Form 
			   <span class="error"><?php echo $form_status;?> </span>
		   </h4>
		   <div class="content-top">
			   <form method="post" action="contact.php">
					<div class="to">
                     	<input type="text" id="userName" name="userName" class="text" value="Name" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Name';}">
					 	<input type="text" id="userEmail" name="userEmail" class="text" value="Email" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Email';}">
					</div>
					<!-- style="margin-left: 10px" -->
					<div class="to">
                     	<input type="text" id="userPhone" name="userPhone" class="text" value="Contact Number" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Contact Number';}">
					 	<input type="text" id="subject" name="subject" class="text" value="Subject" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Subject';}">
					</div>
					<div class="text">
	                   <textarea value="Message:" id="userMsg" name="userMsg" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Type Your Message';}">Type Your Message</textarea>
	                </div>
	                <div class="submit">
	               		<input type="submit" value="Submit">
	                </div>
               </form>
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