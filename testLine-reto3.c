#include <stdio.h>
#include "../turtlec.h"

void fractalArbol(Turtle *t, float l, int p, float a, float t1, float t2){
  if(p == 0 || l < 5)
    return;
  //es en este cambio donde pasa de colorear simulando un arbol a ir bajando por una escala de grises, siendo las copas de los árboles los puntos más claros
  turtleSetColor(t, (255 - ((10 * p) % 256)), (255 - ((10 * p) % 256)), (255 - ((10 * p) % 256)));
  
  turtleForward(t, l);

  turtleLeft(t, a);
  fractalArbol(t, l * t1, p - 1, a, t1, t2);

  turtleRight(t, a);
  fractalArbol(t, l * (t1 + t2)/2.0, p - 1, a, t1, t2);

  turtleRight(t, a);
  fractalArbol(t, l * t2, p - 1, a, t1, t2);

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
