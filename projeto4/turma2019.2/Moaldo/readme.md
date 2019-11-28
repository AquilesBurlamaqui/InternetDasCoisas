# Projeto 4 - NodeMCU + Switch Button
### Passo 0 - Preparar o Ambiente Arduino - IDE
Adicionar em preferencias->URL adicionais para gerenciamento de placas : http://arduino.esp8266.com/stable/package_esp8266com_index.json

Link com tutorial para instalar a placa ESP e programas iniciais para a placa
https://www.filipeflop.com/blog/programar-nodemcu-com-ide-arduino/


### Passo 1 - Montar o circuito com o NodeMCU e o Switch Button
![button]()


### Passo 2 - Executar o seguinte código que verifica o estado do Switch Button

```c++
/*
 Este codigo tem a função de ler o estado de um botao conectado ao NodeMCU e exibir o estado no monitor serial.
*/

// O pino D7 do NodeMCU corresponde ao pino 13 no Arduino, nele esta ligado o switch button; nomeamos ele
int switchbutton = 13;

void setup() {
  // Inicializa a comunicacao serial ah 9600 bits por segundo
  Serial.begin(9600);
  // Define o pino do switch button como entrada
  pinMode(switchbutton, INPUT);
}

void loop() {
  // Ler o pino do switch button
  int buttonState = digitalRead(switchbutton);
  // Escreve no monitor serial o estado do switch button
  Serial.println(buttonState);
  // Adiciona um delay para a estabilidade dos dados
  delay(10);
}

```

### Passo 3 - Enviando os dados do sensor para o ThingSpeak
Pegamos o código do passo 2 como base e o encrementamos para que capture os dados do sensor e os envie para o nosso canal do ThingSpeak
criado anteriormente.  
O código base do projeto foi modificado adicionando as configurações da rede Wi-Fi em que o Node-MCU foi conectado, no meu caso a rede
da``` UFRN ```. Também adicionei as Key do meu canal do ThingSpeak``` E3JOPGCNI91TVHIV ```.  

```c++
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
 
/* Configuração das credenciais - rede */
const char *ssid = "UFRN";  //Entre com as configurações da sua wifi
const char *password = "suasenha";

// O pino D7 do NodeMCU corresponde ao pino 13 no Arduino, nele esta ligado o switch button; nomeamos ele
int switchbutton = 13; 

const char *host = "https://api.thingspeak.com";   //site ou ip
 
//=======================================================================
//                    Power on setup
//=======================================================================
 
void setup() {
  delay(1000);
  // Define o pino do switch button como entrada
  pinMode(switchbutton, INPUT);
  
  Serial.begin(9600);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid);     //Connect to your WiFi router
  Serial.println("");
 
  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}
 
//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  HTTPClient http;    //Declare object of class HTTPClient
 
  String ADCData, station, getData, Link;
  int adcvalue=digitalRead(switchbutton);  //Le o valor digital do switch button   Read Analog value of LDR
  ADCData = String(adcvalue);   //String to interger conversion
  station = "B";
 
  //GET Data
  //GET https://api.thingspeak.com/update?api_key=540QGLZMYPB8U2M4&field1=0   https://api.thingspeak.com/update?api_key=E3JOPGCNI91TVHIV&field1=0
  getData = "?api_key=E3JOPGCNI91TVHIV&field1=" + ADCData; 
  Link = "http://api.thingspeak.com/update" + getData;
  
  http.begin(Link);     //Specify request destination
  Serial.println(Link); 
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
 
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
 
  http.end();  //Close connection
  
  delay(5000);  //GET Data at every 5 seconds
}
```
