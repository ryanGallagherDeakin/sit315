int soundSensor=2;
int LED=4;
boolean LEDStatus=false;
static const unsigned long REFRESH_INTERVAL = 1000; // ms
static unsigned long lastRefreshTime = 0;


void setup() {
 pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);
 Serial.begin(9600);

}

void waitingMessage()
{
  // runs every second.... 
  Serial.println("Waiting patiently...");
}

void statusMessage()
{
  if(LEDStatus == true){
    Serial.println("LED IS ON!");
  }
  else
  {
    Serial.println("LED IS OFF!");
  }
}


void loop() {

  
  int SensorData=digitalRead(soundSensor);    

  if(millis() - lastRefreshTime >= REFRESH_INTERVAL)
    {
      lastRefreshTime += REFRESH_INTERVAL;
                  waitingMessage();
    }


  if(SensorData==1){

    if(LEDStatus==false){
        digitalWrite(LED,HIGH);
        LEDStatus=true;
        statusMessage();

}
    else{
        digitalWrite(LED,LOW);
        LEDStatus=false;
        statusMessage();        
    }
  }

 } 
