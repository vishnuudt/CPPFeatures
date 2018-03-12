//============================================================================
// Name        : TestDriver.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <typeinfo>
#include "ChronoFeatures.h"
#include "SorterLambda.h"
#include "TuplesFeatures.h"

using namespace std;

using UniqPtrFeatures = std::unique_ptr<ChronoFeatures>;

int start(int port);

int main() {

	boost::property_tree::ptree pt;
	boost::property_tree::read_json("/workspace/valhalla/valhalla.json", pt);
	auto word = 0b10'00;
	auto s = "man";
	std::cout << s << std::endl;
	std::cout << word << std::endl;
	std::vector<UniqPtrFeatures> featuresToRun;
	featuresToRun.emplace_back(std::move(std::make_unique<ChronoFeatures>()));
	featuresToRun.emplace_back(std::move(std::make_unique<SorterLambda>()));
	featuresToRun.emplace_back(std::move(std::make_unique<TuplesFeatures>()));

	std::for_each(std::cbegin(featuresToRun), std::cend(featuresToRun), [](auto const& prtToFeature) {
		prtToFeature->exportItem();
	});
	return 0;
}



