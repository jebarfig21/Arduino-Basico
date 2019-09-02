/*
 * 
 * Programa para arduino uno que modula la intensidad de brillo de un led mediante la cantidad de luz que recibe un sensor ldr.
 * 
 * @author Jesus Barajas
 */
const int LED_PIN = 5;
const int LDR = A0;


void setup() {
  pinMode(LED_PIN, OUTPUT); //LED en el pin 4 es la salida
  Serial.begin(9600);
  }

void loop() {
  
  int entrada = analogRead(LDR);
  entrada = entrada - 150 ;
  analogWrite(LED_PIN, entrada);//Se manda como salida a LED_PIN el valor que se reciba de la entrada LDR sobre 4 para que sea un valor menor que 256
  Serial.println(entrada);
 
  }
