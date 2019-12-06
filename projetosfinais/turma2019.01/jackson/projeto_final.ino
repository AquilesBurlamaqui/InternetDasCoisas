#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Servo.h>
#include <PubSubClient.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#ifndef APSSID
#define APSSID "First Connection"
#define APPSK  "thereisnopass"
#endif

//MQTT Server
const char* BROKER_MQTT = "mqtt.eclipse.org";
int BROKER_PORT = 1883;
#define ID_MQTT  "STGEFJG4583N634N563J456"
#define TOPIC_SUBSCRIBE "BCITexto1"
WiFiClient wifiClient; 
PubSubClient MQTT(wifiClient);
void mantemConexoes();
void conectaMQTT();
void recebePacote(char* topic, byte* payload, unsigned int length);

void mantemConexoes() {
    if (!MQTT.connected()) {
       conectaMQTT(); 
    }
}
void conectaMQTT() { 
    while (!MQTT.connected()) {
        Serial.print("Conectando ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT)) {
            Serial.println("Conectado ao Broker com sucesso!");
            MQTT.subscribe(TOPIC_SUBSCRIBE);
        } 
        else {
            Serial.println("Nao foi possivel se conectar ao broker.");
            Serial.println("Nova tentatica de conexao em 3s");
            delay(3000);
        }
    }
}
void recebePacote(char* topic, byte* payload, unsigned int length) {
    String msg;
    //obtem a string do payload recebido
    for(int i = 0; i < length; i++) {
       char c = (char)payload[i];
       msg += c;
    }
    comando(msg);
    Serial.print("Mensagem: ");
    Serial.println(msg);
}




Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char *ssid = APSSID;
const char *password = APPSK;
bool isAccessPoint = true;

Servo motor;

ESP8266WebServer server(80);

const int pinoServo = 14; //D5
const int indicator = 2; //D4
const int led = 16; //D0

void setup(void) {
  
  Serial.begin(115200);

  motor.attach(pinoServo);
  motor.write(90);

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Comparando se uma string está dentro da outra
  /*const String s1 = "Ola garotos de ipanema";
  const String s2 = "garox";
  if(s1.indexOf(s2) > 0) {
    Serial.print("EXISTE ");
  }*/

  allocation();

  clearDisplay();

  pinMode(indicator, OUTPUT);
  digitalWrite(indicator, 0);

  pinMode(led, OUTPUT);
  digitalWrite(led, 0);

  // WiFi.mode(WIFI_STA);
  // WiFi.begin(ssid, password);

  Serial.println("");
  display.println("");

  
  // Wait for connection
  /*
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    display.print(".");
    display.display();
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Connected to:");
  display.println(ssid);
  display.println("");
  display.print("IP: ");
  display.println(WiFi.localIP());
  display.display();
  */

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  setupRoutes();
  
  // APAGAR -----------------------------------------------------------------------------------
  //setWifi();

  
  Serial.println("HTTP server started");
  display.println("");
  display.println("HTTP server started");
  display.display();

  MQTT.setServer(BROKER_MQTT, BROKER_PORT);  
  MQTT.setCallback(recebePacote); 
}

void loop(void) {
  server.handleClient();
  MDNS.update();
  if (!MQTT.connected()) {
     conectaMQTT(); 
  }
  MQTT.loop();
}
