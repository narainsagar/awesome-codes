<html>
<link rel="stylesheet" href="stylo.css">
<head>
</head>
<body>
	<div class="header">
	<h1> Neural Network Based Approach To Document Classification</h1>
	</div>
	<div class="file">
		<form action="doc_classification.php" method="POST" enctype="multipart/form-data">
			<label for="file">Filename:</label>
			<input type="file" name="file[]" multiple><br>
			<input type="submit" name="submit" value="Submit">
		</form>
	</div>
	<div class="box">
		<table border=1 style="width:600px">
			<th>Input File</th>
			<th>Output</th>
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
		$src_dir = "files/";
	//	echo "No. files uploaded : ".$files_count."<br>";
	//	echo "</br>....******* DOC CLASSIFICATION RESULT. *******... </br>";
		for($ind = 0; $ind < $files_count ; $ind++){
				$nameFile = $_FILES["file"]["name"][$ind];
				$directory = $src_dir.$nameFile;
				$myfile = fopen($directory , "r") or die("Unable to open file!");
				$filecontent = file_get_contents($directory);
				$filecontent = strtolower($filecontent);
				$inputs = preg_split('/[\s,.;":!()?\'\\[\]]+/', $filecontent, -1, PREG_SPLIT_NO_EMPTY);
				
				$matched_words_array = array();
				$not_matched_words_array = array();
				$words_counter=array();
				$unique_counter=array();
				$output_string = array("Business","Sports","Arts","Technology","Culture","Social","Entertainment","Politics","Health");
				$words_array_ = array();
				for ( $i=0 ; $i<9 ; $i++ ){
					$words_counter[$i] = 0;
					$unique_counter[$i] = 0;
					$words_array_[$i] = array();
				}
				foreach( $inputs as $input_word ){
					$query_1 = ("SELECT word FROM words WHERE word='$input_word'");
					$result_1 = mysql_query($query_1, $link2) or die("Error : " .mysql_error());
					if( mysql_num_rows($result_1) == 0 ){
						$query_2 = ("SELECT * FROM training_data_set WHERE data_word='$input_word'");
						$result_2 = mysql_query($query_2, $link2) or die("Error : " .mysql_error());
						if( mysql_num_rows($result_2) != 0){
							$matched_words_array[] = $input_word;
							$row = mysql_fetch_array($result_2);
//if($row['business'] && !$row['sports'] && !$row['arts']  && !$row['technology']  && !)							
							if($row['business']){
							$words_counter[0]++;
							$words_array_[0][] = $input_word;
							}
							if($row['sports']){
							$words_counter[1]++;
							$words_array_[1][] = $input_word;
							}
							if($row['arts']){
							$words_counter[2]++;
							$words_array_[2][] = $input_word;
							}
							if($row['technology']){
							$words_counter[3]++;
							$words_array_[3][] = $input_word;
							}
							if($row['culture']){
							$words_counter[4]++;
							$words_array_[4][] = $input_word;
							}
							if($row['social']){
							$words_counter[5]++;
							$words_array_[5][] = $input_word;
							}
							if($row['entertainment']){
							$words_counter[6]++;
							$words_array_[6][] = $input_word;
							}
							if($row['politics']){
							$words_counter[7]++;
							$words_array_[7][] = $input_word;
							}
							if($row['health']){
							$words_counter[8]++;
							$words_array_[8][] = $input_word;
							}
						}
						else{
							// word not found..
							$not_matched_words_array[] = $input_word;
						}
					}  
				}
				foreach($matched_words_array as $in_word){
					for ( $k = 0 ; $k < 9 ; $k++ ){
						$sub_qry = "$output_string[$k]=1";
						for ( $h = 0 ; $h < 9 ; $h++ ){
							if($h != $k){
							$sub_qry = $sub_qry." and ";
							$sub_qry = $sub_qry."$output_string[$h]=0";
							}
						}
						$sub_qry = strtolower($sub_qry);
						$query_4 = ("SELECT * FROM training_data_set WHERE (data_word='$in_word' and $sub_qry)");
						$result_4 = mysql_query($query_4, $link2) or die("Error : " .mysql_error());
						if( mysql_num_rows($result_4) != 0){
							 $unique_counter[$k]++;
						}
					} 
				}
				$max_count = $words_counter[0];
				$max_index = 0;
				for ( $j = 1 ; $j < 9 ; $j++ ){
					if( $words_counter[$j] > $max_count )
					{
						$max_count = $words_counter[$j];
						$max_index = $j;
					}
				}
			//	echo "</br> ******  input file : ".$nameFile." | OUTPUT: ".$output_string[$max_index]."  ****** <br><br>";	
				echo "<tr> <td>".$nameFile."</td><td>".$output_string[$max_index]."</td></tr>";
		}
    }
}
?>
		</table>
	</div>
</body>
</html>