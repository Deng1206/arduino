int ledPins[] = {14,27,26,25,33,32,22,21,17,16};  
int buttonPin=12;   
int k=0;

void setup(){
  pinMode(buttonPin,INPUT);
  for(int a=0;a<10;a++){
    pinMode(ledPins[a],OUTPUT);
    Serial.begin(115200);
  }
}

void loop(){
  int b=digitalRead(12);
  if(b==HIGH){
     Serial.print(b);
    k++;
    if(k<=10){
      for(int i=-1;i<k;i++){
         digitalWrite(ledPins[i],HIGH);
         delay(100);
      }
    }
    
    if(k>10){
      for(int i=9,j=1;k-(2*j-1)>i;i--,j++){
        digitalWrite(ledPins[i],LOW);
        delay(100);
      }
    }
    if(k==20)k=0;
  }
}
