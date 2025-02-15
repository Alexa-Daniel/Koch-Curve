#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include "graphics2.h"

using namespace std;

void koch(int it,int x1,int y1,int x5,int y5);
int culori[]={1,2,3,4,5,14};
int nrculori,nrliniute=100;

int main()
{
    int it;
    int driver,mod;

    cout<<"Enter Number Of Iterations : "<<endl;
    cin>>it;

    for(int i=0;;i++)
    {
        if(culori[i]==0)
            break;
        else
            nrculori++;
    }

    initgraph(&driver,&mod,"",1920,1080);
    ///curba lui koch
    koch(it,40,280,280,40);
    ///snowflake
    /*
    koch(it,300,40,40,560);
    koch(it,40,560,560,560);
    koch(it,560,560,300,40);
    */

    ///patrat
    /*koch(it,40,40,560,40);
    koch(it,560,40,560,560);
    koch(it,560,560,40,560);
    koch(it,40,560,40,40);
    */

    ///triunghiul de verif
    /*
    koch(0,300,40,40,560);
    koch(0,40,560,560,560);
    koch(0,560,560,300,40);
    */

    getch();
    closegraph();

    return 0;
}
int cnt=0,cnt2=0;
void koch(int it,int x1,int y1,int x5,int y5)
{

    int x2,y2,x3,y3,x4,y4;

    float angle=60*M_PI/180;
    ///SA SE SCHIMBE CULOAREA LA FIECARE LINIUTA
    /*
    if(cnt==nrculori)
        cnt=0;
    if(it==0)
    {
        setcolor(culori[cnt]);
        line(x1,y1,x5,y5);
        cnt++;
    }*/
    ///SA SE SCHIMBE CULOAREA LA UN ANUMIT NR DE LINIUTE
    if(cnt==nrculori)
        cnt=0;
    if(cnt2==nrliniute)
    {
        cnt++;
        cnt2=0;
    }
    if(it==0)
    {
        setcolor(culori[cnt]);
        line(x1,y1,x5,y5);
        cnt2++;
    }
    /*if(it==0)
    {
        line(x1,y1,x5,y5);
    }*/
    else
    {
        //delay(10);

        x2=(2*x1+x5)/3 ;
        y2=(2*y1+y5)/3 ;

        x4=(x1+2*x5)/3 ;
        y4=(y1+2*y5)/3 ;


        ///snowflake
        x3=(x2+(x4-x2)*cos(angle)+(y4-y2)*sin(angle));
        y3=(y2-(x4-x2)*sin(angle)+(y4-y2)*cos(angle));

        koch(it-1,x1,y1,x2,y2);
        koch(it-1,x2,y2,x3,y3);
        koch(it-1,x3,y3,x4,y4);
        koch(it-1,x4,y4,x5,y5);

        /*
        setfillstyle(1,4);
        if(x3<0)
        {
            if(y3<0)
                floodfill(x3-2,y3-2,10);
            else
                floodfill(x3-2,y3+2,10);
        }
        else
        {
            if(y3<0)
                floodfill(x3+2,y3-2,10);
            else
                floodfill(x3+2,y3+2,10);
        }*/
    }
}
