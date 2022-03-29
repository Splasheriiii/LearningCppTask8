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
/// Считывание char[] с помощью getline не останавливается на пробелах, в отличие от >>
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
/// Перегруженный оператор добавления в поток вывода
/// </summary>
/// <param name="stream">Поток вывода</param>
/// <param name="value">Строка для вывода в поток</param>
/// <returns>параметр stream</returns>
ostream& operator<<(ostream& stream, Stroka& value)
{
	value.vyvod();
	return stream;
}
/// <summary>
/// Перегруженный оператор считывания из поток ввода
/// </summary>
/// <param name="stream">Поток ввода</param>
/// <param name="value">Строка для ввода из потока</param>
/// <returns>параметр stream</returns>
istream& operator>>(istream& stream, Stroka& value)
{
	value.vvod();
	return stream;
}