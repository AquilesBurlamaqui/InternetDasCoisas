/**
   Sensor detector de vibração SW-18015
*/

const int SW_18015 = D0;

void setup() {
  Serial.begin(9600);
  pinMode(SW_18015, INPUT);
}

void loop() {

  if (digitalRead(SW_18015) == HIGH)
  {
    Serial.println("Vibração detectada.");
  }
  delay(500);
}
