#include "temp.h"

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
    
    delay(60);

  }

}
