// UOSL (native)
inherits nrgyboltbase;

trigger use
{
  Q4M9(this, user);
  return(0x00);
}

trigger message("castspell")
{
  obj user = Q4BB(this, args);
  if(!isValid(user))
  {
    return(0x00);
  }
  if(isMobile(this))
  {
    return(0x01);
  }
  Q5RD(user, this);
  Q4WO(user, this);
  return(0x00);
}

trigger targetobj
{
  if(!Q4C8(user, this))
  {
    return(0x01);
  }
  if(usedon == NULL())
  {
    return(0x00);
  }
  if(Q5UM(user, usedon, 0x0C))
  {
    if(!Q5YC(user, this))
    {
      return(0x00);
    }
    if(Q4LT(user, getLocation(usedon), this))
    {
      if(hasScript(usedon, "reflctor"))
      {
        doMobAnimation(usedon, 0x37B9, 0x0A, 0x05, 0x00, 0x00);
        Q4JO(usedon, user, 0x01);
        detachScript(usedon, "reflctor");
      }
      else
      {
        Q4JO(user, usedon, 0x00);
      }
    }
    else
    {
      Q4RD(user);
    }
  }
  return(0x00);
}

trigger creation
{
  return(0x00);
}

trigger callback(0x49)
{
  obj user = getObjVar(this, "user");
  obj target = getObjVar(this, "target");
  if(Q41X(user, target))
  {
    Q4JO(target, user, 0x01);
    Q5MF(target);
  }
  else
  {
    Q4JO(user, target, 0x00);
  }
  return(0x00);
}