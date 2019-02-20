//============================================================================
// Name        : parallel-quicksort2.cpp
// Author      : vaibhav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Box.h"
#include "csvreadwrite.h"
#include "quicksort.h"
#include "sortwriter.h"
#include "helper.h"

void mergeRuns(string fname, vector<int> so, long long numberOfLines){
	long bucketSize = MERGELIMIT;
	//string ext = ".csv";
	string fileName = "temp";
	int run = 1;
	Box *b1;
	Box *b2;
	string opfname;

	SortWriter *sw;
	while(true){
		long iterations = numberOfLines / bucketSize;
		if (iterations == 0)
			break;

		string fnameA = fname + "a";
		string fnameB = fname + "b";
		Helper::filecopy(fname, fnameA);
		Helper::filecopy(fname, fnameB);

		for(long itr=0; itr<iterations; itr+=2){
			opfname = fileName + to_string(run);
			b1 = new Box(itr * bucketSize, bucketSize, fnameA);
			b2 = new Box((itr+1) * bucketSize, bucketSize, fnameB);
			sw = new SortWriter(opfname, so);
			sw->sortWrite(b1, b2);
		}

		Helper::deleteCopies(fname);

		fname = opfname;
		bucketSize *= 2;
		run++;
		delete(b1);
		delete(b2);
		delete(sw);
	}
}


int main()
{
    CsvReader reader("rankings.csv");
    CsvWriter writer("r_temp2.csv", true);

    vector<int> order {0,1};
    std::vector<std::vector<string>> v;
    QuickSort sorter(order);
    int j = 1;
    while(reader.hasData()) {
        v = reader.getData();
        if (v.size() < MERGELIMIT){
        	cout << j <<"\n";
        }
        sorter.sortlogic(v);
        writer.writeData(v);
        j++;
    }
    reader.close();
    writer.close();

    mergeRuns("r_temp2.csv", order, reader.getTotalLines());

    cout << "Done";
    return 0;

}
