//dclaración de variables globales para pines y umbral de luz
int pinLed = 13;      //pin digital conectado al LED indicador
int pinLdr = A0;      //pin analógico conectado al divisor de voltaje con LDR
int umbral = 500;     //valor límite para diferenciar (0 a 1023)

void setup() {
  //configuración del pin del LED como salida de corriente
  pinMode(pinLed, OUTPUT);
  
  //inicialización de la comunicación serial a 9600 para monitoreo
  Serial.begin(9600);
}

//función personalizada para evaluar la iluminación ambiental
void evaluarIluminacion(int lectura) {
  //si la lectura es menor al umbral, significa que hay oscuridad
  if (lectura < umbral) {
    digitalWrite(pinLed, HIGH); //encender indicador lumínico
  } else {
    //si la lectura es mayor o igual, hay suficiente luz natural
    digitalWrite(pinLed, LOW);  //apagar indicador lumínico
  }
}

void loop() {
  //lectura del valor analógico del sensor LDR
  int nivelLuz = analogRead(pinLdr);

  //impresión de datos por el monitor serie para depuración
  Serial.print("Luz ambiental: ");
  Serial.println(nivelLuz);

  //llamada a la función modular para actualizar el estado del LED según la lectura
  evaluarIluminacion(nivelLuz);

  //pausa para estabilizar las lecturas y no saturar el puerto serie
  delay(200);
}