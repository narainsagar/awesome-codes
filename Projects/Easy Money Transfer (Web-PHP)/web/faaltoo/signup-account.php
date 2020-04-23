<?php
require 'connection-bld.php' ; 
$full_name = $shop_name = $mobile_number = $cnic_number = $passwrd = $email_id = $transac_pin_code = $address = $country = $city_name = $sec_question = $sec_answer = $SFO_id = $SFO_passwrd = "";
$trx_success = $Sfo_Id_Err = $Sfo_Pass_Err = $Sec_Quest_Err = $Sec_Ans_Err = $City_Err = $Country_Err = $Address_Err = $Trx_Pin_Err = $Email_Id_Err = $rePasswd_Err = $Passwd_Err = $Shop_Name_Err = $Full_Name_Err = $Cnic_Err = "";
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
	$valid = true;
	if (empty($_REQUEST['full_name']))
	{
		$Full_Name_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['shop_name']))
	{
		$Shop_Name_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['mobile_number']))
	{
		$Sender_cnic_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['cnic_number']))
	{
		$Cnic_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['passwd']))
	{
		$Passwd_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['re_passwd']))
	{
		$rePasswd_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['email_id']))
	{
		$Email_Id_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['transac_pin_code']))
	{
		$Trx_Pin_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['address']))
	{
		$Address_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['country']))
	{
		$Country_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['city_name']))
	{
		$City_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['sec_question']))
	{
		$Sec_Quest_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['sec_answer']))
	{
		$Sec_Ans_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['SFO_id']))
	{
		$Sfo_Id_Err = "*";
		$valid = false; //false
	}
	if (empty($_REQUEST['SFO_passwd']))
	{
		$Sfo_Pass_Err = "*";
		$valid = false; //false
	}
	if($valid){
		$full_name = $_REQUEST['full_name'];
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
		$new_bal = 1000; // new balance load..
		
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