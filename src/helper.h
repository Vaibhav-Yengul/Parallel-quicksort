/*
 * helper.h
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#ifndef HELPER_H_
#define HELPER_H_

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
#define MERGELIMIT 3600

using namespace std;
typedef std::vector<std::vector<string>> vvs;

class Helper {
	Helper();
public:
	static string joins(const vector<string>& v, char c);
	static int compare(const vector<string> &v1, const vector<string> &v2, const vector<int> &sortOrder);
	static void filecopy(string &source, string &dest);
	static void deleteCopies(string source);
};

#endif /* HELPER_H_ */
