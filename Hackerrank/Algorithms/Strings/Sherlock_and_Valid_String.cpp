// Name: Sherlock_and_Valid_String
// WWWW: https://www.hackerrank.com/challenges/sherlock-and-valid-string
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string s;
    cin >> s;
    
    // create histogram
    vector<int> hist(26,0);
    
    for(int i = 0; i < s.size(); i++){
        hist[int(s[i]) - 97]++;
    }
    
    sort(hist.begin(), hist.end());
    vector<int>::iterator it = find_if(hist.begin(), hist.end(), [](int i){return i > 0;});
    
    int start =  distance(hist.begin(),it);
    int first_count = hist[start];
    int last_count = hist.back();
    
    set<int> test(hist.begin() + start, hist.end());
    
    if(test.size() == 1){
        cout << "YES" << endl;
        return 0;
    }else if(test.size() > 2){
            cout << "NO" << endl;
            return 0;                 
    }else{         
        // count last count .. count first count
        int fc = 0;
        int lc = 0;
        for(vector<int>::iterator it = hist.begin() + start; it != hist.end(); it++){
            if(*it == first_count){
                fc++;
            }else{
                lc++;   
            };
        }
        
        // we can only remove characters..
        if(lc > 1 & fc != 1){
            cout << "NO" << endl;
            return 0;              
        }     
    }
    cout << "YES" << endl;
    return 0 ;  
}
