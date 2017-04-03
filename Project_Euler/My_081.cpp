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


int a[80][80];

void print_me(int a[80][80]){
    for(int i = 0; i < 80; i++){
        for(int j = 0; j < 80; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    //first rows and then columns

    string current_line;
    ifstream path("/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_81.txt");
    int i = 0;
    while(getline(path,current_line)){
        for(int j = 0; j < 80; j++){
            //copy number
            a[i][j] = stoi(current_line);
            //delete the number and the comma(if there is one..end of line has no comma
            string::size_type found = current_line.find(",",0);
            if(found != string::npos){
                current_line.erase(0,found + 1);
            }
        }
        i++;
    }
    print_me(a);
    cout<<endl<<endl<<endl;

    //cumulate last column - you can only go down
    for(int i = 78; i >= 0; i--){
        a[i][79] += a[i+1][79];
    }

    print_me(a);
    cout<<endl<<endl<<endl;
    //cumulate last row - you can only go right
    for(int j = 78; j >= 0; j--){
        a[79][j] += a[79][j+1];
    }
    print_me(a);
    cout<<endl<<endl<<endl;
    //cumulate rest
    for(int j = 78; j >=0; j--){
        for(int row = 78; row >=0; row--){
            a[row][j] += min(a[row+1][j],a[row][j+1]);
        }
    }

    print_me(a);
    cout<<endl<<endl<<endl;
    cout << a[0][0] << endl;

    return 0;
}


