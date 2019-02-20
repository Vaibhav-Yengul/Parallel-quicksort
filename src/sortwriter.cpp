/*
 * sortwriter.cpp
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#include "sortwriter.h"

SortWriter::SortWriter(string fname, vector<int> so){
	outputFileName = fname;
	sortOrder = so;
}

void SortWriter::flushData(vvs &data){
	csvWriter = new CsvWriter(this->outputFileName, false);
	csvWriter->writeData(data);
	csvWriter->close();
	delete(csvWriter);
}

void SortWriter::sortWrite(Box* b1, Box* b2){
	vvs b1Data, b2Data;
	bool b1empty = true, b2empty =true;
	int b1ptr = 0, b2ptr = 0;
	while(true){
		if(b1empty && b1->hasNext()){
			b1Data = b1->getData();
			b1ptr = 0;
			b1empty = false;
		}
		if(b2empty && b2->hasNext()){
			b2Data = b2->getData();
			b2ptr = 0;
			b2empty = false;
		}

		if(b1empty || b2empty)
			break;

		while(b1ptr < MERGELIMIT && b2ptr < MERGELIMIT){
			if(Helper::compare(b1Data[b1ptr], b2Data[b2ptr], sortOrder) <= 0){
				writeData.push_back(b1Data[b1ptr]);
				b1ptr++;
			}
			else{
				writeData.push_back(b2Data[b2ptr]);
				b2ptr++;
			}

			if(writeData.size()==MERGELIMIT){
				flushData(writeData);
				writeData.clear();
			}
		}
		b1empty = b1ptr==MERGELIMIT;
		b2empty = b2ptr==MERGELIMIT;
	}

	if(b1empty){
		while(true){
			if(b2empty && b2->hasNext()){
				b2Data = b2->getData();
				b2ptr = 0;
				b2empty = false;
			}

			if(b2empty) break;

			while(b2ptr < MERGELIMIT)
				writeData.push_back(b2Data[b2ptr++]);
			b2empty = b2ptr==MERGELIMIT;
			flushData(writeData);
			writeData.clear();
		}
	}
	else if(b2empty){
		while(true){
			if(b1empty && b1->hasNext()){
				b1Data = b1->getData();
				b1ptr = 0;
				b1empty = false;
			}

			if(b1empty) break;

			while(b1ptr < MERGELIMIT)
				writeData.push_back(b1Data[b1ptr++]);
			b1empty = b1ptr==MERGELIMIT;
			flushData(writeData);
			writeData.clear();
		}
	}
}
