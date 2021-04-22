/*Funcion para escribir el estado de cada fila del arreglo de leds, establecido cada uno 
por un CI 74HC595, es una funcion tipo void que recibe 8 parametros
que representan el estado de cada una de las 8 filas. Nota= dentro de esta funcion
se llama la funcion shiftOut que es una funcion avanzada de entrada/salida,perteneciente
a la libreria de base(Core library).(puede encontrar documentacion de esta funcion
en la carpeta funciones de la rama Documentation).*/

//la funcion no me retorna nada y me recibe 8 enteros

void ledLineWrite(int Sf1, int Sf2, int Sf3, int Sf4, int Sf5, int Sf6, int Sf7, int Sf8)
{
  //Cada que se ejecuta un shiftOut estoy cargando 8 bits en un CI
  //Empiezo con los 8 bits que me representan el estado de la ultima fila
  //ya que al ejecutar otro shifOut estos 8 datos me pasan en serie al 
  //Siguiente CI y es el ultimo CI quien me controla la ultima fila
   
   shiftOut(SER, SRCLK, MSBFIRST, Sf8); 
   shiftOut(SER, SRCLK, MSBFIRST, Sf7);
   shiftOut(SER, SRCLK, MSBFIRST, Sf6);
   shiftOut(SER, SRCLK, MSBFIRST, Sf5);
   shiftOut(SER, SRCLK, MSBFIRST, Sf4);
   shiftOut(SER, SRCLK, MSBFIRST, Sf3);
   shiftOut(SER, SRCLK, MSBFIRST, Sf2);
   shiftOut(SER, SRCLK, MSBFIRST, Sf1);
   
   //Una vez guardados los estados de cada fila, envio un flanco de subida
  // por el puerto que controla el reloj de registro de salida RCLK 
   digitalWrite(RCLK, HIGH); 
   digitalWrite(RCLK, LOW);
}