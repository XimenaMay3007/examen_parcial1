// C++ code
//


void setup()
{
  // Inicializar el puerto serie para la salida de datos
  Serial.begin(9600);
}

void loop()
{
  // Declaración de variables
int lectura, temp;  // 'lectura' almacenará el valor leído del sensor, 'temp' almacenará la temperatura en °C

// Leer el valor analógico del sensor conectado al pin A0
lectura = analogRead(A0);  // 'analogRead(A0)' devuelve un valor entre 0 y 1023 dependiendo de la lectura del sensor

// Imprimir la lectura del sensor
Serial.print("Lectura: ");   // Imprime un texto indicando que se mostrará la lectura
Serial.print(lectura);      // Imprime el valor numérico de la lectura del sensor (0-1023)

// Imprimir la temperatura calculada
Serial.print(", temperatura: ");  // Imprime un texto que indica que a continuación se mostrará la temperatura
temp = (lectura * (500.0 / 1023.0)) - 50.0;  // Convierte el valor de la lectura a temperatura en °C
  // (lectura * (500.0 / 1023.0)) convierte el valor analógico (0-1023) a un voltaje en mV
  // Luego, le restamos 50.0 para ajustar el offset de la temperatura (esto depende del sensor)
Serial.print(temp);   // Imprime la temperatura en °C calculada
Serial.println(",");  // Añade una coma y salta una línea para una nueva lectura en el siguiente ciclo

// Esperar 1 segundo antes de hacer otra lectura
delay(1000);   // Espera 1000 milisegundos (1 segundo) antes de realizar otra lectura

  
}