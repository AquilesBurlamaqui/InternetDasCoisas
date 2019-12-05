### Projeto 6 - Introdução ao Node-RED 
Neste projeto, somos introduzidos ao Node-RED, uma plataforma de desenvolvimento open source baseada em fluxos para a programação visual e foi desenvolvida pela IBM.  
Esta plataforma é utilizada em IoT para a junção de hardware, API’s e serviços online. É bastante utilizada em automação pela sua facilidade de programação pois utiliza uma forma visual de organização, além de poder ser editado em qualquer sistema operacional.  
O Node-RED disponibiliza um editor web que facilita a criação de funções, utilizando JavaScript como linguagem principal. Também disponibiliza conexões com MQTT e bancos de dados de maneira simples.  
A programação com Node-RED é bastante facilitada, sendo necessário apenas a conexão dos nós (node) que você adiciona e a edição de suas propriedades. Existem diversos tipos de nós e no editor você tem uma breve introdução ao que cada um faz e também podem ser criados outros nós.  

Esse projeto tem como função receber os dados de saída MQTT do [Projeto5](https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto5/2019.2/Moaldo) no tópico ```buttonECT```, fazer o tratamento desses dados e por fim enviar o resultado para outro tópico ```Estado``` e o exibe na janela de depuração do navegador.
No meu projeto foram utilizados 4 nós: 1 de entrada, 1 de processamento e 2 de saída, o broker mqtt utilizado foi o ```test.mosquitto.com```. 

![project_view](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto6/turma%202019.2/Moaldo/nodered.PNG)

O nó de entrada switch é do tipo mqtt in e recebe as informações do tópico buttonECT.  
![mqtt_in](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto6/turma%202019.2/Moaldo/mqtt_in.PNG)

O nó de processamento  é chamado de Core e é do tipo function, recebe os dados da entrada e se for igual a 1 ele indica que o botão está Ligado, se for 0 está desligado e se for um valor diferente desses indica que teve um erro de leitura.  
![Core](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto6/turma%202019.2/Moaldo/core.PNG)  

O primeiro nó de saída e do tipo mqtt out e exibe a mensagem do processamento em um tópico chamado Estado.  
![mqtt_out](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto6/turma%202019.2/Moaldo/mqtt_out.PNG)  

O último nó tem o propósito de exibir o resultado do processamento na tela de depuração do Node-RED.  
Como resultado temos as seguintes informações dos tópicos MQTT que foram obtidos utilizando o app disponível para Android MyMQTT. Com a linha verde está o tópico Estado e em roxo o tópico buttonECT.  
![results](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto6/turma%202019.2/Moaldo/Resultado.png)
