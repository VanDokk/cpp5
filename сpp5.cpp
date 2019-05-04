
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main()
{
	setlocale(0, "Russian");

	ifstream FIN_TEST1("test1.txt");
	ofstream FOUT_TEST2("test2.txt", ios_base::app);

	string str1;
	string str2;


	
	if (FIN_TEST1.is_open() && FOUT_TEST2.is_open())
	{
		while (!FIN_TEST1.eof())
		{
			str2 = str1;
			getline(FIN_TEST1, str1);
			if ((str2[0] == '-') && (str1[0] == '0') || (str2 == "") && (str1[0] == '0'))
			{
				while (str1 != "-")
				{
					FOUT_TEST2 << str1 << endl;
					getline(FIN_TEST1, str1);
				}
				FOUT_TEST2 << '-' << endl;
			}
		}		
	}
	else
	{
		cout << "Не удалось открыть файлы";
	}



	ifstream FIN_TEST2("test2.txt"); 
	
	string line;

	//FIN_TEST1.seekg(0,ios::beg);
	ifstream FIN_TEST("test1.txt");
	cout << endl << "test1.txt" << endl << endl;
	while (!FIN_TEST.eof())
	{
		getline(FIN_TEST, line);
		cout << line << endl;
	}
	cout << endl << "test2.txt" << endl << endl;
	while (!FIN_TEST2.eof())
	{
		getline(FIN_TEST2, line);
		cout << line << endl;
	}

	FIN_TEST.close();
	FOUT_TEST2.close();
	FIN_TEST2.close();
	FIN_TEST1.close();
}

