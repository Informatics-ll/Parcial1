int pinData  = 2;
int pinLatch = 4;
int pinClock = 5;
#define TIEMPO 20

void ledWrite(int f1, int f2, int f3, int f4, int f5, int f6, int f7, int f8)
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
}

void setup(){
   pinMode(pinData, OUTPUT);
   pinMode(pinLatch, OUTPUT);
   pinMode(pinClock, OUTPUT);
}

void loop(){
   //fila 1
   ledWrite(128,0,0,0,0,0,0,0); delay(TIEMPO);
   ledWrite(64,0,0,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(32,0,0,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(16,0,0,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(8,0,0,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(4,0,0,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(2,0,0,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(1,0,0,0,0,0,0,0);   delay(TIEMPO);
   //fila 2
   ledWrite(0,128,0,0,0,0,0,0); delay(TIEMPO);
   ledWrite(0,64,0,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,32,0,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,16,0,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,8,0,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,4,0,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,2,0,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,1,0,0,0,0,0,0);   delay(TIEMPO);
   //fila 3
   ledWrite(0,0,128,0,0,0,0,0); delay(TIEMPO);
   ledWrite(0,0,64,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,32,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,16,0,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,8,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,4,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,2,0,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,1,0,0,0,0,0);   delay(TIEMPO);
  //fila 4
   ledWrite(0,0,0,128,0,0,0,0); delay(TIEMPO);
   ledWrite(0,0,0,64,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,32,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,16,0,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,8,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,4,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,2,0,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,1,0,0,0,0);   delay(TIEMPO);
  //fila 5
   ledWrite(0,0,0,0,128,0,0,0); delay(TIEMPO);
   ledWrite(0,0,0,0,64,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,32,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,16,0,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,8,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,4,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,2,0,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,1,0,0,0);   delay(TIEMPO);
   //fila 6
   ledWrite(0,0,0,0,0,128,0,0); delay(TIEMPO);
   ledWrite(0,0,0,0,0,64,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,32,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,16,0,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,8,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,4,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,2,0,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,1,0,0);   delay(TIEMPO);
  //fila 7
   ledWrite(0,0,0,0,0,0,128,0); delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,64,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,32,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,16,0);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,8,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,4,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,2,0);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,1,0);   delay(TIEMPO);
   //fila 8
   ledWrite(0,0,0,0,0,0,0,128); delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,0,64);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,0,32);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,0,16);  delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,0,8);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,0,4);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,0,2);   delay(TIEMPO);
   ledWrite(0,0,0,0,0,0,0,1);   delay(TIEMPO);
}