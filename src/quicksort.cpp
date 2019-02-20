/*
 * quicksort.cpp
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#include "quicksort.h"

int QuickSort::partition (std::vector<std::vector<string>> &data, int low, int high)
{
	vector<string> pivot = data[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		if (Helper::compare(data[j],pivot, this->sortorder) <= 0)
		{
			i++;
			data[i].swap(data[j]);
		}
	}
	data[i + 1].swap(data[high]);
	return (i + 1);
}

void QuickSort::quicksort(std::vector<std::vector<string>> &data, int low, int high)
{
	if (low < high)
	{
		int pi = partition(data, low, high);
		quicksort(data, low, pi - 1);
		quicksort(data, pi + 1, high);
	}
}

QuickSort::QuickSort(vector<int> order) {
	this->sortorder = order;
}

void QuickSort::sortlogic(std::vector<std::vector<string>> &data){
	quicksort(data, 0, data.size()-1);
}
