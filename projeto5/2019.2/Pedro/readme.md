
Neste experimento utilizamos o MQTT, que é umprotocolo de rede que permite a comunicação de 2 ou mais dispositivos por meio da internet
e para isso é necessário um Broker que é responsável por receber e encaminhar as mensagens para todos os dispositivos que estão inscritos 
para receber tais informações.

No meu experimento utilizei o Broker Mosquitto (test.mosquitto.org), uma placa ESP, um switchButton para variar valores(0 e 1)

```
#include <ESP8266WiFi.h> 
#include <PubSubClient.h>

//WiFi
const char* SSID = "Pedro Cavalcanti M.";                // SSID / nome da rede WiFi que deseja se conectar
const char* PASSWORD = "123456790";   // Senha da rede WiFi que deseja se conectar
WiFiClient wifiClient;                        
 
//MQTT Server
const char* BROKER_MQTT = "test.mosquitto.org"; //URL do broker MQTT que se deseja utilizar
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

**Por meio do app MQTTool(IOS) foi possivel se inscrever no Topico(SensorECT) 
![Alt Text](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Pedro/Subscride.PNG)
Tambem foi possivel receber os dados enviados pela variação do switchButton(0 e 1)
![Alt Text](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Pedro/RecebeValoresSB.PNG)
E tambem foi possivel enviar mensagens para o broker.
![Alt Text](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Pedro/EnviarMensagem.PNG)
Recebendo as mensagens pelo broker
![Alt Text](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Pedro/RecebeValoresSubscribe.PNG)
