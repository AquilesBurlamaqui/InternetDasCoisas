# Documentação para utilização do blink interno e de um buzzer de 3 pinos

Alimentação em 3v

```
void setup() {
pinMode(2, OUTPUT); // Define o pino 2 como saida //a porta tx (interna 2) é ao contrário (High apaga o Led, Low Acende o Led)
pinMode(16, OUTPUT); // Define o pino D0 como saida - conectar o sig na D0
}

void loop() {
digitalWrite(2, LOW); // Acende o Led
tone(16,1500);
delay(3000); // Aguarda 3 segundos

digitalWrite(2, HIGH); // Apaga o Led
noTone(16);
delay(1000); // Aguarda 3 segundo
}
```
