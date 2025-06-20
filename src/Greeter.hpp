#pragma once

#include <string>

class Greeter {
public:
  Greeter(const std::string &thingToGreet);
  std::string greet();

private:
  std::string greetTarget;
};