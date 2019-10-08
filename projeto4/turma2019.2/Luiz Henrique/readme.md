
Para o desenvolvimento desse projeto utilizei o sensor ultrasônico, que funciona a partir da coleta de sons emitidos a uma certa distância do sensor. O código utilizado para o projeto foi:


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

Utilizando o software "Arduino", com base na biblioteca da placa ESP8266 12E, baixadas no aplicativo, é possível assim interagir com a placa, podendo enviar códigos para que sejam executados em tempo real junto ao computador e os componentes.

A obtenção de dados do sensor é feita em uma nova janela, que consegue medir os sons que estão sendo executados ao redor.
