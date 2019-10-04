#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"

class Renderer {
 public:
  //constructor
  Renderer(const std::size_t screen_width, const std::size_t screen_height, const std::size_t grid_width, const std::size_t grid_height);

 private:
  //declare pointer to window
  SDL_Window *win;

  //declare coordinates
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
