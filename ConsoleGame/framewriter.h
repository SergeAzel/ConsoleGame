#include "frame.h"

#pragma once

class FrameWriter
{
public:
  FrameWriter(ConsoleFrame& frame);

  void Draw(int x, int y, char character);
  void HorizontalLine(int left, int y, int width, char character);
  void VerticalLine(int x, int top, int height, char character);
  void OutlineRectangle(int left, int top, int width, int height, char character);
  void FillRectangle(int left, int top, int width, int height, char character);

private:
  ConsoleFrame& frame;
};
