float leitura;
 
 void setup() 
{ 
  //define velocidade do serial 
  Serial.begin(115200);
  Serial.println("Leitura do potenciometro");
  Serial.println("Valor        Volts");
}
 
void loop() 
{
  //lê o valor do potenciômetro [0, 1023] e imprime
  Serial.print(analogRead(A0));
  Serial.print("         ");
  leitura = (analogRead(A0)*3.3/1023);
  Serial.println(leitura);
  delay(1500);  
}
