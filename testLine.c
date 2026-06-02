#include <stdio.h>
#include "../turtlec.h"

void fractalArbol(Turtle *t, float l, int p, float a, float t1, float t2){
  if(p == 0 || l < 5)
    return;
  
  if(p >= 5)
    turtleSetColor(t, 120, 70, 20);
  else if(2 < p)
    turtleSetColor(t, 0, 200, 0);
  else
    turtleSetColor(t, 100, 200, 50);
  
  turtleForward(t, l);

  turtleLeft(t, a);
  fractalArbol(t, l * t1, p - 1, a);

  turtleRight(t, a);
  fractalArbol(t, l * (t1 + t2)/2.0, p - 1, a);

  turtleRight(t, a);
  fractalArbol(t, l * t2, p - 1, a);

  turtleLeft(t, a);
  turtleBackward(t, l);
}

int main(void){
  TurtleApp *app = turtleAppCreate(800, 800, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);
  turtleLeft(t, 90.0);
  fractalArbol(t, 80.0f, 5, 60.0, 0.5, 0.6);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
