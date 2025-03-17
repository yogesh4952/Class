#include <SDL2/SDL.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

// Region codes
#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

int computeCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = INSIDE;

    if (x < xmin)       code |= LEFT;
    else if (x > xmax)  code |= RIGHT;
    if (y < ymin)       code |= BOTTOM;
    else if (y > ymax)  code |= TOP;

    return code;
}

void cohenSutherlandClipAndDraw(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int code_out;
            int x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            float slope = (x2 - x1) != 0 ? (float)(y2 - y1) / (x2 - x1) : 1e9;

            if (code_out & TOP) {
                x = x1 + (int)((ymax - y1) / slope);
                y = ymax;
            } else if (code_out & BOTTOM) {
                x = x1 + (int)((ymin - y1) / slope);
                y = ymin;
            } else if (code_out & RIGHT) {
                y = y1 + (int)(slope * (xmax - x1));
                x = xmax;
            } else if (code_out & LEFT) {
                y = y1 + (int)(slope * (xmin - x1));
                x = xmin;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red clipped line
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Cohen-Sutherland Line Clipping - SDL2",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window creation failed! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int xmin, ymin, xmax, ymax;
    int x1, y1, x2, y2;

    printf("Enter Clipping Window (Xmin Ymin): ");
    scanf("%d %d", &xmin, &ymin);
    printf("Enter Clipping Window (Xmax Ymax): ");
    scanf("%d %d", &xmax, &ymax);
    printf("Enter Line Start Point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter Line End Point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw Clipping Rectangle (White)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect clipRect = { xmin, ymin, xmax - xmin, ymax - ymin };
    SDL_RenderDrawRect(renderer, &clipRect);

    // Draw Original Line (Green)
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

    // Perform Clipping and draw red line
    cohenSutherlandClipAndDraw(renderer, x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    SDL_RenderPresent(renderer);

    // Wait until window is closed
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = 1;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
