- Fiz uma [página](https://paulohenriqueaf.000webhostapp.com/pagina2.html) no 000webhost para mostrar o gráfico do canal **Luminosidade_Android** do Thingspeak.

``` html
	<html>

		<head>
			<title>Página 2</title>
			
		</head>

		<body>
			<p>Essa é a página referente ao projeto 2, onde foi criada uma aplicação que usa o sensor de luz de um smartphone android que, enquanto estiver com o aplicativo aberto, atualizará os dados a cada 10 segundos</p>
			
            <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/851154/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
			<a href= "index.html">clique e vá para a página inicial</a>
		</body>

	</html>
```
- Tal gráfico é alimentado por um script que roda no DroidScript, aplicativo de celular. Vemos o script abaixo, explicado passo a passo. 

``` js
luxGlobal = 0; ///variável declarada globalmente que mensura a quantidade de lux captada

function OnStart()
{
    /// cria uma tela usando funções do droidscript
    lay = app.CreateLayout( "linear", "VCenter,FillXY" );    

    /// cria um texto e adiciona ao layout
    txt = app.CreateText( "Medindo lux" );
    txt.SetTextSize( 32 );
    lay.AddChild( txt );
    
    /// adicionar o layout criado ao aplicativo
    app.AddLayout( lay );
    
    sns = app.CreateSensor( "Light" ); /// criando o sensor de luz
    sns.SetOnChange( sns_OnChange ); /// avisando ao aplicativo que quando ele mudar ele vai chamar a função sns_OnChange
    sns.Start(); /// ligando o sensor
    setInterval(sendToAPI, 10000); /// setando um tempo para que o aplicativo chame a função sendToAPI
}

function sns_OnChange( lux ) /// função para reatribuir o valor de luxGlobal
{
  luxGlobal = lux;
}

function sendToAPI() { ///  manda o valor do sensor para o thingspeak e atualiza a variavel de luz com a resposta do thingspeak
  const http = new XMLHttpRequest()
  http.open("GET", "https://api.thingspeak.com/update?api_key=0QV5JSAW9IYH2U0H&field1="+luxGlobal) /// faz uma request para atualizar o gráfico do thingpeak com a variável de luz
  http.send() /// manda a request
  http.onload = setLuxText(http.responseText, luxGlobal) /// retorna o valor e usa a função que atualiza o texto na tela
}

function setLuxText(resp,lux) { /// atualiza o texto na tela
    txt.SetText( resp +" level = " + lux + " lux" );
}
```
