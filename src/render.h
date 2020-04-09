#ifndef RENDER_H
#define RENDER_H

#include "SDL.h"
#include "spaceship.h"

class Renderer {
    public:
        Renderer(const std::size_t screen_width, const std::size_t screen_height, 
                const std::size_t grid_width, const std::size_t grid_height);
        ~Renderer(); //will not adhere to the rule of five since this is just to close the window.
        void ClearScreen();
        void UpdateScreen();
        void RenderSpaceship(Spaceship &ship);

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;

        const std::size_t _screen_width;
        const std::size_t _screen_height;
        const std::size_t _grid_width;
        const std::size_t _grid_height;

};



#endif