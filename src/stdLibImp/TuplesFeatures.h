/*
 * TuplesFeatures.h
 *
 *  Created on: Mar 11, 2018
 *      Author: vishnu
 */

#ifndef STDLIBIMP_TUPLESFEATURES_H_
#define STDLIBIMP_TUPLESFEATURES_H_

#include <iostream>
#include <tuple>
#include "ChronoFeatures.h"

namespace VVVNS::Features {

	using namespace std;

	class TuplesFeatures : public ChronoFeatures{
	public:
		TuplesFeatures():stup{std::make_tuple(10.4, 10, "some"s)}{}


		void exportItem() {
			double mydub;
			int myint;
			std::string mystr;
			std::tie (mydub, myint, mystr) = stup;

			std::cout << std::get<0>(stup) <<" " << mystr << std::endl;
		}

	private:
		std::tuple<double, int, std::string> stup;

	};
}

#endif /* STDLIBIMP_TUPLESFEATURES_H_ */
