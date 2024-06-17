#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
int main()
{ int mh=0,mode=0;
  initgraph(&mh,&mode, (char*)"");
  line(23,32,34,54);
  getch();
  closegraph();
   return 0;
}