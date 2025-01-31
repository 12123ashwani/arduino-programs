#include <Keypad.h>
#define NO_KEY '\0'

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {33, 32, 35, 34}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {25, 26, 27, 13}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char key_val = 'X';

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad Ready");
  pinMode(15, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) { // Only process if a key is actually pressed
    key_val = key;
    if (key_val == '1') {
      digitalWrite(15, HIGH);
      Serial.println("Key 1 is pressed");
    } else {
      digitalWrite(15, LOW);
      Serial.println(key);
    }
  } 
}
