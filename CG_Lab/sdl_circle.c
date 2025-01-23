#include <SDL2/SDL.h>
#include <stdio.h>

void drawCircle(SDL_Renderer *renderer, int x_center, int y_center, int radius)
{
  int x = radius;
  int y = 0;
  int err = 1 - radius;

  // Draw the initial points
  SDL_RenderDrawPoint(renderer, x_center + x, y_center - y);
  SDL_RenderDrawPoint(renderer, x_center - x, y_center - y);
  SDL_RenderDrawPoint(renderer, x_center + y, y_center + x);
  SDL_RenderDrawPoint(renderer, x_center - y, y_center + x);

  if (radius > 0)
  {
    SDL_RenderDrawPoint(renderer, x_center - x, y_center + y);
    SDL_RenderDrawPoint(renderer, x_center + x, y_center + y);
    SDL_RenderDrawPoint(renderer, x_center - y, y_center - x);
    SDL_RenderDrawPoint(renderer, x_center + y, y_center - x);
  }

  while (x > y)
  {
    y++;
    if (err < 0)
    {
      err += 2 * y + 1;
    }
    else
    {
      x--;
      err += 2 * (y - x) + 1;
    }

    // Stop if x < y
    if (x < y)
      break;

    // Draw the points
    SDL_RenderDrawPoint(renderer, x_center + x, y_center - y);
    SDL_RenderDrawPoint(renderer, x_center - x, y_center - y);
    SDL_RenderDrawPoint(renderer, x_center + x, y_center + y);
    SDL_RenderDrawPoint(renderer, x_center - x, y_center + y);

    if (x != y)
    {
      SDL_RenderDrawPoint(renderer, x_center + y, y_center - x);
      SDL_RenderDrawPoint(renderer, x_center - y, y_center - x);
      SDL_RenderDrawPoint(renderer, x_center + y, y_center + x);
      SDL_RenderDrawPoint(renderer, x_center - y, y_center + x);
    }
  }
}

int main()
{
  int x_center, y_center, radius;

  // Input for the circle
  printf("Enter the center coordinates (x, y): ");
  scanf("%d %d", &x_center, &y_center);
  printf("Enter the radius: ");
  scanf("%d", &radius);

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window
  SDL_Window *window = SDL_CreateWindow(
      "SDL Circle Drawing",
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

  // Clear the screen with black color
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  // Set the drawing color to white
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

  // Draw the circle
  drawCircle(renderer, x_center, y_center, radius);

  // Present the rendered content
  SDL_RenderPresent(renderer);

  // Wait for 5 seconds
  SDL_Delay(5000);

  // Cleanup and exit
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
