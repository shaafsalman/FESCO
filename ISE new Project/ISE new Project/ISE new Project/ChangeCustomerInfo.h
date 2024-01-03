#pragma once
#include"AddCustomer.h"

void storeIntoTempFile(const char* sourceFile, const char* destinationFile)
{
	ifstream inFile;
	loadFile(inFile, sourceFile);

	ofstream outFile;
	outFile.open(destinationFile);

	char character;

	inFile.get(character);

	while (!inFile.eof())
	{
		outFile << character;

		inFile.get(character);

	}

	outFile.close();
	inFile.close();

}

void showMeters(char* cnic)
{
	int count = 0;
	int count1 = 0;
	ifstream inFile;
	loadFile(inFile, "CustomerInfo.txt");
	char* data;

	adjustPosition2(inFile, cnic);
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	while (count < metersLimit && !inFile.eof())
	{
		count1 = 0;
		while (count1 < 9)
		{
			getStringFile(data, inFile);
			delete[]data;
			count1++;
		}

		getStringFile(data, inFile);
		cout << "\t\t\t\t\t\t\t|               Meter: " << data <<"                |\n";

		if (!inFile.eof())
			adjustPosition2(inFile, cnic);

	}
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
}

void askInfo(ofstream& outFile)
{
	char* information;

	cout << "Domestic[1] OR Commercial[2]: ";
	information = new char[1];

	information[0] = _getch();

	while (information[0] != '1' && information[0] != '2')
	{
		information[0] = _getch();
	}

	if (information[0] == '1')
	{
		outFile << "Domestic,";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|                 Domestic Meter                   |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	}

	else
	{
		outFile << "Commercial,";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|                 Commercial Meter                 |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	}

	cout << endl;

	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (1) To add phase 1               |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (2) To add phase 3               |\n";
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	information[0] = _getch();

	while (information[0] != '1' && information[0] != '2')
	{
		information[0] = _getch();
	}

	if (information[0] == '1')
	{
		outFile << "1,";
		cout << "1,";
	}

	else
	{
		outFile << "3,";
		cout << "3,";
	}

	delete[]information;
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|   Enter the Connection Date(DD-MM-YYYY): |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	getStringConsole(information);

	while (!verifyDate(information))
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
		cout << "\t\t\t\t\t\t\t|   Enter the Connection Date(DD-MM-YYYY): |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		delete[]information;
		getStringConsole(information);
	}

	outFile << information << ",";

	cout << information << ",";


}

void changeMeter(char* cnic)
{
	char* meterID;

	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|   Meters  registered under the given CNIC:       |\n";
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	showMeters(cnic);


	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|          Enter the Meter ID to change it:        |\n";
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	getStringConsole(meterID);

	while (!verifyMeter(meterID, cnic))
	{
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|         Choose among the given options           |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		delete[]meterID;

		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|         Enter the Meter ID to change it:         |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		getStringConsole(meterID);

	}

	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "temp.txt");

	ofstream outFile;
	outFile.open("CustomerInfo.txt");

	char* data;
	int count = 0;
	bool check = true;
	int position;

	adjustPosition3(inFile, meterID);

	inFile.seekg(-1, ios::cur);
	dummy = inFile.peek();

	while (count < 6)
	{
		if (dummy == ',')
		{
			count++;
		}

		if (count != 6)
		{
			inFile.seekg(-1, ios::cur);
			dummy = inFile.peek();
		}

	}

	position = inFile.tellg();

	//cout << "Position: "  << position << endl;

	inFile.clear();
	inFile.seekg(0, ios::beg);

	dummy = '\0';

	int position2;

	while (!inFile.eof())
	{
		getStringFile(data, inFile);

		if (inFile.eof())
			check = true;


		if (!inFile.eof())
		{
			position2 = outFile.tellp();
			position2--;
			//cout << "Position 2: " << position2 << endl;
			//cout << "Position 1: " << position << endl;
			if (position2 == position)
			{
				askInfo(outFile);

				outFile << " , ," << meterID;
				cout << " , ," << meterID;

				inFile.get(dummy);

				while (dummy != '\n' && !inFile.eof())
				{
					inFile.get(dummy);
				}

				check = false;

			}

			else
			{
				inFile.seekg(-1, ios::cur);
				inFile.get(dummy);
				outFile << data;
				cout << data;
				if (dummy == ',')
				{
					outFile << dummy;
					cout << dummy;
				}
			}

		}

		if (inFile.eof() && check == true)
		{
			outFile << data;
			cout << data;
		}

		else
		{
			if (dummy == '\n')
			{
				outFile << endl;
				cout << endl;
				dummy = '\0';
			}
		}

		delete[]data;

	}

	inFile.close();
	outFile.close();


	system("pause");

}

void changePhoneNumber(char* cnic)
{
	char* newPhone;

	char* data;
	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "temp.txt");

	ofstream outFile;
	outFile.open("CustomerInfo.txt");

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|    --> Enter new phone of the Customer   |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";	
	getStringConsole(newPhone);

	while (!verifyPhoneNo(newPhone))
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
		cout << "\t\t\t\t\t\t\t|    --> Enter number  again               |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		delete[]newPhone;

		getStringConsole(newPhone);

	}

	while (!verifyPhoneInCustomer(newPhone))
	{

		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|         Phone Number already exists      |\n";
		cout << "\t\t\t\t\t\t\t|    --> Enter number  again               |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		delete[]newPhone;

		getStringConsole(newPhone);
	}

	while (!inFile.eof())
	{
		getStringFile(data, inFile);

		if (!inFile.eof())
		{
			if (stringsEqual(cnic, data))
			{
				inFile.seekg(-1, ios::cur);
				inFile.get(dummy);
				outFile << data;
				if (dummy == ',')
					outFile << dummy;

				delete[]data;
				getStringFile(data, inFile);
				outFile << data << ",";

				delete[]data;
				getStringFile(data, inFile);
				outFile << data << ",";

				outFile << newPhone << ",";

				inFile.get(dummy);

				while (dummy != ',')
				{
					inFile.get(dummy);
				}
			}

			else
			{
				inFile.seekg(-1, ios::cur);
				inFile.get(dummy);
				outFile << data;
				if (dummy == ',')
					outFile << dummy;
			}

		}

		if (inFile.eof())
		{
			outFile << data;
		}

		else
		{
			if (dummy == '\n')
			{
				outFile << endl;
				dummy = '\0';
			}
		}

		delete[]data;

	}

	inFile.close();
	outFile.close();

}

void changeAddress(char* cnic)
{
	char* newAddress;

	char* data;
	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "temp.txt");

	ofstream outFile;
	outFile.open("CustomerInfo.txt");
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|    --> Enter new address of the Customer |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	getStringConsole(newAddress);

	while (!inFile.eof())
	{
		getStringFile(data, inFile);

		if (!inFile.eof())
		{
			if (stringsEqual(cnic, data))
			{
				inFile.seekg(-1, ios::cur);
				inFile.get(dummy);
				outFile << data;
				if (dummy == ',')
					outFile << dummy;

				delete[]data;
				getStringFile(data, inFile);
				outFile << data << ",";

				outFile << newAddress << ",";

				inFile.get(dummy);

				while (dummy != ',')
				{
					inFile.get(dummy);
				}
			}

			else
			{
				inFile.seekg(-1, ios::cur);
				inFile.get(dummy);
				outFile << data;
				if (dummy == ',')
					outFile << dummy;
			}

		}

		if (inFile.eof())
		{
			outFile << data;
		}

		else
		{
			if (dummy == '\n')
			{
				outFile << endl;
				dummy = '\0';
			}
		}

		delete[]data;

	}

	inFile.close();
	outFile.close();

}

void changeName(char* cnic)
{
	char* newName;

	char* data;
	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "temp.txt");

	ofstream outFile;
	outFile.open("CustomerInfo.txt");

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|    --> Enter new  Name                   |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		getStringConsole(newName);

	while (!inFile.eof())
	{
		getStringFile(data, inFile);

		if (!inFile.eof())
		{
			if (stringsEqual(cnic, data))
			{
				inFile.seekg(-1, ios::cur);
				inFile.get(dummy);
				outFile << data;
				if (dummy == ',')
					outFile << dummy;

				outFile << newName << ",";

				inFile.get(dummy);

				while (dummy != ',')
				{
					inFile.get(dummy);
				}
			}

			else
			{
				inFile.seekg(-1, ios::cur);
				inFile.get(dummy);
				outFile << data;
				if (dummy == ',')
					outFile << dummy;
			}

		}

		if (inFile.eof())
		{
			outFile << data;
		}

		else
		{
			if (dummy == '\n')
			{
				outFile << endl;
				dummy = '\0';
			}
		}

		delete[]data;

	}

	inFile.close();
	outFile.close();

}

void changeCustomerInfo()
{
	char choice;
	char* data;

	system("cls");


	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|                                                  |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (1) To change Customer Name          |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (2) To change Customer Address       |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (3) To change Customer Phone Number  |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (4) To change Customer Meter         |\n";
	cout << "\t\t\t\t\t\t\t|                                                  |\n";
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	choice = _getch();

	if (choice == '1')
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";	
		getStringConsole(data);

		while (!verifyCNICFormat(data))
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
			cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]data;
			getStringConsole(data);
		}

		if (verifyCNICInCustomer(data))
		{
			storeIntoTempFile("CustomerInfo.txt", "temp.txt");
			changeName(data);
		}

		else
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|  Customer with this CNIC does not exist  |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		}

	}

	else if (choice == '2')
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		getStringConsole(data);

		while (!verifyCNICFormat(data))
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
			cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]data;
			getStringConsole(data);
		}

		if (verifyCNICInCustomer(data))
		{
			storeIntoTempFile("CustomerInfo.txt", "temp.txt");
			changeAddress(data);


		}

		else
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|  Customer with this CNIC does not exist  |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		}
	}

	else if (choice == '3')
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		
		getStringConsole(data);

		while (!verifyCNICFormat(data))
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
			cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]data;
			getStringConsole(data);
		}

		if (verifyCNICInCustomer(data))
		{
			storeIntoTempFile("CustomerInfo.txt", "temp.txt");
			changePhoneNumber(data);


		}

		else
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|  Customer with this CNIC does not exist  |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		}
	}

	else if (choice == '4')
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";			
		getStringConsole(data);

		while (!verifyCNICFormat(data))
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
			cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]data;
			getStringConsole(data);
		}

		if (verifyCNICInCustomer(data))
		{
			storeIntoTempFile("CustomerInfo.txt", "temp.txt");
			changeMeter(data);


		}

		else
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|  Customer with this CNIC does not exist  |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		}
	}

}
