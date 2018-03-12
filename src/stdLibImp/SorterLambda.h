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

class SorterLambda : public ChronoFeatures{
public:

	void exportItem() const{
		std::vector<std::string> names{"1", "2", "3", "4"};
		std::sort(std::begin(names), std::end(names), [] (std::string const& a, std::string const& b){
			return a.length() > b.length();
		});
		std::cout << names[0] << std::endl;
	}
};



#endif /* LAMBDAIMP_SORTERLAMBDA_H_ */
