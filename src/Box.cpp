/*
 * Box.cpp
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#include "Box.h"

void Box::readfile(){
	fstream file;
	file.open(fileName);
	numberofitrs--;
	this->data.clear();
	string sen;
	std::vector<std::string> t;

	int xReads = startline;
	while(xReads > 0 && getline(file,sen)){
		xReads--;
	}
	xReads = MERGELIMIT;
	while(xReads > 0 && getline(file,sen)){
		std::stringstream ss(sen);
		std::string buf;
		while (getline(ss, buf, ','))
			t.push_back(buf);
		xReads--;
		this->data.push_back(t);
		t.clear();
	}
	startline += MERGELIMIT;
	file.close();
}

Box::Box(long sline, long &size, string &fileName){
    startline = sline;
    this->size = size;
    this->fileName = fileName;
    numberofitrs = size/MERGELIMIT;
}

vvs Box::getData(){
	return this->data;
}

bool Box::hasNext(){
	if(numberofitrs > 0){
		readfile();
		return this->data.size() > 0;
	}
	else{
		return false;
	}
}

Box::~Box() {
	// TODO Auto-generated destructor stub
}

