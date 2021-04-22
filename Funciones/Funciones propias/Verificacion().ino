/*Funcion creada para verificar el funcionamiento de una cantidad
especifica de leds en un arreglo de 8x8, es una funcion tipo void
y no recibe ningun parametro. NOTA:Dentro de esta funcion
se llama la funcion ledLineWrite creada y documentada
anteriormente*/


void Verificacion(void) //Defino el tipo de funcion, nombre y parametro
{
int led=0; //Variable que me guarda el estado de una fila de leds
  for(int i=0; i<9;i++){
    led=pow(2,i); //led puede tomar el valor de [1,2,4,8,16,32,64,128]
    //Ingreso cada valor posible de led como parametro de la funcion ledLineWrite
    ledLineWrite(led,led,led,led,led,led,led,led); delay(20); 
  	//El delay me pausa el funcionamiento del programa N=20 milisegundos antes de cada iteracion 
  }}