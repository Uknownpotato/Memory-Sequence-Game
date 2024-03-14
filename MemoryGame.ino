const int YELLOW = 8;
const int GREEN = 9;
const int BLUE = 10;
const int RED = 11;
const int btnYEL = 2;
const int btnGRE = 3;
const int btnBLU = 4;
const int btnRED = 5;
const int buzzer = 1;
const int c = 262;
const int db = 277;
const int d = 294;
const int eb = 311;
const int e = 330;
const int f = 349;
const int gb = 370;
const int g = 392;
const int ab = 415;
const int a = 440;
const int b = 466;
const int h = 494;
const int tones[4] = {c, d, e, f};
int duration = 350;
int sequence[6];
int seqSize = 2;
int debounceTime = 20;
bool gameOver = false;
bool computerTurn = true;

// LED and btn pins
void setup() {
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(btnYEL, INPUT_PULLUP);
  pinMode(btnGRE, INPUT_PULLUP);
  pinMode(btnBLU, INPUT_PULLUP);
  pinMode(btnRED, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
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

  
}

// Generate random LED-color flash
int getRandomColor() {
	return random(4) + 8;
}


// Display LED
void displayColor(int color, int duration) {
	digitalWrite(color, HIGH);
  	tone(buzzer, tones[color - 8], duration); 
    delay(duration);
    digitalWrite(color, LOW);
    delay(duration);
}

// Player turn
void playerTurn() {
  for(int i = 0; i < seqSize && !gameOver; i++) {
    byte buttonState = buttonPress();
    displayColor(buttonState, 270);
  
    // Check if player press wrong button.
    if(buttonState != sequence[i]) {
   		gameOver = true;
    } else {
      computerTurn = true;
    }
  }
  if(gameOver){
    loseSound();
  } else {
    winSound();
  }
}

// Wait for user input
int buttonPress() {
	while(true) {
    	if(digitalRead(btnYEL) == HIGH) {
        delay(debounceTime);
        if(digitalRead(btnYEL) == HIGH) {
    		  return YELLOW;
        }
    	} else if(digitalRead(btnGRE) == HIGH) {
        delay(debounceTime);
        if(digitalRead(btnGRE) == HIGH) {
    		  return GREEN;
        }
    	} else if(digitalRead(btnBLU) == HIGH) {
        delay(debounceTime);
        if(digitalRead(btnBLU) == HIGH) {
    		  return BLUE;
        }
    	} else if(digitalRead(btnRED) == HIGH) {
        delay(debounceTime);
        if(digitalRead(btnRED) == HIGH) {
    		  return RED;
        }
      } 
  }
}

void winSound() {
  tone(buzzer, a, 250);
  delay(300);
  tone(buzzer, a, 100);
  delay(150);
  tone(buzzer, a);
  delay(450);
  tone(buzzer, db*2); 
  delay(450);
  tone(buzzer, e*2);
  delay(450);
  tone(buzzer, a*2, 900);
  delay(900);
  noTone(buzzer);
}

void loseSound() {
  tone(buzzer, g, 150);
  delay(200);
  tone(buzzer, g, 150);
  delay(200);
  tone(buzzer, g, 150);
  delay(200);
  tone(buzzer, eb, 1200);
  delay(1800);
  tone(buzzer, f, 150);
  delay(200);
  tone(buzzer, f, 150);
  delay(200);
  tone(buzzer, f, 150);
  delay(200);
  tone(buzzer, d, 1200);
  delay(1800);
  noTone(buzzer);
}


void loop() {
  // Check whos turn it is
  while(!gameOver) {
  	if(computerTurn) {
    	if(seqSize < 6) {
    		seqSize++;
  		} else if(duration > 150) {
    		duration -= 50;
  	}
  		playSequence(duration);
    	computerTurn = false;
  	} else {
 		playerTurn();
  	}

  	delay(300);
  }
}
 