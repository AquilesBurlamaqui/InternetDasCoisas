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

Conta no ThingSpeak: FabianyLopes
Canal criado: LUX

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





