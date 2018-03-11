int led= 13;
int battery = A1;
int timer = 600000;
unsigned long clok = 0;
unsigned long previousClok = 0;
boolean sign_battery = true;
boolean anim = true;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(battery, INPUT_PULLUP);
  Serial.begin(9600);
  for(int i = 0; i<3; i++){
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
  }
}

void loop() {
  clok = millis();
  Serial.println(clok);
  digitalWrite(led,HIGH);
  if(clok - previousClok > timer) {
    if(anim){
      for (int i = 0; i < 30; i++) {
      digitalWrite(led, LOW);
      delay(random(50,500));
      digitalWrite(led, HIGH);
      delay(random(50,300));
      anim = false;
      }
    }
    digitalWrite(led, LOW);
    Serial.println("Spengo");
    delay(50);
    sign_battery = digitalRead(battery);
    if(!sign_battery){
      delay(2000);
      Serial.println("tentativo");
      sign_battery = true;
      sign_battery = digitalRead(battery);
      if (!sign_battery){
        digitalWrite(led,HIGH);
        Serial.println("Accendo");
        previousClok = clok;
        anim = true;
      }
    }
  }
delay(30);
}
