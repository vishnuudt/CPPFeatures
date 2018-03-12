/*
 * FileCacher.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: vishnu
 */
#include <iostream>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/asio.hpp>
#include <boost/container/vector.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "FileCacher.h"
using namespace std;
using namespace boost::interprocess;

FileCacher::FileCacher() {
	// TODO Auto-generated constructor stub
	cout << "cons" << endl;

}

FileCacher::~FileCacher() {
	// TODO Auto-generated destructor stub
	cout << "des" << endl;
}

void FileCacher::doIt(string&& container){

	boost::property_tree::ptree pt;
	boost::property_tree::read_json("/workspace/valhalla/valhalla.json", pt);

	cout << "doing it" << &container << endl;
	boost::optional<std::string> some = boost::none;
	cout << "done it" << some << endl;

	//Create a file_mapping object
	file_mapping  mapping("/home/vishnu/eclipse-workspace/TestDriver/testfile", read_write);

	//Create a mapped_region covering the whole file
	mapped_region region (mapping, read_write);

	//Obtain the size and the address of the mapped region
	void *address    = region.get_address();
	std::size_t size = region.get_size();

	std::cout << size << address << endl;

	//Set the whole file
	std::memset(address, 0xFF, size);

	//Make sure all the data is flushed to disk
	region.flush();

}

