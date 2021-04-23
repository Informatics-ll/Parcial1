const int SER  = 2; // Guardo la salida digital a la que voy a conectar el pin14 del CI 74HC595
const int RCLK = 4; // Guardo la salida digital a la que voy a conectar el pin12 del CI 74HC595
const int SRCLK = 5; // Guardo la salida digital a la que voy a conectar el pin11 del CI 74HC595
short int led[8]={0}; // arreglo de la funcion Verificacion
int num_patrones = 0; //Numero de patrones para la animacion
int time = 0; //en milisegundos
int M; //Estado de la fila de leds
int arreglo[8]={0}; //Arreglo donde se almacena patron predeterminado
int option=1; //Para ingresar al menu

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
}
 


void loop()
{
  while (option != 0)
{
	Serial.println();
    Serial.println("******************* Parcial 1 **********************");
    Serial.println("Presione 1 para verificar el estado de todos los led  ");
    Serial.println("Presione 2 para ingresar el patron independientemente ");
    Serial.println("Presione 3 para ingresar una secuencia de patrones ");
	Serial.println("Presione 0 para salir ");
    Serial.println("****************************************************");
    Serial.println();
    while(Serial.available()==0);
    option = Serial.parseInt();

	switch(option)
  	{
      case 1:
      	//Verificacion funcionamiento de los 64 leds
  		Verification();
 		ledLineWrite(0,0,0,0,0,0,0,0);
 		delay(1000);
      	break;	
      
      case 2:
      	//Llamado de la funcion Imagen
      	Imagen();
      	break;
      
      
      case 3:
        //Llamado de la funcion publik
  		publik();
      	break;

    	}
	}

}



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
    delay(10);
  }
}

//Funcion para mostrar un patrón ingresado por el usuario
void Imagen(void)
{
 
  int N;
  int arreglo[8]={0};

  for (int i=1;i<9;i++) {
    Serial.print("Por favor ingrese el estado de la fila "); Serial.print(i,DEC);
    Serial.println(" como se indica en el manual");
    while(Serial.available()==0);
    N= Serial.parseInt();
    arreglo[i-1]= N;
  }
  int *ptrArr = new int[8]{arreglo[0],arreglo[1],arreglo[2],arreglo[3],arreglo[4],arreglo[5],arreglo[6],arreglo[7]};
  ledLineWrite(*(ptrArr),*(ptrArr + 1),*(ptrArr + 2),*(ptrArr + 3),*(ptrArr + 4),*(ptrArr + 5),*(ptrArr + 6),*(ptrArr + 7)); 

  delete[] ptrArr; 	}

//Funcion que permite mostrar secuencia de patrones
void publik(void)
{
  
  Serial.println("Ingrese el numero de patrones que desea mostrar: ");
  while(Serial.available()==0);
  num_patrones = Serial.parseInt();
  int arrays[num_patrones][8]; //Arreglo donde se almacenan la secuencia de patrones
  Serial.println("Ingrese el tiempo en segundos que quiere ver entre un patron y otro: ");
  Serial.println();
  while(Serial.available()==0);
  time = Serial.parseInt();
  time = time*1000; //conversion a milisegundos
    
  for (int k=0; k<num_patrones;k++){
        // creación de un solo patron
        for (int i=1;i<9;i++) {
    		Serial.print("Por favor ingrese el estado de la fila "); Serial.print(i,DEC);
    		Serial.print(" del patron "); Serial.print(k+1,DEC);
            Serial.println(" como se indica en el manual");
   	 		while(Serial.available()==0);
    		M = Serial.parseInt();
    		arreglo[i-1]= M;
          }
    	 Serial.println();
         for(int j=0; j<8;j++){
              arrays[k][j] = arreglo[j];
        }
    }
  Serial.println("Si desea detener la animacion presiona 1");
  while(Serial.available()!= 1){   
 	for (int i=0 ; i < num_patrones ; i++){
        int *ptrArr = new int[8]{arrays[i][0],arrays[i][1],arrays[i][2],arrays[i][3],arrays[i][4],arrays[i][5],arrays[i][6],arrays[i][7]};
        ledLineWrite(*(ptrArr),*(ptrArr + 1),*(ptrArr + 2),*(ptrArr + 3),*(ptrArr + 4),*(ptrArr + 5),*(ptrArr + 6),*(ptrArr + 7));
        delay(time);
        delete[] ptrArr;
    }
  }

}


