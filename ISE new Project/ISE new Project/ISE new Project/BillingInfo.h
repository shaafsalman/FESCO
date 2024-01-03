#pragma once

#include"ChangeCustomerInfo.h"



void storeint(char* ptr, int num)
{
	string number = to_string(num);
	if (ptr != nullptr)
	{
		for (int i = 0; i < number.length(); i++)
		{
			ptr[i] = number[i];
		}
	}
}

void storeIntoBillingInfo(const char* data)
{
	ofstream outFile;
	outFile.open("Billinginfo.txt", ios_base::app);
	ifstream inFile;
	inFile.open("Billinginfo.txt");
	char dummy;


	if (inFile.eof())
	{
		outFile << data;
		outFile << ",";
	}

	else
	{
		outFile.seekp(0, ios::end);
		outFile << data;
		outFile << ",";
	}

	inFile.close();
	outFile.close();

}

void storeIntoBillingInfo(int  data)
{
	ofstream outFile;
	outFile.open("Billinginfo.txt", ios_base::app);
	ifstream inFile;
	inFile.open("Billinginfo.txt");
	char dummy;

    if (data == '\n')
	{
		outFile << data;

	}
	if (inFile.eof())
	{
		outFile << data;
		outFile << ",";
	}
	
	else
	{
		outFile.seekp(0, ios::end);
		outFile << data;
		outFile << ",";
	}


	inFile.close();
	outFile.close();

}

char MeterTypeCheck(char* meterID)
{

	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "CustomerInfo.txt");

	char* data;
	int count = 0;
	bool check = true;
	int position;

	adjustPosition3(inFile, meterID);
	inFile.seekg(-1, ios::cur);
	dummy = inFile.peek();


	while (count < 4)
	{
		if (dummy == ',')
		{
			count++;
		}

		if (count != 4)
		{
			inFile.seekg(-1, ios::cur);
			dummy = inFile.peek();
		}
	}

	inFile.seekg(-1, ios::cur);
	position = inFile.tellg();

	//cout << "\nPosition: " << position << endl;
	char point;
	inFile.get(point);
	//cout << "Type : " << point << endl;

	inFile.clear();
	inFile.seekg(0, ios::beg);
	inFile.close();

	return point;
}

char MeterStatusCheck(char* meterID)
{
	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "CustomerInfo.txt");

	char* data;
	int count = 0;
	bool check = true;
	int position;

	adjustPosition3(inFile, meterID);
	inFile.seekg(-1, ios::cur);
	dummy = inFile.peek();


	while (count < 5)
	{
		if (dummy == ',')
		{
			count++;
		}

		if (count != 5)
		{
			inFile.seekg(-1, ios::cur);
			dummy = inFile.peek();
		}
	}

	inFile.seekg(-1, ios::cur);
	position = inFile.tellg();

	//cout << "\nPosition: " << position << endl;
	char point;
	inFile.get(point);
	//cout << "Type : " << point << endl;

	inFile.clear();
	inFile.seekg(0, ios::beg);
	inFile.close();

	return point;
}

void storeReadings(ofstream& out, const char* currentRegular, const char* currentPeak)
{
	out << currentRegular;
	out << ",";
	out << currentPeak;
	cout << currentPeak;
	out << ",";

}

void skiplines(std::istream& is, size_t n, char delim)
{
	size_t i = 0;
	while (i++ < n)
		is.ignore(80, delim);

}

void taxsetter(char* meterID, int total, char* currentRegular, char* currentPeak)
{
	char* data = nullptr;
	char* totalcostptr = nullptr;

	int i = 0;
	ifstream info;
	loadFile(info, "TariffTaxInfo.txt");



	if (MeterStatusCheck(meterID) == 'c')//domestic   --> c ends with c  ,dom single
	{
		if (MeterTypeCheck(meterID) == '1')
		{
			getStringFile(data, info);
			getStringFile(data, info);
			storeIntoBillingInfo(data);//sales tax
			total += myStoi(data);

			getStringFile(data, info);
			getStringFile(data, info);
			storeIntoBillingInfo(data);//fixed charges
			total += myStoi(data);

			getStringFile(data, info); //per unit tariff
			int temp = myStoi(data);
			temp *= myStoi(currentRegular);
			total += temp;
		}
		else //dom3
		{
			skiplines(info, 2, '\n');

			getStringFile(data, info);
			getStringFile(data, info);
			storeIntoBillingInfo(data);//sales tax normal
			total += myStoi(data);
			getStringFile(data, info);
			storeIntoBillingInfo(data);//sales tax peak
			total += myStoi(data);


			getStringFile(data, info);
			storeIntoBillingInfo(data);//fixed charges
			total += myStoi(data);

			getStringFile(data, info); //per unit tariff
			int temp = myStoi(data);
			temp *= myStoi(currentRegular);
			temp *= myStoi(currentPeak);
			total += temp;
		}
	}
	else //commercial
	{
		if (MeterTypeCheck(meterID) == '1')  //com single
		{
			skiplines(info, 1, '\n');

			getStringFile(data, info);
			getStringFile(data, info);
			storeIntoBillingInfo(data);//sales tax
			total += myStoi(data);

			getStringFile(data, info);
			getStringFile(data, info);
			storeIntoBillingInfo(data);//fixed charges
			total += myStoi(data);

			getStringFile(data, info); //per unit tariff
			int temp = myStoi(data);
			temp *= myStoi(currentRegular);
			total += temp;

		}
		else //com 3
		{
			cout << "Commercial 3 Phase\n";
			skiplines(info, 4, '\n');

			getStringFile(data, info);
			getStringFile(data, info);
			storeIntoBillingInfo(data);//sales tax normal
			total += myStoi(data);
			getStringFile(data, info);
			storeIntoBillingInfo(data);//sales tax peak
			total += myStoi(data);


			getStringFile(data, info);
			storeIntoBillingInfo(data);//fixed charges
			total += myStoi(data);

			getStringFile(data, info); //per unit tariff
			int temp = myStoi(data);
			temp *= myStoi(currentRegular);
			temp *= myStoi(currentPeak);
			total += temp;
		}
	}

	//storeint(data, total);
	storeIntoBillingInfo(total);//total charges

}

void CostCalculator(char* meterID, char* currentRegular, char* currentPeak)
{
	int UnitsUsed = 0;
	int totalCost = 0;
	int RegularCost = 0;
	int PeakCost = 0;

	if (MeterStatusCheck(meterID) == 'c')//domestic   --> c ends with c  ,dom single
	{
		if (MeterTypeCheck(meterID) == '1')
		{
			cout << "Domestic Single Phase\n";
			UnitsUsed = myStoi(currentRegular);
			cout << "units used " << UnitsUsed << endl;
			RegularCost = 5 * UnitsUsed;
			PeakCost = 0;

			totalCost = RegularCost;

			cout << "units used" << UnitsUsed << endl;
			cout << "regularcost" << RegularCost << endl;
			cout << "Peak cost" << PeakCost << endl;
			storeIntoBillingInfo(RegularCost);
			storeIntoBillingInfo(PeakCost);
		}
		else //dom3
		{
			cout << "Domestic 3 Phase\n";

			UnitsUsed = myStoi(currentRegular);
			RegularCost = 8 * UnitsUsed;

			UnitsUsed = myStoi(currentPeak);
			PeakCost = 12 * UnitsUsed;

			totalCost += RegularCost + PeakCost;

			cout << "units used" << UnitsUsed << endl;
			cout << "regularcost" << RegularCost << endl;
			cout << "Peak cost" << PeakCost << endl;

			storeIntoBillingInfo(RegularCost);
			storeIntoBillingInfo(PeakCost);
		}
	}
	else //commercial
	{
		if (MeterTypeCheck(meterID) == '1')  //com single
		{
			cout << "Commercial Single Phase\n";

			UnitsUsed = myStoi(currentRegular);
			RegularCost = 15 * UnitsUsed;
			totalCost = RegularCost;

			cout << "units used " << UnitsUsed << endl;
			cout << "regularcost " << RegularCost << endl;
			cout << "Peak cost " << PeakCost << endl;



			storeIntoBillingInfo(RegularCost);
			storeIntoBillingInfo(PeakCost);
		}
		else //com 3
		{
			cout << "Commercial 3 Phase\n";

			UnitsUsed = myStoi(currentRegular);
			cout << "units used " << UnitsUsed << endl;
			RegularCost = 18 * UnitsUsed;

			UnitsUsed = myStoi(currentPeak);
			PeakCost = 25 * UnitsUsed;

			totalCost += (RegularCost) + PeakCost;

			cout << "units used " << UnitsUsed << endl;
			cout << "regularcost " << RegularCost << endl;
			cout << "Peak cost " << PeakCost << endl;


			storeIntoBillingInfo(RegularCost);
			storeIntoBillingInfo(PeakCost);
		}
	}
    
	taxsetter(meterID,totalCost,currentRegular,currentPeak);	
}

bool RegualarUnitsUsed(char* meterID, char* currentRegular)
{
	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "CustomerInfo.txt");

	char* data;
	int count = 0;
	bool check = true;
	int position;

	adjustPosition3(inFile, meterID);
	inFile.seekg(-1, ios::cur);
	dummy = inFile.peek();


	while (count < 2)
	{
		if (dummy == ',')
		{
			count++;
		}

		if (count != 2)
		{
			inFile.seekg(-1, ios::cur);
			dummy = inFile.peek();
		}
	}

	char point = ' ';
	inFile.seekg(-2, ios::cur);
	position = inFile.tellg();
	char regular[3];
	int i = 0;
	while (point != ',')
	{
		inFile.get(point);
		regular[i] = point;
		if (point == ',')
		{
			regular[i] = '\0';
		}
		i++;
	}


	if (myStoi(currentRegular) > myStoi(regular))
	{
		//cout << "Regular True\n";
		int temp = myStoi(currentRegular) - myStoi(regular);
		storeint(currentRegular, temp);
		inFile.clear();
		inFile.seekg(0, ios::beg);
		inFile.close();
		cout << "currentregular0 :" << currentRegular << endl;

		return true;
	}

	cout << "currentregular1 :" << currentRegular << endl;


	inFile.clear();
	inFile.seekg(0, ios::beg);
	inFile.close();

	return false;

}

bool PeakUnitsUsed(char* meterID, char* currentPeak)
{
	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "CustomerInfo.txt");

	char* data;
	int count = 0;
	bool check = true;
	int position;

	adjustPosition3(inFile, meterID);
	inFile.seekg(-1, ios::cur);
	dummy = inFile.peek();


	while (count < 1)
	{
		if (dummy == ',')
		{
			count++;
		}

		if (count != 1)
		{
			inFile.seekg(-1, ios::cur);
			dummy = inFile.peek();
		}
	}

	char point = ' ';
	inFile.seekg(-2, ios::cur);
	position = inFile.tellg();

	//cout << "Peak\n";
	char Peak[3];
	int i = 0;
	while (point != ',')
	{
		inFile.get(point);
		Peak[i] = point;
		if (point == ',')
		{
			Peak[i] = '\0';
		}
		i++;
	}

	if (myStoi(currentPeak) > myStoi(Peak))
	{
		int temp = myStoi(currentPeak) - myStoi(Peak);
		storeint(currentPeak, temp);
		inFile.clear();
		inFile.seekg(0, ios::beg);
		inFile.close();
		
		cout << "currentpeak0 :" << currentPeak << endl;
		return true;
	}
	if (currentPeak == 0 || currentPeak == nullptr)
	{
		cout << "currentpeak1 :"  << endl;

		return true;
	}
	cout << "currentpeak2 :" << currentPeak << endl;

	inFile.clear();
	inFile.seekg(0, ios::beg);
	inFile.close();

	return false;
}

void MeterSetup(char* cnic)
{
	char* PaidStatus = nullptr;
	char* currentRegular = nullptr;
	char* currentPeak = nullptr;
	char* date = nullptr;

	storeIntoTempFile("CustomerInfo.txt", "temp.txt");

	char* meterID;

	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|   Meters  registered under the given CNIC:       |\n";
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	showMeters(cnic);

	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|          Enter the Meter ID to add :             |\n";
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";

	getStringConsole(meterID);
	storeIntoBillingInfo(meterID);

	while (!verifyMeter(meterID, cnic))
	{
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|          Choose among the given options          |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";

		delete[]meterID;
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|         Enter the Meter ID add data :            |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		getStringConsole(meterID);

	}

	///////////////////////////////////////////////////////////////////////////////////
	// UNITS SYSTEM
	char Type = '\0';
	Type = MeterTypeCheck(meterID);
	cout <<  endl;
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|             Phase Type :" << Type <<"                        | \n";
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	
	if (Type == '1')
	{

		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|                 Domestic Meter                   |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|        Enter Current Normal used units           |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "";
		getStringConsole(currentRegular);
		storeIntoBillingInfo("1");
		storeIntoBillingInfo(currentRegular);
		storeIntoBillingInfo("0");
	}
	else
	{
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|                 Commercial Meter                 |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|        Enter Current Normal used units           |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		getStringConsole(currentRegular);
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|        Enter Current Peak used units             |\n";
		cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
		getStringConsole(currentPeak);
		storeIntoBillingInfo("3");
		storeIntoBillingInfo(currentRegular);
		storeIntoBillingInfo(currentPeak);
	}

	///////////////////////////////////////////////////////////////////////////////////
	// ENTRY DATE SET
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|                Entry Date                |\n";
		cout << "\t\t\t\t\t\t\t|   Enter the Entry  Date(DD-MM-YYYY):     |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		getStringConsole(date);
		while (!verifyDate(date))
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
			cout << "\t\t\t\t\t\t\t|   Enter the Entry Date(DD-MM-YYYY):      |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]date;
			getStringConsole(date);
		}
		if (verifyDate(date))
		{
			storeIntoBillingInfo(date);
		}
	}

	///////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////
	// COST SUMMARY

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|               Cost Summary :             |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	CostCalculator(meterID, currentRegular, currentPeak);
	///////////////////////////////////////////////////////////////////////////////////
	//DUE DATE SET
	{
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|                Due Date                  |\n";
		cout << "\t\t\t\t\t\t\t|   Enter the Entry  Date(DD-MM-YYYY):     |\n";
		cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";		
		getStringConsole(date);
		while (!verifyDate(date))
		{
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|             Incorrect Format             |\n";
			cout << "\t\t\t\t\t\t\t|   Enter the Due Date(DD-MM-YYYY):        |\n";
			cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
			delete[]date;
			getStringConsole(date);
		}
		if (verifyDate(date))
		{
			storeIntoBillingInfo(date);
		}

	}
	
	///////////////////////////////////////////////////////////////////////////////////
	// PAID UNPAID
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|           Enter Status for the Bill          |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (1) For Paid                     |\n";
	cout << "\t\t\t\t\t\t\t|   Press --> (2) For Unpaid                   |\n";
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	cout << "Enter Status for the Bill\nEnter 1 for paid \nEnter 2 for unpaid \n";
	getStringConsole(PaidStatus);
	int paid = myStoi(PaidStatus);

	if (paid == 2 || paid != 1)
	{
		storeIntoBillingInfo("UNPAID");
	}
	else if (paid == 1 && RegualarUnitsUsed(meterID, currentRegular) == true && PeakUnitsUsed(meterID, currentPeak) == true)
	{
		//cout << "here\n" << endl << currentRegular << endl;
		storeIntoBillingInfo("PAID");

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

		while (count < 2)
		{
			if (dummy == ',')
			{
				count++;
			}

			if (count != 2)
			{
				inFile.seekg(-1, ios::cur);
				dummy = inFile.peek();
			}

		}

		inFile.seekg(-1, ios::cur);
		position = inFile.tellg();
		char dummyTemp = inFile.peek();

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
				if (position2 == position)
				{

					if (currentPeak == nullptr)
					{
						storeReadings(outFile, currentRegular, "0");

					}
					else
					{
						storeReadings(outFile, currentRegular, currentPeak);

					}

					outFile << meterID;
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
					if (dummy == ',')
					{
						outFile << dummy;
					}
				}

			}

			if (inFile.eof() && check == true)
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

			//delete[]data;

		}

		cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
		cout << "\t\t\t\t\t\t\t|               Process Complete               |\n";
		cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
		storeIntoBillingInfo("\n");
		inFile.close();
		outFile.close();

	}
	///////////////////////////////////////////////////////////////////////////////////

	system("pause");

}
