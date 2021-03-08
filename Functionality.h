#ifndef Functionality_H
#define Functionality_H
#include "snake.h"

class Functionality {
 public:
  void SnakeStatus(bool &Status, Snake &Player) const;

 private:
  void UserInput(Snake &Player, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif