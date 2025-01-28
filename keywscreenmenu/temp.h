#ifndef TEMP_H
#define TEMP_H
#include <Arduino.h>
#include <TVout.h>
void print_str(TVout TV, int x, int y, String s, bool cent = false);
void temp(TVout TV);

#endif