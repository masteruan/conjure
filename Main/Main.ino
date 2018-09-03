/* ********************
* 29 Marzo 2018
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
* C1 tarocchi
* C2 santi
* C3 finestra
* C4 sedia
* C5 led finestra
<<<<<<< HEAD
* C6 croci
=======
* C6 Orologio
* C7 Croci
>>>>>>> dd849e536ef996ab5650b5a73c1ec85d121b60aa
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
* "_uvfx" UV fx and faretto bue
* "_startGame" to start the game
*
* "_openAll" open all the doors and magnets
* "_reset" open all the doors and switch on the lights
* "_preparation" to close all the doors all the magnets and switch on all the lights
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
int in_orologio = A1;
boolean sign_orologio = true;
boolean OK_orologio = false;
boolean regia_orologio = false;

int pauseTens = 20;

// nulla
int nulla1 = 22;

// calamite
int C1 = 26; // Tarocchi
int C2 = 27; // Santi
int C3 = 28; // Finestra
int C4 = 29; // Sedia
int C5 = 25; // Gioco cantina
<<<<<<< HEAD
int C6 = 23; // Orologio
int C7 = 24; // Croci

=======
int C6 = 24; // Orologio #################### Contollare !!
int C7 = 23; // Croci #################### Contollare !!
>>>>>>> dd849e536ef996ab5650b5a73c1ec85d121b60aa
// Porte
int P1 = 32; // Porta ingresso
int P2 = 31; // Porta corridoio
int P3 = 30; // Porta Uscita

// Luci
int L1 = 36; // Occhio di bue
int L2 = 37; // Luci sala ingresso
int L3 = 35; // UV
int L4 = 34;// Strobo
int L5 = 33;// Luci cantina

// Arrays
int doors[] = {P1,P2,P3}; // seven doors
<<<<<<< HEAD
int magnets[] = {C1, C2, C3, C4, C5, C6}; // giochi e armadi
int lights [] = {L2, L3, L5};
=======
int magnets[] = {C1,C2,C3,C4,C5}; // giochi e armadi
int lights [] = {L1,L2, L3, L4, L5};
>>>>>>> dd849e536ef996ab5650b5a73c1ec85d121b60aa

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
  pinMode(in_orologio, INPUT_PULLUP);

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
      regia_orologio = false;

      // Close all doors
      digitalWrite(P1, LOW);
      digitalWrite(P2, LOW);
      digitalWrite(P3, LOW);

      // Close all 
      digitalWrite(C1, LOW);
      digitalWrite(C2, LOW);
      digitalWrite(C3, HIGH);
      digitalWrite(C4, LOW);
      digitalWrite(C5, LOW);
      digitalWrite(C6, LOW);
      digitalWrite(C7, HIGH);

      
    for (int i = 0; i < 3; i++){
      digitalWrite(lights[i], LOW);
      delay(pauseTens);
    }

      // variables
      start_game = false;
      game_started = true;
      Serial.println("gameStarted");
      delay(1000);
      }

  if (game_started){
    if (!OK_orologio){
      sign_orologio = digitalRead(in_orologio);
      if(!sign_orologio){
          sign_orologio = true;
          delay(300);
          sign_orologio = digitalRead(in_orologio);
      }
        if (!sign_orologio || regia_orologio){
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
