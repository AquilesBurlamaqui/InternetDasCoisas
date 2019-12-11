# Projeto 4: Geração de gráfico referente a umidade pelo ThingSpeak

O projeto consistiu na captura de dados de umidade gerados pelo Sensor de Umidade do Solo Higrômetro para um canal do ThingSpeak.
Começamos criando o canal no site e anexando o gráfico em um [site](https://projetosiot.000webhostapp.com/) no tópico Projeto 04.

Utilizou-se a IDE do Arduino, a biblioteca da placa ESP8266, bem como o código de referência. Posteriormente foram feitas alterações na questão de conexão a rede e chave do canal.

Trecho do código alterado:
~~~ 
#define SSID_REDE     "UFRN" 
#define SENHA_REDE    ""  
#define INTERVALO_ENVIO_THINGSPEAK  30000 

char EnderecoAPIThingSpeak[] = "api.thingspeak.com";
String ChaveEscritaThingSpeak = "H8GEGVAZD3HSU3R9";
long lastConnectionTime; 
WiFiClient client;
~~~

