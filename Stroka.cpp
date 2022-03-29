#include "Stroka.h"

Stroka::Stroka(char* in_str)
{
	strcpy_s(str, in_str);
}
Stroka::Stroka(const Stroka& in_str)
{
	strcpy_s(str, in_str.str);
}
Stroka& Stroka::operator=(const Stroka& in_str)
{
	strcpy_s(str, in_str.str);
	return *this;
}
int Stroka::operator==(const Stroka& in_str)
{
	return strcmp(str, in_str.str);
}
Stroka& Stroka::operator+(const Stroka& in_str)
{
	strcat_s(str, in_str.str);
	return *this;
}
int Stroka::dlina()
{
	return strlen(str);
}
/// <summary>
/// ���������� char[] � ������� getline �� ��������������� �� ��������, � ������� �� >>
/// </summary>
void Stroka::vvod()
{
	std::cin.getline(str, 80);
}
void Stroka::vyvod()
{
	std::cout << str;
}
/// <summary>
/// ������������� �������� ���������� � ����� ������
/// </summary>
/// <param name="stream">����� ������</param>
/// <param name="value">������ ��� ������ � �����</param>
/// <returns>�������� stream</returns>
ostream& operator<<(ostream& stream, Stroka& value)
{
	value.vyvod();
	return stream;
}
/// <summary>
/// ������������� �������� ���������� �� ����� �����
/// </summary>
/// <param name="stream">����� �����</param>
/// <param name="value">������ ��� ����� �� ������</param>
/// <returns>�������� stream</returns>
istream& operator>>(istream& stream, Stroka& value)
{
	value.vvod();
	return stream;
}