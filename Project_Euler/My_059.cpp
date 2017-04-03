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

//Problem 59

string decipher(vector<int> key, vector<int> message){
    //we assume that the key is 3 integers
    string output;
    int key_index = 0;
    for(vector<int>::iterator it = message.begin(); it < message.end(); it++){
      output.push_back(char(((*it))^key[key_index]));
//        output.push_back(char(key[key_index]^((*it))));
        if(key_index == 2){
            key_index = 0;
        }else{
            key_index++;
        }
    }
    return output;
}
using namespace std;
int main() {
    /* INPUT AND NECESSARY CONVERSIONS */
    // Reading the txt file and converting into vector<int>/
    vector<int> message;
    string message_string = read_txt_file("/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_59.txt");
    message.push_back(stoi(message_string));
    while(true){
        int pos = message_string.find(",",0);
        if(pos == string::npos){
            break;
        }
        message_string = message_string.substr(pos + 1,10000);
        message.push_back(stoi(message_string));
    }
    int counter = 0;
    string winner;

    /* Trying different keys*/
    int lower_bound = 97;
    int upper_bound = 122;
    for(int a = lower_bound; a <= upper_bound; a++){
        for(int b = lower_bound ; b <= upper_bound; b++){
            for(int c = lower_bound ; c <= upper_bound; c++){
                vector<int> key({a,b,c});
                string translation = decipher(key,message);
                if(string::npos != translation.find("and") && string::npos != translation.find("because") && string::npos != translation.find("to")) {
                    winner = translation;
                    cout << "Decryption key is: " << (char)key[0]<< (char)key[1]<< (char)key[2]<< endl;
                    counter ++;
                }
            }
        }
    }
    /* SUMMARY AND RESULTS */
    cout <<"Only "<< counter << " translations exists"<< endl;
    int final_sum = 0;
    for(int i = 0; i < winner.length(); i++){
        final_sum += (int)winner[i];
    }

    cout << "CORRECT SOLUTION: "<<  winner << endl << endl;
    cout << "The ASCII sum is: "<< final_sum;
}

