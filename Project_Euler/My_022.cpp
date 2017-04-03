#include <iostream>
#include "Toolkit_functions.h"
#include <vector>
using namespace std;

class my_cool_object{
    // We want to create a storage for a)name string b)its order with respect to other strings 3)alphabetical value
public:
    my_cool_object(const string &name_string) : name_string(name_string){};


public:
    string  name_string;

};

class database{
public:
    void add_record(my_cool_object mco){
        my_records.push_back(mco);
    }

    void determine_order(){
        //Create a vector of the name strings only
        vector<string> vector_names;
        int size_of_database = my_records.size();

        for(int i = 0; i < size_of_database; i++ ){
            vector_names.push_back(my_records[i].name_string);
        }
        // Bubble sort
        bool no_changes = false;
        while(!no_changes) {
            no_changes = true;
            for (int i = 0; i < size_of_database; i++) {
                string string1 = vector_names[i];
                string string2 = vector_names[i + 1];
                bool condition = !is_alphabetically_above(vector_names[i], vector_names[i + 1]);
                if (condition) {
                    string temp = vector_names[i];
                    vector_names[i] = vector_names[i + 1];
                    vector_names[i + 1] = temp;
                    no_changes = false;
                }
            }
        }
            // There is an empty string that goes first for some reason...so that means that there are size_of_database
        cout << vector_names.size();        for(int i = 0; i <= size_of_database; i++ ){
            cout<< i << " "<< vector_names[i]<<" "<< i*alphabetical_value(vector_names[i]) << endl ;
            ultimate_number += (i)*alphabetical_value(vector_names[i]);
        };
    }
public:
    vector<my_cool_object> my_records ;
    long ultimate_number = 0;

};

int main() {

    string input_string = "," + read_txt_file("/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_22_new.txt") + ",";
    //Create vector of strings
    database my_database;


    int position_character = 1;
    string delimter = ",";
    int start = position_character;
    while(position_character<input_string.size()){
        int end =  input_string.find(delimter, position_character) - 1;


        string extracted_string = input_string.substr(start,end - start + 1);
        my_cool_object mco(extracted_string);
        my_database.add_record(mco);

        start = end + 2;
        position_character = start;



    }


    my_database.determine_order();
    cout<<my_database.ultimate_number;
    return 0;
}

