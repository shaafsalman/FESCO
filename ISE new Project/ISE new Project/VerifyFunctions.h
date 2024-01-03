#pragma once
#include"Checks.h"

bool verifyCustomer(ifstream& inFile, const char* customerID, const char* CNIC)
{

	char* fileCustomerID = nullptr;
	char* fileCNIC = nullptr;

	while (!inFile.eof())
	{
		getStringFile(fileCustomerID, inFile);
		if (stringsEqual(fileCustomerID, customerID))
		{

			getStringFile(fileCNIC, inFile);

			if (stringsEqual(fileCNIC, CNIC))
			{

				delete[]fileCustomerID;
				delete[]fileCNIC;

				return true;
			}

			else
			{
				delete[]fileCustomerID;
				delete[]fileCNIC;
				cout << "Invalid CNIC; CNIC not found in customer info" << endl;


				return false;
			}

		}

		else
		{
			delete[]fileCustomerID;
			delete[]fileCNIC;

			fastForward(inFile);
		}

	}

	cout << "Invalid CustomerID; Customer ID not found in customer info." << endl;
	return false;

}

bool verifyEmployee(ifstream& inFile, const char* userName, const char* password)
{

	char* fileUserName = nullptr;
	char* filePassword = nullptr;

	while (!inFile.eof())
	{
		getStringFile(fileUserName, inFile);
		if (stringsEqual(fileUserName, userName))
		{

			getStringFile(filePassword, inFile);

			if (stringsEqual(filePassword, password))
			{

				delete[]filePassword;
				delete[]fileUserName;

				return true;
			}

			else
			{
				delete[]filePassword;
				delete[]fileUserName;
		
				cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
				cout << "\t\t\t\t\t\t\t|             Invalid Password.            |\n";
				cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";

				return false;
			}

		}

		else
		{
			delete[]filePassword;
			delete[]fileUserName;

			fastForward(inFile);
		}

	}

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|             Invalid username.            |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";	
	return false;

}

bool verifyUserName(const char* userName)
{
	ifstream inFile;
	loadFile(inFile, "EmployeesData.txt");

	char dummy;

	inFile.get(dummy);

	if (inFile.eof())
	{
		inFile.close();
		return true;
	}

	inFile.seekg(0, ios::beg);

	char* fileUserName = nullptr;

	while (!inFile.eof())
	{
		getStringFile(fileUserName, inFile);
		if (stringsEqual(fileUserName, userName))
		{
			delete[]fileUserName;

			inFile.close();

			return false;
		}


		else
		{
			delete[]fileUserName;

			fastForward(inFile);
		}


	}

	inFile.close();

	return true;

}

bool verifyCNICInCustomer(char* CNIC)
{
	char* nadraCNIC = nullptr;

	ifstream inFile;
	loadFile(inFile, "CustomerInfo.txt");

	inFile.seekg(customerIdLimit + 1, ios::cur);

	getStringFile(nadraCNIC, inFile);

	while (!inFile.eof())
	{
		if (stringsEqual(CNIC, nadraCNIC))
		{
			return true;
		}

		fastForward(inFile);
		if (!inFile.eof())
		{
			inFile.seekg(customerIdLimit + 1, ios::cur);
			delete[]nadraCNIC;
			getStringFile(nadraCNIC, inFile);
		}
	}

	inFile.close();

	//inFile.seekg(0, ios::beg);

	return false;

}

bool verifyPhoneInCustomer(char* phone)
{
	char* fileData = nullptr;
	int count = 0;
	char dummy;

	ifstream inFile;
	loadFile(inFile, "CustomerInfo.txt");

	while (!inFile.eof())
	{
		getStringFile(fileData, inFile);

		if (stringsEqual(fileData, phone))
		{
		
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|        Phone Number already exists.      |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			return true;
		}

		delete[]fileData;

	}

	return false;

}

bool verifyCNIC(char* CNIC)
{
	char* nadraCNIC = nullptr;

	ifstream inFile;
	loadFile(inFile, "NADRADB.txt");

	getStringFile(nadraCNIC, inFile);

	while (!inFile.eof())
	{
		if (stringsEqual(CNIC, nadraCNIC))
		{
			return true;
		}

		fastForward(inFile);
		getStringFile(nadraCNIC, inFile);
	}

	inFile.close();

	inFile.seekg(0, ios::beg);

	return false;

}

int verfiyNumberOfMeters(const char* CNIC, ifstream& inFile)
{
	//	ifstream inFile;

		//loadFile(inFile, "CustomerInfo.txt");

	char* fileCNIC = nullptr;
	int count = 0;

	inFile.seekg(1, ios::cur);

	while (!inFile.eof())
	{
		getStringFile(fileCNIC, inFile);

		if (stringsEqual(CNIC, fileCNIC))
		{
			count++;
		}

		if (count == metersLimit)
		{
			//inFile.seekg(0, ios::beg);
			return count;
		}

		else
		{
			fastForward(inFile);

			if (!inFile.eof())
				inFile.seekg(customerIdLimit + 1, ios::cur);

		}
	}

	//inFile.close();

	//inFile.seekg(0, ios::beg);

	return count;

}

bool verifyMeter(char*& data, char* cnic)
{
	char dummy;
	bool check = true;
	ifstream inFile;
	char* fileData;
	loadFile(inFile, "CustomerInfo.txt");

	adjustPosition2(inFile, cnic);
	fastForward(inFile);

	if (inFile.eof() && check == true)
	{
		inFile.clear();
		inFile.seekg(-1, ios::end);

		check = false;
	}

	while (!inFile.eof())
	{
		if (check == true)
			inFile.seekg(-6, ios::cur);

		else
		{
			inFile.seekg(-3, ios::cur);
		}

		getStringFile(fileData, inFile);

		if (stringsEqual(data, fileData))
		{
			inFile.close();
			return true;
		}

		adjustPosition2(inFile, cnic);
		fastForward(inFile);


		if (inFile.eof() && check == true)
		{
			inFile.clear();
			inFile.seekg(-1, ios::end);

			check = false;
		}

	}

	return false;

}
