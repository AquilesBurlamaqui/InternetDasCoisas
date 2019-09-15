/**
     Módulo Relé acionado por módulo MQ-2 (detector de gás e fumaça)
*/

const int MODULO_RELE = D0;
const int MQ_2 = A0;
const int valorMaximo = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MODULO_RELE, OUTPUT);
  pinMode(MQ_2, INPUT);
  digitalWrite(MODULO_RELE, LOW);
}

void loop() {

  int valorMaximo = random(200, 500);
  Serial.print("valor máximo: ");
  Serial.println(valorMaximo);

  Serial.print("valor MQ_2: ");
  Serial.println(analogRead(MQ_2));

  Serial.println("");

  if (analogRead(MQ_2) > valorMaximo)  {
    digitalWrite(MODULO_RELE, LOW);
    Serial.println("Alerta de segurança! Acionando sprinklers.");
    Serial.println("");
  }
  else {
    digitalWrite(MODULO_RELE, HIGH);
  }

  delay(3000);
}
