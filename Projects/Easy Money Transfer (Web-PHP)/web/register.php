<!DOCTYPE HTML>
<html>
<head>
<title> Easy Money Transfer| Sign Up </title>
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
require 'connection-bld.php'; 
$full_name = "Full Name";
$shop_name = "Shop Name";
$mobile_number = "Mobile Number";
$cnic_number = "CNIC Number";
$passwrd = "Password";
$re_passwrd = "Re-Type Password";
$email_id = "E-Mail";
$transac_pin_code = "Transaction Pin Code";
$address = "Address";
$country = "Select a Country";
$city_name = "City";
$sec_question = "Select a Security Question";
$sec_answer = "Type your Answer";
$SFO_id = "SFO ID";
$SFO_passwrd = "SFO Password";
$trx_success = $Mobile_Err = $Sfo_Id_Err = $Sfo_Pass_Err = $Sec_Quest_Err = $Sec_Ans_Err = $City_Err = $Country_Err = $Address_Err = $Trx_Pin_Err = $Email_Id_Err = $rePasswd_Err = $Passwd_Err = $Shop_Name_Err = $Full_Name_Err = $Cnic_Err = "";
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
	$valid = true;
	if (empty($_REQUEST['full_name']) || $_REQUEST['full_name']=="Full Name")
	{
		$full_name = "Full Name";
		$Full_Name_Err = "*";
		$valid = false; //false
	}else $full_name = $_REQUEST['full_name'];
	if (empty($_REQUEST['shop_name']) || $_REQUEST['shop_name']=="Shop Name")
	{
		$shop_name = "Shop Name";
		$Shop_Name_Err = "*";
		$valid = false; //false
	}else $shop_name = $_REQUEST['shop_name'];
	if (empty($_REQUEST['mobile_number']) || $_REQUEST['mobile_number']=="Mobile Number")
	{
		$mobile_number = "Mobile Number";
		$Mobile_Err = "*";
		$valid = false; //false
	}else $mobile_number = $_REQUEST['mobile_number'];
	if (empty($_REQUEST['cnic_number']) || $_REQUEST['cnic_number']=="CNIC Number")
	{
		$cnic_number = "CNIC Number";
		$Cnic_Err = "*";
		$valid = false; //false
	}else $cnic_number = $_REQUEST['cnic_number'];
	if (empty($_REQUEST['passwd']) || $_REQUEST['passwd']=="Password")
	{
		$passwrd = "Password";
		$Passwd_Err = "*";
		$valid = false; //false
	}else $passwrd = $_REQUEST['passwd'];
	if (empty($_REQUEST['re_passwd']) || $_REQUEST['re_passwd']=="Re-Type Password")
	{
		$re_passwrd = "Re-Type Password";
		$rePasswd_Err = "*";
		$valid = false; //false
	}else $re_passwrd = $_REQUEST['re_passwd'];
	if (empty($_REQUEST['email_id']) || $_REQUEST['email_id']=="E-Mail")
	{
		$email_id = "E-Mail";
		$Email_Id_Err = "*";
		$valid = false; //false
	}else $email_id = $_REQUEST['email_id'];
	if (empty($_REQUEST['transac_pin_code']) || $_REQUEST['transac_pin_code']=="Transaction Pin Code")
	{
		$transac_pin_code = "Transaction Pin Code";
		$Trx_Pin_Err = "*";
		$valid = false; //false
	}else $transac_pin_code = $_REQUEST['transac_pin_code'];
	if (empty($_REQUEST['address']) || $_REQUEST['address']=="Address")
	{
		$address = "Address";
		$Address_Err = "*";
		$valid = false; //false
	}else $address = $_REQUEST['address'];
	if (empty($_REQUEST['country']))
	{
		$country = "Select a Country";
		$Country_Err = "*";
		$valid = false; //false
	}else $country = $_REQUEST['country'];
	if (empty($_REQUEST['city_name']) || $_REQUEST['city_name']=="City")
	{
		$city_name = "City";
		$City_Err = "*";
		$valid = false; //false
	}else $city_name = $_REQUEST['city_name'];
	if (empty($_REQUEST['sec_question']))
	{
		$sec_question = "Select a Security Question";
		$Sec_Quest_Err = "*";
		$valid = false; //false
	}else $sec_question = $_REQUEST['sec_question'];
	if (empty($_REQUEST['sec_answer']) || $_REQUEST['sec_answer'] == "Type your Answer")
	{
		$sec_answer = "Type your Answer";
		$Sec_Ans_Err = "*";
		$valid = false; //false
	}else $sec_answer = $_REQUEST['sec_answer'];
	if (empty($_REQUEST['SFO_id']) || $_REQUEST['SFO_id']=="SFO ID")
	{
		$SFO_id = "SFO ID";
		$Sfo_Id_Err = "*";
		$valid = false; //false
	}else $SFO_id = $_REQUEST['SFO_id'];
	if (empty($_REQUEST['SFO_passwd']) || $_REQUEST['SFO_passwd']=="SFO Password")
	{
		$SFO_passwrd = "SFO Password";
		$Sfo_Pass_Err = "*";
		$valid = false; //false
	}else $SFO_passwrd = $_REQUEST['SFO_passwd'];
	if($valid){
	/*	$full_name = $_REQUEST['full_name'];
		$shop_name = $_REQUEST['shop_name'];
		$mobile_number = $_REQUEST['mobile_number'];
		$cnic_number = $_REQUEST['cnic_number'];
		$passwrd = $_REQUEST['passwd'];
		$re_passwrd = $_REQUEST['re_passwd'];
		$email_id = $_REQUEST['email_id'];
		$transac_pin_code = $_REQUEST['transac_pin_code'];
		$address = $_REQUEST['address'];
		$country = $_REQUEST['country'];
		$city_name = $_REQUEST['city_name'];
		$sec_question = $_REQUEST['sec_question'];
		$sec_answer = $_REQUEST['sec_answer'];
		$SFO_id = $_REQUEST['SFO_id'];
		$SFO_passwrd = $_REQUEST['SFO_passwd'];
	*/
		$new_bal = 1000; // starting balance - new balance load..
		$query1 = ("SELECT * FROM sfo WHERE mobile_no='$SFO_id' and passwd='$SFO_passwrd'"); // query to check user already registered. 
		$result1 = mysql_query($query1, $link2) or die("query1 problem..");        // execute query
		if( mysql_fetch_array($result1) ){
			 // AUTHENTICATED..!! VALID SFO ID and PASSWRD.
			  $query2 = ("SELECT * FROM shop_keeper WHERE mobile_no='$mobile_number'"); // query to check user already registered. #or cnic='$cnic_number' or email_id='$email_id'
			  $result2 = mysql_query($query2, $link2) or die("query2 problem..");        // execute query
			  if( !mysql_fetch_array($result2) ){
				  // VALID and NEW-USER..!!
				  $query_new_user = ( "INSERT INTO shop_keeper ( mobile_no, SFO_mobile_no, cnic_no, full_name, email_id, passwd, shop_name, address, city_name, country_name, security_question, security_ans, transaction_pin, available_balance ) VALUES ( '".$mobile_number."','".$SFO_id."','".$cnic_number."','".$full_name."','".$email_id."','".$passwrd."','".$shop_name."','".$address."','".$city_name."','".$country."','".$sec_question."','".$sec_answer."','".$transac_pin_code."','".$new_bal."' )" );
				  if( ! mysql_query($query_new_user,$link2)){
					  die("Error : " .mysql_error()); 
				  }
				  else{
					  // registration-successfull..
					  $trx_success = "Registeration Successfull!";
					  echo "Congratulations : Registeration Successfull!";
				  }  
			  }
			  else
			  {
				$trx_success = "Sorry..!! You are already registered..!!";
				 echo "Sorry..!! You are already registered..!!";
			  }
		}
		else{
		   $trx_success = "SFO ID or PASSWRD is wrong.!!";
		   echo "Sorry..!! SFO ID or PASSWRD is wrong.. !!";
		}
	}
}
?>
    <div class="register_account">
        <div class="wrap">
    	      <h4 class="title">Create an Account</h4>
			  <span class="error"> <?php echo $trx_success;?> </span>
    		<form method="post" action="register.php">
    			 <div class="col_1_of_2 span_1_of_2">
		   			 <div><span class="error"> <?php echo $Full_Name_Err;?> </span>
					 <input type="text" id="full_name" name="full_name" value="<?php echo $full_name; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $full_name; ?>';}"></div>
		    		 <div><span class="error"> <?php echo $Shop_Name_Err;?> </span>
					 <input type="text" id="shop_name" name="shop_name" value="<?php echo $shop_name; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $shop_name; ?>';}"></div>
		    		 <div><span class="error"> <?php echo $Mobile_Err;?> </span>
					 <input type="text" id="mobile_number" name="mobile_number" value="<?php echo $mobile_number; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $mobile_number; ?>';}"></div>
		    		 <div><span class="error"> <?php echo $Cnic_Err;?> </span>
					 <input type="text" id="cnic_number" name="cnic_number" value="<?php echo $cnic_number; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $cnic_number; ?>';}"></div>
					 <div><span class="error"> <?php echo $Passwd_Err;?> </span>
					 <input type="text" id="passwd" name="passwd" value="<?php echo $passwrd; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $passwrd; ?>';}"></div>
					 <div><span class="error"> <?php echo $rePasswd_Err;?> </span>
					 <input type="text" id="re_passwd" name="re_passwd" value="<?php echo $re_passwrd; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $re_passwrd; ?>';}"></div>
					 <div><span class="error"> <?php echo $Email_Id_Err;?> </span>
					 <input type="text" id="email_id" name="email_id" value="<?php echo $email_id; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $email_id; ?>';}"></div>
					<div><span class="error"> <?php echo $Trx_Pin_Err;?> </span>
					<input type="text" id="transac_pin_code" name="transac_pin_code" value="<?php echo $transac_pin_code; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $transac_pin_code; ?>';}"></div>
		    	 </div>
		    	<div class="col_1_of_2 span_1_of_2">	
		    		<div><span class="error"> <?php echo $Address_Err;?> </span>
					<input type="text" id="address" name="address" value="<?php echo $address; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $address; ?>';}"></div>
		    		<div><span class="error"> <?php echo $Country_Err;?> </span>
					<select id="country" name="country" onchange="change_country(this.value)" class="frm-field required">
		            <option value=""><?php echo $country; ?></option>         
		            <option value="AX">Åland Islands</option>
		            <option value="AF">Afghanistan</option>
		            <option value="AL">Albania</option>
		            <option value="DZ">Algeria</option>
		            <option value="AS">American Samoa</option>
		            <option value="AD">Andorra</option>
		            <option value="AO">Angola</option>
		            <option value="AI">Anguilla</option>
		            <option value="AQ">Antarctica</option>
		            <option value="AG">Antigua And Barbuda</option>
		            <option value="AR">Argentina</option>
		            <option value="AM">Armenia</option>
		            <option value="AW">Aruba</option>
		            <option value="AU">Australia</option>
		            <option value="AT">Austria</option>
		            <option value="AZ">Azerbaijan</option>
		            <option value="BS">Bahamas</option>
		            <option value="BH">Bahrain</option>
		            <option value="BD">Bangladesh</option>
		            <option value="BB">Barbados</option>
		            <option value="BY">Belarus</option>
		            <option value="BE">Belgium</option>
		            <option value="BZ">Belize</option>
		            <option value="BJ">Benin</option>
		            <option value="BM">Bermuda</option>
		            <option value="BT">Bhutan</option>
		            <option value="BO">Bolivia</option>
		            <option value="BA">Bosnia and Herzegovina</option>
		            <option value="BW">Botswana</option>
		            <option value="BV">Bouvet Island</option>
		            <option value="BR">Brazil</option>
		            <option value="IO">British Indian Ocean Territory</option>
		            <option value="BN">Brunei</option>
		            <option value="BG">Bulgaria</option>
		            <option value="BF">Burkina Faso</option>
		            <option value="BI">Burundi</option>
		            <option value="KH">Cambodia</option>
		            <option value="CM">Cameroon</option>
		            <option value="CA">Canada</option>
		            <option value="CV">Cape Verde</option>
		            <option value="KY">Cayman Islands</option>
		            <option value="CF">Central African Republic</option>
		            <option value="TD">Chad</option>
		            <option value="CL">Chile</option>
		            <option value="CN">China</option>
		            <option value="CX">Christmas Island</option>
		            <option value="CC">Cocos (Keeling) Islands</option>
		            <option value="CO">Colombia</option>
		            <option value="KM">Comoros</option>
		            <option value="CG">Congo</option>
		            <option value="CD">Congo, Democractic Republic</option>
		            <option value="CK">Cook Islands</option>
		            <option value="CR">Costa Rica</option>
		            <option value="CI">Cote D'Ivoire (Ivory Coast)</option>
		            <option value="HR">Croatia (Hrvatska)</option>
		            <option value="CU">Cuba</option>
		            <option value="CY">Cyprus</option>
		            <option value="CZ">Czech Republic</option>
		            <option value="DK">Denmark</option>
		            <option value="DJ">Djibouti</option>
		            <option value="DM">Dominica</option>
		            <option value="DO">Dominican Republic</option>
		            <option value="TP">East Timor</option>
		            <option value="EC">Ecuador</option>
		            <option value="EG">Egypt</option>
		            <option value="SV">El Salvador</option>
		            <option value="GQ">Equatorial Guinea</option>
		            <option value="ER">Eritrea</option>
		            <option value="EE">Estonia</option>
		            <option value="ET">Ethiopia</option>
		            <option value="FK">Falkland Islands (Islas Malvinas)</option>
		            <option value="FO">Faroe Islands</option>
		            <option value="FJ">Fiji Islands</option>
		            <option value="FI">Finland</option>
		            <option value="FR">France</option>
		            <option value="FX">France, Metropolitan</option>
		            <option value="GF">French Guiana</option>
		            <option value="PF">French Polynesia</option>
		            <option value="TF">French Southern Territories</option>
		            <option value="GA">Gabon</option>
		            <option value="GM">Gambia, The</option>
		            <option value="GE">Georgia</option>
		            <option value="DE">Germany</option>
		            <option value="GH">Ghana</option>
		            <option value="GI">Gibraltar</option>
		            <option value="GR">Greece</option>
		            <option value="GL">Greenland</option>
		            <option value="GD">Grenada</option>
		            <option value="GP">Guadeloupe</option>
		            <option value="GU">Guam</option>
		            <option value="GT">Guatemala</option>
		            <option value="GG">Guernsey</option>
		            <option value="GN">Guinea</option>
		            <option value="GW">Guinea-Bissau</option>
		            <option value="GY">Guyana</option>
		            <option value="HT">Haiti</option>
		            <option value="HM">Heard and McDonald Islands</option>
		            <option value="HN">Honduras</option>
		            <option value="HK">Hong Kong S.A.R.</option>
		            <option value="HU">Hungary</option>
		            <option value="IS">Iceland</option>
		            <option value="IN">India</option>
		            <option value="ID">Indonesia</option>
		            <option value="IR">Iran</option>
		            <option value="IQ">Iraq</option>
		            <option value="IE">Ireland</option>
		            <option value="IM">Isle of Man</option>
		            <option value="IL">Israel</option>
		            <option value="IT">Italy</option>
		            <option value="JM">Jamaica</option>
		            <option value="JP">Japan</option>
		            <option value="JE">Jersey</option>
		            <option value="JO">Jordan</option>
		            <option value="KZ">Kazakhstan</option>
		            <option value="KE">Kenya</option>
		            <option value="KI">Kiribati</option>
		            <option value="KR">Korea</option>
		            <option value="KP">Korea, North</option>
		            <option value="KW">Kuwait</option>
		            <option value="KG">Kyrgyzstan</option>
		            <option value="LA">Laos</option>
		            <option value="LV">Latvia</option>
		            <option value="LB">Lebanon</option>
		            <option value="LS">Lesotho</option>
		            <option value="LR">Liberia</option>
		            <option value="LY">Libya</option>
		            <option value="LI">Liechtenstein</option>
		            <option value="LT">Lithuania</option>
		            <option value="LU">Luxembourg</option>
		            <option value="MO">Macau S.A.R.</option>
		            <option value="MK">Macedonia</option>
		            <option value="MG">Madagascar</option>
		            <option value="MW">Malawi</option>
		            <option value="MY">Malaysia</option>
		            <option value="MV">Maldives</option>
		            <option value="ML">Mali</option>
		            <option value="MT">Malta</option>
		            <option value="MH">Marshall Islands</option>
		            <option value="MQ">Martinique</option>
		            <option value="MR">Mauritania</option>
		            <option value="MU">Mauritius</option>
		            <option value="YT">Mayotte</option>
		            <option value="MX">Mexico</option>
		            <option value="FM">Micronesia</option>
		            <option value="MD">Moldova</option>
		            <option value="MC">Monaco</option>
		            <option value="MN">Mongolia</option>
		            <option value="ME">Montenegro</option>
		            <option value="MS">Montserrat</option>
		            <option value="MA">Morocco</option>
		            <option value="MZ">Mozambique</option>
		            <option value="MM">Myanmar</option>
		            <option value="NA">Namibia</option>
		            <option value="NR">Nauru</option>
		            <option value="NP">Nepal</option>
		            <option value="NL">Netherlands</option>
		            <option value="AN">Netherlands Antilles</option>
		            <option value="NC">New Caledonia</option>
		            <option value="NZ">New Zealand</option>
		            <option value="NI">Nicaragua</option>
		            <option value="NE">Niger</option>
		            <option value="NG">Nigeria</option>
		            <option value="NU">Niue</option>
		            <option value="NF">Norfolk Island</option>
		            <option value="MP">Northern Mariana Islands</option>
		            <option value="NO">Norway</option>
		            <option value="OM">Oman</option>
		            <option value="PK">Pakistan</option>
		            <option value="PW">Palau</option>
		            <option value="PS">Palestinian Territory, Occupied</option>
		            <option value="PA">Panama</option>
		            <option value="PG">Papua new Guinea</option>
		            <option value="PY">Paraguay</option>
		            <option value="PE">Peru</option>
		            <option value="PH">Philippines</option>
		            <option value="PN">Pitcairn Island</option>
		            <option value="PL">Poland</option>
		            <option value="PT">Portugal</option>
		            <option value="PR">Puerto Rico</option>
		            <option value="QA">Qatar</option>
		            <option value="RE">Reunion</option>
		            <option value="RO">Romania</option>
		            <option value="RU">Russia</option>
		            <option value="RW">Rwanda</option>
		            <option value="SH">Saint Helena</option>
		            <option value="KN">Saint Kitts And Nevis</option>
		            <option value="LC">Saint Lucia</option>
		            <option value="PM">Saint Pierre and Miquelon</option>
		            <option value="VC">Saint Vincent And The Grenadines</option>
		            <option value="WS">Samoa</option>
		            <option value="SM">San Marino</option>
		            <option value="ST">Sao Tome and Principe</option>
		            <option value="SA">Saudi Arabia</option>
		            <option value="SN">Senegal</option>
		         </select>
				 </div>
    	          <div><span class="error"> <?php echo $City_Err;?> </span>
				  <input type="text" id="city_name" name="city_name" value="<?php echo $city_name; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $city_name; ?>';}"></div>
				   <div>
				   <span class="error"> <?php echo $Sec_Quest_Err;?> </span>
				        <select id="sec_question" name="sec_question" onchange="change_country(this.value)" class="frm-field required">
							<option value=""><?php echo $sec_question; ?></option>         
							<option value="What is name of your mother?"> What is name of your mother? </option>
							<option value="What model of Car you have?"> What model of Car you have? </option>
							<option value="What is your favourite fruit?"> What is your favourite fruit? </option>
						</select> 
					</div>
					<div><span class="error"> <?php echo $Sec_Ans_Err;?> </span>
					<input type="text" id="sec_answer" name="sec_answer" value="<?php echo $sec_answer; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $sec_answer; ?>';}"></div>
		           
					<p class="code"><span class="error">Prove us that you are making an account through our Customer Sales Officer.!</span></p> 
					<div><span class="error"> <?php echo $Sfo_Id_Err;?> </span>
					<input type="text" id="SFO_id" name="SFO_id" value="<?php echo $SFO_id; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $SFO_id; ?>';}"></div>
					<div><span class="error"> <?php echo $Sfo_Pass_Err;?> </span>
					<input type="text" id="SFO_passwd" name="SFO_passwd" value="<?php echo $SFO_passwrd; ?>" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = '<?php echo $SFO_passwrd; ?>';}"></div>
				   <br>
		        </div>
			    <div class="submit">
	               	<!--	<p class="terms">By clicking 'Create Account' you agree to the <a href="#">Terms &amp; Conditions</a>.</p> -->
						<input type="submit" value="Create Account">
	             </div>
			   <div class="clear"></div>
		    </form>
    	</div>
    </div>
    <div class="footer">
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