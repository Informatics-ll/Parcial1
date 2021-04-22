/* Funcion que permite al usuario ingresar el estado de las filas de la matriz 
de 8x8 leds, es una funcion tipo void que no recibe ningun parametro.
Nota: esta funcion ejecuta la funcion ledLineWrite () anteriormente codificada
y documentada */


void Imagen(void) //Defino prototipo de funcion 
{
 
  int N; // Variable que me guarda el estado de cada fila que ingreso en representacion entera
  int arreglo[8]={0}; //arreglo de enteros que me guarda conjuntamente el estado de cada fila

  //Necesito iterar 8 veces
  for (int i=1;i<9;i++) {
    
    // Imprimo por consola el mensaje que indica que ingrese el estado de determinada fila
    Serial.print("Por favor ingrese el estado de la fila "); Serial.print(i,DEC);
    Serial.println(" como se indica en el manual");
    
    // Ingreso por consola el estado de cada fila y lo guardo en el arreglo de forma ordenada
    while(Serial.available()==0);
    N= Serial.parseInt();
    arreglo[i-1]= N; //i-1 por que empiezo desde la posicion 0 e i lo inicializo en 1
  }
  
  // Le indico al programa que me reserve un espacio en el heap para un arreglo de enteros de tamaño 8
  // y apunto a la primera posicion de ese arreglo que voy a llenar con los datos de arreglo[] que 
  // contiene el estado de cada fila de leds
  int *ptrArr= new int[8]{arreglo[0],arreglo[1],arreglo[2],arreglo[3],arreglo[4],arreglo[5],arreglo[6],arreglo[7]};
  
  //LLamo la funcion ledLineWrite que me escribe el estado de los leds de cada fila y le paso
  //como parametro el contenido de cada posicion del arreglo que guarde en el heap
  ledLineWrite(*(ptrArr),*(ptrArr + 1),*(ptrArr + 2),*(ptrArr + 3),*(ptrArr + 4),*(ptrArr + 5),*(ptrArr + 6),*(ptrArr + 7)); 

  //Limpio la basura, es decir le indico a la memoria dinamica que ya no necesito ese espacio
  delete[] ptrArr; 	}
