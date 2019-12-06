No projeto 5, fizemos um projeto que tem como objetivo final, a comunicação entre em sensor e um broker, que esse tem como função enviar dados desse sensor para um pessoa, sem a necessidade de qualquer ligação direta, ou seja, as únicas ligações que teremos e entre o Publisher/Subscriber e a comunicação via Wifi. Tudo isso baseado no protocolo MQTT, o nosso Broker será o “Mosquitto”.

MQTT é um protocolo de transporte de mensagens Cliente/Servidor no conceito Publicação/Assinatura, isso quer dizer que pode existir um servidor e enviar pra “N”, assinantes, ou melhor, existir “N” servidores, enviando para um Assinante.   	
- O que faz um Publicador?
        	Um publicador, é um cliente que envia pacotes de dados.
- O que faz um Assinante?
        	Um assinante, é o cliente que recebe o pacote de dados.
- Broker?
        	Broker é o SERVIDOR que recebe os dados do Publicador , Armazena e distribui aos Assinante(s).
          
          Código que utilizado, esse envia dados ao broker a cada 5 segundos, e exibe a cada 1 segundo no monitor serial, o valor da umidade detectado pelo sensor. Que Varia entre mais ou menos 400 ( detectando muita umidade) a 1000 (pouca umidade).
          
          

