# Projeto 3 - Substituição do ThingSpeak por sistema web e banco de dados

### Passo 1 - Criar conta em site que ofereça serviço de hospedagem, PHP e banco de dados Mysql
Sugestão de criar a conta no serviço  https://br.000webhost.com 

### Passo 2 - Criar um banco de dados(mysql) para armazenar os dados do sensor;
#### 2.1 No  https://br.000webhost.com  ir em Database Manager e criar new Database
  - Um banco de dados será criado com informações como:
```
DB Name 	DB User 	DB Host 	 
id8850089_db_iot 	id8850089_db_iot 	localhost
```
#### 2.2 Entre em Manage - para gerenciar o seu banco de dados criado, escolha PhpMyAdmin; 
 - O PhpMyadmin é um sistema web que te ajudar a gerenciar o banco de dados.
#### 2.3 No menu lateral, escolha o seu banco, ex: d8850089_db_iot
#### 2.4 Procure no contéudo centra a função Create table, ela possui um formulário para entrada do nome
 - Esse formulário pede o nome da tabela a ser criada e o número de colunas.
 - Coloque o nome: lux_sensor e colunas 3 e clique em GO/IR
#### 2.5 Primeiro campo: id:INT - index:PRIMARY - AI:MARQUE (Se surgir uma janela popup, aperto em G) para confirmar que id é chave primária)
- Segundo campo: valor:INT
- Terceiro campo: data:timestamp - Default:CURRENT_TIMES
- Aperte SAVE

Sua tabela estará criada. Ela armazenará 3 informações. Um identificador único(como se fosse um CPF para cada dado, de modo que ele possa ser diferenciado dos demais, por isso dizemos que ele é PRIMARY-não se repete, e AI-autoincremento sera organizado como se fosse um contador. O primeiro valor será 1, o segundo 2, e assim por diante) 
 
 #### 2.5 Ainda utilizando o phpmyadmin, e ja com sua tabela criada, tente inserir um dado via interface do phpmyadmin. 
 - Selecione a tabela no menu lateral, e no menu superior, escolha INSERT;
 - Aparecerá vários campos para entrada de dados. Preencha somente um dos campos, o referente a valor. Coloque qualquer valos, por exemplo 50. Não precisa colocar o id (pois ele sera incrementado automaticamente), nem precisar colocar a data (pois ele sera preencido com a hora do sistema)
 #### 2.6 Clique em BROWSE para verificar se o valor que você entrou esta armazenado. Ele deve listar todos os valores armazenados nesta tabela desse banco;

### Passo 3 - Criar um código php para receber os dados e inserir no banco;

```php
<?php
error_reporting(~E_WARNING & ~E_NOTICE);
 
  $servername = "localhost";
  $username = "id8850089_db_iot";
  $password = "q1w2e3r4t5y6";
  $dbname = "id8850089_db_iot";
 
// get the HTTP method, path and body of the request
$method = $_SERVER['REQUEST_METHOD'];
$request = explode('/', trim($_SERVER['PATH_INFO'],'/'));
$input = json_decode(file_get_contents('php://input'),true);
 
// connect to the mysql database
$link = mysqli_connect($servername, $username, $password, $dbname);
mysqli_set_charset($link,'utf8');
 
// retrieve the table and key from the path
$table = preg_replace('/[^a-z0-9_]+/i','',array_shift($request));
$key = array_shift($request)+0;
 
// escape the columns and values from the input object
$columns = preg_replace('/[^a-z0-9_]+/i','',array_keys($input));
$values = array_map(function ($value) use ($link) {
  if ($value===null) return null;
  return mysqli_real_escape_string($link,(string)$value);
},array_values($input));
 
// build the SET part of the SQL command
$set = '';
for ($i=0;$i<count($columns);$i++) {
  $set.=($i>0?',':'').'`'.$columns[$i].'`=';
  $set.=($values[$i]===null?'NULL':'"'.$values[$i].'"');
}
 
// create SQL based on HTTP method
switch ($method) {
  case 'GET':
    $sql = "select * from `$table`".($key?" WHERE id=$key":''); break;
  case 'PUT':
    $sql = "update `$table` set $set where id=$key"; break;
  case 'POST':
    $sql = "insert into `$table` set $set"; break;
  case 'DELETE':
    $sql = "delete `$table` where id=$key"; break;
}
 
// excecute SQL statement
$result = mysqli_query($link,$sql);
 
// die if SQL statement failed
if (!$result) {
  http_response_code(404);
  die(mysqli_error());
}
 
// print results, insert id or affected row count
if ($method == 'GET') {
  if (!$key) echo '[';
  for ($i=0;$i<mysqli_num_rows($result);$i++) {
    echo ($i>0?',':'').json_encode(mysqli_fetch_object($result));
  }
  if (!$key) echo ']';
} elseif ($method == 'POST') {
  echo mysqli_insert_id($link);
} else {
  echo mysqli_affected_rows($link);
}
 
// close mysql connection
mysqli_close($link);
```

### Passo 4 - Criar um código php para recuperar os dados do banco;

### Passo 5 - Criar um código em php para exibir como um gráfico os dados recebidos;


