/*
 * GenericsImp.h
 *
 *  Created on: Mar 13, 2018
 *      Author: vishnu
 */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include "ChronoFeatures.h"

namespace VVVNS::Features {

	using namespace std;
	using PairStrStr = std::pair<std::string, std::string>;

	// Both the arms of if statement are not evaluated, only the one that matches or unmatches during compilation is
	// used by the compiler.
	template<typename T>
	auto length_VVV(T const& value){
		if constexpr(std::is_integral<T>::value){
			return value;
		}else {
			return value.length();
		}
	}


	class GenericsFeatures : public ChronoFeatures{
		public:
		GenericsFeatures(){
			_mapElement.insert ( PairStrStr("sedia"s, "chair"s));
		}
		void exportItem(){
			int n{64};
			string s{"Some"};
			std::cout << "length(n) " << length_VVV(n) << std::endl;
			std::cout << "length(s) " << length_VVV(s) << std::endl;

			// structured binding in action
			auto [iter, success] = _mapElement.insert ( PairStrStr("sedia"s, "chair"s) );
			std::cout << "insert " << " with " << success << std::endl;

			// for loop structured bindings
			for (const auto& [first, second] : _mapElement){
				std::cout << "f " << first << " s " << second << std::endl;
			}
		}
		private:
			std::map<std::string, std::string> _mapElement;
	};
}
