/**
 * Blink_ATTINY85
 * Parpadea un led en el pin 4 del ATtiny85.
 *
 * Este ejemplo es de dominio público.
 *
 * Modificado el 10 de marzo de 2016
 * por Pablo Bacho para Fábrica Digital
 */

const int LED_PIN = 4;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
