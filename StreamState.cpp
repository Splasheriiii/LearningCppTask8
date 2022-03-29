#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <string>


using namespace std;
/// <summary>
/// Простенькая программа, которая устанавливает флажочек в поток, опираясь на данные с клавиатуры
/// </summary>
inline void test_stream_state()
{
	fstream fs("TestFile");
	string input = "";

	while (input != "exit")
	{
		cout << "Current state sum is " << fs.rdstate() << "\tIs error(check by operator!) - " << !fs << endl;
		cout << "Enter new state: " << endl << "\t 1) eof" << endl << "\t 2) fail" << endl << "\t 3) bad" << endl << "\t 4) good" << endl << "Or type \"exit\" to quit" << endl;
		cin >> input;
		if (input == "exit")
		{
			return;
		}
		else if (input == "eof")
		{
			fs.setstate(fs.eofbit);
		}
		else if (input == "fail")
		{
			fs.setstate(fs.failbit);
		}
		else if (input == "bad")
		{
			fs.setstate(fs.badbit);
		}
		else if (input == "good")
		{
			fs.clear(0);
		}
	}
}