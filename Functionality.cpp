#include "Functionality.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Functionality::UserInput(Snake &Player, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (Player.direction != opposite || Player.size == 1) Player.direction = input;
  return;
}

void Functionality::SnakeStatus(bool &Status, Snake &Player) const {
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT) 
    {
      Status = false;
    } else if (e.type == SDL_KEYDOWN) 
    {
      switch (e.key.keysym.sym) 
      {
        case SDLK_UP:
            UserInput(Player, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
            UserInput(Player, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
            UserInput(Player, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
            UserInput(Player, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}