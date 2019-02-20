/*
 * csvreadwrite.h
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#ifndef CSVREADWRITE_H_
#define CSVREADWRITE_H_

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

class CsvReader {
    ifstream file;
    string fname;
    vvs data;
    long long numberofLines;

public:
    CsvReader(string filename);
    bool hasData();
    vvs getData();
    void close();
    int getTotalLines();
};


class CsvWriter {
    fstream file;
    string fname;
public:
    CsvWriter(string filename, bool deletePresent);

    void writeData(vvs &data);

    void close();
};


#endif /* CSVREADWRITE_H_ */
