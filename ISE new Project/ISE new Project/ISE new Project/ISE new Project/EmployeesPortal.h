#pragma once
#include"BillingInfo.h"

void employeesPortal(const char* userName, const char* password, ifstream& file)
{
	char choice;

	system("cls");

	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|            Logged In Successfully            |\n";
	cout << "\t\t\t\t\t\t\t|                                              |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (1) To  change Password          |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (2) To add a customer            |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (3) change Customer Information  |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (4) To add billing information   |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (5) To Enter Tax Credentials     |\n";
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	choice = _getch();

	if (choice == '1')
	{

		char* newPassword = nullptr;

		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|           Enter New Password:            |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		
		getStringConsole(newPassword);

		while (!checkPassword(newPassword))
		{

			cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|              Invalid Password!               |\n";
			cout << "\t\t\t\t\t\t\t|                                              |\n";
			cout << "\t\t\t\t\t\t\t|   Password must be of atleast 8 characters   |\n";
			cout << "\t\t\t\t\t\t\t|   Password must contain atleast              |\n";
			cout << "\t\t\t\t\t\t\t|           one digit                          |\n";
			cout << "\t\t\t\t\t\t\t|           one alphabet                       |\n";
			cout << "\t\t\t\t\t\t\t|           one Special Character              |\n";
			cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";



			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|           Enter  Password again :        |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]newPassword;
			getStringConsole(newPassword);
		}

		changePassword(newPassword, file, password);

	}

	else if (choice == '2')
	{
		addCustomer();
	}

	else if (choice == '3')
	{

		ifstream in;
		loadFile(in, "CustomerInfo.txt");

		char dummy;

		in.get(dummy);

		if (in.eof())
		{

			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|           No Customer Exsist    :        |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		}

		else
		{
			changeCustomerInfo();
		}

		in.close();

	}

	else if (choice == '4')
	{

		char* data = nullptr;

		int* numdata = nullptr;


		ifstream info;
		loadFile(info, "CustomerInfo.txt");

		//id
		getStringFile(data, info);
		storeIntoBillingInfo(data);
		////billin month
		//cout << "\nEnter the Billing Month (1-12)\n";
		//getStringConsole(data);
		//storeIntoBillingInfo(data);
		//cnic
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		getStringConsole(data);
		storeIntoBillingInfo(data);

		while (!verifyCNICFormat(data))
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
			cout << "\t\t\t\t\t\t\t|    Enter the CNIC(Without Dashes):       |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]data;
			getStringConsole(data);
			getStringFile(data, info);
		}

		if (verifyCNICInCustomer(data))
		{
			storeIntoTempFile("CustomerInfo.txt", "temp.txt");
			storeIntoBillingInfo(data);
			MeterSetup(data);
		}
		else
		{
			cout << "" << endl;
			cout << "\t\t\t\t\t\t\t:---------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|   Customer with this CNIC does not exist.   |\n";
			cout << "\t\t\t\t\t\t\t:---------------------------------------------:\n";
		}

	}

	else if (choice == '5')
	{

		changeTariffTax();
	}

}
