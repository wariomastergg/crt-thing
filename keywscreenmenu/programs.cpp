#include "programs.h"

const int ntitles = 2;

//put the titles of your pgm here
String titles[ntitles] = {
  "cube",
  "temp",
};

int getNTitles(){
  return ntitles;
}

String getTitles(int i){
  return titles[i];
}

void ProgramChoice(int p, TVout TV){
  switch(p){
    case 0:
      cube(TV);
      break;
    case 1:
      temp(TV);
      break;


  }
}
