// main.cpp

#include <iostream>
#include <fstream>
#include <exception>

#include "nal_unit.h"

int main(int argc, const char* argv[])
{
  if (argc < 2) {
	std::cerr << "hevcparse <filename> [number of iterations]\n";
	return EXIT_FAILURE;
  }

  int iterations = 1;
  if (argc == 3) {
	iterations = std::stoi(argv[2]);
  }

  for (int i = 0; i < iterations; i++) {
	std::ifstream rbsp(argv[1], std::ios_base::in|std::ios_base::binary);
	if (!rbsp.good())
	  return EXIT_FAILURE;

	nal_unit nu;
	nu.find_first(rbsp);

	do {
	  nu.read(rbsp);
	  nu.process();
	} while (!rbsp.eof());
  }

  return EXIT_SUCCESS;
}
