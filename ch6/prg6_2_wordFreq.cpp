#include <iostream>
#include <fstream>
#include <cstdlib>  // exit()
#include <list>
#include <string>

#include "../include/d_search.h" // seqSearch()±í
#include "../include/d_wfreq.h" // wordFreq
#include "../include/d_util.h" // writeList()

using namespace std;

int main()
{
	ifstream fin;
	// read word from file insert wf
	list<wordFreq> wf;
	// use seqSearch() and display list
	list<wordFreq>::iterator iter;
	string fileName, word;
	// user input file name
	cout << "Enter name of the file containing the words: ";
	cin >> fileName;

	// check error
	fin.open(fileName.c_str());
	if(!fin)
	{
		cerr << "Cannot open " << fileName << endl;
		exit(1);
	}
	// read a word until end of file
	while (fin >> word)
	{
		// wordFreq object, number of apperen is 1
		wordFreq obj(word);
		// find word in wf
		iter = seqSearch<wordFreq>(wf.begin(), wf.end(), obj);

		// is find this word?
		if(iter != wf.end())
			// find this word ,num+1
			(*iter).increment();
		else
			// word is new, insert list
			wf.push_back();
	}
	// sort wf
	wf.sort();
	cout << endl;
	writeList(wf, "\n");

	return 0;
}
