#include <iostream>
#include <SDL3/SDL.h>

#define S_WIDTH 1280
#define S_HEIGHT 720

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL3

    SDL_Window* window = SDL_CreateWindow( // Declare a pointer
        "SDL 3 BASE Template",                  // window title
        S_WIDTH,                               // width, in pixels
        S_HEIGHT,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    bool gameIsRunning = SDL_Init(SDL_INIT_VIDEO);

    // Check that the window was successfully created
    if (window == NULL) 
    {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    while (gameIsRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) // poll until all events are handled! poll event should be called in it's own loop
        {  
            switch (event.type)
            {
            case SDL_EVENT_KEY_DOWN :
                if (SDLK_ESCAPE) //If key down is escape
                {
                    SDL_DestroyWindow(window);  // Close and destroy the window
                    gameIsRunning = false;
                }
                break;

            case SDL_EVENT_WINDOW_CLOSE_REQUESTED : //if 'X' is clicked
                SDL_DestroyWindow(window);  // Close and destroy the window
                gameIsRunning = false;
                break;
            default:
                break;
            }
        }
        // update game state, draw the current frame
    }

    SDL_Quit(); // Clean up
    return EXIT_SUCCESS;
}

