#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "Casa Amarela";
const char* password = "veronica1001";

ESP8266WebServer server(80);

const int indicator = 2;
const int led = 5;


void homePage() {
  digitalWrite(indicator, 1);

  String textoHTML;
  textoHTML += "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>ESP Server</title>";
  textoHTML += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  textoHTML += "<link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.10.2/css/all.css'>";
  textoHTML += "<link href='https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css' rel='stylesheet'>";
  textoHTML += "</head><body><div class='container text-center mt-5'><h1><i class='fas fa-home'></i> IOT Light</h1>";
  textoHTML += "<h3 class='mt-4'>Status <button id='refresh' class='btn btn-outline-secondary rounded-0'>";
  textoHTML += "<i class='fas fa-redo'></i></button></h3><div id='light-on'><br><i class='fas fa-spin fa-sun text-warning'></i>";
  textoHTML += "<h1><i class='fas fa-lightbulb text-warning'></i></h1></div><div id='light-off'><br><i class='fas fa-sun'></i>";
  textoHTML += "<h1><i class='fas fa-lightbulb'></i></h1></div><br><button id='change' class='btn btn-dark px-4 rounded-0'>Led</button>";
  textoHTML += "</div><script src='https://code.jquery.com/jquery-3.4.1.min.js'></script><script>";
  textoHTML += "$('#light-on, #light-off').addClass('d-none');$('#change').click(function (e) {";
  textoHTML += "e.preventDefault();$.get('/led/change', function (data) {";
  textoHTML += "data.led == '1' ? $('#light-on').removeClass('d-none') : $('#light-on').addClass('d-none');";
  textoHTML += "data.led == '0' ? $('#light-off').removeClass('d-none') : $('#light-off').addClass('d-none');});});";
  textoHTML += "function ledStatus() {$.get('/led/status', function (data) {";
  textoHTML += "data.led == '1' ? $('#light-on').removeClass('d-none') : $('#light-on').addClass('d-none');";
  textoHTML += "data.led == '0' ? $('#light-off').removeClass('d-none') : $('#light-off').addClass('d-none');});  }";
  textoHTML += "$('#refresh').click(() => ledStatus());ledStatus();</script></body></html>";
  
  server.send(200, "text/html", textoHTML);
  digitalWrite(indicator, 0);
}

/*
void turnLedOn(){
  digitalWrite(led, 1);
}

void turnLedOf(){
  digitalWrite(led, 0);
}
*/

void handleNotFound() {
  digitalWrite(indicator, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(indicator, 0);
}

void setup(void) {
  pinMode(indicator, OUTPUT);
  digitalWrite(indicator, 0);
  
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", homePage);

  server.on("/led/status", []() {
    String resp = "{\"status\" : \"ok\", \"led\" : ";
    resp += digitalRead(led);
    resp += "}";
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "application/json", resp);
  });
  
  server.on("/led/change", []() {
    if (digitalRead(led) == 0) {
      digitalWrite(led, 1);
    }
    else {
      digitalWrite(led, 0);
    }
    String resp = "{\"status\" : \"ok\", \"led\" : ";
    resp += digitalRead(led);
    resp += "}";
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "application/json", resp);
  });

  /*
  server.on("/led/off", []() {
    digitalWrite(led, 0);
    server.send(200, "application/json", "{\"status\" : \"ok\", \"led\" : \"off\"}");
  });
  */

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}