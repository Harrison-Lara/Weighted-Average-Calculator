// Harrison Lara
// May ZeinelDin
// Feb 19, 2017

// header defaults
#ifndef MY_STUDENT
#define MY_STUDENT

// includes
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Student // Class that reads through two files, grabs students information, id, quiz scores and calculates overall grade with menu options for user
{
public: // public members

	// string functions
	string grab_first(); // grabs first name
	string grab_last(); // grabs last name
	string full_name(); // creates students full name
	
	float calc_average(); // finds the overall grade for students with scores

	bool read_data(istream * text);

	// constructor variables
	Student(int _id_, string first_n, string last_n);
	Student();
	
	// getters (ints)
	int grab_id(); // getter for student id
	int grab_quiz1(); // getter for quiz 1
	int grab_quiz2(); // getter for quiz 2
	int grab_mid(); // getter for midterm
	int grab_fin(); // getter for final

	// setters (voids)
	void first_set(string first_n); // sets first name
	void last_set(string last_n); // sets last name
	void id_set(int _id_); // sets the students id
	void quiz1_set(int score1); // sets quiz 1 score
	void quiz2_set(int score2); // sets quiz 2 score
	void midterm_set(int h); // sets midterm score
	void final_set(int j); // sets final score
	
private: // private members

	int id; // default id 
	int quiz1_score, quiz2_score, midterm_score, final_score; // default scores 
	string first_name; // default first name
	string last_name; // default last name
};
#endif // end of file reached