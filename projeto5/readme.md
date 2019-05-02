# Projeto 5

## MQTT

O MQTT é um protocolo rede, desenvolvido com base na pilha TCP/IP. Devido as suas caracteristicas, o MQTT (Message Queue Telemetry Transport) vem sendo utilizado para a comunicações de IoT.

Através desse protocolo, 2 ou mais dispositivos podem se comunicar através da internet. 
A arquitetura do MQTT prevê a existemcia de um Broker. O Broker é sistema servidor responsável por receber as mensagens de um dispositivo que deseja PUBLICAR seus dados, e repassá-las para os dispositivos que deseja se INSCREVER para receber esses dados. Dizemos que o MQTT funciona seguindo o padrão 
Publisher/Subscriber. 

No presente projeto, vamos utilizar um Broker, que disponibiliza tal serviço de forma gratuita. Dessa forma não precisaremos instalar e executar um broker exclusivo. 

## Passo 1 - Instalar a biblioteca no IDE Arduino pubsubclient

[pubsubclient](pubsubclient.zip)

## Passo 2 - Adicionar o código base na IDE Arduino

``` C++
#include <ESP8266WiFi.h> 
#include <PubSubClient.h>

//WiFi
const char* SSID = "aquiles";                // SSID / nome da rede WiFi que deseja se conectar
const char* PASSWORD = "suasenha";   // Senha da rede WiFi que deseja se conectar
WiFiClient wifiClient;                        
 
//MQTT Server
const char* BROKER_MQTT = "iot.eclipse.org"; //URL do broker MQTT que se deseja utilizar
int BROKER_PORT = 1883;                      // Porta do Broker MQTT

#define ID_MQTT  "LDRect"            //Informe um ID unico e seu. Caso sejam usados IDs repetidos a ultima conexão irá sobrepor a anterior. 
#define TOPIC_PUBLISH "SensorECT"    //Informe um Tópico único. Caso sejam usados tópicos em duplicidade, o último irá eliminar o anterior.
PubSubClient MQTT(wifiClient);        // Instancia o Cliente MQTT passando o objeto espClient

//Declaração das Funções
void mantemConexoes();  //Garante que as conexoes com WiFi e MQTT Broker se mantenham ativas
void conectaWiFi();     //Faz conexão com WiFi
void conectaMQTT();     //Faz conexão com Broker MQTT
void enviaPacote();     //

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
  Serial.println("  Aguarde!");

  WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI  
  //WiFi.begin(SSID); // Conecta na rede WI-FI  
  
  while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Conectado com sucesso, na rede: ");
  Serial.print(SSID);  
  Serial.print("  IP obtido: ");
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
  Serial.println("  ### Envia valores");
  String ADCData;
  int adcvalue=analogRead(0);  //Read Analog value of LDR
  ADCData = String(adcvalue);   //String to interger conversion
  Serial.println("value: "+ADCData);
  const char* dados = ADCData.c_str();
  MQTT.publish(TOPIC_PUBLISH, dados);
  delay(5000);  //GET Data at every 5 seconds
}


```


Assisitir a playlist
[Introdução ao ESP e MQTT](https://www.youtube.com/playlist?list=PL7CjOZ3q8fMe6DxojEFuDx4BP0qbbpKtP)
