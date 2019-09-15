/**
   Sensor detector de gás e fumaça
*/

const int MQ_2 = A0;
const int valorMaximo = 500;

void setup() {
  Serial.begin(9600);
  pinMode(MQ_2, INPUT);
}

void loop() {

  Serial.println(analogRead(MQ_2));
  if (analogRead(MQ_2) > valorMaximo)  {
    Serial.println("Alerta! Valor de leitura crítico");
  }
  delay(500);
}
