Projeto 3


Nesse projeto foi criado um banco de dados no site WebHost para que fosse possível fazer uma substituição do gráfico gerado pelo ThingSpeak. Primeiramente, foi criado um banco de dados com o nome "iot" no próprio site, assim gerou um nome para o banco de dados: "id10448913_iot".

Nesse banco de dados, foi criado uma tabela para que fosse recebido e armazenado os valores do sensor.

Em seguida foram criados três arquivos no Gerenciador de Arquivos do WebHost, são eles: api.php, graficos.php e iot.php, todos iniciados a partir dos exemplos disponibilizados nos tutoriais.
O api.php é necessário para que a interface do banco de dados receba os dados gerados pelo acelerômetro desenvolvido no projeto 2. Assim, partindo do exemplo foram alterados as seguintes linhas:

// 

<?php
error_reporting(~E_WARNING & ~E_NOTICE);
 
  $servername = "localhost";
  $username = "id10448913_iot";
  $password = "12345";
  $dbname = "id10448913_iot";

//

Para direcionar os dados à tabela criada foi mudado apenas os parâmetros "$username" e "$dbname" para o nome que foi disponibilizado durante a criação do banco de dados.

Para gerar o gráfico devemos utilizar o arquivo "graficos.php", baseado no exemplo disponibilizado deve-se trocar apenas a url da tabela. Agora com a atualização dos dados da tabela, eles serão mostrados no gráfico.

//

 var jsonData = $.ajax({
        url: 'http://stravitzky.000webhostapp.com/api.php/lux_sensor',
  
//

Semelhante ao "api.php" o "iot.php" será necessário para que seja possível acessar o gráfico, assim devemos atualizar apenas os usuários de entrada e o nome do banco de dados.

//

 <?php
      $servername = "localhost";
      $username = "id10448913_iot";
      $password = "12345";
      $dbname = "id10448913_iot";

//

Ao final do arquivo, introduzi links para que fosse possível analisar a diferença entre os gráficos.

Finalizando o projeto, devemos atualizar o caminho do projeto 2, para que agora seja possível alimentar o banco de dados e o gráfico. As linhas antes, utilizadas pelo "GET" devemos substituir pelo "POST", pois assim será alimentado o gráfico do nosso banco de dados.

//

function sendToAPI() {
  const http = new XMLHttpRequest()
  
  //http.open("GET", "https://api.thingspeak.com/update?api_key=ZJL904XR0FKPBVQR&field1="+dirGlobal)
  http.open("POST", "https://stravitzky.000webhostapp.com/api.php/lux_sensor");
  http.setRequestHeader("Content-type", "application/json");
  var data = JSON.stringify({"valor":""+dirGlobal});
  http.send(data);
  http.onload = setLuxText(http.responseText, dirGlobal)
}

//

Com essa mudança, o acelerômetro conseguirá alimentar o gráfico gerado, tirando a dependência de hospedar o nosso gráfico no ThingSpeak.
