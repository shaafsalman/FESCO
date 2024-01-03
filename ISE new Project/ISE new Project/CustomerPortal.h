#include"EmployeesPortal.h"

void showBill(ifstream& inFile, char*& fileData)
{
	inFile.seekg(-24, ios::cur);

	delete[]fileData;
	getStringFile(fileData, inFile);
	cout << endl;
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|       Customer ID :"<< fileData<<endl;

	delete[]fileData;
	getStringFile(fileData, inFile);
	cout << "\t\t\t\t\t\t\t|       Customer CNIC :" << fileData << endl;

	delete[]fileData;
	getStringFile(fileData, inFile);
	cout << "\t\t\t\t\t\t\t|       Meter ID :" << fileData << endl;

	delete[]fileData;
	getStringFile(fileData, inFile);
	cout << "\t\t\t\t\t\t\t|       Meter Phase :" << fileData << endl;

	if (stringsEqual(fileData, "1"))
	{
		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Regular Units :" << fileData << endl;

		delete[]fileData;
		getStringFile(fileData, inFile);

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Reading Date :" << fileData << endl;
		 

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Regular Units Bill :" << fileData << endl;


		delete[]fileData;
		getStringFile(fileData, inFile);

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       T1 :" << fileData << endl;

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       T2 :" << fileData << endl;


		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Total Bill:" << fileData << endl;

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Due Date :" << fileData << endl;

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Paid/Unpaid :" << fileData << endl;
		cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";

	}

	else
	{

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Regular Units :" << fileData << "      | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Peak Units :" << fileData << "      | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Reading Date :" << fileData << "      | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Regualar Units Bill :" << fileData << "      | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Peak Units Bill :" << fileData << "      | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       T1 :" << fileData << "      | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       T2 :" << fileData << "      | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Total Bill :" << fileData << "        | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Due Date :" << fileData << "      | \n";

		delete[]fileData;
		getStringFile(fileData, inFile);
		cout << "\t\t\t\t\t\t\t|       Paid Unpaid :" << fileData << "      | \n";

		cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";

	}

}


void viewBill(char* customerID, char* cnic)
{
	ifstream inFile;
	loadFile(inFile, "BillingInfo.txt");

	char* meterID;
	char* fileData=nullptr;
	int commaCount = 0;
	char dummy;
	cout << "\t\t\t\t\t\t\t:-----------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|     meters are registered under the given CNIC :\n";
	cout << "\t\t\t\t\t\t\t|              ";
	showMeters(cnic);

	cout << "\t\t\t\t\t\t\t|            Enter the Meter ID to change it :\n";
	cout << "\t\t\t\t\t\t\t:-----------------------------------------------------:\n";

	getStringConsole(meterID);

	while (!verifyMeter(meterID, cnic))
	{
		cout << "\t\t\t\t\t\t\t|            Enter the Meter ID to change it :\n";
		delete[]meterID;

		cout << "\t\t\t\t\t\t\t | Enter the Meter ID to change it: " << endl;
		cout << "\t\t\t\t\t\t\t:-----------------------------------------------------:\n";

		getStringConsole(meterID);

	}

	inFile.seekg(5, ios::cur);
	getStringFile(fileData, inFile);

	while (!inFile.eof())
	{
		if (stringsEqual(meterID, fileData))
		{
			cout << endl;
			showBill(inFile, fileData);
			cout << endl;
		}

		if (!inFile.eof())
		{
			inFile.seekg(-1, ios::cur);
			inFile.get(dummy);

			if (dummy == '\n')
			{
				inFile.seekg(5, ios::cur);
			}

			delete[]fileData;

			getStringFile(fileData, inFile);
		}
	}
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";


	delete[]fileData;
	inFile.close();

	system("pause");

}
