#ifndef PROGRAMS_H
#define PROGRAMS_H
#include <Arduino.h>
#include <TVout.h>
#include "cube.h"
#include "temp.h"

int getNTitles();
String getTitles(int i);

void ProgramChoice(int p, TVout TV);

#endif