// Real-C
#include "ENGINE.hpp"

#include "globals.h"

MEMBER int Q4ID;

TRIGGER( creation )()
{
  if(!getCompileFlag(0x01))
  {
    if(getNotoriety(this) < 0x00)
    {
      setNotoriety(this, 0x00);
      Q4ID = 0x01;
      callback(this, 0x01, 0x76);
    }
    else
    {
      if(getNotoriety(this) > 0x00)
      {
        setNotoriety(this, 0x00);
        Q4ID = 0x00;
        callback(this, 0x01, 0x76);
      }
    }
  }
  else
  {
    if(getFameLevel(this) < 0x00)
    {
      setFame(this, 0x00);
      Q4ID = 0x01;
      callback(this, 0x01, 0x76);
    }
    else
    {
      if(getFameLevel(this) > 0x00)
      {
        setFame(this, 0x00);
        Q4ID = 0x00;
        callback(this, 0x01, 0x76);
      }
    }
  }
  return(0x01);
}

TRIGGER( callback , 0x76 )()
{
  if(Q4ID)
  {
    barkTo(this, this, "You have been granted amnesty for your crimes.  --Lord British.");
  }
  else
  {
    barkTo(this, this, "Let no good deed go unpunished!  --Lord Blackthorn");
  }
  return(0x01);
}