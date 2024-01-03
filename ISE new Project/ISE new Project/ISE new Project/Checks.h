#pragma once
#include"UtilityFunctions.h"

int CharCheck(char input_char)
{

	if ((input_char >= 65 && input_char <= 90) || (input_char >= 97 && input_char <= 122))
		return 1;

	else if (input_char >= 48 && input_char <= 57)
		return 2;

	else
		return 3;
}

bool checkPassword(char* password)
{
	int passSize = 0;
	bool alphabetcheck = false;
	bool numericcheck = false;
	bool specialcharactercheck = false;



	for (int i = 0; password[i] != '\0'; i++)
	{
		passSize++;
	}
	if (passSize < 8)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < passSize; i++)
		{
			if (CharCheck(password[i]) == 1)
			{
				alphabetcheck = true;
			}
		}

		for (int i = 0; i < passSize; i++)
		{
			if (CharCheck(password[i]) == 2)
			{
				numericcheck = true;
			}
		}
		for (int i = 0; i < passSize; i++)
		{
			if (CharCheck(password[i]) == 3)
			{
				specialcharactercheck = true;
			}
		}
	}
	if (alphabetcheck == true && numericcheck == true && specialcharactercheck == true)
	{
		return true;
	}
	else
		return false;

}

int checkLength(char* arr)
{
	int count{ 0 };
	int i;
	for (i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == '-')
			count++;
	}
	return i - count;
}

int myStoi(char* str)
{
	if (str == nullptr)
	{
		return 0;
	}

	int result{ 0 };
	for (int i{ 0 }; str[i] != '\0'; i++)
	{
		result = result * 10 + str[i] - '0';
	}
	return result;
}

bool verifyPhoneNo(char* num)
{
	int len = checkLength(num);
	if (len == 11)
	{
		for (int i{ 0 }; num[i] != '\0'; i++)
		{
			if (!(num[i] >= '0' && num[i] <= '9'))
				if (num[i] != '-')
					return false;
		}
		return true;
	}
	return false;
}

bool verifyCNICFormat(char* CNIC)
{
	int len = checkLength(CNIC);
	if (len == 13)
	{
		for (int i{ 0 }; CNIC[i] != '\0'; i++)
		{
			if (!(CNIC[i] >= 48 && CNIC[i] <= 57))
				if (CNIC[i] != '-')
					return false;
		}
		return true;
	}
	return false;
}

bool verifyDate(char* Date)
{

	int len = checkLength(Date);
	if (len == 8)
	{
		char datee[3];
		char monthh[3];
		char yearr[5];
		datee[2] = '\0';
		monthh[2] = '\0';
		yearr[4] = '\0';
		int date;
		int month;
		int year;
		time_t t = time(0);

		tm newTime;
		localtime_s(&newTime, &t);
		int count{ 0 };
		for (int i{ 0 }; Date[i] != '\0'; i++)
		{
			if (i >= 0 && i < 2)
			{
				if (Date[i] >= 48 && Date[i] <= 57)
				{
					datee[count] = Date[i];
					count++;
				}
				else
					return false;
			}
			else if (i >= 2 && i < 5)
			{
				if (Date[i] == '-')
					count = 0;
				else
				{
					if (Date[i] >= 48 && Date[i] <= 57)
					{
						monthh[count] = Date[i];
						count++;
					}
					else
						return false;
				}
			}
			else if (i >= 5 && i < 10)
			{
				if (Date[i] == '-')
					count = 0;
				else
				{
					if (Date[i] >= 48 && Date[i] <= 57)
					{
						yearr[count] = Date[i];
						count++;
					}
					else
						return false;
				}
			}
		}
		date = myStoi(datee);
		month = myStoi(monthh);
		year = myStoi(yearr);
		if (year == newTime.tm_year + 1900)
		{
			if (month > newTime.tm_mon + 1)
				return false;
			else if (month == newTime.tm_mon + 1)
				if (date > newTime.tm_mday)
					return false;
		}
		else if (year > newTime.tm_year + 1900)
			return false;
		if (month > 0 && month <= 12)
		{
			if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
			{
				if (month % 2 == 0)
				{
					if (month == 2)
					{
						if (!(date > 0 && date <= 29))
							return false;
						else
							return true;
					}
					else
					{
						if (!(date > 0 && date <= 30))
							return false;
						else
							return true;
					}
				}
				else
				{
					if (!(date > 0 && date <= 31))
						return false;
					else
						return true;
				}
			}
			else
			{
				if (month % 2 == 0)
				{
					if (month == 2)
					{
						if (!(date > 0 && date <= 28))
							return false;
						else
							return true;
					}
					else
					{
						if (!(date > 0 && date <= 30))
							return false;
						else
							return true;
					}
				}
				else
				{
					if (!(date > 0 && date <= 31))
						return false;
					else
						return true;
				}
			}
		}
		return false;
	}
	return false;
}

bool compareDates(const char* Date1, const char* Date2)
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

	int date2;

	int month2;

	int year2;

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

	count = 0;

	for (int i{ 0 }; Date2[i] != '\0'; i++)

	{

		if (i >= 0 && i < 2)

		{

			datee[count] = Date2[i];

			count++;


		}

		else if (i >= 2 && i < 5)

		{

			if (Date2[i] == '-')

				count = 0;

			else

			{

				monthh[count] = Date2[i];

				count++;


			}

		}

		else if (i >= 5 && i < 10)

		{

			if (Date2[i] == '-')

				count = 0;

			else

			{


				yearr[count] = Date2[i];

				count++;


			}

		}

	}

	date2 = myStoi(datee);

	month2 = myStoi(monthh);

	year2 = myStoi(yearr);

	if (year1 == year2)

	{

		if (month1 < month2)

			return false;

		else if (month1 == month2)

			if (date1 < date2)

				return false;

	}

	else if (year1 < year2)

		return false;

	return true;
}