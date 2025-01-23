#include <TVout.h>
#include <fontALL.h>
#include "cube.h"


int w = 128;
int h = 96;
TVout TV;


void setup() {
  TV.begin(_NTSC,w,h);
  TV.select_font(font4x6);
  Serial.begin(9600);
  Serial1.begin(9600);
  }

void print_str(int x, int y, String s, bool cent = false){
  
  for (int i = 0; i < s.length(); i++){
    TV.print_char(x+(i*4)-(cent*s.length()*2),y-(cent*3),s[i]);
  }
}

// crt origin is 0, 10
// crt bottom right is is 105, 70
//full range (0,0) -> (104,60)

int box = 20;
bool select = false;

int grid[] = {4,3};


int pos[] = {1,1};
int key = 0;
bool pressed = false;
void loop() {

  if (Serial1.available() > 0){
    key = Serial1.read();
    pressed = true;
  }
  if (pressed){
    Serial.println(key);
    
    switch(key){
      case 99:
        pos[0] += 1;
        break;
      case 51:
        pos[0] -= 1;
        break;
      case 100:
        pos[1] += 1;
        break;
      case 97:
        pos[1] -= 1;
        break;
      case 104:
        select = true;        
        break;
    }

    pressed = false;
  }

pos[0] = constrain(pos[0], 1, grid[0]);
pos[1] = constrain(pos[1], 1, grid[1]);

if (select){
  if (pos[0] == 1 && pos[1] == 1){
    cube(TV);
  } 
  select = false;
}

TV.clear_screen();

//TV.println("Arduino Analog Read Tv");
//TV.println("Arduino Analog Read Tv");
//TV.draw_rect((w/4)-(box/2),(h/4)-15,30,30,0x60);
//TV.draw_rect((w*3/4)-15,(h/4)-15,30,30,0x60);
//TV.set_pixel(0, 0, 0x60);

TV.draw_rect(((w*pos[0])/(grid[0]+1))-(box/2)-1,((h*pos[1])/(grid[1]+1))-(box/2)-1,box+2,box+2,0x60);

//TV.print_char(
//((w*1)/(grid[0]+1)),
//((h*1)/(grid[1]+1)),'B');

print_str(
((w*1)/(grid[0]+1)),
((h*1)/(grid[1]+1)), "cube", true);


for (int i = 1; i <= grid[0]; i++){
  for (int j = 1; j <= grid[1]; j++){
    TV.draw_rect(((w*i)/(grid[0]+1))-(box/2),((h*j)/(grid[1]+1))-(box/2),box,box,0x60);
//TV.draw_line( x1, y1, x2, y2, 0x60 );
  }
}
delay(60);

//for (int i = 0; i < 4; i++){
//TV.set_pixel(vert_2d[i][0], vert_2d[i][1], 0x60);
//}

//float x = 0.0;
//TV.draw_line(0,10,105,70,0x60);

//TV.draw_circle(50, 40, 15, 0x60);
//for(float i = 0.0; i <= 2*3.14159; i += .01){
//  set_pixel( round(sin(i)*15)+50, round(cos(i)*15)+30 );
//}


//TV.set_pixel(105,70 ,0x60 );
//TV.set_pixel(0,10 ,0x60 );
//TV.bitmap(10, 10, Pi);

}
