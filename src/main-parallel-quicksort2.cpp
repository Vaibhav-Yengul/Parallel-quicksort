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

void mergeRuns(string fname, vector<int> so, long long numberOfLines, string outputfilename){
	long bucketSize = MERGELIMIT;
	//string ext = ".csv";
	string fileName = "temp";
	int run = 1;
	Box *b1;
	Box *b2;
	string opfname;

	SortWriter *sw;
	while(true){
		long iterations = (long) ceil(numberOfLines*1.0 / bucketSize);
		if (iterations == 1)
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
	Helper::filecopy(opfname, outputfilename);
	remove(opfname.c_str());
}


int main(int argc, char* argv[])
{
	if(argc<5){
		cout << "Usage  : ./<executable> input.csv output.csv “{order of indexes}” {no of threads}\m";
		return 0;
	}
	string input(argv[1]);
	string output(argv[2]);
	string sortorder(argv[3]);
	string noOfT(argv[4]);

    CsvReader reader(input);
    CsvWriter writer("r1.csv", true);

    vector<int> order;
    std::stringstream ss(sortorder);
	std::string buf;
	while (getline(ss, buf, ','))
		order.push_back(stoi(buf));

    vvs v;
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

    mergeRuns("r1.csv", order, reader.getTotalLines(), output);

    cout << "Done";

	return 0;

}
