#include<stdio.h>

#include<graphics.h>
#include<math.h>

int main()
{
  clrscr();
  int x0,y0,x1,y1,i=0;
  float delx,dely,len,x,y;
  int gr = DETECT, gm;
  initgraph(&gr,&gm,NULL);
  printf("\n******** DDA Line Drawing Algorithm **********");
  printf("\n Please enter the starting coordinate of x,y = ");
  scanf("%d%d", &x0,&y0);

  dely = abs(y1-y0);
  delx = abs(x1-x0);
  if(delx<dely){
	len = dely;
  }else {
    len = delx;
  }
  delx = (x1-x0)/len;
  dely = (y1-y0)/len;

  x = x0 + 0.5;
  y = y0 + 0.5;

  do{
   putpixel(x,y,3);
   x = x + delx;
   y = y + dely;
   i++;
   delay(30);

  } while(i<=len);
  getch();
  closegraph();

  return 0;

}
