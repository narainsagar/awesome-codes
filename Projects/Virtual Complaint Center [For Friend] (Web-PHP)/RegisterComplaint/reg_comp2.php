<?php
session_start();
?>
<?php
require 'connection-bld.php';
$form_status = $userId = $userDept = $userSub = $userMsg ="";		
$cstatus = "in process.";
$token = 0;
if ($_SERVER["REQUEST_METHOD"] == "POST")
{	
	$userSub=$_REQUEST['cSub']; //sub
	$userDept = $_REQUEST['cDept']; //dept
	$userMsg=$_REQUEST['cMsg']; //msg
	 // session_start();
	  $userId=$_SESSION["username"];
	  $query_new_user = ( "INSERT INTO registercomplaint (user_id, subject,dept,msg) VALUES ('".$userId."', '".$userSub."', '".$userDept."','".$userMsg."' )" );
	  if( ! mysql_query($query_new_user,$link2)){
		  die("Error : " .mysql_error()); 
	  }
	  else{
		  $form_status = "complaint submitted!";
	  }	
	$query_t = ("SELECT token_no FROM registercomplaint WHERE user_id='$userId' && subject='$userSub' && dept='$userDept' && msg='$userMsg'");
	$result_t = mysql_query($query_t, $link2) or die("Error : " .mysql_error());
	if($result_t){
		$row = mysql_fetch_array($result_t);
		$token = $row["token_no"];
	}	
}	
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
	    </div>
	 </div>			      	
  <!------FOOTER Starts----------->
  <div  id="contact" class="footer">
      <div class="container">
	  
		   <br><br><br><br><br>
		 <h1><center><font color="white" size=7><?php echo $form_status; ?></font></center></h1>
		 <br>
		 <div class="row">
		 
			 
			 </div>
			  
			  <div class="col-md-6">
				  <div class="footer-right">
				 <div class="form">
				 <form>
					 <input type="text" class="text" readonly="readonly" value="<?php echo $token;?>" name="uname" >
					 
					 <input type="text" class="text" readonly="readonly" value="<?php echo $userSub;?>" name="uname" >
					 <input type="text" class="text" readonly="readonly" value="<?php echo $userDept;?>" name="udept" >
					 
					 <textarea rows="4" cols="70" name="umsg" readonly="readonly" value=""><?php echo $userMsg;?></textarea>
					 <div class="clear"> </div>
				 </form>
				 </div>
				  </div>
				  
		 </div>
	 
 
 </body>
 </html>
 
   