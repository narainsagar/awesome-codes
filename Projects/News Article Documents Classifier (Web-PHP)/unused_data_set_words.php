<html>
<head>
<link rel="stylesheet" href="track.css">
</head>
<body>
	<div class="header">
		<h1> Neural Network Based Approach To Document Classification <br> Insert Unused Dataset words</h1>
	</div>
	<div class="file">
		<div class="form">
			<form action="unused_data_set_words.php" method="POST" enctype="multipart/form-data">
				<label for="file">Filename:</label>
				<input type="file" name="file[]" multiple><br>
				<input type="submit" name="submit" value="Submit">
			</form>
		</div>
	</div>
	<div class="box">
		<table border=1 style="width:600px">
			<th>Input File</th>
			<th>Total Words in File</th>
			<th>Words Inserted into Db</th>
			<th>Words Matched with Db</th>
<?php
if(isset($_POST['submit']))
{
    if ($_FILES["file"]["error"][0] > 0)
    {
        echo "Error: " . $_FILES["file"]["error"][0] . "<br>";
    }
    else
    {
		require 'connection-bld.php';
		$files_count = count($_FILES['file']['name']);
		$src_dir = "files/unused_data_set/";
		//echo "No. files uploaded : ".$files_count."<br>";
		for( $ind = 0; $ind < $files_count ; $ind++ ){
				$nameFile = $_FILES["file"]["name"][$ind];
				$directory = $src_dir.$nameFile;
				$myfile = fopen($directory , "r") or die("Unable to open file!");
				$count=0;
				$total_inserted = 0;
				$matched_words = 0;
				$filecontent = file_get_contents($directory);
				$filecontent = strtolower($filecontent);
				$words_ = preg_split('/[\s,.;":!()?\'\\[\]]+/', $filecontent, -1, PREG_SPLIT_NO_EMPTY);
				foreach($words_ as $value)
				{
					$query_1 = ("SELECT word FROM words WHERE word='$value'");
					$result_1 = mysql_query($query_1, $link2) or die("Error : " .mysql_error());
					if( ! mysql_fetch_array($result_1) ){   // word not found..
						$query_insert_1 = ("insert into words(word) values ('".$value."')");
						$is_inserted = mysql_query($query_insert_1,$link2) or die("Error : " .mysql_error());
						if($is_inserted){
						   // word - inserted...
						   $total_inserted++;
						//   echo $temp_word."</br>";
						}
					}
					else{
						$matched_words++;
					}
					$count++;
				}
			//	echo "matched words in db_table=".$matched_words."</br>";
			//	echo "total words inserted=".$total_inserted."</br>";
			    echo "<tr> <td>".$nameFile."</td><td>".$count."</td><td>".$total_inserted."</td><td>".$matched_words."</td></tr>";
				fclose($myfile);		
		}	
	}
}
?>
			
		</table>
	</div>
</body>
</html>