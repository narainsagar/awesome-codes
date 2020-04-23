<?php
session_start();
// Create connection
$con=mysqli_connect("localhost","root","","hcidatabase");

// Check connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

if($_SERVER["REQUEST_METHOD"] == "POST"){
  $user = $_POST['email'];
  $pass = $_POST['password'];
  
  // Create table
$sql="SELECT * FROM logindb where username='$user' and password='$pass'";

$result = mysql_query($con, $sql);
$valid = false;
while($row = mysql_fetch_array($result)) {
  $valid = true;
}
if($valid){
$_SESSION["username"] = $user;
if($user=="admin" and $pass=="fastadmin")
header('Location: ViewComplaint/');
else
header('Location: RegisterComplaint/');
}
else{
 echo "Invalid Username or Password.";
}

}
?>