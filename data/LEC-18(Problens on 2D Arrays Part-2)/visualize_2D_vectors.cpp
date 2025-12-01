#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Function to map a value from one range to another
double mapValue(double value, double fromMin, double fromMax, double toMin, double toMax)
{
    return toMin + (value - fromMin) * (toMax - toMin) / (fromMax - fromMin);
}

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "2D Vector Visualization",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (!window)
    {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::vector<std::pair<double, double>> vectors = {
        {2.0, 3.0},
        {-1.5, 2.5},
        {4.0, -2.0}};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Draw vectors
    for (const auto &vec : vectors)
    {
        double startX = SCREEN_WIDTH / 2.0;
        double startY = SCREEN_HEIGHT / 2.0;
        double endX = startX + mapValue(vec.first, -5.0, 5.0, -100.0, 100.0);
        double endY = startY - mapValue(vec.second, -5.0, 5.0, -100.0, 100.0);

        SDL_RenderDrawLine(renderer, static_cast<int>(startX), static_cast<int>(startY),
                            static_cast<int>(endX), static_cast<int>(endY));
    }

    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
