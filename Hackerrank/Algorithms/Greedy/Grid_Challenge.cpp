// Name: Grid_Challenge
// WWWW: https://www.hackerrank.com/challenges/grid-challenge
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool horizontal_switch(vector<string> &a){
    bool was_used = false;

    for(int i = 0; i < a.size(); i++){
        for(int j = 1; j < a.size(); j++){
            if((int)a[i][j - 1] > (int)a[i][j]){
                char temp_f,temp_s;
                temp_f = a[i][j - 1];
                temp_s = a[i][j];
                a[i][j] = temp_f;
                a[i][j - 1] = temp_s;
                was_used = true;
            }
        }
    }
    return was_used;
}

bool vertical_switch(vector<string> &a){
    bool was_used = false;

    for(int i = 1; i < a.size(); i++){
        for(int j = 0; j < a.size(); j++){
            if((int)a[i - 1][j] > (int)a[i][j]){
//                char temp;
//                temp = a[j - 1][i];
//                a[j - 1][i] = a[i][j];
//                a[i][j] = temp;
                was_used = true;
            }
        }
    }
    return was_used;
}

int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int n;
        cin >> n;

        vector<string> matrix(n);
        for(int j = 0; j < n; j++ ){
            string temp;
            cin >> temp;
            matrix[j] = temp;
        }

        bool hor = true;
        bool ver = true;

        int counter = 0;
        while((hor || ver) && counter <= 1000){
            hor = horizontal_switch(matrix);
            ver = vertical_switch(matrix);
            counter++;
        }
        if(counter < 1000){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}