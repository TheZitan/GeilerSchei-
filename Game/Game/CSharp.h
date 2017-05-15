#pragma once
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class StreamReader
{
private:
	string fileName;
	string errorString;

public:
	StreamReader(string fName, string error = "File Path not Found.")
	{
		fileName = fName;
		errorString = error;
	}

	string readToEnd()
	{
		ifstream read(fileName);
		string line;
		string s;

		if (read.is_open())
		{
			while (!read.eof)
			{
				getline(read, line);
				s += (line + "\n").c_str();
			}
			read.close;
		}
		else
		{
			return errorString;
		}
		return s;
	}
};