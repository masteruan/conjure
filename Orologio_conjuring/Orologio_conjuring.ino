/*
Conjuring clock hall effect sensor
4 Marzo 2018 ore 21:18
*/

int Led = 13; // define LED Interface
int SENSOR = 7; // define the Hall magnetic sensor interface
int SENSOR2 = 8; // define the Hall magnetic sensor interface
int val; // define numeric variables val
int val2; // define numeric variables val
int relay = 11;

void setup ()
{
  pinMode (Led, OUTPUT) ;    // define LED as output interface
  pinMode (relay, OUTPUT);
  Serial.begin(9600);
  pinMode (SENSOR, INPUT) ;  // define the Hall magnetic sensor line as input
  pinMode (SENSOR2, INPUT) ;  // define the Hall magnetic sensor line as input
  for (int i = 0; i < 5; i++){
    digitalWrite(Led, HIGH);
    delay(100);
    digitalWrite(Led, LOW);
    delay(100);
  }
}

void loop ()
{
  val = digitalRead (SENSOR) ; // read sensor line
  val2 = digitalRead (SENSOR2) ; // read sensor line

  if (val == LOW && val2 == LOW) // when the Hall sensor detects a magnetic field, Arduino LED lights up
  {
    
    Serial.println("primo");
    delay(2000);
  
    val = HIGH;
    val2 = HIGH;
    delay(800);
    val = digitalRead (SENSOR) ; // read sensor line
    val2 = digitalRead (SENSOR2) ; // read sensor line
    
    if (val == LOW && val2 == LOW){
    digitalWrite (Led, HIGH);
    digitalWrite (relay, HIGH);
    Serial.println("Calamita!!!");
    delay(2000);
    }
  }
  else
  {
    digitalWrite (Led, LOW);
    digitalWrite (relay, LOW);
  }
}
