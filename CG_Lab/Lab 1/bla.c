#include <SDL2/SDL.h>
#include <stdio.h>

void drawline(SDL_Renderer *renderer, int x0, int y0, int x1, int y1)
{
  int dx = x1 - x0;
  int dy = y1 - y0;
  int x = x0, y = y0;
  int p = 2 * dy - dx;

  while (x <= x1)
  {
    SDL_RenderDrawPoint(renderer, x, y);

    if (p >= 0)
    {
      y++;
      p += 2 * dy - 2 * dx;
    }
    else
    {
      p += 2 * dy;
    }
    x++;
  }
}

int main()
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window
  SDL_Window *window = SDL_CreateWindow(
      "Bresenham's Line Drawing",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      800, 600,
      SDL_WINDOW_SHOWN);

  if (!window)
  {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // Create a renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer)
  {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Clear the screen
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  // Set drawing color to white
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

  // Input coordinates
  int x0, y0, x1, y1;
  printf("Enter coordinates of the first point (x0 y0): ");
  scanf("%d %d", &x0, &y0);
  printf("Enter coordinates of the second point (x1 y1): ");
  scanf("%d %d", &x1, &y1);

  // Draw the line
  drawline(renderer, x0, y0, x1, y1);

  // Present the rendered content
  SDL_RenderPresent(renderer);

  // Wait before exiting
  printf("Press any key to exit...\n");
  getchar(); // Wait for newline after scanf
  getchar(); // Wait for user input to close the program

  // Clean up
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
