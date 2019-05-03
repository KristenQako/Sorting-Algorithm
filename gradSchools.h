/*************************************
 *Name: Kristen Qako
 *Date: 05/02/2019
 *Class: CSCI132
 *Assignment 8
 *Specification File: Gradschool.h
 *
 *This file declares all of the methods and data members required for the GradSchool object
 *
 *************************************/
#include <iostream>
#include <string>
#include "school.h"
#include "sortable_list.h"
#include "list.h"
using namespace std;

#ifndef GRADSCHOOL_H
#define GRADSCHOOL_H

class GradSchools {
 public:
	GradSchools();
	void addSchool (string name, string state, int women, int rateAI, int rateSys,
			int rateTheory, int effect, int ratePubs);
	void printGradSchools();
	void computeRatings (int weightWomen, int weightAI, int weightSys, 
			     int weightTheory, int weightEffect, int weightPubs);
	void rankSchools (int weightWomen, int weightAI, int weightSys, 
			  int weightTheory, int weightEffect, int weightPubs);
	void rankSchoolsFactor (string factor); 
 private:
	Sortable_list<School> schools;	 // array of School instances
};
   
#endif
