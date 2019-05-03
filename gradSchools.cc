/*************************************
 *Name: Kristen Qako
 *Date: 05/02/2019
 *Class: CSCI132
 *Assignment 8
 *Specification File: gradSchools.cc
 *
 *This file implements all of the methods in GradSchool.
 *
 *************************************/

#include "gradSchools.h"
    
/*Implement functions from gradSchools.h file here */

GradSchools :: GradSchools()
/*Pre:None
Post: clears the school object
*/
{
    schools.clear();
}

void GradSchools :: addSchool (string name, string state, int women, int rateAI, int rateSys,
                                int rateTheory, int effect, int ratePubs)
/*Pre: School object is declared
Post: Declares a new school of type School and inserts it into a list
*/
{
    School newSchool(name,state,women,rateAI,rateSys,rateTheory,effect,ratePubs);
    schools.insert(schools.size(), newSchool);
}

void GradSchools :: printGradSchools()
/*Pre: School object is declared.
Post: Prints out the retrieved graduate school.
*/
{
    cout << endl;
    cout << "There are " << schools.size() << " schools in the database" << endl;
    School thisSchool;
    for(int i = 0; i < schools.size(); i ++){
        schools.retrieve(i,thisSchool);
        thisSchool.printSchoolInfo();
        cout << endl;
    }
}

void GradSchools :: computeRatings(int weightWomen, int weightAI, int weightSys, 
                                    int weightTheory, int weightEffect, int weightPubs)
/*Pre: A school object to rate
  Post: Uses computeRating to calculate the rating of each Graduate School in the list
*/
{
    School thisSchool;
    for(int i = 0; i < schools.size(); i++){
        schools.retrieve(i,thisSchool);
        thisSchool.computeRating(weightWomen, weightAI,weightSys,weightTheory,weightEffect,weightPubs);
        schools.replace(i, thisSchool);
    }
}

void GradSchools :: rankSchools (int weightWomen, int weightAI, int weightSys, 
                                 int weightTheory, int weightEffect, int weightPubs)
/*Pre: A list of schools to be ordered
Post: uses computeRankings and the quick_sort algorithm to arrange the graduate schools based on their overall rating.
*/
{
    School thisSchool;
    computeRatings(weightWomen, weightAI,weightSys,weightTheory,weightEffect,weightPubs);
    schools.quick_sort();
    cout << "Ranking of Grad School programs given your preferences: " << endl;
    for(int i = schools.size() - 1; i>=0;i--){
        schools.retrieve(i,thisSchool);
        thisSchool.printName();
    }
}

void GradSchools :: rankSchoolsFactor(string factor)
/*Pre: Graduate schools in a list
  Post: Ranks the grad schools based solely on one factor(ex:women in PhD)
*/
{
    if(factor == "women"){
        rankSchools(1,0,0,0,0,0);
    }else if(factor == "AI"){
        rankSchools(0,1,0,0,0,0);
    }else if(factor == "Sys"){
        rankSchools(0,0,1,0,0,0);
    }else if(factor == "Theory"){
        rankSchools(0,0,0,1,0,0);
    }else if(factor == "Effectiveness"){
        rankSchools(0,0,0,0,1,0);
    }else if(factor == "Pubs"){
        rankSchools(0,0,0,0,0,1);
    }
}
