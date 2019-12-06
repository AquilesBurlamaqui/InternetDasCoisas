# Projeto 03: Gráfico utilizando sistema web e banco de dados

Inicialmente, foi criado um banco de dados no 000webhost, chamado “iot2019” foi feito o gerenciamento do banco de dado pelo PhpMyAdmin. Em seguida, foi criada uma tabela “lux_sensor” com três colunas contendo id, valor e data onde serão armazenados os dados do eixo x do acelerômetro do smartphone. 

Dados do banco de dados:
~~~ 
DB Name: id11678197_iot2019
DB User: id11678197_iot2019
DB Host: localhost 	
~~~

Baseando-se no tutorial disponibilizado no Github da disciplina foram criados os arquivos graficos.php, api.php e iot.php.

O 

O arquivo graficos.php é responsável pela exibição do gráfico, a partir da biblioteca Chart.js emprega em criação de design em aplicações web. 

Tendo como base o código da disciplina, substituiu-se a url para http://projetosiot.000webhostapp.com/api.php/lux_sensor. Direcionado para a tabela criada no primeiro passo.

~~~javascript
var jsonData = $.ajax({
        url: 'http://projetosiot.000webhostapp.com/api.php/lux_sensor',
        dataType: 'json',
      }).done(function (results) {
        console.log(results);
~~~

Código usado no projeto 2: foi feita a alteração para usar o POST e enviar os dados para a tabela do banco de dados. Devido algumas limitações de rede o envio de dados pode demorar um pouco.

~~~javascript
x = 0;
y = 0;
z = 0;
time = 0;

function OnStart()
{
    
    lay = app.CreateLayout( "Linear", "VCenter,FillXY" );    

    txt = app.CreateText( "Valor de X do acelerometro:" );
    lay.AddChild( txt );
    app.AddLayout( lay );

    sns = app.CreateSensor( "Accelerometer" );
    sns.SetOnChange( sns_OnChange );
    sns.Start();
    setInterval(sendToAPI, 10000);
}

function sns_OnChange( x, y, z, time )
{
    txt.SetText( "x=" + x + "\n y=" + y + "\n z=" + z );
}

function sendToAPI() {
  const http = new XMLHttpRequest()
  http.open("POST", "http://projetosiot.000webhostapp.com/api.php/lux_sensor")
  http.send()
  http.onload = setAceText(http.responseText, x)
}

function setAceText(resp,x) {
    txt.SetText( "x=" + x );
~~~
