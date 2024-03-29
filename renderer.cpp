#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height, const std::size_t grid_width, const std::size_t grid_height)
  : screen_width(screen_width), screen_height(screen_height),
    grid_width(grid_width), grid_height(grid_height) {
  
  //TODO: Add error handling
  SDL_Init(SDL_INIT_VIDEO);

  //TODO: Add error handling
  win = SDL_CreateWindow("Game Title", SDL_WINDOWPOS_CENTERED,
			 SDL_WINDOWPOS_CENTERED, screen_width,
			 screen_height, SDL_WINDOW_RESIZABLE);

  //TODO: Add error handling
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

}

Renderer::~Renderer(){
  SDL_DestroyWindow(win);
  SDL_Quit();
}

void Renderer::UpdateWindowTitle(int fps){
  std::string title{std::to_string(fps)};
  //const char *title = "Kitty Corner";
  SDL_SetWindowTitle(win, title.c_str());
}

//update the background color
void Renderer::UpdateBackgroundColor(){
  surface = SDL_GetWindowSurface(win);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
  SDL_UpdateWindowSurface(win);
}

void Renderer::Render(){
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  //clear screen
  SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(renderer);

  block.x = 10 * block.w;
  block.y = 10 * block.h;

  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

  SDL_RenderFillRect(renderer, &block);

  //update screen
  SDL_RenderPresent(renderer);
}
