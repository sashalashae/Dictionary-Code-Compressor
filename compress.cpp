//--------------------------------------------------------
// You can only use these headers

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "treap_bst.h"

//--------------------------------------------------------
//Sasha Morgan

using std::string;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using namespace std;
#include <stdint.h>

int main(int argc,char* argv[])
{
	string operation;
	string infile; //input filename
	string ofile; //output filename
	try{
		if (argc == 3)
		{
			operation = "compress"; //when the file needs to compress
			infile = argv[1]; //name of the input file
			ofile = argv[2]; //name of the output file
		}
		if (argc == 4)
		{
			operation = "decompress";
			infile = argv[1];
			ofile = argv[2];
		}
		ifstream in(infile);
		ofstream out(ofile);
		TreapBST<int, string> track; //creates a new treap
		if (operation == "command")
		{
			int key = 1;
			while (!in.fail())
			{
				string newitem;
				in >> newitem;
				cout << "Your Key is the following value: " + key << endl; //Displays the key
				cout << "Your Value item is the following value: " + newitem << endl; //Displays the vaue
				track.insert(key, newitem); //Inserts the new element
				key++;
			}
			int i = 1;
			while (i <= key)
			{
				uint32_t curr = key; //makes a new key
				bool a = true;
				string nwi2 = track.search(key, a); //searches for the key
				out.write(reinterpret_cast<char*>(&curr), sizeof(curr)); //writes to the file
				out.write(reinterpret_cast<char*>(&nwi2), sizeof(nwi2)); //writes to the file
				i++;
			}
		}
		if (operation == "decompress") //Decompression opperation
		{
			int i = 1;
			while (!in.fail())
			{
				uint32_t key;
				string value;
				in.read(reinterpret_cast<char*>(&key), sizeof(key)); //reads in from the file
				in.read(reinterpret_cast<char*>(&value), sizeof(value)); //reads in from the file
				track.insert(key, value);
				i++;
			}
			int j = 1;
			while (j <= i)
			{
				bool b = true;
				string readout = track.search(i, b); //searches for the information
				out << readout << "\t";
				j++;
			}
		}
			
	}
	catch (std::logic_error)
	{
		cout << "Invalid argument, their is no information present" << endl;
	}
	return 0;
}
