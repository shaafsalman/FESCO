  #include"EmployeesPortal.h"

int main()
{
	maximizeWindow();
	char choice;

	do
	{	///////////////////////////////////////////////////
		system("cls");
		MainMenu();
		choice = _getch();
		///////////////////////////////////////////////////


		if (choice == '1')
		{
			do
			{
				system("cls");
				printSighn();
				choice = _getch();

				if (choice == '1')
				{

					ifstream inFile;
					char dummy;
					loadFile(inFile, "EmployeesData.txt");

					inFile.get(dummy);

					if (inFile.eof())
					{

						system("cls");

						cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
						cout << "\t\t\t\t\t\t\t|           No registered Employee.        |\n";
						cout << "\t\t\t\t\t\t\t|               First SignUp.              |\n";
						cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
						
						system("pause");
						
					}

					else
					{

						inFile.seekg(0l, ios::beg);

						char* userName = nullptr;
						char* password = nullptr;

						do
						{
							system("cls");

							cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
							cout << "\t\t\t\t\t\t\t|           Enter the UserName:            |\n";
							cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
							getStringConsole(userName);

							cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
							cout << "\t\t\t\t\t\t\t|           Enter the Password:            |\n";
							cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
							getStringConsole(password);


							if (verifyEmployee(inFile, userName, password) == true)
							{
								//delete[]userName;
								//delete[]password;

								employeesPortal(userName, password, inFile);

							}

							else
							{
								delete[]userName;
								delete[]password;
								cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
								cout << "\t\t\t\t\t\t\t|   Press --> (1) To Enter Credentials again   |\n";
								cout << "\t\t\t\t\t\t\t|   Press --> (2) To Return to Employee Menu   |\n";
								cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";								choice = _getch();

							}

							inFile.clear();

							inFile.seekg(0l, ios::beg);

						} while (choice != '2');

					}

					inFile.close();

				}

				else if (choice == '2')
				{
					char* userName = nullptr;
					char* password = nullptr;

					do
					{
						system("cls");
						cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
						cout << "\t\t\t\t\t\t\t|           Enter New UserName:            |\n";
						cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
						getStringConsole(userName);

						cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
						cout << "\t\t\t\t\t\t\t|           Enter New Password:            |\n";
						cout << "\t\t\t\t\t\t\t:------------------------------------------:\n";
						getStringConsole(password);

						while (!checkPassword(password))
						{
							cout << "InValid Password." << endl;
							cout << "." << endl;
				
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
							delete[]password;
							getStringConsole(password);
						}

						if (verifyUserName(userName))
						{
							storeIntoEmployeesData(userName, password);

							delete[]userName;
							delete[]password;

							cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
							cout << "\t\t\t\t\t\t\t|   Press --> (1) To Enter Credentials again   |\n";
							cout << "\t\t\t\t\t\t\t|   Press --> (2) To Return to Employee Menu   |\n";
							cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
							choice = _getch();
						}

						else
						{
							delete[]userName;
							delete[]password;

							cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
							cout << "\t\t\t\t\t\t\t|            UserName already taken!           |\n";
							cout << "\t\t\t\t\t\t\t|                                              |\n";
							cout << "\t\t\t\t\t\t\t|   Press --> (1) To Enter Credentials again   |\n";
							cout << "\t\t\t\t\t\t\t|   Press --> (2) To Return to Employee Menu   |\n";
							cout << "\t\t\t\t\t\t\t:----------------------------------------------:\n";
							choice = _getch();
						}

					} while (choice != '2');

				}

			} while (choice != '3');
			

		}

	} while (choice != 27);


	system("pause");
	return 0;
}
