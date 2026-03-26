#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x = 50, y = 200, radius = 30;
    int dx = 5, dy = 5;

    while (!kbhit())
    {
        cleardevice();

        // Draw circlels
        circle(x, y, radius);

        // Update position
        x += dx;
        y += dy;

        // Boundary collision detection
        if (x + radius >= getmaxx() || x - radius <= 0)
            dx = -dx;
        if (y + radius >= getmaxy() || y - radius <= 0)
            dy = -dy;

        delay(30);
    }

    getch();
    closegraph();
    return 0;
}