// LOW switch ON
// HIGH switch OFF

void seriale() {

  // open doors
  if (input[0] == '1'){
    digitalWrite(P1, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == '2'){
    digitalWrite(P2, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == '3'){
    digitalWrite(P3, HIGH);
    delay(pauseTens);
  }

  // close the doors
  else if (input[0] == '!'){
    digitalWrite(P1, LOW);
    delay(pauseTens);
  }
  else if (input[0] == '@'){
    digitalWrite(P2, LOW);
    delay(pauseTens);
  }
  else if (input[0] == '='){
    digitalWrite(P3, LOW);
    delay(pauseTens);
  }

  // lights
  else if (input[0] == 'N'){
    digitalWrite(L1, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'n'){
    digitalWrite(L1, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'O'){
    digitalWrite(L2, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'o'){
    digitalWrite(L2, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'R'){
    digitalWrite(L3, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'r'){
    digitalWrite(L3, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'H'){
    digitalWrite(L4, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'h'){
    digitalWrite(L4, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'K'){
    digitalWrite(L5, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'k'){
    digitalWrite(L5, HIGH);
    delay(pauseTens);
  }
  // games
  else if (input[0] == 'Q'){
    digitalWrite(C1, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'q'){
    digitalWrite(C1, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'W'){
    digitalWrite(C2, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'w'){
    digitalWrite(C2, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'E'){
    digitalWrite(C3, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'e'){
    digitalWrite(C3, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'D'){
    digitalWrite(C4, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'd'){
    digitalWrite(C4, HIGH);
    delay(pauseTens);
  }

  // SEQUENCES

  // orologio
  // _orologio orologio TRUE
  else if (input == "_orologio\n"){
    regia_orologio = true;
    Serial.println("Orologio regia");
  }

  // start
  // start game TRUE
  else if (input == "_startGame\n" && !start_game){
    start_game = true;
    game_started = false;
  }

  // tempesta
  // _tempesta light on windows
  else if (input == "_tempesta\n"){
    for (int i = 0; i < 8; i++){
      digitalWrite(C5, LOW);
      delay(random(30, 80));
      digitalWrite(C5, HIGH);
      delay(random(50, 100));
    }
  }

  // UV FX
  // _uvfx
  else if (input == "_uvfx\n"){
    for (int i = 0; i < 15; i++){
      digitalWrite(L4, LOW);
      delay(20);
      digitalWrite(L3, HIGH);
      delay(random(50, 150));
      digitalWrite(L4, HIGH);
      delay(20);
      digitalWrite(L3, LOW);
      delay(random(30, 150));
    }
  }

  // Open All
  // _openAll Open all doors, all games and switch on lights
  else if (input == "_openAll\n") {
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (pauseTens);
    }
    for (int i = 0; i < 8; i++){
      digitalWrite(magnets[i], HIGH);
      delay (pauseTens);
    }
    for (int i = 0; i < 8; i++){
       digitalWrite(lights[i], LOW);
       delay (pauseTens);
    }
  }

  // reset
  // _reset open all doors and switch on lights
  else if (input == "_reset\n"){
    for (int i = 0; i < 6; i++){
      digitalWrite(lights[i], LOW);
      delay(pauseTens);
    }
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (pauseTens);
    }
  }

  //preparation
  // _preparation close all doors and magnets and switch on the lights
  else if (input == "_preparation\n"){
    for (int i = 0; i < 6; i++){
      digitalWrite(lights[i], LOW);
      delay(pauseTens);
    }
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], LOW);
      delay (pauseTens);
    }
    for (int i = 0; i < 8; i++){
      digitalWrite(magnets[i], LOW);
      delay (pauseTens);
    }
  }
}
