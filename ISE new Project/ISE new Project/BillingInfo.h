#pragma once
#include"ChangeCustomerInfo.h"

string standardDateFormat(int date, int month, int year)
{
	ostringstream output;
	output << setfill('0') << setw(2) << to_string(date) << "-" << setw(2) << to_string(month) << "-" << to_string(year);
	return output.str();
}

char* dateIncreaseByWeek(const char* Date1)
{
	char datee[3];

	char monthh[3];

	char yearr[5];

	datee[2] = '\0';

	monthh[2] = '\0';

	yearr[4] = '\0';

	int date1;

	int month1;

	int year1;

	char* Date2 = new char[11];
	Date2[10] = '\0';

	int count{ 0 };

	for (int i{ 0 }; Date1[i] != '\0'; i++)

	{

		if (i >= 0 && i < 2)

		{

			datee[count] = Date1[i];

			count++;


		}

		else if (i >= 2 && i < 5)

		{

			if (Date1[i] == '-')

				count = 0;

			else

			{

				monthh[count] = Date1[i];

				count++;


			}

		}

		else if (i >= 5 && i < 10)

		{

			if (Date1[i] == '-')

				count = 0;

			else

			{


				yearr[count] = Date1[i];

				count++;


			}

		}

	}

	date1 = myStoi(datee);

	month1 = myStoi(monthh);

	year1 = myStoi(yearr);

	if (month1 != 12)
	{
		if (month1 % 2 == 0)
		{
			if (month1 == 2)
			{
				if (year1 % 400 == 0 || year1 % 100 != 0 && year1 % 4 == 0)
				{
					for (int i{ 0 }; i < 7; i++)
					{
						if (date1 < 29)
							date1++;
						else if (date1 >= 29)
						{
							month1++;
							date1 = 1;
						}
						else
							date1++;
					}
				}
				else
				{
					for (int i{ 0 }; i < 7; i++)
					{
						if (date1 < 28)
							date1++;
						else if (date1 >= 28)
						{
							month1++;
							date1 = 1;
						}
						else
							date1++;
					}
				}
			}
			else
			{
				for (int i{ 0 }; i < 7; i++)
				{
					if (date1 < 30)
						date1++;
					else if (date1 >= 30)
					{
						month1++;
						date1 = 1;
					}
					else
						date1++;
				}
			}
		}
		else
		{
			for (int i{ 0 }; i < 7; i++)
			{
				if (date1 < 31)
					date1++;
				else if (date1 >= 31)
				{
					month1++;
					date1 = 1;
				}
				else
					date1++;
			}
		}
	}
	else
	{
		for (int i{ 0 }; i < 7; i++)
		{
			if (date1 < 30)
				date1++;
			else if (date1 >= 30)
			{
				year1++;
				month1 = 1;
				date1 = 1;
			}
			else
				date1++;
		}
	}
	string dateTemp = standardDateFormat(date1, month1, year1);
	for (int i{ 0 }; i < 10; i++)
	{

		Date2[i] = dateTemp[i];
	}
	return Date2;
}

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


	if (data == "PAID" || data == "UNPAID")
	{
		outFile << data;

	}
	else if (inFile.eof())
	{
		outFile << data;
		outFile << ",";
	}
	else if (*data == '\n')
	{
		outFile << data;
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
	else if (inFile.eof())
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
	//cout << currentPeak;
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
			skiplines(info, 3, '\n');

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
	/*1Phase, 5, , 17, 150
	1Phase, 15, , 20, 250
	3Phase, 8, 12, 17, 150
	3Phase, 18, 25, 20, 250*/
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
		//int temp = myStoi(currentRegular) - myStoi(regular);
		//
		//cout << "to be stored" << temp << endl;
		//storeint(currentRegular, temp);
		inFile.clear();
		inFile.seekg(0, ios::beg);
		inFile.close();
		//cout << "old regular :" << regular<<endl;
		//cout << "currentregular0 new regular used : " << currentRegular << endl;

		return true;
	}

	/*cout << "old regular : " << regular << endl;
	cout << "currentregular1 : " << currentRegular << endl;*/


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
		//int temp = myStoi(currentPeak) - myStoi(Peak);
		//storeint(currentPeak, temp);
		inFile.clear();
		inFile.seekg(0, ios::beg);
		inFile.close();
		//cout << "old peak :" << Peak<<endl;
		//cout << "currentpeak0  new peak used :" << currentPeak << endl;
		return true;
	}
	if (currentPeak == 0 || currentPeak == nullptr)
	{
		//cout << "old peak :" << Peak << endl;
		//cout << "currentpeak1 :"  << endl;

		return true;
	}
	//cout << "old peak :" << Peak << endl;
	//cout << "currentpeak2 :" << currentPeak << endl;

	inFile.clear();
	inFile.seekg(0, ios::beg);
	inFile.close();

	return false;
}

void SetUnitsinCustomerID(char* meterID, char*currentRegular,char*currentPeak)
{

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
	char dummyTemp = inFile.peek();



	if (dummyTemp != ',')
	{
		while (dummyTemp != ',')
		{
			inFile.seekg(-1, ios::cur);
			dummyTemp = inFile.peek();
		}

		inFile.seekg(1, ios::cur);

	}



	position = inFile.tellg();

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
					storeReadings(outFile, currentRegular, " ");

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
}

bool GreaterthanInstallationDate(const char* meterID, const char* entryDate)
{
	char dummy = '\0';
	ifstream inFile;
	loadFile(inFile, "CustomerInfo.txt");

	char* data;
	char* installdate;
	char letter = ' ';
	data = new char[1];
	data[0] = '\0';
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

	char point = ' ';
	inFile.seekg(1, ios::cur);
	position = inFile.tellg();
	installdate= new char[1];
	installdate[0] = '\0';

	int i = 0;
	while (point != ',')
	{

		if (point == ',')
		{
			growString(installdate, letter);
			installdate[i] = '\0';
		}
		inFile.get(point);

		if (point != ',')
		{
			growString(installdate, letter);
			installdate[i] = point;
			i++;
		}
	}


	for (int j = 0; j < 10; j++)
	{
		growString(data, letter);

		data[j] = installdate[j];
		cout << data[j];
	}
	

	installdate[0]='\0';


	if (compareDates(entryDate,data ) == true)
	{
		
		delete[]installdate;
		delete[]data;
		data = nullptr;
		installdate = nullptr;
		return true;
	}
	delete[]installdate;
	delete[]data;
	data = nullptr;
	installdate = nullptr;

	return false;
}

void MeterSetup(char* cnic)
{
	char* PaidStatus = nullptr;
	char* currentRegular = nullptr;
	char* currentPeak = nullptr;
	char* date = nullptr;
	char* meterID=nullptr;
	storeIntoTempFile("CustomerInfo.txt", "temp.txt");
	

	///////////////////////////////////////////////////////////////////////////////////
    // CNIC
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|   Meters  registered under the given CNIC:       |\n";
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	showMeters(cnic);

	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|          Enter the Meter ID to add :             |\n";
	cout << "\t\t\t\t\t\t\t:--------------------------------------------------:\n";

	getStringConsole(meterID);
	storeIntoBillingInfo(meterID);
	///////////////////////////////////////////////////////////////////////////////////
    // ID Selector
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
		GreaterthanInstallationDate(meterID, date);
		

		while (!GreaterthanInstallationDate(meterID, date) && !verifyDate(date))
		{
			cout << "\t\t\t\t\t\t\t:-------------------------------------------------------------:\n";
			cout << "\t\t\t\t\t\t\t|  Caution: Date must be greater than installation month      |\n";
			cout << "\t\t\t\t\t\t\t|          Enter the Entry Date(DD-MM-YYYY):                  |\n";
			cout << "\t\t\t\t\t\t\t:-------------------------------------------------------------:\n";
		
			delete[]date;
			getStringConsole(date);
		}
		
	
		if (verifyDate(date)&& GreaterthanInstallationDate(meterID,date))
		{
			storeIntoBillingInfo(date);
		}
	}
	///////////////////////////////////////////////////////////////////////////////////
	// COST SUMMARY

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|               Cost Summary :             |\n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	CostCalculator(meterID, currentRegular, currentPeak);
	///////////////////////////////////////////////////////////////////////////////////
	//DUE DATE SET	
	date = dateIncreaseByWeek(date);

	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|               Due Date issued            |\n";
	cout << "\t\t\t\t\t\t\t|                  "<<date<<"              | \n";
	cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
	storeIntoBillingInfo(date);

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
		storeIntoBillingInfo("\n");
	}
	else if (paid == 1 && RegualarUnitsUsed(meterID, currentRegular) == true && PeakUnitsUsed(meterID, currentPeak) == true)
	{
		storeIntoBillingInfo("PAID");
		SetUnitsinCustomerID(meterID, currentRegular, currentPeak);
		storeIntoBillingInfo("\n");	
	}
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	cout << "\t\t\t\t\t\t\t|               Process Complete               |\n";
	cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
	///////////////////////////////////////////////////////////////////////////////////
	//desructor
	delete[] PaidStatus;
	delete[] currentRegular;
	delete[] currentPeak;
	delete[] date;
	delete[] meterID;
    PaidStatus = nullptr;
	currentRegular = nullptr;
	currentPeak = nullptr;
	date = nullptr;
	meterID = nullptr;



	system("pause");

}
