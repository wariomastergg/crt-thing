/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>

const byte ROWS = 6; //four rows
const byte COLS = 7; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3','4','5','6'},
  {'7','8','9','a','b','c','d'},
  {'e','f','g','h','i','j','k'},
  {'l','m','n','o','p','q','r'},
  {'s','t','u','v','w','x','y'},
  {'z','A','B','C','D','E','F'},
};
byte rowPins[ROWS] = {12, 11, 10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {14, 15, 16, 17, 18, 19, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);

}
char a = 'a';
bool send = false;
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    a = customKey;
    send = true;
  }
  if (send){
    Serial.print(a);
    send = false;
  }
  
}
