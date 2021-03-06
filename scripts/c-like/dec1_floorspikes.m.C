// Real-C
#include "ENGINE.hpp"

#include "globals.h"

TRIGGER( creation )()
{
  setType(this, 0x11A1);
  return(0x00);
}

TRIGGER( enterrange , 0x00 )(obj target)
{
  list Q5DQ;
  if(!hasObjVar(this, "disarmed"))
  {
    loseHP(target, dice(0x14, 0x05));
  }
  return(0x01);
}

TRIGGER( message , "fs_disarm" )(obj sender, list args)
{
  int Q5DQ;
  if(!hasObjVar(this, "disarmed"))
  {
    setType(this, 0x11A0);
    setObjVar(this, "disarmed", Q5DQ);
  }
  return(0x00);
}

TRIGGER( message , "fs_reload" )(obj sender, list args)
{
  int Q5DQ;
  if(hasObjVar(this, "disarmed"))
  {
    setType(this, 0x11A1);
    removeObjVar(this, "disarmed");
  }
  return(0x00);
}