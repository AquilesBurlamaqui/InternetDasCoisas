/**
     Modulo Relé
*/

const int MODULO_RELE = D0;

void setup() {
  Serial.begin(9600);
  pinMode(MODULO_RELE, OUTPUT);
}

void loop() {

  digitalWrite(MODULO_RELE, HIGH);
  delay(1000);
  digitalWrite(MODULO_RELE, LOW);
  delay(1000);
}
