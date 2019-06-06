# Documentação para utilização do blink interno e de um buzzer de 3 pinos

O Buzzer funciona basicamente da mesma forma que o blink interno.

A função tone(Pino,Frequencia) define o pino digital e a frequência na qual o buzzer emitirá o som.

Para silenciar o buzzer, utilizar a função noTone(Pino).

O codigo abaixo alterna o led interno entre aceso (3 segundos) e apagado (1s), sendo acompanhado pelo buzzer.

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
delay(1000); // Aguarda 1 segundo
}
```
