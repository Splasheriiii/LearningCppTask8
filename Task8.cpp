#include "Stroka.h"
#include "FileFunctions.cpp"
#include "Encoding.cpp"
#include "StreamState.cpp"

#define DELIMITER "-----------------------------"

int main()
{
    cout << "TASK 8" << endl;
    cout << DELIMITER << endl;

    cout << "SUBTASK 1)" << endl;
    cout << DELIMITER << endl;
    Stroka str;
    cout << "Please, write any word: ";
    cin >> str;
    cout << str << endl;
    cout << DELIMITER << endl << endl;
    

    cout << "SUBTASK 2)" << endl;
    cout << DELIMITER << endl;
    test_read_file();
    test_write_file();
    cout << DELIMITER << endl << endl;


    cout << "SUBTASK 3)" << endl;
    cout << DELIMITER << endl;
    encode_text("text to encode.txt", "text encoded.txt");
    encode_text("text encoded.txt", "text decoded.txt");
    cout << DELIMITER << endl << endl;


    cout << "SUBTASK 4)" << endl;
    cout << DELIMITER << endl;
    test_stream_state();
    cout << DELIMITER << endl << endl;
}