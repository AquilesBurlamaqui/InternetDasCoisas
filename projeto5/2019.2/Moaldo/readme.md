### Projeto 5 
O MQTT é um protocolo de rede subjacente, desenvolvido com base no protocolo TCP/IP, ele permite que dispositivos trabalhem entre
si e com serviços de backend. Por ser um protocolo leve permite ser implementado em redes com largura de banda limitada.  
O MQTT define dois tipos de entidades: um message broker e os clientes. O broker é um servidor que recebe todas as mensagens dos
clientes e depois as envia para os outros clientes relevantes. O cliente é qualquer coisa que possa interagir com o broker e
receber mensagens, o cliente pode ser um sensor ligado a internet ou um aplicativo que processa dados de IoT.  
O cliente se conecta no broker e assina um tópico de mensagens. O cliente publica as mensagens no tópico. Em seguida o broker envia
essa mensagem aos outros clientes que assinaram esse tópico.  
Neste projeto, utilizei o broker mosquito com a url ```test.mosquitto.org``` e na porta ```1883```.
O nome do tópico é ```buttonECT```. 
O NodeMCU envia para este tópico o estado do switch button utilizado no [Projeto4](https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto4/turma2019.2/Moaldo).  
### Código para a implementação

```c++
#include <ESP8266WiFi.h> 
#include <PubSubClient.h>

int switchbutton = 13; //Pino utilizado pelo botao

//WiFi
const char* SSID = "UFRN";                // SSID / nome da rede WiFi que deseja se conectar
const char* PASSWORD = "suasenha";   // Senha da rede WiFi que deseja se conectar
WiFiClient wifiClient;                        
 
//MQTT Server
const char* BROKER_MQTT = "test.mosquitto.org"; //URL do broker MQTT que se deseja utilizar
int BROKER_PORT = 1883;                      // Porta do Broker MQTT

#define ID_MQTT  "moaldoect"            //Informe um ID unico e seu. Caso sejam usados IDs repetidos a ultima conexão irá sobrepor a anterior. 
#define TOPIC_PUBLISH "buttonECT"    //Informe um Tópico único. Caso sejam usados tópicos em duplicidade, o último irá eliminar o anterior.
PubSubClient MQTT(wifiClient);        // Instancia o Cliente MQTT passando o objeto espClient

//Declaração das Funções
void mantemConexoes();  //Garante que as conexoes com WiFi e MQTT Broker se mantenham ativas
void conectaWiFi();     //Faz conexão com WiFi
void conectaMQTT();     //Faz conexão com Broker MQTT
void enviaPacote();     //

void setup() {
  Serial.begin(9600);

  pinMode(switchbutton, INPUT);

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

  //WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI  
  WiFi.begin(SSID); // Conecta na rede WI-FI  
  
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
            Serial.println("Nao foi possivel se conectar ao broker.");
            Serial.println("Nova tentatica de conexao em 10s");
            delay(10000);
        }
    }
}

void enviaValores() {
  Serial.println("  ### Envia valores");
  String ADCData;
  int adcvalue=digitalRead(switchbutton);  //le o estado do button
  ADCData = String(adcvalue);   //String to interger conversion
  Serial.println("value: "+ADCData);
  const char* dados = ADCData.c_str();
  MQTT.publish(TOPIC_PUBLISH, dados);
  delay(5000);  //GET Data at every 5 seconds
}
```
### Visualizando os dados do tópico MQTT

Utilizando o app para android MyMQTT, foi possivel se conectar no broker mosquitto e se inscrever no tópico buttonECT, assim
exibindo os dados obtidos.  
Conexão ao broker
![conexao](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Moaldo/conexao.png)  
Inscrito no tópico
![topico](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Moaldo/topico.png)
As mensagens do tópico
![mensagens](https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto5/2019.2/Moaldo/mensagensTopico.png)
