<?php
error_reporting(~E_WARNING & ~E_NOTICE);
 
$servername = "sql107.epizy.com";
$username = "";
$password = "";
$dbname = "epiz_24386991_db_iot";

header('Content-Type: application/json');
 
$link = mysqli_connect($servername, $username, $password, $dbname);
mysqli_set_charset($link,'utf8');
 
$table = "lux_sensor";

$sql = "SELECT * FROM " . 
        "(SELECT * FROM `$table` ORDER BY `$table`.`id` DESC LIMIT 10)" .
        " temporario ORDER BY temporario.id ASC";
 
$result = mysqli_query($link, $sql);
 
if (!$result) {
  http_response_code(500);
  die(mysqli_error());
}
 
header('Content-Type: application/json');

$data = array();

while ( $row = $result->fetch_assoc() ){
    $data[] = $row;
}

echo json_encode( $data );
 
mysqli_close($link);
