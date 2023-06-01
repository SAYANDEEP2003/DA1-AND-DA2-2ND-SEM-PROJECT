#include <graphics.h>
#include <iostream>

const int screenWidth = 650;
const int screenHeight = 500;

void cloud(int c1, int c2, int radius)
{
    int x = c1;
    int y = c2;
    int r = radius;

    setcolor(WHITE);
    circle(x, y, r);
    setfillstyle(1, 15);
    floodfill(x, y, 15);

    setcolor(WHITE);
    circle(x + r, y - r, 1.25 * r);
    setfillstyle(1, 15);
    floodfill(x + r, y - r, 15);

    setcolor(WHITE);
    ellipse(x + 1.5 * r, y, 0, 360, 2 * r, r);
    setfillstyle(1, 15);
    floodfill(x + 1.5 * r, y, 15);
    floodfill(x + 2 * r, y + 0.5 * r, 15);
}

void moveBirdAndPillars()
{
    setcolor(15);
    bar(0, 0, screenWidth, screenHeight);
    // Cloud properties
    int cloudX1 = screenWidth + 100;
    int cloudX2 = screenWidth + 500;
    int cloudX3 = screenWidth + 200;
    int cloudX4 = screenWidth + 600;
    int speed = 2;
    // Bird properties
    int y = 0;
    int direction = 10;
    // Pillar properties
    int pillarWidth = 75;
    int pillarGap = 300;
    int tunnelWidth = 150;
    int pillarSpeed = 3.2;
    int pillar1X = 650;
    int pillar2X = pillar1X + pillarWidth + pillarGap;
    int pillarHeight = getmaxy();
    int page = 0;
    while (true)
    {
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();
        // Cloud algorithm
        cloudX1 -= speed;
        cloudX2 -= speed;
        cloudX3 -= speed;
        cloudX4 -= speed;
        if (cloudX1 + 20 <= 0)
        {
            cloudX1 = screenWidth + 50;
        }
        if (cloudX2 + 20 <= 0)
        {
            cloudX2 = screenWidth + 50;
        }
        if (cloudX3 + 20 <= 0)
        {
            cloudX3 = screenWidth + 200;
        }
        if (cloudX4 + 20 <= 0)
        {
            cloudX4 = screenWidth + 600;
        }

        cloud(cloudX1, 100, 20);
        cloud(cloudX2, 100, 20);
        cloud(cloudX3, 300, 20);
        cloud(cloudX4, 300, 20);

        // Bird
        // Body
        setcolor(WHITE);
        line(250, y, 290, y);
        arc(270, y, 180, 360, 20);
        setfillstyle(1, 14);
        floodfill(251, y + 1, 15);

        // Head
        setcolor(WHITE);
        circle(295, y, 8);
        setfillstyle(1, 14);
        floodfill(291, y, 15);

        // Eye
        setcolor(WHITE);
        circle(298, y - 3, 3);
        setfillstyle(1, 0);
        floodfill(298, y - 3, 15);

        // Wings
        setcolor(WHITE);
        setfillstyle(1, 0);
        // Clipping area for the wings
        rectangle(258, y - 10, 292, y + 20);
        floodfill(275, y, 15);

        // Beak
        setcolor(WHITE);
        line(299, y - 3, 310, y);
        line(301, 3 + y, 310, y);
        setfillstyle(1, 4);
        floodfill(304, y, 15);

        // Tail
        setcolor(WHITE);
        line(230, y - 15, 250, y);
        line(230, y - 15, 232, y - 5);
        line(232, y - 5, 250, y);
        setfillstyle(1, 4);
        floodfill(234, y - 5, 15);

        // Pillars
        pillar1X -= pillarSpeed;
        pillar2X -= pillarSpeed;

        if (pillar1X + pillarWidth < 0)
        {
            pillar1X = 650;
        }
        if (pillar2X + pillarWidth < 0)
        {
            pillar2X = 650;
        }
        // Algorithm for collision
        int birdLeft = 265;
        int birdRight = 305;
        int birdTop = y - 20;
        int birdBottom = y + 25;
        int pillar1Left = pillar1X;
        int pillar1Right = pillar1X + pillarWidth;
        int pillar1Top = 0;
        int pillar1Bottom = 100;
        int pillar2Left = pillar2X;
        int pillar2Right = pillar2X + pillarWidth;
        int pillar2Top = 200;
        int pillar2Bottom = 500;
        if ((birdRight >= pillar1Left && birdLeft <= pillar1Right) &&
            ((birdTop <= pillar1Bottom && birdBottom >= pillar1Top) || (birdTop <= pillar2Bottom && birdBottom >= pillar2Top)))
        {
            // Bird collided with down pillar
            direction = -2;
        }
        if ((birdRight >= pillar2Left && birdLeft <= pillar2Right) &&
            (birdTop <= pillar2Bottom && birdBottom >= pillar2Top))
        {
            // Bird collided with up pillar
            direction = -2;
        }
        setfillstyle(1, 6);
        bar(pillar1X, 0, pillar1X + pillarWidth, 100);
        bar(pillar1X, 250, pillar1X + pillarWidth, 500);
        bar(pillar2X, 0, pillar2X + pillarWidth, 200);
        bar(pillar2X, 350, pillar2X + pillarWidth, 500);
        delay(10);
        y += direction;
        if (y <= 150)
        {
            direction = 2;
        }
        else if (y >= 350)
        {
            direction = -2;
        }

        page = 1 - page;
    }
}

int main()
{
    initwindow(screenWidth, screenHeight, "Moving Bird and Pillars");
    setbkcolor(11);

    moveBirdAndPillars();
    return 0;
}