# Sensor Ultrassônico

Sensores ultrassônicos são aplicados como um detectores de objetos e são muito populares principalmente na robótica, onde são utilizados para identificar obstáculos e corrigir continuamente o trajeto feito por um robô.

<p align="center">
  <img src="https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto4/Rafael/IMG_20190613_144305.jpg">
</p>

# Montagem do circuito
<p align="center">
<img src="https://www.14core.com/wp-content/uploads/2015/12/Ultrasonic-HCSR04-NodeMCU-Schematics-Diagram.jpg">
<br><br><br><br>
  Como o sensor ultrasônico funciona apenas em 5v, foi conectado a entrada VIN que poderia fornecer esse valor.
<br><br>
<img src="https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto4/Rafael/IMG_20190613_144323.jpg">
<img src="https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto4/Rafael/IMG_20190613_144335.jpg">
</p>

# Código
```
/*
********************************************
14CORE ULTRASONIC DISTANCE SENSOR CODE TEST
********************************************
*/
#define TRIGGER 5
#define ECHO    4

// NodeMCU Pin D1 > TRIGGER | Pin D2 > ECHO

void setup() {
	
  Serial.begin (9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
	
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  delay(1000);
}

```

# Resultado
<p align="center">
  <img src="https://github.com/AquilesBurlamaqui/InternetDasCoisas/blob/master/projeto4/Rafael/IMG_20190613_145617%20(1).jpg">
</p>
