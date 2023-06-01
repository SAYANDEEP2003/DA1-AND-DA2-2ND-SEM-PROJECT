#include <graphics.h>
#include <iostream>

const int screenWidth = 650;
const int screenHeight = 500;


void cloud(int c1, int c2, int radius)
{
    int x=c1;
    int y=c2;
    int r = radius;
    
    setcolor(WHITE);
    circle(x,y,r);
    setfillstyle(1,15);
    floodfill(x,y,15);

    setcolor(WHITE);
    circle(x+r,y-r,1.25*r);
    setfillstyle(1,15);
    floodfill(x+r,y-r,15);


    setcolor(WHITE);
    ellipse(x+1.5*r,y,0,360,2*r,r);
    setfillstyle(1,15);
    floodfill(x+1.5*r,y,15);
    floodfill(x+2*r,y+0.5*r,15);


}



void moveBirdAndPillars() {
   
    
    setcolor(15);
    bar(0,0,650,500);

    int y = 150;


        cleardevice();

        cloud(50, 100, 20);
        cloud(450, 100, 20);
        cloud(100, 300, 20);
        cloud(500, 300, 20);





                                    // Bird
         // Body
        setcolor(WHITE);
        line(250, y, 290, y);
        arc(270, y, 180, 360, 20);
        setfillstyle(1,14);
        floodfill(251,y+1,15);

        // Head
        setcolor(WHITE);
        circle(295, y, 8);
        setfillstyle(1,14);
        floodfill(291,y,15);

         // Eye
        setcolor(WHITE);
        circle(298, y-3, 3);
        setfillstyle(1,0);
        floodfill(298,y-3,15);


         // Wing
        setcolor(WHITE);
        arc(270, y, 180, 360, 15);
        setfillstyle(1,0);
        floodfill(276,y+1,15);

       
        // Beak
        setcolor(WHITE);
        line(299, y-3 , 310, y);
        line(301, 3+ y, 310, y);
        setfillstyle(1,4);
        floodfill(304,y,15);


       

        // Tail
        setcolor(WHITE);
        line(230, y - 15, 250, y);
        line(230, y - 15, 232, y - 5);
        line(232, y - 5, 250, y);
        setfillstyle(1,4);
        floodfill(234,y-5,15);




        setfillstyle(1,6);
        
        bar(250, 0, 300, 100);
        bar(250, 250, 300, 500);
        bar(550, 0, 600, 200);
        bar(550, 350, 600, 500);
        bar(0, 0, 50,200);
        bar(0, 350, 50, 500);

      
    }

   


int main() {
   
     initwindow(screenWidth, screenHeight, "Moving Bird and Pillars");
    setbkcolor(11);
    
    

    moveBirdAndPillars();

    getch();

    closegraph();

    return 0;
}
