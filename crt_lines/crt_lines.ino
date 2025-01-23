#include <TVout.h>


double* x_rot( double x, double y, double z, double a){
   double s[] = { x, y*cos(a)+z*sin(a), -y*sin(a)+z*cos(a)};
   return s;
}

double* y_rot( double x, double y, double z, double a){
   double s[] = { x*cos(a)+z*sin(a), y, -x*sin(a)+z*cos(a)};
  return s;
}

double* z_rot( double x, double y, double z, double a){
  double s[] = { x*cos(a)+y*sin(a), -x*sin(a)+y*cos(a), z};
  return s;
}


int w = 105;
int h = 60;
TVout TV;

//void set_pixel(int x, int y){
//  TV.set_pixel(x, y + 10 ,0x60 );
//}

void setup() {TV.begin(_NTSC,112,80);
Serial.begin(9600);}


// crt origin is 0, 10
// crt bottom right is is 105, 70
//full range (0,0) -> (104,60)


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
double b = 0.0;
double c = 1.0;
bool spin = true;

void loop() {



b += .057;
c += .05;

for (int i = 0; i < 8; i++){
  //get vertex
  double x = vert[i][0];
  double y = vert[i][1];
  double z = vert[i][2];

  //get distance from origin
  double d = sqrt( (x*x) + (y*y) );

  //get angle from origin
  double ang = asin( (x / d) );
  if ( y <= 0 ){ang = -ang+3.14159;}

  vert_2d[i][0] = ceil(       (sin(ang+b)*d*15)        )+55;
  vert_2d[i][1] = ceil(       (cos(ang+b)*d*15)*sin(c)+(cos(c)*z*15)       )+40;
  //Serial.println(x/d);

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
//delay(60);

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
