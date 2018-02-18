/* ********************
* 17 Febbraio 2018
* per Conjuring
* v 0.1
* Giovanni Gentile
* 0lab.it projectg.it
*
* OUTPUT
* Porte
* P1 ingresso
* P2 corridoio
* P3 uscita
*
* Calamite
* C1 sedia dondolo
* C2 santi
* C3 tarocchi
* C4 croci
*
* Luci
* L1 stanza1
* L2 stanza2
* L3 occhio bue
* L4 lamp UV
*
* INPUT
* in_orologio
*
* Instructions
* Send to serial
* "_tempesta" lights in window and lights
* "_diablo" UV fx and faretto bue
* "_preparation" to close all the doors and switch on all the lights
* "_startGame" to start the game
* "_openAll" open all the doors and magnets
* "_reset" open all the doors and switch on the lights
* ***********************/

// switch
boolean start_game = false;
boolean game_started = false;
boolean preparation = false;

// serial
boolean stringComplete = false;
String input = ""; //String
char inChar ;

// INPUT
int in_orologio = A0;
boolean sign_orologio = true;
boolean OK_orologio = false;
boolean regia_orologio = false;

int L1 = 10; //
int L2 = 11; //
int L3 = 12;
int L4 = 13;

int pauseTens = 20;

// calamite
int C1 = 30; //
int C2 = 31; //
int C3 = 32; //
int C4 = 33;

// Porte
int P1 = 22; //
int P2 = 23; //
int P3 = 24; //

// Arrays
int doors[] = {2,3,4,5,6,7,8,9}; // seven doors
int magnets[] = {30,31,32,33,34,35,36,37}; // giochi e armadi
int lights [] = {12};

void setup() {
  Serial.flush();
  // Declare output
  // da 22 a 37 16 relay
  for (int i = 22; i < 38; i++){
    pinMode(i, OUTPUT);
    delay(20);
    digitalWrite(i, HIGH);
  }
  // Declare input
  // This input give FALSE if the input is open TRUE if the input is closed
  pinMode(A0, INPUT_PULLUP);

  // Start up serial connection
  Serial.begin(9600); //default 115200
  input.reserve(200);

  Serial.println("####################################");
  Serial.println("You are Welcome into Breakout System");
  Serial.println("Conjuring v 1.0.");
}

void loop() {

  if (stringComplete) {
    seriale();
    delay(20);
    input = "";
    stringComplete = false;
  }
  game();
}

void game () {
   if (start_game){
      // reset booleane
      OK_orologio = false;

      // Close all doors
      digitalWrite(P1, LOW);
      digitalWrite(P2, LOW);
      digitalWrite(P3, LOW);

      // Close all armadi
      digitalWrite(C1, LOW);
      digitalWrite(C2, LOW);
      digitalWrite(C3, LOW);
      digitalWrite(C4, LOW);

      // ON lights
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(L3, LOW);
      digitalWrite(L4, LOW);

      // variables
      start_game = false;
      game_started = true;
      regia_orologio = false;
      Serial.println("gameStarted");
  }

  else if (game_started){
    if (!OK_orologio){
      sign_orologio = digitalRead(in_orologio);
      delay(50);
      if(!sign_orologio){
          sign_orologio = true;
          delay(300);
          sign_orologio = digitalRead(in_orologio);
      }
    else if (!sign_orologio||regia_orologio){
      digitalWrite(P2, HIGH);
      delay(200);
      Serial.println("OROLOGIOK");
      OK_orologio = true;
      }
    }
  }
}

void serialEvent() {
  Serial.flush();
  delay(20);
  // Read any serial input
  while (Serial.available())
  {
    inChar = (char)Serial.read(); // Read in one char at a time
    input += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
