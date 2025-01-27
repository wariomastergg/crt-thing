#include <TVout.h>
#include <fontALL.h>
#include "programs.h"

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

int menu2index(int p[2], int g[2]){
  return (p[0]-1) + ((p[1]-1)*g[0]);
}

// crt origin is 0, 10
// crt bottom right is is 105, 70
//full range (0,0) -> (104,60)

int box = 30;
bool select = false;

int grid[] = {3,2};


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
//keep the cursor from going out of bounds
pos[0] = constrain(pos[0], 1, grid[0]);
pos[1] = constrain(pos[1], 1, grid[1]);

if (select){
  ProgramChoice( menu2index(pos, grid), TV );
  select = false;
}

TV.clear_screen();

//draw box cursor
TV.draw_rect(((w*pos[0])/(grid[0]+1))-(box/2)-1,((h*pos[1])/(grid[1]+1))-(box/2)-1,box+2,box+2,0x60);
//draw boxes and titles
for (int i = 1; i <= grid[0]; i++){
  for (int j = 1; j <= grid[1]; j++){
    int bx[2] = {i,j};
    int dex = menu2index(bx, grid);
    TV.draw_rect(((w*i)/(grid[0]+1))-(box/2),((h*j)/(grid[1]+1))-(box/2),box,box,0x60);
    if (dex < getNTitles()){
      print_str(
      ((w*i)/(grid[0]+1)),
      ((h*j)/(grid[1]+1)),
      getTitles(dex),
      true);
    }
  }
}
delay(60);
}
