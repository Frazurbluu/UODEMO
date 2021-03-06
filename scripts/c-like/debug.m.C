// Real-C
#include "ENGINE.hpp"

#include "globals.h"

TRIGGER( targetobj )(obj user, obj usedon)
{
  if(!isEditing(user))
  {
    return(0x01);
  }
  if(usedon == NULL())
  {
    return(0x00);
  }
  setObjVar(usedon, "debugger", user);
  return(0x00);
}

TRIGGER( use )(obj user)
{
  if(!isEditing(user))
  {
    return(0x01);
  }
  systemMessage(user, "Select object to debug:");
  targetObj(user, this);
  return(0x00);
}