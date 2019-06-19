const int LED_PIN = 4;
const int LDR = A1;
void setup() {
  pinMode(LED_PIN, OUTPUT); //LED en el pin 4 es la salida
}

void loop() {
  analogWrite(LED_PIN, analogRead(LDR/4));//Se manda como salida a LED_PIN el valor que se reciba de la entrada LDR sobre 4 para que sea un valor menor que 256
  delay(210);
  }
