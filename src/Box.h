/*
 * Box.h
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#ifndef BOX_H_
#define BOX_H_

#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <array>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <math.h>
#include "helper.h"


using namespace std;
typedef std::vector<std::vector<string>> vvs;

class Box {
	long startline;
	long size;
	int numberofitrs;
	vvs data;
	string fileName;

	void readfile();

public:
	Box(long sline, long &size, string &fileName);
	vvs getData();
	bool hasNext();
	~Box();
};

#endif /* BOX_H_ */
