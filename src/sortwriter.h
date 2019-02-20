/*
 * sortwriter.h
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#ifndef SORTWRITER_H_
#define SORTWRITER_H_
#include "helper.h"
#include "Box.h"
#include "csvreadwrite.h"

class SortWriter {
    string outputFileName;
    CsvWriter *csvWriter;
    vector<int> sortOrder;
    vvs writeData;
public:
    SortWriter(string fname, vector<int> so);
    void flushData(vvs &data);
    void sortWrite(Box* b1, Box* b2);
};


#endif /* SORTWRITER_H_ */
