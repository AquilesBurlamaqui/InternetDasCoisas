<?php
error_reporting(E_WARNING | E_NOTICE);
 
$servername = "sql107.epizy.com";
$username = "";
$password = "";
$dbname = "epiz_24386991_db_iot";

$link = mysqli_connect($servername, $username, $password, $dbname);
mysqli_set_charset($link,'utf8');
 
$table = "lux_sensor";

$data = json_decode(file_get_contents('php://input'));

if (!isset($data['value'])){
    $data['value'] = $_GET['value'];
}

echo $data;

if (isset($data['value'])) {

  $lux = $data['value'];
  
  $sql = "INSERT INTO `$table` (`value`) VALUES ('$lux')";
   
  $result = mysqli_query($link, $sql);

  if ($result){

		$data = array("message" => "Lux inserted");

  } else {

		$data = array("message" => "Database error");

  }

} else {

	$data = array("message" => "Variable error");
  http_response_code(400);
	// die();

}
 
header('Content-Type: application/json');

echo json_encode( $data );
 
mysqli_close($link);
