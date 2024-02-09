#include <span>
#include <vector>
#include <ranges>

#pragma once

class ConsoleFrame
{
public:
  ConsoleFrame(int width, int height);
  ConsoleFrame(const ConsoleFrame& other); //Copy constructor
  ConsoleFrame(ConsoleFrame&& other) noexcept; //Move "scavenging" constructor
  ~ConsoleFrame();

  ConsoleFrame& operator=(const ConsoleFrame& other); //Clone assignment
  ConsoleFrame& operator=(ConsoleFrame&& other) noexcept; //Move "scavenging" assignment

  std::span<char> data();
  std::span<const char> data() const;
  std::span<char> line(int lineNumber);
  std::span<const char> line(int lineNumber) const;
  std::vector<std::span<char>> lines();
  std::vector<std::span<const char>> lines() const;

  int getWidth() const;
  int getHeight() const;
  int getCapacity() const;

private:
  char* raw;

  int width;
  int height;
};
