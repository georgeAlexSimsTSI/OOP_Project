#ifndef USERINPUT_H
#define USERINPUT_H

#include <string>
#include <vector>
using std::string;
using std::vector;

namespace userInput{
  float floatInRange(float lower, float upper);
  float floatInRange(float upper);
  int intInRange(int upper, int lower);
  int intInRange(int upper);
  string stringMatching(vector<string> options);
  char charMatching(vector<char> options);  
};

#endif