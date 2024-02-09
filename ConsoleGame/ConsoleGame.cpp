// ConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

std::string getNextInput();

int main()
{
  std::string command = "start";

  bool run = true;
  while (run)
  {
    // 1. Process input command

    // 2. Render new page

    // 3. Accept new command
    command = getNextInput();
  }
}


std::string getNextInput()
{
  std::string result;
  std::cin >> result;
  return result;
}
