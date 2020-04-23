<?php
session_start();
?>
<!DOCTYPE html>
<html>
<head>
	<title>Virtual Complaint Center NUCES Karachi</title>
	<script src="js/jquery.min.js"> </script>
	
	<link href="css/style.css" rel="stylesheet" type="text/css" media="all" />
	<link href="css/style.css" rel="stylesheet" type="text/css" media="all" />
	<link href="css/styleheader.css" rel="stylesheet" type="text/css" media="all" />
	<link href='http://fonts.googleapis.com/css?family=Lato:100,300,400,700,900' rel='stylesheet' type='text/css'>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<script type="application/x-javascript"> addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false); function hideURLbar(){ window.scrollTo(0,1); } </script>
	<!---- start-smoth-scrolling---->
		<script type="text/javascript" src="js/move-top.js"></script>
		<script type="text/javascript" src="js/easing.js"></script>
		<script type="text/javascript">
			jQuery(document).ready(function($) {
				$(".scroll").click(function(event){		
					event.preventDefault();
					$('html,body').animate({scrollTop:$(this.hash).offset().top},1000);
				});
			});
		</script>
 	<!---- start-smoth-scrolling---->
</head>
<body>
<div class="header" id="home">
  	  <div class="header_top">
	   <div class="wrap">
		 	     <div class="logo">
						<a><img src="images/logo2.png" alt="" /></a>
						</div>	
						<div class="welcome">
						<a href="http://localhost/hci/"><img src="images/logout.png"/></a>
						<?php echo $_SESSION["username"]; ?></div>
						
						
						</div>
						
					</div>	
												
	    		 <div class="clear"></div>
	        </div>
  <!------FOOTER Starts----------->
  <div  id="contact" class="footer">
      <div class="container">
	  
		   <br><br><br><br><br>
		 <h1><center><font color="white" size=7>Register your Complaint</font></center></h1>
		 <br>
		 
			  <div class="col-md-6">
				  <div class="footer-right">
				 <div class="form">
				 <form method="post" action="reg_comp2.php">
					 <input type="text" class="text" value="Subject" name="cSub" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Name';}">
					 <input type="text" class="text" value="Select Department" name="cDept" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'E-mail';}">
					 
					 <textarea rows="4" cols="70" name="cMsg" onfocus="if(this.value == 'Your Message') this.value='';" onblur="if(this.value == '') this.value='Your Message';" >Description</textarea>
					 <div class="clear"> </div>
					 <input type="submit" value="SUBMIT"> 
				 </form>
				 </div>
				  </div>
				  
		 </div>
	 
 </div>
 </div>
 </body>
 </html>
 
   