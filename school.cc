/*************************************
 *Name: Kristen Qako
 *Date: 05/02/2019
 *Class: CSCI132
 *Assignment 8
 *Specification File: school.cc
 *
 *This file implements all of the methods for the school object.
 *
 *************************************/
#include "school.h"

/*Implement functions from school.h file here */

School :: School() //default constructor
/*Pre: None
 Post: Initializes all data members of the School class.
*/
{
    women = 0;
    rateAI = 0;
    rateSys = 0;
    rateTheory = 0;
    effectiveness = 0;
    ratePubs = 0;
    overallRating = 0;
}

School :: School(string myName, string myState, int theWomen, int myRateAI, int myRateSys,
                 int myRateTheory, int myEffectiveness, int myRatePubs) //non-default constructor
/* Pre:None
 Post: intializes all of the parameters of the non default constructor to the corresponding data member.
*/
{
    name = myName;
    state = myState;
    women = theWomen;
    rateAI = myRateAI;
    rateSys = myRateSys;
    rateTheory = myRateTheory;
    effectiveness = myEffectiveness;
    ratePubs = myRatePubs;
    overallRating = 0;
}

void School :: printSchoolInfo()
/*Pre: A school object
 Post: Prints all the information in a single School object
*/
{
    cout << "Name: " << name << endl;
    cout << "State: " << state << endl;
    cout << "Rating of number of women PhD's: " << women << endl;
    cout << "Rating of AI Program: " << rateAI << endl;
    cout << "Rating of Systems program: " << rateSys << endl;
    cout << "Rating of Theory program: " << rateTheory << endl;
    cout << "Effectiveness rating: " << effectiveness << endl;
    cout << "Rating of faculty publications: " << ratePubs << endl;
    cout << "Overall rating: " << overallRating << endl;
}

void School :: computeRating (int weightWomen, int weightAI, int weightSys, 
			    int weightTheory, int weightEffect, int weightPubs)
/*Pre:
Post: Computes the overall rating of a school.
*/
{
    overallRating = (weightWomen * women) + (weightAI * rateAI) + (weightSys * rateSys) + (weightTheory * rateTheory) + (weightEffect * effectiveness) + (weightPubs * ratePubs);   
}

void School :: printName() //this is a function to help with rankSchools (so I do not need to print it in reverse order)
/*Pre:
  Post: Print out the names of a school
*/
{
 cout << name << endl;
}


bool operator ==(const School &x, const School &y)
/*Pre:
  Post: defines the == operator for the School class. Based on overall rating
*/
{
    return x.overallRating == y.overallRating;
}

bool operator >(const School &x, const School &y)
/*Pre:
  Post:defines the > operator for the School class. Based on overall rating
*/
{
    return x.overallRating > y.overallRating; 
}

bool operator <(const School &x, const School &y)
/*Pre:
  Post:defines the < operator for the School class. Based on overall rating
*/
{
    return x.overallRating < y.overallRating;   
}

bool operator >=(const School &x, const School &y)
/*Pre:
  Post:defines the >= operator for the School class. Based on overall rating
*/
{
    return x.overallRating >= y.overallRating;

}

bool operator <=(const School &x, const School &y)
/*Pre:
  Post:defines the <= operator for the School class. Based on overall rating
*/
{
    return x.overallRating <= y.overallRating;
}

bool operator !=(const School &x, const School &y)
/*Pre:
  Post:defines the != operator for the School class. Based on overall rating
*/
{
    return x.overallRating != y.overallRating;  
}
    
    
    
