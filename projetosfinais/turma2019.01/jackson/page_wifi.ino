      void homeWifi() {

  String textoHTML;
  textoHTML += "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>ESP Server</title>";
  textoHTML += "<meta name='viewport' content='width=device-width,initial-scale=1'></head>";
  textoHTML += "<style>*{padding:0;margin:0;box-sizing:border-box}body{display:flex;";
  textoHTML += "align-items:center;padding-top:40px;padding-bottom:40px;";
  textoHTML += "background-color:#f5f5f5}body form{width:100%;max-width:330px;padding:15px;";
  textoHTML += "margin:0 auto}input{margin:10px 0;height:25px;width:300px;padding:0 6px}";
  textoHTML += "button{padding:0;margin:10px 0;height:25px;width:300px}fieldset{padding:10px}";
  textoHTML += "p{margin:6px}</style><body><form action='/setwifi'><!--<fieldset><legend>Redes Disponíveis</legend>";
  textoHTML += "<p>UFRN</p><p>Escola de Saude</p></fieldset>--><input type='text' name='wifi' placeholder='Wifi'> ";
  textoHTML += "<input type='password' name='pass' placeholder='Senha'><br><button>Conectar</button>";
  textoHTML += "</form></body></html>";

  server.send(200, "text/html", textoHTML);
}

void setWifi() {

  String textoHTML;
  textoHTML += "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>ESP Server</title>";
  textoHTML += "<meta name='viewport' content='width=device-width,initial-scale=1'></head><style>";
  textoHTML += "*{padding:0;margin:0;box-sizing:border-box;color:#26583b}body{display:flex;align-items:center;";
  textoHTML += "padding-top:40px;padding-bottom:40px;background-color:#f5f5f5;background:#68dd8f}div{width:100%;height:80px;";
  textoHTML += "max-width:330px;padding:15px;margin:0 auto}fieldset{padding:20px;border:2px solid #fff}";
  textoHTML += "h3{margin:0 10px}</style><body><div><fieldset><legend><h3>Sucesso</h3></legend><p><b>Wifi: </b>";
  textoHTML += server.arg("wifi");
  textoHTML += "</p><br><p><b>Senha: </b>";
  textoHTML += server.arg("pass");
  textoHTML += "</p><br><small>Cheque o display para saber o IP da placa.</small></fieldset></div></body></html>";

  server.send(200, "text/html", textoHTML);

  delay(1000);

  // --------------------------------------

  WiFi.mode(WIFI_STA);

  // MUDAR DE VOLTA -----------------------------------------------------------------------------------
  WiFi.begin(server.arg("wifi"), server.arg("pass"));

  Serial.println("");
  display.println("Connecting");
  display.display();
  

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    display.print(".");
    display.display();
  }

  isAccessPoint = false;
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(server.arg("wifi"));
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

  
  //Excluir depois
  //ESP8266WebServer server(80);
  //setupRoutes();

} 
