<!DOCTYPE html>
<head>
	<title>VCC | View Complaint  </title>
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
$form_status = $userName = $userEmail = $usersubject = $userMsg = $userStatus  = "";	
$token_no = $utoken=0;	
$token_found = true;
$valid = false;
if ($_SERVER["REQUEST_METHOD"] == "POST")
{	
	 $utoken=$_REQUEST['token'];
	 if(!$utoken){
		$form_status = "Token Must Required.";
		$token_found = false;
	 }
	else{	 
		$token_found = true;
		$query_t = ("SELECT * FROM users_complaints WHERE token_no='$utoken' ");
		$result_t = mysql_query($query_t, $link2) or die("Error : " .mysql_error());
		if( mysql_num_rows($result_t)>0 ){
			$form_status = " Here is Your Complaint Status..!!";
			$row = mysql_fetch_array($result_t);
			$token_no = $row['token_no'];
			$userName = $row['full_name'];
			$userEmail = $row['email_id'];
			$usersubject = $row['category'];
			$userMsg = $row['complaint'];
			$userStatus = $row['comp_status'];
			$valid = true;
		}
		else{
			$form_status = "Token Not Found..! Try Again";
			$valid = false;
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
					<?php if($token_found and $valid){?>
		        <div class="form-group">
		          <div class="col-md-12">		          	
		            <label for="name" class="control-label">Complaint Token Number *</label>
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
		            	<input type="text" class="form-control" readonly="readonly" value="<?php echo $userStatus;?>"  id="name" name="uname" placeholder="">
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
		            <label for="message" class="control-label">Enter complaint *</label>
		            <div class="templatemo-input-icon-container">
		            	<i class="fa fa-pencil-square-o"></i>
		            	<textarea rows="8" cols="50" class="form-control" readonly="readonly"  id="message" name="ucomplaint" placeholder="<?php echo $userMsg;?>"></textarea>
		            </div>
		          </div>
		        </div>	
					<?php }else{?>	
					<div class="col-md-12">			
						<form class="form-horizontal templatemo-contact-form-1" role="form" action="view_comp.php" method="post">
							<div class="form-group">
								<div class="col-md-12">
									<h1 class="margin-bottom-15">View Your Complaint Status</h1>
								</div>
							</div>				
							<div class="form-group">
							  <div class="col-md-12">		          	
								<label for="name" class="control-label">Enter Token Number *</label>
								<div class="templatemo-input-icon-container">
									<i class="fa fa-user"></i>
									<input type="number" class="form-control" id="name" name="token" placeholder="">
								</div>		            		            		            
							  </div>              
							</div>
							
							<div class="form-group">
							  <div class="col-md-12">
								<input type="submit" value="Submit Token" class="btn btn-success pull-right">
							  </div>
							</div>		    	
					  </form>		      
				    </div>
					<?php }?>
		</div>
	</div>
</body>
</html>