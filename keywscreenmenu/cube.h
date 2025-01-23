#ifndef CUBE_H
#define CUBE_H
#include <Arduino.h>
#include <TVout.h>

void x_rot( double* p, double a, double* nwpt);
void y_rot( double* p, double a, double* nwpt);
void z_rot( double* p, double a, double* nwpt);

void cube(TVout TV);

#endif