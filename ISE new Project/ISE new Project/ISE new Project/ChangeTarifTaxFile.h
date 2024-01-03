#pragma once

#include"VerifyFunctions.h"

void updateRegularUnitPrice1PhaseD()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "" << endl;
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}
	while (count < 2)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;
	cout << "\n ";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|      Enter new regular unit price        |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updatePercentageOfTax1PhaseD()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}
	while (count < 4)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|      Enter new percentage of tax:        |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updateFixedCharges1PhaseD()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}
	while (count < 5)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;
	cout << "\n ";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|       Enter new fixed charges:           |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position - 1)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i < position)
		{
			outFile << input << endl;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updateRegularUnitPrice1PhaseC()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		
		exit(0);
	}
	while (count < 7)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 1;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;
	cout << "\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|      Enter new regular unit price:       |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updatePercentageOfTax1PhaseC()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		exit(0);
	}
	while (count < 9)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 1;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|       Enter new percentage of tax:       |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updateFixedCharges1PhaseC()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}
	while (count < 10)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 1;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|       Enter new fixed charges:           |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position - 1)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i < position)
		{
			outFile << input << endl;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updateRegularUnitPrice3PhaseD()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}
	while (count < 12)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 2;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|       Enter new regular unit price:      |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updatePeakHourUnitPrice3PhaseD()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}
	while (count < 13)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 2;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|      Enter new peak hour unit price:     |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updatePercentageOfTax3PhaseD()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}
	while (count < 14)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 2;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|      Enter new percentage of tax:        |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updateFixedCharges3PhaseD()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}
	while (count < 15)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 2;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|     Enter new fixed charges:             |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position - 1)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i < position)
		{
			outFile << input << endl;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updateRegularUnitPrice3PhaseC()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		exit(0);
	}
	while (count < 17)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 3;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|    Enter new regular unit price:         |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updatePeakHourUnitPrice3PhaseC()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		exit(0);
	}
	while (count < 18)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 3;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|     Enter new peak hour unit price:      |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updatePercentageOfTax3PhaseC()
{
	int count{ 0 };
	string input;
	char* data = nullptr;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";			exit(0);
	}
	while (count < 19)
	{
		getStringFile(data, inFile);
		count++;
	}
	int position = (int)inFile.tellg();
	int dataSize = getSize(data);
	//dataSize--;
	//cout << data << " " << position << " " << dataSize;
	position -= dataSize + 3;
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|     Enter new percentage of tax:         |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cin >> input;
	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };
	while (fileData[count] != '\0')
	{
		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i <= position)
		{
			outFile << input;
			i++;
			count = position + dataSize - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}
	outFile.close();
}

void updateFixedCharges3PhaseC()
{
	int count{ 0 };
	char* input;
	char* fileData = nullptr;
	ifstream inFile;
	inFile.open("TariffTaxInfo.txt");
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|       File corrupted or not exist!       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		exit(0);
	}


	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|      Enter new fixed charges:            |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	getStringConsole(input);

	inFile.clear();
	inFile.seekg(0, ios::beg);
	getFileInput(fileData, inFile);
	//cout << endl << fileData << endl;

	inFile.clear();
	inFile.close();
	ofstream outFile;
	outFile.open("TariffTaxInfo.txt");
	count = 0;
	int i{ 0 };

	int position = getSize(fileData) - 1;
	char dummy;

	while (count < 1)
	{
		dummy = fileData[position];

		if (dummy == ',')
		{
			count++;
		}

		else
		{
			position--;
		}


	}

	count = 0;

	while (fileData[count] != '\0')
	{

		if (count < position)
		{
			outFile << fileData[count];
			count++;
			i++;
		}
		else if (i == position)
		{

			outFile << ",";
			outFile << input;
			i++;
			count = getSize(fileData) - 1;
		}
		else
		{
			outFile << fileData[count];
			count++;
			i++;
		}
	}

	outFile.close();
}

void changeTariffTax()
{
	char choice;
	bool wrongChoice{ false };
	int count{ 0 };
	do
	{
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|                    Tarif Tax                     |\n";
		cout << "\t\t\t\t\t\t\t|                                                  |\n";
		cout << "\t\t\t\t\t\t\t|   Press --> (1) To update regular unit price     |\n";
		cout << "\t\t\t\t\t\t\t|   Press --> (2) To add a customer                |\n";
		cout << "\t\t\t\t\t\t\t|   Press --> (3) To update peak hour unit price   |\n";
		cout << "\t\t\t\t\t\t\t|   Press --> (4) To update the percentage of tax  |\n";
		cout << "\t\t\t\t\t\t\t|   Press --> (5) To update the fixed charges      |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		choice = _getch();
		if (choice == '1')
		{
			wrongChoice = false;
			count = 0;
			do
			{
				system("cls");
				if (count != 0)
				{
					cout << "\n\n\t\t\t\t\t\t\t:--------------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|           Invalid choice, Try Again!             |\n";
					cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n\n";
				}
				cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
				cout << "\t\t\t\t\t\t\t|                    Tarif Tax                     |\n";
				cout << "\t\t\t\t\t\t\t|                                                  |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (1) To update regular unit price     |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (2) To add a customer                |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (3) To update peak hour unit price   |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (4) To update the percentage of tax  |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (5) To update the fixed charges      |\n";
				cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
				choice = _getch();
				if (choice == '1')
				{
					updateRegularUnitPrice1PhaseD();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '2')
				{
					updatePercentageOfTax1PhaseD();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '3')
				{
					updateFixedCharges1PhaseD();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else
				{
					wrongChoice = true;
					count++;
				}
			} while (wrongChoice);
		}
		else if (choice == '2')
		{
			wrongChoice = false;
			count = 0;
			do
			{
				system("cls");
				if (count != 0)
				{
					cout << "\n\n\t\t\t\t\t\t\t:--------------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|           Invalid choice, Try Again!             |\n";
					cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n\n";
				}
				cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
				cout << "\t\t\t\t\t\t\t|                    Tarif Tax                     |\n";
				cout << "\t\t\t\t\t\t\t|                                                  |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (1) To update regular unit price     |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (2) To add a customer                |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (3) To update peak hour unit price   |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (4) To update the percentage of tax  |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (5) To update the fixed charges      |\n";
				cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
				choice = _getch();
				if (choice == '1')
				{
					updateRegularUnitPrice1PhaseC();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '2')
				{
					updatePercentageOfTax1PhaseC();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '3')
				{
					updateFixedCharges1PhaseC();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else
				{
					wrongChoice = true;
					count++;
				}
			} while (wrongChoice);
		}
		else if (choice == '3')
		{
			wrongChoice = false;
			count = 0;
			do
			{
				system("cls");
				if (count != 0)
				{
					cout << "\n\n\t\t\t\t\t\t\t:--------------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|           Invalid choice, Try Again!             |\n";
					cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n\n";
				}
				cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
				cout << "\t\t\t\t\t\t\t|                    Tarif Tax                     |\n";
				cout << "\t\t\t\t\t\t\t|                                                  |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (1) To update regular unit price     |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (2) To add a customer                |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (3) To update peak hour unit price   |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (4) To update the percentage of tax  |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (5) To update the fixed charges      |\n";
				cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
				choice = _getch();
				if (choice == '1')
				{
					updateRegularUnitPrice3PhaseD();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				
				}
				else if (choice == '2')
				{
					updatePeakHourUnitPrice3PhaseD();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '3')
				{
					updatePercentageOfTax3PhaseD();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '4')
				{
					updateFixedCharges3PhaseD();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else
				{
					wrongChoice = true;
					count++;
				}
			} while (wrongChoice);
		}
		else if (choice == '4')
		{
			wrongChoice = false;
			count = 0;
			do
			{
				system("cls");
				if (count != 0)
				{
					cout << "\n\n\t\t\t\t\t\t\t:--------------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|           Invalid choice, Try Again!             |\n";
					cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n\n";
				}
				

				cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
				cout << "\t\t\t\t\t\t\t|                    Tarif Tax                     |\n";
				cout << "\t\t\t\t\t\t\t|                                                  |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (1) To update regular unit price     |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (2) To add a customer                |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (3) To update peak hour unit price   |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (4) To update the percentage of tax  |\n";
				cout << "\t\t\t\t\t\t\t|   Press --> (5) To update the fixed charges      |\n";	
				cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";




				choice = _getch();
				if (choice == '1')
				{
					updateRegularUnitPrice3PhaseC();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '2')
				{
					updatePeakHourUnitPrice3PhaseC();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '3')
				{
					updatePercentageOfTax3PhaseC();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else if (choice == '4')
				{
					updateFixedCharges3PhaseC();
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
					cout << "\t\t\t\t\t\t\t|     Successfully updated the record!     |\n";
					cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				}
				else
				{
					wrongChoice = true;
					count++;
				}
			} while (wrongChoice);
		}
		else
		{
			cout << "\nInvalid choice, Try Again!\n";
			wrongChoice = true;
		}
	} while (wrongChoice);
}
