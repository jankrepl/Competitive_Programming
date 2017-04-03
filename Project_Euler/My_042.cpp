
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"

using namespace std;



int main() {
    // Create a string of all txt file
    string concatenated = read_txt_file("/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_42.txt") + ",";
    string concatenated_copy = concatenated;

    //Create a vector of strings
    vector<string> database_string;
    string delimiter = ",";
    int start = 0;
    int end = 0;

    while(concatenated_copy.size()>=6) {
        end = concatenated_copy.find(delimiter);
        database_string.push_back(concatenated_copy.substr(start+1,end-start-2));
        concatenated_copy.erase(start,end-start+1);
    }

    //Create a vector of numbers
    vector<int> database_number;
    int counter = 0;
    for(int i = 0; i <database_string.size(); i++){
        database_number.push_back(alphabetical_value(database_string[i]));
        if(is_triangular(database_number[i])) counter++;

    }
    cout<< counter;
}



