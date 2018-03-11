/*
 * FileCacher.h
 *
 *  Created on: Nov 25, 2017
 *      Author: vishnu
 */

#ifndef FILECACHER_H_
#define FILECACHER_H_

#include <vector>

using namespace std;

class FileCacher {
public:
	FileCacher();
	virtual ~FileCacher();
	virtual void doIt(string&& container);
};

#endif /* FILECACHER_H_ */
