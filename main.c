#include <stdio.h>
#include <SDL.h>

#define WIDTH 500
#define HEIGHT 500

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              WIDTH, HEIGHT, 0);
    if (window == NULL) {
        fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
        return 1;
    }

    SDL_bool running = SDL_TRUE;
    while (running == SDL_TRUE) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = SDL_FALSE;
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (SDL_BUTTON(SDL_GetMouseState(NULL, NULL)) == SDL_BUTTON_LEFT)
                    printf("x position: %d | y position: %d\n", event.button.x, event.button.y);
            }
        }

        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
