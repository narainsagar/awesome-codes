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
		 <h1><center><font color="white" size=7>USER'S COMPLAINTS.!</font></center></h1><br>

<?php
	//include_once('db.php');
	
   // require 'connection-bld.php';
	
	echo "<table style='border: solid 2px white;'>";
	echo "<tr><th>Token</th><th>UserName</th><th>Subject</th><th>Dept</th><th>Message</th></tr>";

	class TableRows extends RecursiveIteratorIterator { 
		function __construct($it) { 
			parent::__construct($it, self::LEAVES_ONLY); 
		}

		function current() {
			return "<td style='width: 300px; border: 2px solid white;'>" . parent::current(). "</td>";
		}

		function beginChildren() { 
			echo "<tr>"; 
		} 

		function endChildren() { 
			echo "</tr>" . "\n";
		} 
	} 

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "hcidatabase";
	

	try {
		$conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $conn->prepare("SELECT * FROM registercomplaint"); 
		$stmt->execute();

		// set the resulting array to associative
		$result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 

		foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
			echo $v;
		}
		$dsn = null;
		}
	catch(PDOException $e)
		{
		echo "Error: " . $e->getMessage();
		}
	$conn = null;
	echo "</table>";
?>		 
		</DIV> 
	</DIV>		  
 </body>
 </html>
 
   