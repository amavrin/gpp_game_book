#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

enum func_status {FUNC_OK, FUNC_ERR};

func_status rnd_between(int, int, int&);
void guess(int, int);

