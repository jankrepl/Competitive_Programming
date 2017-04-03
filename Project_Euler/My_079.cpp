#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"



using namespace std;

//problem 79
bool could_generate(vector<int> passcode, vector<int> offspring){
    vector<int>::iterator pc_it,pc_found;
    pc_it = passcode.begin();
    for(vector<int>::iterator it = offspring.begin(); it < offspring.end(); it++){

        pc_found = find(pc_it,passcode.end(),*it);

        if(pc_found == passcode.end()){
            return false;
        }else{
            pc_it = pc_found + 1;

        }
    }

    return true;

}


int main(){
    //read in the txt into vector<int>
    vector<vector<int>> offspring_integers;
    string current_line;
    ifstream path("/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_79.txt");
    while(getline(path,current_line)){
        offspring_integers.push_back(number_to_vector_of_digits(stol(current_line)));

    }


    //CREATE PASSCODE DATABASE

    vector<vector<int>> passcode_database;
    vector<int> test_passcode({1,3,5});

    passcode_database.push_back(test_passcode);

    vector<int> possible_values({0,1,2,3,6,7,8,9});
    for(long i = 10000000; i < 100000000; i++ ){
        passcode_database.push_back(number_to_vector_of_digits(i));
        //todo
        //Would be nice to disable all numers containing 4 and 5
        if(i % 1000000 == 0){
            cout << "I am just at the number: " << i <<endl;
        }
    }
    cout << " Created your database" << endl;


    //SEARCH IN THE DATABASE

    for(vector<vector<int>>::iterator passcode = passcode_database.begin(); passcode < passcode_database.end(); passcode++) {
        bool survived = true;

        vector<int>  bad_offspring;

        for (vector<vector<int>>::iterator it = offspring_integers.begin(); it <= offspring_integers.end(); it++) {
            if (!could_generate(*passcode, *it)) {
                survived = false;
                bad_offspring = *it;
                break;
            }
        }
        if (survived) {
            cout << "The following passcode is feasible!!!!! : " ; print_vector<int>(*passcode);
            cout << endl;
            break;
        } else {
//            cout << "The following passcode failed "; print_vector<int>(*passcode);
//            cout << "on the following offspring "; print_vector<int>(bad_offspring);
//            cout << endl;
        }
        if(distance(passcode_database.begin(),passcode) % 1000000 == 0){
            cout << "I have tried " << distance(passcode_database.begin(),passcode) << " passcodes already"<< endl;
        }
    }

    return 0;
}


