#pragma once
#include"ChangeTarifTaxFile.h"

void storeIntoEmployeesData(const char* userName, const char* password)
{
	ofstream outFile;

	outFile.open("EmployeesData.txt", ios_base::app);

	ifstream inFile;

	inFile.open("EmployeesData.txt");

	char dummy;

	inFile.get(dummy);

	if (inFile.eof())
	{
		outFile << userName;
		outFile << ",";
		outFile << password;

	}

	else
	{
		outFile.seekp(0, ios::end);

		outFile << endl;

		outFile << userName;
		outFile << ",";
		outFile << password;

	}

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|         New Employee Sighned Up          |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	inFile.close();
	outFile.close();

}

void changePassword(const char* newPassword, ifstream& inFile, const char* oldPassword)
{

	if (!inFile)
	{
		inFile.clear();
		inFile.seekg(0, ios::end);
	}

	int position = inFile.tellg();

	position -= getSize(oldPassword);

	ofstream outFile;

	outFile.open("temp.txt");

	inFile.seekg(0, ios::beg);

	char temp;

	inFile.get(temp);

	while (!inFile.eof())
	{
		outFile << temp;
		inFile.get(temp);
	}

	if (!inFile)
	{
		inFile.clear();
		inFile.seekg(0, ios::end);
	}

	outFile.close();

	outFile.open("EmployeesData.txt");

	ifstream newInFile;

	newInFile.open("temp.txt");

	newInFile.get(temp);

	while (!newInFile.eof())
	{
		if (newInFile.tellg() == position)
		{
			newInFile.seekg(getSize(oldPassword), ios::cur);
			outFile << newPassword << endl;
			newInFile.get(temp);
		}

		else
		{

			outFile << temp;

			newInFile.get(temp);

		}

	}


	newInFile.close();
	outFile.close();

}

void showExistingInformation(ofstream& outFile, ifstream& inFile, char*& data)
{
	if (inFile.eof())
	{
		outFile << endl;
	}

	adjustPosition(inFile, data);

	inFile.seekg(-5, ios::cur);

	getStringFile(data, inFile);


	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|           Customer ID:                   |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";	
	cout << data << endl;
	outFile << data << ",";


	delete[]data;


	getStringFile(data, inFile);


	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|           Customer CNIC:                 |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << data << endl;
	outFile << data << ",";


	delete[]data;

	getStringFile(data, inFile);


	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|           Customer Name:                 |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		
	cout << data << endl;
	outFile << data << ",";

	delete[]data;

	getStringFile(data, inFile);


	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|           Customer Address:              |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		
	cout << data << endl;
	outFile << data << ",";

	delete[]data;

	getStringFile(data, inFile);


	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|           Customer PhoneBook:            |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		
	cout << data << endl;
	outFile << data << ",";

	delete[]data;

}

void getCustomerID(ifstream& inFile, int& digit)
{
	inFile.clear();
	inFile.seekg(0, ios::beg);

	int maximum = digit;

	while (!inFile.eof())
	{
		fastForward(inFile);

		if (!inFile.eof())
		{
			inFile >> digit;
			if (digit > maximum)
				maximum = digit;
		}

	}

	digit = maximum + 1;

}

void getMeterID(ifstream& inFile, int& meterID)
{
	inFile.clear();
	inFile.seekg(0, ios::beg);

	int count;
	char dummy;

	while (!inFile.eof())
	{
		count = 0;
		while (count < 10)
		{
			inFile.get(dummy);

			if (dummy == ',')
				count++;
		}

		if (!inFile.eof())
		{
			inFile >> meterID;
		}

		inFile.get(dummy);

	}

	meterID++;

}

void takeCustomerInfoUser(ofstream& outFile, char*& information, int digit, int meterID)
{

	if (digit != -1)
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|           Customer ID:                   |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		if (digit > 0 && digit <= 9)
		{
			cout << 0 << 0 << 0 << digit << endl;
			outFile << 0 << 0 << 0 << digit << ",";
		}

		else if (digit >= 10 && digit <= 99)
		{
			cout << 0 << 0 << digit << endl;
			outFile << endl << 0 << 0 << digit << ",";
		}

		else if (digit >= 100 && digit <= 999)
		{
			cout << 0 << digit << endl;
			outFile << endl << 0 << digit << ",";
		}

		else
		{
			cout << digit << endl;
			outFile << endl << digit << ",";
		}

		outFile << information << ",";

		delete[]information;

		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|     --> Enter Name of the Customer       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";	
		getStringConsole(information);

		outFile << information << ",";

		delete[]information;

		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|     --> Enter address of the Customer    |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";			
		getStringConsole(information);

		outFile << information << ",";

		delete[]information;

		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|    --> Enter PhoneBook of the Customer   |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		getStringConsole(information);

		while (!verifyPhoneNo(information))
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
			cout << "\t\t\t\t\t\t\t|    --> Enter PhoneBook again             |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]information;

			getStringConsole(information);
		}

		outFile << information << ",";
		delete[]information;
	}

	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (1) To add Domestic              |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (2) To add Commercial            |\n";
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";	
	information = new char[1];

	information[0] = _getch();

	while (information[0] != '1' && information[0] != '2')
	{
		information[0] = _getch();
	}

	if (information[0] == '1')
	{
		outFile << "Domestic,";
	}

	else
	{
		outFile << "Commercial,";
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
	}

	else
	{
		outFile << "3,";
	}

	delete[]information;

	cout << endl;
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

	outFile << " , ,";

	cout << "Meter ID: ";

	if (meterID > 0 && meterID <= 9)
	{
		cout << 0 << 0 << 0 << meterID << endl;
		outFile << 0 << 0 << 0 << meterID;
	}

	else if (meterID >= 10 && meterID <= 99)
	{
		cout << 0 << 0 << meterID << endl;
		outFile << 0 << 0 << meterID;
	}

	else if (meterID >= 100 && meterID <= 999)
	{
		cout << 0 << meterID << endl;
		outFile << 0 << meterID;
	}

	else
	{
		cout << meterID << endl;
		outFile << meterID;
	}

	system("pause");

}

void addCustomer()
{
	char* information = nullptr;

	system("cls");
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	getStringConsole(information);

	while (!verifyCNICFormat(information))
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
		cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		delete[]information;
		getStringConsole(information);
	}

	if (verifyCNIC(information))
	{
		ifstream inFile;
		loadFile(inFile, "CustomerInfo.txt");

		ofstream outFile;
		outFile.open("CustomerInfo.txt", ios_base::app);

		int digit = 0;
		int meterID = 0;

		inFile >> digit;

		if (inFile.eof())
		{
			digit = 1;
			meterID = 1;
			takeCustomerInfoUser(outFile, information, digit, meterID);
		}

		else
		{

			int numOfMeters = verfiyNumberOfMeters(information, inFile);

			if (numOfMeters != metersLimit)
			{
				if (numOfMeters > 0)
				{
					getMeterID(inFile, meterID);
					showExistingInformation(outFile, inFile, information);
					takeCustomerInfoUser(outFile, information, -1, meterID);

				}

				else
				{
					getMeterID(inFile, meterID);
					getCustomerID(inFile, digit);
					if (inFile.eof())
					{
						outFile << endl;
					}
					takeCustomerInfoUser(outFile, information, digit, meterID);
				}

			}

			else
			{
				cout << "\t\t\t\t\t\t\t:------------------------------------------------------------:\n";
				cout << "\t\t\t\t\t\t\t|   3 Meters are already registered against the Customer     |\n";
				cout << "\t\t\t\t\t\t\t:------------------------------------------------------------:\n";
				system("pause");
			}

		}


		delete[]information;
		inFile.close();
		outFile.close();
	}

	else
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|             Incorrect CNIC               |\n";
		cout << "\t\t\t\t\t\t\t|   does not existing in NADRA DataBase    |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		delete[]information;
		system("pause");
	}

}