//============================================================================
// Name        : TestDriver.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "FileCacher.h"

using namespace std;

int start(int port);

int main() {

	boost::property_tree::ptree pt;
	boost::property_tree::read_json("/workspace/valhalla/valhalla.json", pt);
	auto word = 0b10'00;
	std::cout << word << std::endl;
	{
		std::unique_ptr<FileCacher> mycacher = std::make_unique<FileCacher>();
		mycacher->doIt("some");
	}

	return 0;
}



