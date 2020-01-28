#define LED 8
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration1, duration2, cm, td, loop1, temp, count;
 
void setup() {
  //Serial Port begin
  Serial.begin  (9600);
  pinMode(LED, OUTPUT);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration1 = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343


//Serial.println(cm);
 td = (35*20)/100;
 loop1 = 1;
 count = 0;
  if(cm < td)
  {
      for(loop1 = 1;loop1<=10;loop1++)
      {
        duration1 = pulseIn(echoPin, HIGH);
        temp = (duration2/2) / 29.1;
        if(temp <= cm)
        {
          count =count + 1;
        }
     }
   }
    if(count == 10)
    {
      Serial.println(1);
    digitalWrite(LED, HIGH);
    delay(10000);
    digitalWrite(LED, LOW);
    delay(10000);
    }
    else
    {
      Serial.println();
    }
     delay(25);
  }
