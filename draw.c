#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"


void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //function that takes care of all drawing cases
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  if (x0 > x1){//perform a swap
    int holdx = x0;
    int holdy = y0;
    x0 = x1;
    y0 = y1;
    x1 = holdx;
    y1 = holdy;
  }
  if (y0 <= y1){//Q1, Q2
    if (dx > dy){//Q1
      draw_line1(x0,y0,x1,y1,s,c);
    }else{//Q2
      draw_line2(x0,y0,x1,y1,s,c);
    }
  }else{//Q7, Q8
    if (dx > dy){//Q8
      draw_line8(x0,y0,x1,y1,s,c);
    }else{//Q7
      draw_line7(x0,y0,x1,y1,s,c);
    }
  }
}

void draw_line1(int x0, int y0, int x1, int y1, screen s, color c) {
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

void draw_line2(int x0, int y0, int x1, int y1, screen s, color c) {
  //d = A + 2B
  int a = y1 - y0;
  int b = x0 - x1;
  int x = x0;
  int y = y0;
  int d = a + (2 * b);

  while (y <= y1){
    plot(s,c,x,y);
    if (d < 0){
      x++;
      d += 2 * a;
    }
    y++;
    d += 2 * b;
  }
}

void draw_line7(int x0, int y0, int x1, int y1, screen s, color c) {
  //d = A - 2B;
  //should be the same as the one that is alwys incremented
  //fix while loop statement to allow for vertical horizontal lines on all
  int a = y1 - y0;
  int b = x0 - x1;
  int x = x0;
  int y = y0;
  int d = a - (2 * b);

  while (y >= y1){
    plot(s,c,x,y);
    if (d > 0){
      x++;
      d += 2 * a;
    }
    y--;
    d -= 2 * b;
  }
}

void draw_line8(int x0, int y0, int x1, int y1, screen s, color c) {
  //d = 2A - B
  int a = y1 - y0;
  int b = x0 - x1;
  int x = x0;
  int y = y0;
  int d = (2 * a) - b;

  while (y >= y1){
    plot(s,c,x,y);
    if (d < 0){
      y--;
      d -= 2 * b;
    }
    x++;
    d += 2 * a;
  }
}


//Redundant Functions -------------------
/*

void draw_line3(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = x0 - x1;
  int x = x0;
  int y = y0;
  int d = (2 * a) + b;

  while (y <= y1){
    plot(s,c,x,y);
    if (d < 0){
      x--;
      d += 2 * a;
    }
    y++;
    d -= 2 * b;
  }
}

void draw_line4(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = x0 - x1;
  int x = x0;
  int y = y0;
  int d = (2 * a) + b;

  while (y <= y1){
    plot(s,c,x,y);
    if (d < 0){
      y++;
      d += 2 * b;
    }
    x--;
    d -= 2 * a;
  }
}

void draw_line5(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = x0 - x1;
  int x = x0;
  int y = y0;
  int d = (2 * a) + b;

  while (y >= y1){
    plot(s,c,x,y);
    if (d > 0){
      y--;
      d -= 2 * b;
    }
    x--;
    d -= 2 * a;
  }
}

void draw_line6(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = x0 - x1;
  int x = x0;
  int y = y0;
  int d = (2 * a) + b;

  while (y >= y1){
    plot(s,c,x,y);
    if (d < 0){
      x--;
      d -= 2 * a;
    }
    y--;
    d -= 2 * b;
  }
}
*/
