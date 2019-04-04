const byte pin[]= {9,8,7,6}; // lo que te permite elegir cualquier pin
byte estado = 0;
int test=0;
void setup() {

  for (int i=0; i<4; i++) {
        pinMode(pin[i], INPUT); // supongo que los pines estan configurados pull-up o down.
  }
    Serial.begin(9600);
}

void loop() {
  // Lectura de pines
  estado = 0;                               // "Borramos" el valor anterior
  for (int i=0; i<4; i++) {                 // Bucle de 0 a 7
        estado |= digitalRead(pin[i])<< i; // Leemos un 0 o un 1, lo desplazamos "i" veces a la izquierda y lo "añadimos" a estado
  }
  //Serial.println(test+=1);
  Serial.println(String(estado));
  delay(1000);
}
