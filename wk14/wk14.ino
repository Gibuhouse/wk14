
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

byte colDataMatrix[8] = { B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110
};
                      
byte rowDataMatrix0[8] = {
    B11001100,
    B11001100,
    B00110011,
    B00110011,
    B11001100,
    B11001100,
    B00110011,
    B00110011
};
byte rowDataMatrix01[8] = {
    B00001100,
    B00001100,
    B00001100,
    B00001100,
    B00001100,
    B00001100,
    B00001100,
    B00001100
};
byte rowDataMatrix1[8] = {
    B00110011,
    B00110011,
    B11001100,
    B11001100,
    B00110011,
    B00110011,
    B11001100,
    B11001100
};


// 定義顯示器顯示的時間 (延遲時間), 預設 1ms
int delay_time = 1;
int count = 0; //計數
       
void setup() {
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
}
void loop() {
    
if(count < 1000){
   for(int i = 0; i < 8 ; i++){
 //byte colData = colDataMatrix[i];
digitalWrite(latchPin,LOW);
  //  pickDigit(i);
   shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix0[i]);
    //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
   
    digitalWrite(latchPin,HIGH);
    count++;
    delay(1);
  }
  }


if(count >= 1000){
   for(int i = 0; i < 8 ; i++){
 //byte colData = colDataMatrix[i];
digitalWrite(latchPin,LOW);
  //  pickDigit(i);
   shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix1[i]);
    //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
   
    digitalWrite(latchPin,HIGH);
        count++;
    delay(1);
  }
  }

if(count > 2000)count = 0;

  
 }
void pickDigit(int x) {
  byte rowByte = 1 << x;
  shiftOut(dataPin, clockPin, MSBFIRST, rowByte);

}
 
