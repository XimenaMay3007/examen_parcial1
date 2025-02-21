void setup() {
//Configura el pin 2 como una
//entrada con resistencia interna pull-up.
//Esto significa que el pin 2 está
//configurado para leer el estado de un botón
//y la resistencia pull-up lo mantiene en un valor
//alto (HIGH) cuando el botón no está presionado.
  pinMode(2, INPUT_PULLUP);
  
  //Configura el pin 7 como salida. 
  //Este pin está destinado a controlar 
  //un LED u otro dispositivo.
  pinMode(7, OUTPUT);
  
  //Configura el pin 13 como salida, 
  //otro pin para controlar un LED u otro dispositivo.
  pinMode(13, OUTPUT);
}

void loop ()	{
  //Lee el valor del pin 2. Si el valor es alto
  //(HIGH), eso significa que el botón no está presionado.
  if (digitalRead(2) == HIGH)	{
    //Enciende el LED conectado al pin 13.
    digitalWrite(13, HIGH);
    //Apaga el LED conectado al pin 7.
  	digitalWrite(7, LOW);		}
  //Si el valor leído del pin 2 es bajo (LOW)
  //es porque el botón está presionado.
  else {
    //Apaga el LED conectado al pin 13.
    digitalWrite(13, LOW);
    //Enciende el LED conectado al pin 7.
  	digitalWrite(7, HIGH);		}
}
//Alvarez Rodriguez Jose Eduardo
//Hernandez Ramos Jose Ubaldo
//Juarez Mayorga Ximena Guadalupe
//Montes Rivera Fernanda Marisela
//Vazquez Reyna Angel Levi