// Harrison Lara
// May ZeinelDin
// Feb 19, 2017

#pragma once

// includes
#include <vector>
#include "Student.h"
#include <string>
using namespace std;

 // Functions being used in main program (Main.cpp)

// voids
void student_grades(); // students that have scores
void student_info(); // information on overall students in the course
void menu_options(); // menu options for user
void student_weighted(); // students overall grades

// strings
string get_input();// obtains input from user

// vectors
vector<Student> grab_stud(); // holds the students information
vector<Student> grab_scores(vector<Student> students); // holds the scores 

// main
int main();

// function vectors
vector<Student> grab_stud() // see if file read successfully or not
{
	vector<Student> kid;
	fstream studentInfo("INFO.txt"); // open file with students information
	while (!studentInfo.eof())
	{
		Student i;
		if (i.read_data(&studentInfo)) // filter through given data
		{
			kid.push_back(i); // place data found into an array/ vector
		}
		else
		{
			cout << "There was an error" << endl; // error when reading the file
		}
	}
	studentInfo.close(); // close file
	return kid; // return the information on students found
}

vector<Student> grab_scores(vector<Student> students) // filters through list to grab students that have scores
{
	vector<Student> has_grade; // student has a grade
	fstream use_grades("Grades.txt"); // file containing grades
	while (!use_grades.eof())
	{
		int grades[5]; // max amount of grades to take
		for (int i = 0; i < 5; i++)
		{
			use_grades >> grades[i]; // iterate through students
		}
		for (Student student : students)
		{
			if (grades[0] == student.grab_id())
			{
				student.quiz1_set(grades[1]); // enters each score taken and assigns to variable (next five lines)
				student.quiz2_set(grades[2]);
				student.midterm_set(grades[3]);
				student.final_set(grades[4]);
				has_grade.push_back(student);
			}
		}
	}
	use_grades.close(); // close files
	return has_grade; // return grades found
}

// function string
string get_input() // take input
{
	string input;
	do
	{
		cout << "Please enter your selection: " << endl;
		cin >> input;
		if (input != "1"&& input != "2" && input != "3" && input != "4") // checks if input if valid
		{
			cout << "Error, input not valid!" << endl; // error message if input is not valid
		}
	} while (input != "1"&& input != "2" && input != "3" && input != "4");
	return input;
}

// function voids
void menu_options() // display menu options for the user
{
	cout << "Please enter a selection: " << endl;
	cout << "(1) Print class roster" << "\n" << endl;
	cout << "(2) Print class roster with their grades" << "\n" << endl;
	cout << "(3) Print class roster with students weighted total" << "\n" << endl;
	cout << "(4) Exit" << "\n" << endl;
}

void student_grades() // outputs the students that have scores (choice 2)
{
	vector<Student> students = grab_scores(grab_stud());
	for (Student i : students)
	{
		cout << i.full_name() << ": " << i.grab_quiz1() << " " << i.grab_quiz2() << " " << i.grab_mid() << " " << i.grab_fin() << endl;
	}
}

void student_info() // outputs the information on all students in the course
{
	vector<Student> students = grab_stud();
	cout << "\n" << "The course has " << students.size() << " students enrolled." << "\n" << endl;
	for (Student i : students)
	{
		cout << i.grab_id() << " " << i.full_name() << endl;
	}
}

void student_weighted() // outputs the students averaged grade (choice 3)
{
	vector<Student> students = grab_scores(grab_stud());
	for (Student i : students)
	{
		cout << "The weighted grade for " << i.full_name() << " is " << i.calc_average() << "% out of 100%" << endl;
	}
}

