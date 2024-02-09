#include "renderer.h"
#include <ranges>
#include <iostream>

/*
Renderer::Renderer() : frameWidth(60), frameHeight(20)
{
  rawFrame = new char[frameWidth * frameHeight];
  frame = std::span<char>(rawFrame, frameWidth * frameHeight);
}

void Renderer::renderFrame()
{
  for (const int& i : std::views::iota(0, frameHeight))
  {
    std::ranges::copy(frame.subspan(i * frameWidth, frameWidth), std::ostream_iterator<char>(std::cout));
  }
}*/
