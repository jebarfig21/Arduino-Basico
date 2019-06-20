/**
 * Actividad que hace parpadear un led haciendo pauas
 * 60 segundos prendidos y 10 segundos apagado
 * 
 * Modificado el 19 de junio de 2018
 * @author Jesus Barajas
 */
const int LED_PIN = 4;
/**
 * 
 * Funcion que recibe dos parametors el primero para mantener encendido un led, el segundo el tiempo que debe de estar apagado.
 * @param int timepoEncendido, tiempo en milisegundos que se requiere estar prendido, ejemplo, 60 segundo = 60000
 * @param int tiempoApagado, tiempo en milisegundos que se requiere estar apagado, ejemplo, 10 segundo = 10000
 * @param int led, el pin donde esta conectado el led que queremos, conveniente cuando tenemos mas de un pin
 * 
 */
void parpadea(long tiempoEncendido, long tiempoApagado, int led){
  if(tiempoEncendido<0){
    tiempoEncendido=1000;
  }
  if(tiempoApagado<0){
    tiempoApagado =1000;
  }
  digitalWrite(led, HIGH);//Enciende el led
  delay(tiempoEncendido);//Mantiene encendido el led
  digitalWrite(led, LOW);//Apaga el led
  delay(tiempoApagado);//Mantiene apagado el ledo

}


void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  parpadea(60000,10000,LED_PIN);
}
