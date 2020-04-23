<?php 
require 'session.php';
require 'loggedIn.php';
if(!LoggedIn()){
	echo "Sorry..!! You are not Logged in...";
    exit;
}
?>
<!DOCTYPE HTML>
<html>
<head>
<title> Easy Transfer | Shop Keeper Dashboard </title>
<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link href="web/css/style1.css" rel="stylesheet" type="text/css" media="all" />
<link href="web/css/portlet.css" rel="stylesheet" type="text/css" media="all" />
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
<style>
.hoverTable{
		width:100%; 
		border-collapse:collapse; 
	}
	.hoverTable td{ 
		padding:7px; border:#4e95f4 1px solid;
	}
	/* Define the default color for all the table rows */
	.hoverTable tr{
		background: #b8d1f3;
	}
	/* Define the hover highlight color for the table row */
    .hoverTable tr:hover {
          background-color: #ffff99;
    }
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
    <div class="login">
          <div class="wrap">
				<div class="section group">
				   <div class="labout span_1_of_about">
					  <h3>SFO DashBoard</h3>
					  <div class="testimonials">
							<div class="testi-item">
								  <blockquote class="testi-item_blockquote">
										<div class="header-top-white">
											<div class="wrap">
											  <ul class="options-font">
											     <a href="sfo_dashboard.php">Main View</a>
											  </ul>
											</div>
										</div>
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font" >
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
										<div class="header-top">
											<div class="wrap">
											  <ul class="options-font" >
											     <a href="sfo_order.php">Order Balance</a>
											  </ul>
											</div>
										</div>
										<div class="clear"></div>										
								  </blockquote>
							</div>
				       </div>
			    </div>
				<div class="cont span_2_of_about">
				    <h3>Main DashBoard</h3>
                            <TABLE class="hoverTable">
                                                <tr>
                                                    <td><input type="checkbox" =""/></td>
                                                    <td><b>SK Name</b></td>
                                                    <td><b>SK Mobile#</b></td>
                                                    <td><b>Order Amount</b></td>
                                                    <td><b>Current Balance</b></td>
													<td><b>Order Date</b></td>
													<td><b>Status</b></td>
													<td><b>Transfer Money</b></td>
                                                </tr> 
                                                <?php
                                                require 'connection-bld.php';
                                                $sfo_mobile_no = $_SESSION['mobile_no'];
												$new_order = 0;
                                                $query2 = ("Select * from shop_keeper_orders where sfo_mobile_no='$sfo_mobile_no' and order_status='$new_order'");
												$result1 = mysql_query($query2, $link2) or die("Error : " .mysql_error());
												if($result1){
													if(mysql_num_rows($result1)>0){
														while ($row = mysql_fetch_array($result1)) {
													
															$sname = "Hello World";
															$smobile = $row['shop_keeper_mobile_no'];
															$order_bal = $row['order_amount'];
															$av_bal = $row['available_balance'];
															$order_time = $row['order_timestamp'];
															$Ostatus = $row['order_status'];
															if(!$Ostatus)  $Ostatus = "New";
															$click = "Click";
															
															$_SESSION['clicked'] = true;
															$_SESSION['smobile'] = $smobile;
															$_SESSION['order_bal'] = $order_bal;
															
															echo '
																<tr>
																	<td><input type="checkbox" /></td>
																	<td>' . $sname . '</td>
																	<td>' . $smobile . '</td>
																	<td>' . $order_bal . '</td>
																	<td>' . $av_bal . '</td>
																	<td>' . $order_time . '</td>
																	<td >' . $Ostatus . '</td>
																	<td ><a href="sfo_transfer.php">' . $click . '</td>
																</tr>
																';
														}
													}
												}
                                                ?>
                                        </table>
                                </div>
                                <!-- END EXAMPLE TABLE PORTLET-->	
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
					<p>Developed & Designed by <a href="#">Dharam Solutions Inc.</p>
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