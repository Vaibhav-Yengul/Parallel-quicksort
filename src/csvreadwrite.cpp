/*
 * csvreadwrite.cpp
 *
 *  Created on: 20-Feb-2019
 *      Author: vyengul
 */

#include "csvreadwrite.h"
#include "helper.h"

CsvReader::CsvReader(string filename){
	this->fname = filename;
	this->file.open(filename);
	numberofLines =0;
}

bool CsvReader::hasData(){
	this->data.clear();
	bool dataPresent = false;
	int i = MERGELIMIT;
	std::string sentence;
	std::vector<std::string> t;
	while (i > 0 && std::getline(this->file, sentence))
	{
		numberofLines++;
		std::stringstream ss(sentence);
		std::string buf;
		while (getline(ss, buf, ','))
			t.push_back(buf);
		i--;
		this->data.push_back(t);
		t.clear();
		dataPresent = true;
	}
	return dataPresent;
}

vvs CsvReader::getData(){
	return this->data;
}

int CsvReader::getTotalLines(){
	return this->numberofLines;
}

void CsvReader::close(){
	file.close();
}

CsvWriter::CsvWriter(string filename, bool deletePresent){
	this->fname = filename;
	struct stat stFileInfo;
	if(deletePresent && stat(filename.c_str(), &stFileInfo) == 0){
		remove(filename.c_str());
	}
	file.open(filename, std::ios_base::app);
}

void CsvWriter::writeData(vvs &data){
	std::string sentence;
	for(auto x: data){
		sentence = Helper::joins(x,',');
		file << sentence << "\n";
	}
}

void CsvWriter::close(){
	file.close();
}

