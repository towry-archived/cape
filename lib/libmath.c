#include "interpreter.h"
#include <math.h>

int 
MathSin(int args)
{
  float angle = 0.0;
  float ret = 0.0;

  Object val = env_lookup('angle');

  angle =  val.value.f;
  ret = sin(angle);

  return 0;
}
