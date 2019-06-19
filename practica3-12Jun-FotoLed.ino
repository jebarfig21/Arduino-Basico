
#define LED 8 // the pin for the LED
#define pinANL 0

int valorFotoresistencia = 0; // variable used to store the value

  void setup() {
     pinMode(LED, OUTPUT); // LED en el pin 9 es Salida
     // Pin análogo es automaticamente entrada  
  }
    
  void loop() {
       valorFotoresistencia = analogRead(pinANL); // Lee el valor del sensor análogo
       analogWrite(LED, valorFotoresistencia/4); // Asigna al led el valor que reciba el sensor divido entre 4
       delay(10); // hace una breve pausa en el programa
}
