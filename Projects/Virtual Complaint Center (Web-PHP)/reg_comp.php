<!DOCTYPE html>
<head>
	<title>VCC | Register Complaint </title>
	<meta name="keywords" content="" />
	<meta name="description" content="" />
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link href="http://fonts.googleapis.com/css?family=Open+Sans:300,400,700" rel="stylesheet" type="text/css">
	<link href="css/font-awesome.min.css" rel="stylesheet" type="text/css">
	<link href="css/bootstrap.min.css" rel="stylesheet" type="text/css">
	<link href="css/bootstrap-theme.min.css" rel="stylesheet" type="text/css">
	<link href="css/templatemo_style.css" rel="stylesheet" type="text/css">
</head>
<?php
require 'connection-bld.php';
$form_status ="Register New Complaint"; 
$userName = $userEmail = $usersubject = $userMsg ="";	
$token_no=0;	
$cstatus = "in process.";
$userN = $userE = $userS = $userM = "";
$request_method = $no_error = $success = false;
if ($_SERVER["REQUEST_METHOD"] == "POST")
{	
	$request_method = true; 
	$userName=$_REQUEST['uname'];
	$userEmail=$_REQUEST['uemail'];
	$usersubject = $_REQUEST['usubject'];
	$userMsg=$_REQUEST['ucomplaint'];
	if($userName == ""){
	 $userN = "Required";
	}
	if($userEmail == ""){
	$userE = "Required";
	}
	if($usersubject == ""){
	$userS = "Required";
	}
	if($userMsg == ""){
	$userM = "Required";
	}
	if($userName =="" or $userEmail=="" or $usersubject=="" or $userMsg==""){
		$form_status = "Form Not Filled Complete! Kindly Fill.!";
	}
	else{
		  $no_error = true;
		  $query_new_user = ( "INSERT INTO users_complaints (full_name, email_id, category,complaint,comp_status) VALUES ( '".$userName."','".$userEmail."', '".$usersubject."','".$userMsg."', '".$cstatus."' )" );
		  if( ! mysql_query($query_new_user,$link2)){
			  die("Error : " .mysql_error()); 
		  }
		  else{
			  $form_status = "complaint submitted!";
			  $success = true;
			  $query_t = ("SELECT token_no FROM users_complaints WHERE full_name='$userName' && email_id='$userEmail' && category='$usersubject' && complaint='$userMsg'");
			  $result_t = mysql_query($query_t, $link2) or die("Error : " .mysql_error());
			  if($result_t){
				 $row = mysql_fetch_array($result_t);
				 $token_no = $row['token_no'];
			  }	
		  }	
	}
}	
?>
<body class="templatemo-bg-image-2">
	<div class="container">
		<div class="form-group1">
		  <div class="col-md-12">
			<input type="submit" value="Go Back To Home" onClick="parent.location='index.html'" class="btn btn-success pull-right">
		  </div>
		</div>
		
		<div class="col-md-12">			
				<div class="form-group">
					<div class="col-md-12">
						<h1 class="margin-bottom-15"><?php echo $form_status; ?></h1>
					</div>
				</div>	
				<?php if($request_method and $no_error and $success){?>
				<div class="form-group">
		          <div class="col-md-12">		          	
		            <label for="name" class="control-label">Your Complaint Token Number *</label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-user"></i>
		            	<input type="text" class="form-control" readonly="readonly" value="<?php echo $token_no;?>"  id="name" name="uname" placeholder="">
		            </div>		            		            		            
		          </div>              
		        </div> 
				<div class="form-group">
		          <div class="col-md-12">		          	
		            <label for="name" class="control-label">Your Complaint Status *</label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-user"></i>
		            	<input type="text" class="form-control" readonly="readonly" value="<?php echo $cstatus;?>"  id="name" name="uname" placeholder="">
		            </div>		            		            		            
		          </div>              
		        </div> 
				<div class="form-group">
		          <div class="col-md-12">		          	
		            <label for="name" class="control-label">Name *</label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-user"></i>
		            	<input type="text" class="form-control" readonly="readonly" value="<?php echo $userName;?>"  id="name" name="uname" placeholder="">
		            </div>		            		            		            
		          </div>              
		        </div> 
		        <div class="form-group">
		          <div class="col-md-12">
		            <label for="email" class="control-label">Email *</label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-envelope-o"></i>
		            	<input type="email" class="form-control" readonly="readonly" value="<?php echo $userEmail;?>" id="email" name="uemail" placeholder="">
		            </div>
		          </div>
		        </div>
		        <div class="form-group">
		          <div class="col-md-12">
		            <label for="subject" class="control-label">Type of complaint category *</label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-info-circle"></i>
		            	<input type="text" class="form-control" readonly="readonly" value="<?php echo $usersubject;?>" id="subject" name="usubject" placeholder="">
		            </div>
		          </div>
		        </div>
		        <div class="form-group">
		          <div class="col-md-12">
		            <label for="message" class="control-label">Your complaint *</label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-pencil-square-o"></i>
		            	<textarea rows="8" cols="50" class="form-control" readonly="readonly"  id="message" name="ucomplaint" placeholder="<?php echo $userMsg;?>"></textarea>
		            </div>
		          </div>
		        </div>	
			<?php }else{?>
			
			<form class="form-horizontal templatemo-contact-form-1" role="form" action="reg_comp.php" method="post">			
		        <div class="form-group">
		          <div class="col-md-12">		          	
		            <label for="name" class="control-label">Name * <span class="warning"><?php echo $userN;?></span></label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-user"></i>
		            	<input type="text" class="form-control" id="name" name="uname" value="<?php echo $userName; ?>">
		            </div>		            		            		            
		          </div>              
		        </div>
		        <div class="form-group">
		          <div class="col-md-12">
		            <label for="email" class="control-label">Email *<span class="warning"><?php echo $userE;?></span></label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-envelope-o"></i>
		            	<input type="email" class="form-control" id="email" name="uemail" value="<?php echo $userEmail; ?>">
		            </div>
		          </div>
		        </div>
		        <div class="form-group">
		          <div class="col-md-12">
		            <label for="subject" class="control-label">Type of complaint category *<span class="warning"><?php echo $userS;?></span></label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-info-circle"></i>
		            	<input type="text" class="form-control" id="subject" name="usubject" value="<?php echo $usersubject; ?>">
		            </div>
		          </div>
		        </div>
		        <div class="form-group">
		          <div class="col-md-12">
		            <label for="message" class="control-label">Enter complaint *<span class="warning"><?php echo $userM;?></span></label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-pencil-square-o"></i>
		            	<textarea rows="8" cols="50" class="form-control" id="message" name="ucomplaint" placeholder="<?php echo $userMsg; ?>"></textarea>
		            </div>
		          </div>
		        </div>
		        <div class="form-group">
		          <div class="col-md-12">
		            <input type="submit" value="Submit Complaint" class="btn btn-success pull-right">
		          </div>
		        </div>		    	
		      </form>	
			  <?php }?>
				
		</div>
	</div>
</body>
</html>