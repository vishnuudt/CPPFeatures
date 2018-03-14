//============================================================================
// Name        : TestDriver.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <type_traits>
#include "ChronoFeatures.h"
#include "SorterLambda.h"
#include "TuplesFeatures.h"
#include "GenericsImp.h"

using namespace std;
using namespace VVVNS;
using namespace VVVNS::Features;

using UniqPtrFeatures = std::unique_ptr<ChronoFeatures>;

int start(int port);

int main() {

	std::vector<UniqPtrFeatures> featuresToRun;
	featuresToRun.push_back(std::move(std::make_unique<ChronoFeatures>()));
	featuresToRun.push_back(std::move(std::make_unique<SorterLambda>()));
	featuresToRun.push_back(std::move(std::make_unique<TuplesFeatures>()));
	featuresToRun.push_back(std::move(std::make_unique<GenericsFeatures>()));

	std::for_each(std::cbegin(featuresToRun), std::cend(featuresToRun), [](auto const& prtToFeature) {
		std::cout << typeid(prtToFeature).name() << std::endl;
		prtToFeature->exportItem();
	});
	return 0;
}

