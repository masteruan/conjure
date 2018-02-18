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
  else if (input[0] == 'h'){
    digitalWrite(L4, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'H'){
    digitalWrite(L4, HIGH);
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
  
  // sequences
  else if (input == "_spegni\n") {
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (100);
    }
    
    for (int i = 0; i < 8; i++){
      digitalWrite(magnets[i], HIGH);
      delay (100);
    }
    digitalWrite(L1, HIGH);
    delay(pauseTens);
    digitalWrite(L2, HIGH);
    delay(pauseTens);
    digitalWrite(L3, HIGH);
    delay(pauseTens);
  }

  // start
  else if (input == "_startGame\n" && !start_game){
    start_game = true;
    game_started = false;
  }

  else if (input == "_reset\n" && !preparation){
    digitalWrite(L1, LOW);
    delay(pauseTens);
    digitalWrite(L2, LOW);
    delay(pauseTens);
    digitalWrite(L3, HIGH);
    delay(pauseTens);
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (100);
    }
  }
  
  else if (input == "_leva\n"){
    regia_orologio = true;
    Serial.println("Leva dalla regia");
  }
  
  else if (input == "_openAll\n"){
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (100);
    }
    for (int i = 0; i < 8; i++){
      digitalWrite(magnets[i], HIGH);
      delay (100);
    }
    digitalWrite(L1, LOW);
    delay(pauseTens);
    digitalWrite(L2, LOW);
    delay(pauseTens);
    digitalWrite(L3, HIGH);
    delay(pauseTens);
  }
}
