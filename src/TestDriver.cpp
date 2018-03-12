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
#include "ChronoFeatures.h"
#include "SorterLambda.h"
#include "TuplesFeatures.h"

using namespace std;

using UniqPtrFeatures = std::unique_ptr<ChronoFeatures>;

int start(int port);

int main() {

	std::vector<UniqPtrFeatures> featuresToRun;
	featuresToRun.emplace_back(std::move(std::make_unique<ChronoFeatures>()));
	featuresToRun.emplace_back(std::move(std::make_unique<SorterLambda>()));
	featuresToRun.emplace_back(std::move(std::make_unique<TuplesFeatures>()));

	std::for_each(std::cbegin(featuresToRun), std::cend(featuresToRun), [](auto const& prtToFeature) {
		prtToFeature->exportItem();
	});
	return 0;
}



