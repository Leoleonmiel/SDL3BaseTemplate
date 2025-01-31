#include <iostream>
#include <SDL3/SDL.h>

#define S_WIDTH 1280
#define S_HEIGHT 720

int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    bool gameIsRunning = SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow( // Declare a pointer
        "SDL 3 BASE Template", // window title
        S_WIDTH, // width, in pixels
        S_HEIGHT,  // height, in pixels
        0  // flags
    );

    renderer = SDL_CreateRenderer(window, NULL);

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
            case SDL_EVENT_KEY_DOWN:
                if (SDLK_ESCAPE) //If key down is escape
                {
                    SDL_DestroyWindow(window);  // Close and destroy the window
                    SDL_DestroyRenderer(renderer);
                    gameIsRunning = false;
                }
                break;

            case SDL_EVENT_WINDOW_CLOSE_REQUESTED: //if 'X' is clicked
                SDL_DestroyWindow(window);  // Close and destroy the window
                SDL_DestroyRenderer(renderer);
                gameIsRunning = false;
                break;
            default:
                break;
            }
        }
        // update game state, draw the current frame

        //Display
        SDL_SetRenderDrawColor(renderer, 130, 200, 130, 255); //set renderer to Red= 130, Green=200, Bblue=130, Alpha(transparence)=255 /Values go from 0 to 255)
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit(); // Clean up
    return EXIT_SUCCESS;
}

