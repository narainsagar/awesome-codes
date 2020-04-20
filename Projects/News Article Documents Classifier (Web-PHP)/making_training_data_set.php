<html>
<head>
<link rel="stylesheet" href="track.css">
</head>
<body>
<div class="header">
		<h1> Neural Network Based Approach To Document Classification <br> Insert Training Data Set </h1>
</div>
	<div class="file">
		<div class="form">
			<form action="making_training_data_set.php" method="POST" enctype="multipart/form-data">
			    <div>
					<label for="file">Select Catagory:</label>
					<select name="selected_category">
						<option value="None">None</option>
						<option value="Business">Business</option>
						<option value="Sports">Sports</option>
						<option value="Entertainment">Entertainment</option>
						<option value="Cultural">Cultural</option>
						<option value="Technology">Technology</option>
						<option value="Social">Social</option>
						<option value="Health">Health</option>
						<option value="Politics">Politics</option>
						<option value="Arts">Arts</option>
					</select>
				</div>
				<div>
					<label for="file">Filename:</label>
					<input type="file" name="file[]" multiple><br>
				</div>
				<input type="submit" name="submit" value="Submit">
			</form>
		</div>
	</div>
	<div class="box">
		<table border=1 style="width:600px">
			<th>Input File</th>
			<th>Total Words in File</th>
			<th>Words Inserted into Db</th>
			<th>Rows Updated in Db</th>
<?php
if(isset($_POST['submit']))
{
    $valid = true;
	if( $_POST['selected_category'] == "None" ){
		$valid = false;
		echo "Error: Select Category Must. <br>";
	}
	if ($_FILES["file"]["error"][0] > 0)
    {
        echo "Error: " . $_FILES["file"]["error"][0] . "<br>";
		$valid = false;
    }
    if( $valid )
    {
		require 'connection-bld.php';
		$files_count = count($_FILES['file']['name']);
		$src_dir = "files/training_data_set/";
		$training_table_col = $_POST['selected_category'];
		$make_true = 1;
	//	echo "No. files uploaded : ".$files_count."<br>";
		for( $ind = 0; $ind < $files_count ; $ind++ ){
				$nameFile = $_FILES["file"]["name"][$ind];
				$directory = $src_dir.$nameFile;
				$myfile = fopen($directory , "r") or die("Unable to open file!");
				$total_inserted = 0;
				$updated_words = 0;
				$count = 0;
				$filecontent = file_get_contents($directory);
				$filecontent = strtolower($filecontent);
				$words_ = preg_split('/[\s,.;":!()?\'\\[\]]+/', $filecontent, -1, PREG_SPLIT_NO_EMPTY);
				foreach($words_ as $value)
				{
					$query_1 = ("SELECT word FROM words WHERE word='$value'");
					$result_1 = mysql_query($query_1, $link2) or die("Error : " .mysql_error());
					if( ! mysql_fetch_array($result_1) ){   
						$query_2 = ("SELECT data_word FROM training_data_set WHERE data_word='$value'");
						$result_2 = mysql_query($query_2, $link2) or die("Error : " .mysql_error());
						if( ! mysql_fetch_array($result_2)){
							$query_insert_1 = ("insert into training_data_set(data_word) values ('".$value."')");
							$is_inserted = mysql_query($query_insert_1,$link2) or die("Error : " .mysql_error());
							if($is_inserted){
							   // word - inserted...
							   $total_inserted++;
							 //  echo $value."</br>";
							}
						}
						$query_3 = ("update training_data_set set $training_table_col = '$make_true'  WHERE data_word='$value' and $training_table_col=0");
						$result_3 = mysql_query($query_3, $link2) or die("Error : " .mysql_error());
						if($result_3){
						// updated..
						$updated_words++;
						}
					}
					$count++;
				}
				echo "<tr> <td>".$nameFile."</td><td>".$count."</td><td>".$total_inserted."</td><td>".$updated_words."</td></tr>";
				fclose($myfile);				
		}
	}
}
?>
		</table>
	</div>
</body>
</html>