// Harrison Lara
// May ZeinelDin
// Feb 19, 2017

// includes
#include <iostream>
#include <string>
#include <fstream>
#include "Main.h"
#include "Student.h"
#include <vector>
#include <sstream>
using namespace std;

// main program
int main()
{
	// appliction greeting
	string input; // takes user input
	cout << "Welcome to the Weighted Average Application" << "\n";
	cout << "-------------------------------------------" << "\n";
	menu_options(); // display menu option to user
	do
	{
		input = get_input();
		if (input == "1")
		{
			student_info(); // print student roster
		}
		else if (input == "2")
		{
			student_grades(); // print students with grades
		}
		else if (input == "3")
		{
			student_weighted(); // print students and their scores
		}

		if (input != "4") 
		{
			string next;
			cout << "\n" << "----------------------------------------------------------------";
			cout << "\n" << "Would you like to return to main menu? [y: yes	| n: no] : ";
			cin >> next;
			if (next == "y")
			{
				menu_options();
			}
			else if (next == "n")
			{
				cout << "\n" << "Ending program..." << endl;
				system("pause");
				exit(1);
			}
		}
	} while (input != "4");
}