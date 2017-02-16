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

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = 0;

  //square
  draw_line(100,100,400,100,s,c);
  draw_line(100,400,400,400,s,c);
  draw_line(100,100,100,400,s,c);
  draw_line(400,100,400,400,s,c);

  //right side in octants
  draw_line(250,250,500,400,s,c);
  draw_line(250,250,400,500,s,c);
  draw_line(250,250,100,500,s,c);
  draw_line(250,250,0,400,s,c);

  //left side in octant
  draw_line(250,250,0,100,s,c);
  draw_line(250,250,100,0,s,c);
  draw_line(250,250,400,0,s,c);
  draw_line(250,250,500,100,s,c);

  //diagonal lines
  draw_line(250,250,0,0,s,c);
  draw_line(250,250,500,0,s,c);
  draw_line(250,250,500,500,s,c);
  draw_line(250,250,0,500,s,c);

  //vertical lines for good measure
  draw_line(250,250,250,0,s,c);
  draw_line(250,250,250,500,s,c);
  draw_line(250,250,0,250,s,c);
  draw_line(250,250,500,250,s,c);


  //fun test code
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int m = 0;

  for (int i; i < 0; i+=10){
    j = rand() % 500;
    k = rand() % 500;
    l = rand() % 500;
    m = rand() % 500;
    draw_line(j,k,l,m,s,c);
  }


  /*
  draw_line1(0,0,150,100,s,c);
  draw_line1(0,0,150,50,s,c);
  draw_line1(0,0,150,15,s,c);
  draw_line1(200,200,450,450,s,c);
  draw_line2(50,50,100,400,s,c);
  draw_line2(350,10,400,450,s,c);
  draw_line2(250,10,400,450,s,c);

  -----
  draw_line1(100,100,400,100,s,c);
  draw_line1(100,400,400,400,s,c);
  draw_line2(100,100,100,400,s,c);
  draw_line2(400,100,400,400,s,c);

  draw_line1(250,250,500,400,s,c);
  draw_line2(250,250,400,500,s,c);
  draw_line3(250,250,100,500,s,c);
  draw_line4(250,250,0,400,s,c);

  draw_line5(250,250,0,100,s,c);
  draw_line6(250,250,100,0,s,c);
  draw_line7(250,250,400,0,s,c);
  draw_line8(250,250,500,100,s,c);
  */

  display(s);
  save_extension(s, "lines.png");
}
