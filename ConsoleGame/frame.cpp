#include "frame.h"

ConsoleFrame::ConsoleFrame(int width, int height) :
  width(width),
  height(height),
  raw(new char[getCapacity()])
{
  raw = new char[getCapacity()];
} 

ConsoleFrame::ConsoleFrame(const ConsoleFrame& other) : 
  width(other.width), 
  height(other.height),
  raw(new char[getCapacity()])
{
  auto otherData = other.data();
  std::copy(otherData.begin(), otherData.end(), raw);
}

ConsoleFrame::ConsoleFrame(ConsoleFrame&& other) noexcept :
  width(other.width), 
  height(other.height),
  raw(other.raw)
{
}

ConsoleFrame::~ConsoleFrame()
{
  delete[] raw;
}

ConsoleFrame& ConsoleFrame::operator=(const ConsoleFrame& other)
{
  int currentCapacity = width * height;
  int otherCapacity = other.width * other.height;

  if (otherCapacity != currentCapacity)
  {
    delete[] raw;
    raw = new char[otherCapacity];
  }

  auto otherData = other.data();
  std::copy(otherData.begin(), otherData.end(), data().begin());

  return *this;
}

ConsoleFrame& ConsoleFrame::operator=(ConsoleFrame&& other) noexcept
{
  width = other.width;
  height = other.height;

  delete[] raw;
  raw = other.raw;

  return *this;
}

std::span<char> ConsoleFrame::data()
{
  return std::span(raw, getCapacity());
}

std::span<const char> ConsoleFrame::data() const
{
  return std::span<const char>(raw, getCapacity());
}

std::span<char> ConsoleFrame::line(int lineNumber)
{
  return data().subspan(lineNumber * width, width);
}

std::span<const char> ConsoleFrame::line(int lineNumber) const
{
  return data().subspan(lineNumber * width, width);
}

std::vector<std::span<char>> ConsoleFrame::lines()
{
  auto range = std::views::iota(0, height) | std::views::transform([this](const int& i) { return line(i); });
  return std::vector(range.begin(), range.end());
}

std::vector<std::span<const char>> ConsoleFrame::lines() const
{
  auto range = std::views::iota(0, height) | std::views::transform([this](const int& i) { return line(i); });
  return std::vector<std::span<const char>>(range.begin(), range.end());
}

int ConsoleFrame::getWidth() const
{
  return width;
}

int ConsoleFrame::getHeight() const
{
  return height;
}

int ConsoleFrame::getCapacity() const
{
  return width * height;
}
