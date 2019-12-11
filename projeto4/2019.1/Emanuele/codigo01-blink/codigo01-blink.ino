#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

/* Configuração das credenciais - rede */
const char *ssid = "Maria";  //Entre com as configurações da sua wifi
const char *password = "manu1998";

const char *host = "https://api.thingspeak.com/update?api_key=UQPIQ5B2X3W17TV1&field1=0";

void setup() {
  delay(1000);
  Serial.begin(9600);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
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
void loop() {
  HTTPClient http;    //Declare object of class HTTPClient
 
  String ADCData, station, getData, Link;
  int adcvalue=analogRead(0);  //Read Analog value of LDR
  ADCData = String(adcvalue);   //String to interger conversion
  station = "B";
 
  //GET Data
  //GET https://api.thingspeak.com/update?api_key=UQPIQ5B2X3W17TV1&field1=0
  getData = "?api_key=UQPIQ5B2X3W17TV1&field1=" + ADCData; 
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
