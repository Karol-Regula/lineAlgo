#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  int a = y1 - y0;
  int b = x0 - x1;
  int x = x0;
  int y = y0;
  int d = (2 * a) + b;
  
  while (x <= x1){
    plot(s,c,x,y);
    if (d > 0){
      y++;
      d += 2 * b;
    }
    x++;
    d+= 2 * a;
  }

}
