# Projeto 05: Utilizando MQTT para receber dados do sensor de umidade

O primeiro passo consistiu em instalar o aplicativo MyMQTT em um smartphone Android. Posteriormente, foram feitas as configurações para o test.mosquitto.org na porta 1883.

O código de referência precisou ser alterado em relação as informações sobre a rede wi-fi e MQTT server.
~~~
//WiFi
const char* SSID = "UFRN";
const char* PASSWORD = "";   
WiFiClient wifiClient;                        

//MQTT Server
const char* BROKER_MQTT = "test.mosquitto.org";
int BROKER_PORT = 1883;               
#define ID_MQTT  "UmidadeECT"            
#define TOPIC_PUBLISH "SensorECT"   
PubSubClient MQTT(wifiClient);  
~~~

Dados da umidade recebidos no smartphone:
![Dados sendo recebidos no smartphone](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/MarcosTeixeira/tela.jpeg)
