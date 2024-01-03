#pragma once
#include<iostream>
#include<conio.h>
#include<fstream>
#include <ctime>
#include <string>
#include<Windows.h>
using namespace std;

const int customerIdLimit = 4;
const int metersLimit = 3;


int getSize(const char* data)
{
	int i;

	for (i = 0; data[i] != '\0'; i++)
	{
		//Empty body loop
	}

	return i + 1;

}

void growString(char*& oldData, char& letter)
{

	int dataSize = getSize(oldData);

	dataSize++;

	char* newData = new char[dataSize];

	for (int i = 0; i < dataSize - 2; i++)
	{
		newData[i] = oldData[i];
	}

	newData[dataSize - 2] = letter;

	newData[dataSize - 1] = '\0';

	delete[]oldData;

	oldData = newData;

}

void getFileInput(char*& data, ifstream& file)
{
	char letter;

	data = new char[1];
	data[0] = '\0';

	file.get(letter);

	while (!file.eof())
	{
		growString(data, letter);
		file.get(letter);
	}
}

void getStringConsole(char*& data)
{
	char letter;

	data = new char[1];
	data[0] = '\0';

	cin.get(letter);

	while (letter == '\n')
	{
		cin.get(letter);
	}

	while (letter != '\n')
	{
		growString(data, letter);
		cin.get(letter);
	}

}

void getStringFile(char*& data, ifstream& file)
{
	char letter;

	data = new char[1];
	data[0] = '\0';

	file.get(letter);

	while (letter != ',' && letter != '\n' && !file.eof())
	{
		growString(data, letter);
		file.get(letter);
	}
}

bool stringsEqual(const char* string1, const char* string2)
{
	int string1_size = getSize(string1);
	int string2_size = getSize(string2);

	if (string1_size == string2_size)
	{
		for (int i = 0; i < string1_size; i++)
		{
			if (string1[i] != string2[i])
			{
				return false;
			}
		}

		return true;

	}

	else
	{
		return false;
	}

}

void loadFile(ifstream& In, const char* fileName)
{
	In.open(fileName);

	if (!In)
	{
		system("cls");

		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|  File is missing!; Software corrupted!   |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(1);
	}

}

void fastForward(ifstream& file)
{
	char dummy;

	file.get(dummy);

	while (dummy != '\n' && !file.eof())
	{
		file.get(dummy);
	}

}

void adjustPosition(ifstream& inFile, const char* data)
{
	inFile.clear();

	inFile.seekg(0, ios::beg);

	char* fileData = nullptr;

	int position = inFile.tellg();

	while (!inFile.eof())
	{
		getStringFile(fileData, inFile);

		if (stringsEqual(data, fileData))
		{
			inFile.seekg(position, ios::beg);
			break;
		}

		position = inFile.tellg();

	}

}

void adjustPosition2(ifstream& inFile, const char* data)
{
	char* fileData = nullptr;

	int position = inFile.tellg();

	while (!inFile.eof())
	{
		getStringFile(fileData, inFile);

		if (stringsEqual(data, fileData))
		{
			inFile.seekg(position, ios::beg);
			break;
		}

		position = inFile.tellg();

	}
}

void adjustPosition3(ifstream& inFile, const char* data)
{
	char* fileData = nullptr;
	char dummy;

	inFile.seekg(5, ios::cur);
	int position = inFile.tellg();

	while (!inFile.eof())
	{
		getStringFile(fileData, inFile);

		if (stringsEqual(data, fileData))
		{
			if (inFile.eof())
			{
				inFile.clear();
			}

			inFile.seekg(position, ios::beg);
			break;
		}

		inFile.seekg(-1, ios::cur);
		inFile.get(dummy);

		if (dummy == '\n')
		{
			inFile.seekg(5, ios::cur);
			position = inFile.tellg();
		}

		else
		{
			position = inFile.tellg();
		}

	}
}



///UI//////////////////////////////////////////////////////
void maximizeWindow() {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
void MainMenu()
{
	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|          Bill Managment System           |\n";
	cout << "\t\t\t\t\t\t\t|                                          |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (1) for Employees Portal     |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (2) for Customer Portal      |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (esc) to exit                |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
}
void printSighn()
{

	cout << "\n\n\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|              lOGIN / lOGOUT              |\n";
	cout << "\t\t\t\t\t\t\t|                                          |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (1) To Sighn in              |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (2) To Sighn up              |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (esc) To Return to Main Menu |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
}