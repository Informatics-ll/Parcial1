const int SER  = 2;
const int RCLK = 4;
const int SRCLK = 5;
short int led[8]={0};
int array[] = {0};
char row=0;
#define TIEMPO 20


//Funcion con datos anteriores
/*void ledWrite(int f1, int f2, int f3, int f4, int f5, int f6, int f7, int f8)
{
   shiftOut(pinData, pinClock, LSBFIRST, f8); 
   shiftOut(pinData, pinClock, LSBFIRST, f7);
   shiftOut(pinData, pinClock, LSBFIRST, f6);
   shiftOut(pinData, pinClock, LSBFIRST, f5);
   shiftOut(pinData, pinClock, LSBFIRST, f4);
   shiftOut(pinData, pinClock, LSBFIRST, f3);
   shiftOut(pinData, pinClock, LSBFIRST, f2);
   shiftOut(pinData, pinClock, LSBFIRST, f1);
   digitalWrite(pinLatch, HIGH);
   digitalWrite(pinLatch, LOW);
}*/

//Funcion para controlar los datos de los 8 CI
void ledLineWrite(int Sf1, int Sf2, int Sf3, int Sf4, int Sf5, int Sf6, int Sf7, int Sf8)
{
   shiftOut(SER, SRCLK, MSBFIRST, Sf8); 
   shiftOut(SER, SRCLK, MSBFIRST, Sf7);
   shiftOut(SER, SRCLK, MSBFIRST, Sf6);
   shiftOut(SER, SRCLK, MSBFIRST, Sf5);
   shiftOut(SER, SRCLK, MSBFIRST, Sf4);
   shiftOut(SER, SRCLK, MSBFIRST, Sf3);
   shiftOut(SER, SRCLK, MSBFIRST, Sf2);
   shiftOut(SER, SRCLK, MSBFIRST, Sf1);
   digitalWrite(RCLK, HIGH);
   digitalWrite(RCLK, LOW);
}  
   
//Funcion para comprobar el funcionamiento de los 64 leds 
void Verification(void)
{
  for(short int i=0; i<9; i++){
  	led[i] = pow(2, i);
  	ledLineWrite(led[i], led[i], led[i], led[i], led[i], led[i], led[i], led[i]);
    delay(100);
  }
}
/*
//Funcion para mostrar un patrón ingresado por el usuario
void Imagen(void)
{
  	
  while(Serial.available()==0)
  {
    Serial.print("Ingrese las filas de leds que desea encender: ");
    row = Serial.read();
    row = Serial.parseInt(); //Conversión a entero
    array = new int[row]; //Asignación de espacio en memoria dinámica
      for(int i=0; i<row; i++){
    	ledLineWrite(led[i], led[i], led[i], led[i], led[i], led[i], led[i], led[i]);
    }
  	
  
  }
  delete[] array;
}
*/

//Configuro el setup
void setup(){
  
  //Se inicia el puerto serial
   Serial.begin(9600);
  
  //Configuro los puertos 2,4,5 como salidas
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
 
  //Aseguro que el reloj de registro de entrada este en bajo
  digitalWrite (SRCLK, LOW);

  //Verifico funcionamiento de los 64 leds
  Verification();
  Imagen();
 ledLineWrite(0,0,0,0,0,0,0,0);
 delay(1000);
 ledLineWrite(192,192,192,192,192,192,255,255);
              
}
 


void loop(){
  
 
 	
  //fila 1
 /*  ledWrite(128,128,128,128,128,128,128,128); delay(TIEMPO);
   ledWrite(64,64,64,64,64,64,64,64);  delay(TIEMPO);
   ledWrite(32,32,32,32,32,32,32,32);  delay(TIEMPO);
   ledWrite(16,16,16,16,16,16,16,16);  delay(TIEMPO);
   ledWrite(8,8,8,8,8,8,8,8);   delay(TIEMPO);
   ledWrite(4,4,4,4,4,4,4,4);   delay(TIEMPO);
   ledWrite(2,2,2,2,2,2,2,2);   delay(TIEMPO);
   ledWrite(1,1,1,1,1,1,1,1);   delay(TIEMPO);
*/
}