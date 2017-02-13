#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;


  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  draw_line(0,0,150,100,s,c);
  draw_line(0,0,150,50,s,c);
  draw_line(0,0,150,15,s,c);
  draw_line(200,200,450,450,s,c);

  display(s);
  save_extension(s, "lines.png");
}
