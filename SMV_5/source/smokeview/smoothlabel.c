// $Date: 2007-10-07 22:08:47 -0400 (Sun, 07 Oct 2007) $ 
// $Revision: 800 $
// $Author: gforney $

#include "options.h"
#include <stdio.h>
#include <math.h>

// svn revision character string
char smoothlabel_revision[]="$Revision: 800 $";

void smoothlabel(float *a, float *b, int n){
  float delta, factor, logdelta;
  int ndigits;

  delta = (*b-*a)/(n-2);
  if(delta==0.0)return;
  logdelta = log10((double)delta);
  ndigits=logdelta-1;
  if(logdelta<=1)ndigits--;
  factor = 5*pow(10,ndigits);
  delta = (int)(delta/factor + 0.5f)*factor;

  *a = factor*(int)(*a/factor+0.5f);
  *b = *a + (n-2)*delta;

}

