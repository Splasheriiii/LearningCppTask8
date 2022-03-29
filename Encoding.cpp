#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

/// <summary>
/// ����������� ����� � ������� ������� ������ ������� XOR.
/// </summary>
/// <param name="file_to_encode">���������� ����</param>
/// <param name="encoded_file">���� ������</param>
inline void encode_text(const char* file_to_encode, const char* encoded_file)
{
	size_t seed_str_size = 100;
	char seed_string[100];

#pragma region ��������� ������� ������ �� �����
	ifstream ifs;
	ifs.open("seed string.txt");
	if (!ifs || ifs.eof())
	{
		cout << "Can't open input seed string file or seed string is empty";
		return;
	}
	ifs.getline(seed_string, seed_str_size);
	size_t length = strlen(seed_string);
	seed_str_size = (seed_str_size > length ? length : seed_str_size) - 1;
	ifs.close();
#pragma endregion

#pragma region �������� ������� ��� ������ �����/������
	ofstream ofs;
	ifs.open(file_to_encode);
	ofs.open(encoded_file);
	if (!ifs || ifs.eof() || !ofs)
	{
		cout << "Error trying to open input or output files";
		return;
	}
#pragma endregion

#pragma region ����������� ����� � ����� ��� � ������ ����
	/*
	* ������� �� 32 �� ���������� � �� ������������ ��� �����������.
	* ��� ��� ��� ����������� ������� � �� ����������� ����� ��������� �� ����������� �����.
	* 
	* ��� ��� � ������� .txt �����, ���������� ������������� ������ �� ���� ������ �� eof.
	* ������ ��� � .txt ���������� ��������� ����� �� �����...
	* 
	* ���� ���������� ���� �� � ���������� .txt, � �������, ��� ���� �������� �� �����
	*/
	size_t current_char = 0;
	while (true)
	{
		char ch;
		ifs.get(ch);

		if (ifs.eof())
		{
			break;
		}

		cout << "Get - " << ch << " - " << (int)ch;

		if (ch < 32)
		{
			ch = ch;
		}
		else
		{
			ch = ch ^ seed_string[current_char];
			if (ch < 32)
			{
				ch = ch ^ seed_string[current_char];
			}
		}

		cout << " - Encode to - " << ch << endl;

		ofs.put(ch);

		current_char = current_char + 1 == seed_str_size ? 0 : current_char + 1;
	}
#pragma endregion

	ifs.close();
	ofs.close();

	cout << "Text encoded" << endl;
}