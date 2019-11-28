# MQTT + Broker
#### O MQTT é um protocolo que está sendo muito utilizado para comunicação de sistemas de IoT.
#### O Broker é o responsável pelo recebimento dos dados transferidos através do protocolo MQTT e sua publicação.
#### Para fazer o envio dos dados gerados por um sensor é necessário passar ao microcontrolador, ESP8266 neste caso, o código (é necessário que a biblioteca [pubsubclient](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/pubsubclient.zip) esteja instalada):
```
#include <WiFi.h> 
#include <PubSubClient.h>

//sensor vibracao
const int pinoSensor = 23; //PINO DIGITAL UTILIZADO PELO SENSOR

//WiFi
const char* SSID = "athos";                // SSID / nome da rede WiFi que deseja se conectar
const char* PASSWORD = "1d3q5s7o9dodt";   // Senha da rede WiFi que deseja se conectar
WiFiClient wifiClient;                        
 
//MQTT Server
const char* BROKER_MQTT = "mqtt.eclipse.org"; //URL do broker MQTT que se deseja utilizar
int BROKER_PORT = 1883;                      // Porta do Broker MQTT

#define ID_MQTT  "AKLSIOT"            //Informe um ID unico e seu. Caso sejam usados IDs repetidos a ultima conexão irá sobrepor a anterior. 
#define TOPIC_PUBLISH "AKLSVibracao"    //Informe um Tópico único. Caso sejam usados tópicos em duplicidade, o último irá eliminar o anterior.
PubSubClient MQTT(wifiClient);        // Instancia o Cliente MQTT passando o objeto espClient

//Declaração das Funções
void mantemConexoes();  //Garante que as conexoes com WiFi e MQTT Broker se mantenham ativas
void conectaWiFi();     //Faz conexão com WiFi
void conectaMQTT();     //Faz conexão com Broker MQTT
void enviaPacote();     //

void setup() {
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);

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
  if(digitalRead(pinoSensor) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("  ### Envia valores");
        String ADCData;
        int adcvalue=digitalRead(pinoSensor);  //Read Analog value of LDR
        ADCData = String(adcvalue);   //String to interger conversion
        Serial.println("value: "+ADCData);
        const char* dados = ADCData.c_str();
        MQTT.publish(TOPIC_PUBLISH, dados);
        delay(1000); 
  }else {                       // wait for a second
     digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW 
  }// wait for a second
}
```
#### OBS: Deve-se alterar o código para que diferentes sensores sejam utilizados. 
#### Utilizando o aplicativo MyMQTT para receber os dados do sensor, aparecerá a seguinte tela inicial:
![Tela inicial](https://i.imgur.com/pb9J4M3m.jpg)
#### Ao clicar no logo aparece as opções:
![Opções](https://i.imgur.com/cFVt0nZm.jpg)
#### Na parte superior da imagem identificamos a URL do Broker MQTT e a porta do Broker abaixo dela.
#### Para adicionar o sensor é preciso clicar em *Subscribe* e adicionar com um tópico único, para garantir que receberá os dados do seu projeto (PIRSensorECT, no caso deste projeto):
![Subscribe](https://i.imgur.com/yk54NwIm.jpg)
#### Para ver o funcionamento é necessário que todos os componentes envolvidos estejam conectados à internet.
![Dados](https://i.imgur.com/yjpJP4xm.jpg)
#### Os valores recebidos foram gerados pelo sensor de presença, que retorna 0 ou 1.
