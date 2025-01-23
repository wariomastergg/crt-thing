#include "cube.h"


double vert[8][3] = {
  { 1.0, 1.0, 1.0 },
  { -1.0, 1.0, 1.0 },
  { 1.0, -1.0, 1.0 },
  { -1.0, -1.0, 1.0 },
  { 1.0, 1.0, -1.0 },
  { -1.0, 1.0, -1.0 },
  { 1.0, -1.0, -1.0 },
  { -1.0, -1.0, -1.0 },
};


int vert_2d[8][2] = {
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  
};

int edge[12][2] = {
  { 3, 7 },
  { 0, 1 },
  { 0, 2 },
  { 3, 1 },
  { 3, 2 },

  { 4, 5 },
  { 4, 6 },
  { 7, 5 },
  { 7, 6 },

  { 0, 4 },
  { 1, 5 },
  { 2, 6 },
  
};

void x_rot( double* p, double a, double* nwpt){
   nwpt[0] = p[0];
   nwpt[1] = p[1]*cos(a) + p[2]*sin(a);
   nwpt[2] = -p[1]*sin(a) + p[2]*cos(a);
}

void y_rot( double* p, double a, double* nwpt ){
   nwpt[0] = p[0]*cos(a)+p[2]*sin(a);
   nwpt[1] = p[1];
   nwpt[2] = -p[0]*sin(a)+p[2]*cos(a);
}
void z_rot( double* p, double a, double* nwpt ){
   nwpt[0] =  p[0]*cos(a)+p[1]*sin(a);
   nwpt[1] = -p[0]*sin(a)+p[1]*cos(a);
   nwpt[2] = p[2];
}
void cube(TVout TV){




//int w = 800;
//int h = 60;
//TVout TV;

//void setup() {TV.begin(_NTSC,128,96);
//Serial.begin(9600);}


double b = 0.3;
double c = 1.0;
double g = 0.0;
double dis = 2.0;
bool spin = true;
int key = 0;
bool pressed = false;
while (key != 111) {
if (Serial1.available() > 0){
    key = Serial1.read();
    pressed = true;
  }
  if (pressed){
    Serial.println(key);
    if (key == 97){dis+=.1;}
    if (key == 100){dis-=.1;}
    if (key == 49){b+=.1;}
    if (key == 50){b-=.1;}  

    pressed = false;
  }

if (spin){
  //b += .17;
  c += .1;
  g += .14;
  

//b += .057;
//c += .05;

for (int i = 0; i < 8; i++){
  //get vertex
  //double x = vert[i][0];
  //double y = vert[i][1];
  //double z = vert[i][2];
  //double s[] = { vert[i][0], vert[i][1]*cos(b)+vert[i][2]*sin(b), -vert[i][1]*sin(b)+vert[i][2]*cos(b)};
  double* s = (double*) malloc(3 * sizeof(double));
  double scale = 0.5;
  s[0]*=scale;
  s[1]*=scale;
  s[2]*=scale;
  z_rot(vert[i], g, s);
  //x_rot(vert[i], b, s);
  y_rot(s, c, s);
  //z_rot(s, g, s);
  s[2] += dis;
  //z_rot(s, g, s);
  vert_2d[i][0] = round(       ( (s[1])/(s[2]*b+1) )*10       )+64;
  vert_2d[i][1] = round(       ( (s[0])/(s[2]*b+1) )*10       )+48;
  free(s);
  //Serial.println(x_rot(vert[i],b)[1]);

}

TV.clear_screen();

for (int i = 0; i < 12; i++){
  int x1 = vert_2d[ edge[i][0] ][0];
  int y1 = vert_2d[ edge[i][0] ][1];
  int x2 = vert_2d[ edge[i][1] ][0];
  int y2 = vert_2d[ edge[i][1] ][1];
  
  if (x1 == x2){
    TV.draw_line( x1, y1, x2, y2, 0x60 );
  }
  else if (y1 == y2){
    TV.draw_line( x1, y1, x2, y2, 0x60 );
  }
  else {
    TV.draw_line( x1, y1, x2, y2, 0x60 );
  }
  //delay(10);
}

delay(60);
b = fmod(b,999.0);
c = fmod(c,999.0);
g = fmod(g,999.0);

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

}

}