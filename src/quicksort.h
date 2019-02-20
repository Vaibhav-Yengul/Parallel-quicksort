/*
 * quicksort.h
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include "helper.h"
#include "Box.h"

class QuickSort
{
    vector<int> sortorder;
    int partition (vvs &data, int low, int high);
    void quicksort(vvs &data, int low, int high);

public:
    QuickSort(vector<int> order);
    void sortlogic(std::vector<std::vector<string>> &data);
};

#endif /* QUICKSORT_H_ */
