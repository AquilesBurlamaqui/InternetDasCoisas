No projeto 5, fizemos um projeto que tem como objetivo final, a comunicação entre em sensor e um broker, que esse tem como função enviar dados desse sensor para um pessoa, sem a necessidade de qualquer ligação direta, ou seja, as únicas ligações que teremos e entre o Publisher/Subscriber e a comunicação via Wifi. Tudo isso baseado no protocolo MQTT, o nosso Broker será o “Mosquitto”.

MQTT é um protocolo de transporte de mensagens Cliente/Servidor no conceito Publicação/Assinatura, isso quer dizer que pode existir um servidor e enviar pra “N”, assinantes, ou melhor, existir “N” servidores, enviando para um Assinante.   	
- O que faz um Publicador?
        	Um publicador, é um cliente que envia pacotes de dados.
- O que faz um Assinante?
        	Um assinante, é o cliente que recebe o pacote de dados.
- Broker?
        	Broker é o SERVIDOR que recebe os dados do Publicador , Armazena e distribui aos Assinante(s).
          
          Código que utilizado, esse envia dados ao broker a cada 5 segundos, e exibe a cada 1 segundo no monitor serial, o valor da umidade detectado pelo sensor. Que Varia entre mais ou menos 400 ( detectando muita umidade) a 1000 (pouca umidade).
    
    
        -Valores sendo enviados pro broker e valores sendo mostrados no Monitor Serial
![Alt Text](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Matheus%20Cavalcante/foto%20(1).png).
 
        -Codigo Ultilizado no Projeto.
```javascript

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
 
//WiFi
const char* SSID = "Brasil"; // SSID / nome da rede WiFi que deseja se conectar
const char* PASSWORD = "13032018"; // Senha da rede WiFi que deseja se conectar
WiFiClient wifiClient;
 
//MQTT Server
const char* BROKER_MQTT = "test.mosquitto.org"; //URL do broker MQTT que se deseja
utilizar
int BROKER_PORT = 1883; // Porta do Broker MQTT
 
#define ID_MQTT "SUTsensor" //Informe um ID unico e seu. Caso sejam usados IDs
repetidos a ultima conexão irá sobrepor a anterior.
#define TOPIC_PUBLISH "SensorECT" //Informe um Tópico único. Caso sejam usados tópicos
em duplicidade, o último irá eliminar o anterior.
PubSubClient MQTT(wifiClient); // Instancia o Cliente MQTT passando o objeto espClient
 
//Declaração das Funções
void mantemConexoes(); //Garante que as conexoes com WiFi e MQTT Broker se mantenham
ativas
void conectaWiFi(); //Faz conexão com WiFi
void conectaMQTT(); //Faz conexão com Broker MQTT
void enviaPacote(); //
 
void setup() {
Serial.begin(9600);
conectaWiFi();
 
MQTT.setServer(BROKER_MQTT, BROKER_PORT);
}
 
void loop() {
mantemConexoes();
enviaValores();
MQTT.loop();
}
 
void mantemConexoes() {
if (!MQTT.connected()) {
conectaMQTT();
}
 
conectaWiFi(); //se não há conexão com o WiFI, a conexão é refeita
}
 
void conectaWiFi() {
 
if (WiFi.status() == WL_CONNECTED) {
return;
}
 
Serial.print("Conectando-se na rede: ");
Serial.print(SSID);
Serial.println(" Aguarde!");
 
WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI
//WiFi.begin(SSID); // Conecta na rede WI-FI
 
while (WiFi.status() != WL_CONNECTED) {
 
delay(100);
Serial.print(".");
}
 
Serial.println();
Serial.print("Conectado com sucesso, na rede: ");
Serial.print(SSID);
Serial.print(" IP obtido: ");
Serial.println(WiFi.localIP());
}
 
void conectaMQTT() {
while (!MQTT.connected()) {
Serial.print("Conectando ao Broker MQTT: ");
Serial.println(BROKER_MQTT);
if (MQTT.connect(ID_MQTT)) {
Serial.println("Conectado ao Broker com sucesso!");
}
else {
Serial.println("Noo foi possivel se conectar ao broker.");
Serial.println("Nova tentatica de conexao em 10s");
delay(10000);
}
}
}
 
void enviaValores() {
int sensorPin = A0;
int sensorValor = 0;
Serial.print("sensor = ");
sensorValor = analogRead(sensorPin);
 
delay(1000);
Serial.println(sensorValor);
Serial.println(" ### Envia valores");
String ADCData;
int adcvalue=analogRead(sensorPin); //Read Analog value of LDR
ADCData = String(adcvalue); //String to interger conversion
const char* dados = ADCData.c_str();
MQTT.publish(TOPIC_PUBLISH, dados);
delay(5000); //GET Data at every 5 seconds
}
```
        -Valores que o Broker está recebedo, Logo após o Assinante, se escrever no topico "SensorECT".

![Alt Text](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Matheus%20Cavalcante/Screenshot_20191205-203336.png).
