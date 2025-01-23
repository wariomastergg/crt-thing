#include <TVout.h>




//double* x_rot( double x, double y, double z, double a){
//   double* s = (double*) malloc(3 * sizeof(double));
//   s[0] = x;
//   s[1] = y*cos(a)+z*sin(a);
//   s[2] = -y*sin(a)+z*cos(a);
//   return s;
//}

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

//double* y_rot( double x, double y, double z, double a){
//   double s[] = { x*cos(a)+z*sin(a), y, -x*sin(a)+z*cos(a)};
//  return s;
//}
//
//double* z_rot( double x, double y, double z, double a){
//  double s[] = { x*cos(a)+y*sin(a), -x*sin(a)+y*cos(a), z};
//  return s;
//}


//static double* x_rot( double x, double x,  double a){
//   double s[] = { 
//    p[0],
//    (p[1]*cos(a)) + (p[2]*sin(a)),
//    (-p[1]*sin(a)) + (p[2]*cos(a))
//    };
//   return s;
//}

//double* y_rot( double p[3], double a){
//   double s[] = { 
//    p[0]*cos(a)+p[2]*sin(a),
//    p[1],
//    -p[0]*sin(a)+p[2]*cos(a)
//    };
//  return s;
//}
//
//double* z_rot( double p[3], double a){
//  double s[] = { 
//    p[0]*cos(a)+p[1]*sin(a),
//    -p[0]*sin(a)+p[1]*cos(a),
//    p[2]
//    };
//  return s;
//}


int w = 105;
int h = 60;
TVout TV;

//void set_pixel(int x, int y){
//  TV.set_pixel(x, y + 10 ,0x60 );
//}

void setup() {
  TV.begin(_NTSC,112,80);
  TV.select_font(font6x8);
  Serial.begin(9600);
  Serial1.begin(9600);
  }


// crt origin is 0, 10
// crt bottom right is is 105, 70
//full range (0,0) -> (104,60)


double b = 0.0;
double c = 1.0;
double g = 0.0;
double dis = 0.3;
bool spin = false;
int key = 0;
bool pressed = false;
void loop() {

  if (Serial1.available() > 0){
    key = Serial1.read();
    pressed = true;
  }
  if (pressed){
    Serial.println(key);
    pressed = false;
  }
  

if (spin){
  b += .057;
  c += .05;
  g += .07;
  if (key == 104){
  spin = false;
}
}
else
{

if (key == 97){
  b += .17;
}
else if (key == 100){
  b -= .17;
}
else if (key == 51){
  c += .17;
}
else if (key == 99){
  c -= .17;
}
else if (key == 104){
  spin = true;
}
}
key = 0;
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
  s[2] += 5.0;
  //z_rot(s, g, s);
  vert_2d[i][0] = round(       ( (s[1])/(s[2]*dis+1) )*15       )+50;
  vert_2d[i][1] = round(       ( (s[0])/(s[2]*dis+1) )*15       )+34;
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
