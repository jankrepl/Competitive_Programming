// helloworld.cpp
#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
using namespace std;

string sum_string(string string1 , string string2){
    string result ;
    result = "00000000000000000000000000000000000000000000000000";
    result = result + "00000";
    int remainder = 0;
    int i = 1;
    // Append both to make them 55 character
    string2 = "00000"+ string2;
    // Start the summing
    while(i<=55){
        int integer_1 = string1[55 - i] - '0'; // '0' has ascii code of 48
        int integer_2 = string2[55 - i] - '0';
        int sum = (integer_1 + integer_2 + remainder)%10;
        remainder = (integer_1 + integer_2 +remainder)/10;

        char sum_char = 48 + sum;
        result[55 - i] = sum_char;
        i++;
    }
    return result;
}


int main()
{
    string string1 = "37107287533902102798797998220837590246510135740250";
    string string2 = "46376937677490009712648124896970078050417018260538";

    cout<< sum_string(string1, string2) << endl;

    ifstream my_input_file;
    my_input_file.open("/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_13.txt");

    string my_output_string;
    string cum_string = "0000000000000000000000000000000000000000000000000000000";
    int counter = 0;

    while(getline(my_input_file, my_output_string)){
        cum_string = sum_string(cum_string, my_output_string);
        counter++;

    }

    cout<<"overallsum:"<<cum_string<<endl;
}

