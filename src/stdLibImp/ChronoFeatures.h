/*
 * ChronoFeatures.h
 *
 *  Created on: Mar 11, 2018
 *      Author: vishnu
 */

#ifndef STDLIBIMP_CHRONOFEATURES_H_
#define STDLIBIMP_CHRONOFEATURES_H_

#include <memory>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class ChronoFeatures{
public:
	seconds secs{10};
	milliseconds millisecs{200};
	virtual ~ChronoFeatures(){};

	virtual void exportItem() const{
		std::cout << secs.count() << std::endl;

		auto word = 0b10'00;
		auto s = "man";
		std::cout << s << std::endl;
		std::cout << word << std::endl;
	}
};




#endif /* STDLIBIMP_CHRONOFEATURES_H_ */
