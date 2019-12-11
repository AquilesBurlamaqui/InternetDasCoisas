/**
   Sensor infravermelho Reflexivo de obstáculo
*/

const int LM393 = D0;

void setup() {
  Serial.begin(9600);
  pinMode(LM393, INPUT);
}

void loop() {
  if (digitalRead(LM393) == LOW)
  {
    Serial.println("Obstáculo está próximo");
  } else {
    Serial.println("Obstáculo fora do alcance");
  }
  delay(500);
}
