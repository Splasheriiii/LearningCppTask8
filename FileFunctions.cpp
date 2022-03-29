#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

/// <summary>
/// Код из методички
/// </summary>
inline void test_read_file()
{
	char fname[15], c;
	size_t old_width = cin.width(15);

	cout << "Enter input filename: ";
	cin >> fname;
	ifstream ifs;
	ifs.open(fname);
	if (!ifs)
	{
		cout << "Can't open input file" << endl;
		ifs.close();
		return;
	}

	cout << "Enter output filename: ";
	cin >> fname;
	ofstream ofs;
	ofs.open(fname);
	if (!ofs)
	{
		cout << "Can't open output file" << endl;
		ifs.close();
		ofs.close();
		return;
	}

	while (ifs && ofs)
	{
		ifs.get(c);
		c = toupper(c);
		ofs.put(c);
		cout << ".";
	}
	cout << endl << "Output file is a copy of input file but in upper case" << endl;
	cin.width(old_width);
	ifs.close();
	ofs.close();
}

/// <summary>
/// Код из методички.
/// За одним исключением - компилятор vs иначе определяет флаги открытия потока(std::ofstream::_Noreplace или std::fstream::app), чем это описано в тексте.
/// </summary>
inline void test_write_file()
{
	const char fname[] = "New file";	
	ofstream ofs;
	ofs.open(fname, std::ofstream::out | std::ofstream::_Noreplace);
	if (!ofs)
	{
		cout << "Can't open output file " << fname << ". Seems like it's already exists" << endl;
		ofs.close();
		return;
	}
	ofs << "First string in a new file";
	ofs.close();

	fstream fs;
	fs.open(fname, std::fstream::out | std::fstream::app);
	fs << "Addition to previous written string";
	fs.close();

	fstream ifs;
	ifs.open(fname);
	if (!ifs)
	{
		cout << "Can't open result file." << endl;
		ifs.close();
		return;
	}
	char line[80];
	ifs.getline(line, sizeof(line));
	cout << "Output file contains: " << endl << line << endl;
}
