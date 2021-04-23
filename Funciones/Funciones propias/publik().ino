/*Funcion creada para observar un numero determinado de patrones ingresados por un usuario cada cierto
tiempo requerido, es una funcion de tipo void y no recibe argumentos. NOTA: Se reutiliza un segmento de 
codigo de la funcion Imagen(), ya que si se llama la funcion, esta solo permite ver un patron, y la
idea es visualizar mas de un patron.*/
void publik(void)
{
  
  Serial.println("Ingrese el numero de patrones que desea mostrar: "); //Se le indica al usuario que ingrese el numero de patrones que quiere mostrar.
  while(Serial.available()==0); //Mientras en el monitor serie este disponible el usuario tendra acceso solo si envia un dato.
  num_patrones = Serial.parseInt(); //Se hace la conversion a entero ya que los datos ingresados por consola pueden tomar varios tipos de datos, ej:(char, string)
  int arrays[num_patrones][8]; //Arreglo donde se almacenan la secuencia de patrones.
  Serial.println("Ingrese el tiempo en segundos que quiere ver entre un patron y otro: "); //Se le indica al usuario que ingrese el tiempo de visualizacion entre un patron y otro.
  Serial.println(); //Salto de linea para mostrar mas ordenado el codigo en consola.
  while(Serial.available()==0);
  time = Serial.parseInt();
  time = time*1000; //Conversion a milisegundos ya que la funcion delay() lo requiere en su argumento.
    
  for (int k=0; k<num_patrones;k++){ //Se condiciona el bucle al numero de patrones que quiere ver el usuario.
        //Creacion de un solo patron, es el mismo segmento de codigo de la funcion Imagen() documentada en funciones propias.
        for (int i=1;i<9;i++) {
        Serial.print("Por favor ingrese el estado de la fila "); Serial.print(i,DEC);
        Serial.print(" del patron "); Serial.print(k+1,DEC);
            Serial.println(" como se indica en el manual");
        while(Serial.available()==0);
        M = Serial.parseInt();
        arreglo[i-1]= M;
          }
       Serial.println();
         for(int j=0; j<8;j++){ //Se almacena dentro de un arreglo los patrones que el usuario ingreso anteriormente.
              arrays[k][j] = arreglo[j];
        }
    }
  Serial.println("Si desea detener la animacion presiona 1");
  while(Serial.available()!= 1){ //Para visualizar la animacion se repite la visualizacion de patrones que el usuario ingreso.  
  for (int i=0 ; i < num_patrones ; i++){
        int *ptrArr = new int[8]{arrays[i][0],arrays[i][1],arrays[i][2],arrays[i][3],arrays[i][4],arrays[i][5],arrays[i][6],arrays[i][7]}; /*El puntero apunta al arreglo donde se almacenaron
        los patrones.*/
        ledLineWrite(*(ptrArr),*(ptrArr + 1),*(ptrArr + 2),*(ptrArr + 3),*(ptrArr + 4),*(ptrArr + 5),*(ptrArr + 6),*(ptrArr + 7)); /*Sacamos el valor que esta dentro del arreglo
        y se lo enviamos como argumentos a la funcion ledLineWrite() que nos permite ver las filas de leds encendidas*/
        delay(time); //Tiempo de espera para ver un de patron al siguiente patron.
        delete[] ptrArr;
    }
  }
