#include "temp.h"

void print_str(TVout TV, int x, int y, String s, bool cent = false){
  
  for (int i = 0; i < s.length(); i++){
    TV.print_char(x+(i*4)-(cent*s.length()*2),y-(cent*3),s[i]);
  }
}

void temp(TVout TV){

  int key = -1;
  bool pressed = false;
  while (key != 111) {
    if (Serial1.available() > 0){
        key = Serial1.read();
        pressed = true;
      }
      if (pressed){
        Serial.println(key);
        switch(key){
          case 100:
            break;
        }
        pressed = false;
      }

    TV.clear_screen();
    print_str(TV, 64, 48, String(analogRead(A0)), true);
    delay(60);

  }

}
