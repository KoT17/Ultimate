#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>

#include "pull_object.h"

using namespace std;

pull_object::pull_object() {
  string temp = "";

  position = -2;
  name = temp;
  success = temp;

}
pull_object::pull_object(int p, string n, string s) {
  position = p;
  name = n;
  success = s;
}

bool pull_object::is_successful() {
  string temp = "S";
  return strcmp(temp.c_str(), success.c_str());
}

string pull_object::get_name() {
  return name;
}

int pull_object::get_position() {
  return position;
}
