# Projeto 1 - Criação de Página HTML e exibição do gráfico ThingSpeak.

* Conforme o passo a passo disponibilizado, comecei criando uma página html local. (Passo 1);
- Editor utilizado: CodeBlocks;
- Comandos básicos inseridos para a criação da página conforme abaixo;

<!DOCTYPE html>
<html>
  <head>
    <title></title> 
  </head>
  <body>
    <h1></h1>
    <p></p> 
  </body>
</html> 

* Passo 2: Inserir outros comandos;
- Novo comando inserido permite ir para a página do Google:
  <a href="http://www.google.com">Ir para página de busca</a>

* Passo 3: Inserir outras mídias utilizando a tag <iframe>;
- Nessa etapa foi adicionado um vídeo do youtube:
  
  <iframe width="560" height="315" src="https://www.youtube.com/embed/QSIPNhOiMoE" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

* Passo 4: Criar uma conta no ThingSpeak: https://thingspeak.com/ e criar um canal;

-Conta no ThingSpeak: FabianyLopes
-Canal criado: LUX

* Passo 5: Compartilhar canal e Adicionar iframe do serviço na página html criada;

- Criei uma nova página html com os comandos abaixo:

<!DOCTYPE html>
<html>
	<head>
		<title>Projeto 1 - Página com Thingspeak </title>
		<meta charset="utf-8">
  </head>
	<body>
	
	<h1>Thingspeak</h1>

  	<iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/709914/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
	</body>
</html> 

- Para hospedar o site criei uma conta no https://br.000webhost.com/;
- Meu site: https://fabiany.000webhostapp.com;

* Passo 6: Criar uma função que gere informações randômicas para alimentar o canal do thingspeak via api rest fornecida pelo Canal;

- Criar um código javascript que gera números randômicos que simulem os dados capturados de um sensor de luz.

<!DOCTYPE html>
<html>
  <head>
    <title>IoT ECT</title>
    <script>
        //criar váriavel global
        var count=1;
        //definição de função para envio de dados para o thinkspeak
        function sendToAPI(lux) {
          //gera um número randomico entre 1 e 100
          count=Math.floor((Math.random() * 100) + 1);
          //criar um objeto capaz de enviar dados via requisição HTTP GET
          const http = new XMLHttpRequest()
          //prepara um GET passando a váriavel lux como ultimo paramentro do link
          http.open("GET", "https://api.thingspeak.com/update?api_key=OYUIUNJVJ995AK6C&field1="+lux)
          //envia um GET
          http.send()
          //quando a requisição retornar ele chama o console e imprime o valor gerado
          http.onload = console.log(http.responseText+" "+lux)
        }   
        //a função de envio de dados é chamada de 3 em 3 segundos
        setInterval( function() { sendToAPI(count) }, 3000);
        
    </script>
  </head>
         
  <body>

  <h1>Praticando Javascript com Iot</h1>
  <p>De 3 em 3 segundos enviando número randomico para o thinkspeak</p>
  <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/709914/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line"></iframe>
  </body>
</html>





