#pragma once
#include "Drawable.h"

class Apple : public Drawable {
public:
  Apple(int x, int y)
  {
        this->x = x;
        this->y = y;
        this->icon = '@';
  }
};
