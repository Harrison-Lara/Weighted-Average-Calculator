// Harrison Lara
// May ZeinelDin
// Feb 19, 2017

// includes
#include "Student.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Student::Student() :Student(-1, "", "") { } // defaults set 

Student::Student(int _id_, string first_n, string last_n) // class constructor defaults
{
	if (_id_ <= 0) // gets id
	{
		id = -1;
	}
	else
	{
		id = _id_;
	}

	// first and last name
	first_name = first_n; //  first name default
	last_name = last_n; // last name default

	// quizzes
	quiz1_score = -1; // quiz 1 default
	quiz2_score = -1; // quiz 2 default

	// midterm
	midterm_score = -1; // midterm default

	// final
	final_score = -1; // final  default
}

// string functions
string Student::grab_last() { return last_name; } // returns last name

string Student::full_name() { return last_name + ", " + first_name; } // changes name to last, first

string Student::grab_first(){ return first_name; } // returns first name

//int functions

int Student::grab_mid() { return midterm_score; } // returns midterm score

int Student::grab_fin() { return final_score; } // returns final score

int Student::grab_id() { return id; } // returns id

int Student::grab_quiz1() { return quiz1_score; } // returns quiz 1 score

int Student::grab_quiz2() { return quiz2_score; } // returns quiz 2 score


// void functions

void Student::quiz1_set(int score1) { quiz1_score = score1; } // set quiz 1 score

void Student::quiz2_set(int score2) { quiz2_score = score2; } // set quiz 2 score

void Student::midterm_set(int h) { midterm_score = h; } // set midterm score

void Student::first_set(string first_n) { first_name = first_n; } // set first name

void Student::last_set(string last_n) { last_name = last_n; } // set last name

void Student::id_set(int _id_) { id = _id_; } // set id

void Student::final_set(int j) { final_score = j; } // set final score

													// float function
float Student::calc_average() // functions finds the average overall grade for each student with scores
{
	float quiz_total = ((((float)quiz1_score + (float)quiz2_score) / 20.0f)*25.0f); // calculates quiz totals
	float midterm_total = (float)midterm_score / 100.0f * 25.0f; // calculate midterm total
	float final_total = (float)final_score / 100.0f * 50.0f; // calculate final total
	return quiz_total + midterm_total + final_total; // calculate overall ending grade
}

// bool function
bool Student::read_data(istream * text) // makes sure file reads correctly, returns true or false
{
	if ((*text) >> id && (*text) >> first_name && (*text) >> last_name)
	{
		return true;
	}
	return false;
}