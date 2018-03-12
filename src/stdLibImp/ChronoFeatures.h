/*
 * ChronoFeatures.h
 *
 *  Created on: Mar 11, 2018
 *      Author: vishnu
 */

#ifndef STDLIBIMP_CHRONOFEATURES_H_
#define STDLIBIMP_CHRONOFEATURES_H_

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class ChronoFeatures{
public:
	seconds secs{10};
	milliseconds millisecs{200};
	virtual ~ChronoFeatures(){};

	virtual void exportItem(){
		std::cout << secs.count() << std::endl;
	}
};




#endif /* STDLIBIMP_CHRONOFEATURES_H_ */
