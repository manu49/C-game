#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

void clear(int l)
{
	gotoxy(1,l);
	for(int i=1;i<80;++i)
		cout<<" ";
}

int search(int A[],int size,int z)
{
 for(int i=0;i<size;i++)
 if(fabs(A[i]-z)<10)
 {
  return 1;
 }
 return 0;
}

void main()
{
 char name[20];
 cout<<"enter your name"<<endl;
 gets(name);

 clrscr();
 int driver=DETECT,gmode;
 initgraph(&driver,&gmode,"C:\\turboc++\\disk\\turboc3\\bgi");
 setcolor(4);
 line(0,300,630,300);
 randomize();

 int x=0;
 int A[1000];
 int i=0;
 while(x<630)
 {
  int y=random(30)+1;
  setcolor(random(10));
  line(x,300,x,250);
  x+=y;
  A[i++]=x++;
 }

 x=0;i=0;
 while(x<80)
 {
  clear(18);
  gotoxy(x,18);
  puts(name);
  delay(2000);

  if(kbhit())
	switch(getch())
	{
	 case 27: abort();
	 default: x+=5;
	}
  else if(search(A,1000,x/8))
   {
    cout<<"GAME OVER";
    break;
   }
   else
   x++;

  }


  if(x>=80)
  cout<<"successful game";
   getch();
   clrscr();

}








