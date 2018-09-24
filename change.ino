int freq = 5000;
int ledchannel = 0;
int resolution = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
ledcSetup(ledchannel,freq,resolution);
ledcAttachPin(LED_BUILTIN,ledchannel);
pinMode(32,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    int rd;
    rd=analogRead(32);
    Serial.println(rd);
    rd=map(rd,0,3615,0,255);
    ledcWrite(ledchannel,rd);
    delay(7);
 
    



}
