void setupRoutes(){

  server.on("/", checkAccessPoint);
  
  server.on("/setwifi", setWifi);

  server.on("/led/status", []() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Access: /led/status");

    String resp = "{\"status\" : \"ok\", \"led\" : ";
    resp += digitalRead(led);
    resp += "}";

    /*display.println("Response:");
    display.println(resp);
    display.display();*/

    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "application/json", resp);
  });

  server.on("/led/change", []() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Access: /led/change");

    if (digitalRead(led) == 0) {
      digitalWrite(led, 1);
    }
    else {
      digitalWrite(led, 0);
    }
    String resp = "{\"status\" : \"ok\", \"led\" : ";
    resp += digitalRead(led);
    resp += "}";

    /*display.println("Response:");
    display.println(resp);
    display.display();*/

    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "application/json", resp);
  });

  server.on("/command", []() {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Access: /command");

    String resp = "";
    
    if(server.arg("text").indexOf("motor") > 0) {

      if(server.arg("text").indexOf("frente") > 0) {
        resp += "{\"status\" : \"ok\", \"motor\" : \"front\"}";
        motor.write(0);
        delay(2000);
        motor.write(90);
      } else if(server.arg("text").indexOf("trás") > 0) {
        resp += "{\"status\" : \"ok\", \"motor\" : \"back\"}";
        motor.write(180);
        delay(2000);
        motor.write(90);
      } else {
        resp += "{\"status\" : \"error\", \"message\" : \"Command not recognized\"}";
      }
      
    } else if(server.arg("text").indexOf("luz") > 0) {
      
      if(server.arg("text").indexOf("ligar") > 0) {
        resp += "{\"status\" : \"ok\", \"led\" : \"on\"}";
        digitalWrite(led, 1);
      } else if(server.arg("text").indexOf("apagar") > 0) {
        resp += "{\"status\" : \"ok\", \"led\" : \"off\"}";
        digitalWrite(led, 0);
      } else {
        resp += "{\"status\" : \"error\", \"message\" : \"Command not recognized\"}";
      }
      
    } else if(server.arg("text").indexOf("sorriso") > 0) {
      
      display.clearDisplay();
      display.drawBitmap(0, 0, happyFace, 128, 64, 1);
      display.display();
      resp += "{\"status\" : \"ok\", \"smile\" : \"true\"}";
      delay(2000);
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Connected to:");
      display.println(ssid);
      display.println("");
      display.print("IP: ");
      display.println(WiFi.localIP());
      display.display();
      
    } else {
      resp += "{\"status\" : \"error\", \"message\" : \"Command not recognized\"}";
    }

    /*display.println("Response:");
    display.println(resp);
    display.display();*/

    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "application/json", resp);
  });

  server.onNotFound(handleNotFound);

  server.begin();

}

void checkAccessPoint(){

  if (isAccessPoint){
    Serial.println("IS AP");
    homeWifi();
  } else {
    Serial.println("IS NOT AP");
    homePage();
  }
  
}
