// Real-C
#include "ENGINE.hpp"

FUNCTION int Q4ZO(obj Q68S)
{
  list Q5A8;
  int Q5NC = messageret(this, Q68S, "spellcanstartcast", Q5A8);
  return(Q5NC);
}

FUNCTION int Q49T(obj Q68S, obj Q67Y)
{
  return(hasObjEquipped(Q68S, Q67Y));
}

FUNCTION int Q49S(obj Q68S, obj Q67Y)
{
  if(hasObjEquipped(Q68S, Q67Y))
  {
    if(Q4ZO(Q68S))
    {
      return(0x01);
    }
  }
  return(0x00);
}

FUNCTION void Q5VL(obj user)
{
  list Q5A8;
  attachScript(user, "spellwords");
  message(user, "spellstartcast", Q5A8);
  return;
}

TRIGGER( use )(obj user)
{
  if(Q49S(user, this))
  {
    Q5VL(user);
  }
  return(0x01);
}