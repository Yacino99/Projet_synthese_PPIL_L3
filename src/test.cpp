//
// Created by user on 14/02/2022.
//
using namespace std;

#include "test.h"
#include <iostream>
#include <fstream>
#include <string>

void test::sayHi()
{
    cout << "hello everyone" << endl;
}


void test::testGetLine()
{
    cout << "testgetline" << endl;

  //  ifstream ifs("fractions.txt");
    ifstream ifs("C:/Users/Anwender/Desktop/fractions.txt");

    string tmp;
    while (getline(ifs, tmp))
    {
        cout << "ligne lue : " << tmp << endl;
    }

    cout << "fin testgetline" << endl;

}