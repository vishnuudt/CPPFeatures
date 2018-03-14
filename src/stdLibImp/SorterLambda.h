/*
 * SorterLambda.h
 *
 *  Created on: Mar 11, 2018
 *      Author: vishnu
 */

#ifndef LAMBDAIMP_SORTERLAMBDA_H_
#define LAMBDAIMP_SORTERLAMBDA_H_

#include "ChronoFeatures.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace VVVNS::Features {

	using namespace std;

	class SorterLambda : public ChronoFeatures{
	public:

		void exportItem(){

			int x = 20;
			double y = 25.4;
			std::vector<std::string> names{"1", "2", "3", "4"};
			// captures by value, by reference
			std::sort(std::begin(names), std::end(names), [x , &y] (std::string const& a, std::string const& b){
				return a.length() > b.length();
			});
			std::cout << names[0] << std::endl;
			std::unique_ptr<int> ptr = std::make_unique<int>(20);

			// and by init captures
			auto const& lambda = [p = std::move(ptr)](){
				std::cout << *p << std::endl;
			};

			lambda();

			// if scoped variable declaration.. ALSO works on SWITCH
			if(const auto its = std::find(std::begin(names), std::end(names), "3"); its != std::end(names)){
				*its = "***";
			}

			std::for_each(std::cbegin(names), std::cend(names), [this](const std::string& a){
				std::cout << a << std::endl;
			});

		}
	};
}

#endif /* LAMBDAIMP_SORTERLAMBDA_H_ */
