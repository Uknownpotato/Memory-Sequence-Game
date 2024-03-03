const int YELLOW = 8;
const int GREEN = 9;
const int BLUE = 10;
const int RED = 11;
const int btnYEL = 2;
const int btnGRE = 3;
const int btnBLU = 4;
const int btnRED = 5;
int duration = 300;
int sequence[6];
int seqSize = 3;
bool gameOver = false;
bool computerTurn = true;

// LED and btn pins
void setup() {
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(btnYEL, INPUT);
  pinMode(btnGRE, INPUT);
  pinMode(btnBLU, INPUT);
  pinMode(btnRED, INPUT);
  initRandomSeed();

}


// Seed number generator
void initRandomSeed() {
	pinMode(A0, INPUT);
  	randomSeed(analogRead(A0));
}

// Plays random sequence
void playSequence(int duration) {  
  for(int i = 0; i < seqSize; i++) {
    int randNum = getRandomColor();
    sequence[i] = randNum;
    displayColor(randNum, duration);
  }

  if(seqSize < 6) {
    seqSize++;
  } else if(duration > 150) {
    duration -= 50;
  }
}

// Generate random LED-color flash
int getRandomColor() {
	return random(4) + 8;
}


// Display LED
void displayColor(int color, int duration) {
	digitalWrite(color, HIGH);
    delay(duration);
    digitalWrite(color, LOW);
    delay(duration);
}

// Player turn
void playerTurn() {
  for(int i = 0; i < seqSize; i++) {
    int buttonPressed = buttonPress();
    displayColor(buttonPressed, 500);
  
    // Check if player press wrong button.
    if(buttonPressed != sequence[i]) {
   		gameOver = true;
      	break;
    } else {
      computerTurn = true;
    }
    
    if(gameOver) break;
  
  }  
}

// Wait for user input
int buttonPress() {
	while(true) {
    	if(digitalRead(btnYEL) == LOW) {
    		return YELLOW;
    	} else if(digitalRead(btnGRE) == LOW) {
    		return GREEN;
    	} else if(digitalRead(btnBLU) == LOW) {
    		return BLUE;
    	} else if(digitalRead(btnRED) == LOW) {
    		return RED;
        } 
  	}
}


void loop() {
  // Check whos turn it is
  if(computerTurn) {
  	playSequence(duration);
    computerTurn = false;
  } else {
    playerTurn();
  }


  delay(1000);
}
 