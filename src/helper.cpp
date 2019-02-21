/*
 * helper.cpp
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#include "helper.h"

string Helper::joins(const vector<string>& v, char c) {

   string s = "";

   for (vector<string>::const_iterator p = v.begin();
        p != v.end(); ++p) {
      s += *p;
      if (p != v.end() - 1)
        s += c;
   }
   return s;
}


int Helper::compare(const vector<string> &v1, const vector<string> &v2, const vector<int> &sortOrder){
	for(int x: sortOrder){
		if(Helper::is_number(v1[x])){
			long num1 = stol(v1[x]);
			long num2 = stol(v2[x]);

			if (num1 > num2){
				return 1;
			}
			else if (num1 < num2){
				return -1;
			}
		}
		else{
			if (v1[x].compare(v2[x]) > 0){
				return 1;
			}
			else if (v1[x].compare(v2[x]) < 0){
				return -1;
			}
		}
	}
	return 0;
}

void Helper::filecopy(string &source, string &dest){
	std::ifstream  src(source, std::ios::binary);
	std::ofstream  dst(dest,   std::ios::binary);

	dst << src.rdbuf();
}

void Helper::deleteCopies(string source){
	remove(source.c_str());
	string s = source+"a";
	remove(s.c_str());
	s = source+"b";
	remove(s.c_str());
}

