const int Trigger = 2;   // Pin digital 2 para el Trigger del sensor
const int Echo = 3;      // Pin digital 3 para el Echo del sensor
const int Led = 4;       // Pin digital 4 para el LED

void setup() {
  Serial.begin(9600);    // Inicializamos la comunicación serial
  pinMode(Trigger, OUTPUT); // Trigger como salida
  pinMode(Echo, INPUT);     // Echo como entrada
  pinMode(Led, OUTPUT);     // LED como salida
  digitalWrite(Trigger, LOW); // Inicializamos el Trigger en LOW
  digitalWrite(Led, LOW);     // Inicializamos el LED apagado
}

void loop() {
  long t;  // Tiempo que demora en llegar el eco
  float d; // Distancia en centímetros

  // Generamos un pulso de 10us en el Trigger
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH, 30000); // Esperamos un máximo de 30ms para la respuesta

  // Si no se detecta respuesta, asumimos que el objeto está fuera del rango
  if (t == 0) {
    d = 1000; // Asignamos un valor alto para que el LED se apague
  } else {
    d = (t * 0.034) / 2;  // Convertimos el tiempo en distancia en cm
  }

  Serial.print("Distancia: ");
  Serial.print(d);      // Enviamos la distancia al monitor serie
  Serial.println(" cm");

  // Encendemos el LED si la distancia es menor a 10 cm, lo apagamos si es mayor
  if (d > 0 && d < 10) {
    digitalWrite(Led, HIGH);
  } else {
    digitalWrite(Led, LOW);
  }

  delay(200); // Pausa de 200ms para la siguiente medición
}
