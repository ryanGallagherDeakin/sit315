int soundSensor=2;
int LED=4;
uint8_t LEDStatus=LOW;
static const unsigned long REFRESH_INTERVAL = 2000; // ms
static unsigned long lastRefreshTime = 0;


void setup() {
 pinMode(soundSensor,INPUT_PULLUP);
 pinMode(LED,OUTPUT);
 Serial.begin(9600);

 attachInterrupt(digitalPinToInterrupt(soundSensor), toggle, FALLING);

}

void waitingMessage()
{
  // runs every second.... 
  Serial.println("Waiting patiently...");
}

void statusMessage(uint8_t led_state)
{
  if(led_state == LOW) {
    Serial.println("LED IS OFF!");
  }
  else {
    Serial.println("LED IS ON!");
  }
}


void loop() {


  if(millis() - lastRefreshTime >= REFRESH_INTERVAL)
    {
      lastRefreshTime += REFRESH_INTERVAL;
                  waitingMessage();
    }
 } 

 void toggle() {
  LEDStatus = !LEDStatus;
  digitalWrite(LED, LEDStatus);
  statusMessage(LEDStatus);
  
 }
