// Name: Marks_Cakewalk
// WWWW: https://www.hackerrank.com/challenges/marcs-cakewalk
// Author: Jan Krepl


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> calories(n);
    for(int calories_i = 0; calories_i < n; calories_i++){
       cin >> calories[calories_i];
    }
    long int miles = 0;
    
    sort(calories.begin(), calories.end());
    reverse(calories.begin(),calories.end());
    for(int i = 0; i < n; i++){
        miles += pow(2,i)*calories[i];
    }
    cout << miles;
    
    // your code goes here
    return 0;
}
