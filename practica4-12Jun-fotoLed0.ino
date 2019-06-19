
#define LED 13 // the pin for the LED
#define pinANL 0
int valorFotoresistencia = 0; // variable used to store the value

  void setup() {
     pinMode(LED, OUTPUT); // LED en el pin 9 es Salida
     // Pin análogo es automaticamente entrada  
  }
    
  void loop() {
       valorFotoresistencia = analogRead(pinANL); // Lee el valor del sensor análogo
       digitalWrite(LED, HIGH); // Asigna al led el valor que reciba el sensor divido entre 4
       delay(valorFotoresistencia); // hace una breve pausa en el programa
        digitalWrite(LED, LOW); // Asigna al led el valor que reciba el sensor divido entre 4
       delay(valorFotoresistencia); // hace una breve pausa en el programa
}
