#include "framewriter.h"

FrameWriter::FrameWriter(ConsoleFrame& frame) :
  frame(frame)
{
}

void FrameWriter::Draw(int x, int y, char character)
{
  frame.line(y)[x] = character;
}

void FrameWriter::HorizontalLine(int left, int y, int width, char character)
{
  auto line = frame.line(y);
  std::fill(line.begin() + left, line.begin() + left + width, character);
}

void FrameWriter::VerticalLine(int x, int top, int height, char character)
{
  auto lines = frame.lines();
  for (std::span<char> line : std::ranges::subrange(lines.begin() + top, lines.end() + top + height)
  {
    line[x] = character;
  }
}

void FrameWriter::OutlineRectangle(int left, int top, int width, int height, char character)
{
}