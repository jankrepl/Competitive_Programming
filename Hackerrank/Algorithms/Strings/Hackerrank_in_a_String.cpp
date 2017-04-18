// Name: HackerRank_in_a_String!
// WWW: https://www.hackerrank.com/challenges/hackerrank-in-a-string
// Author: Jan Krepl

#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    string bm = "hackerrank";
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        // your code goes here
        bool status = true;
        size_t current_position = 0;
        for(int i = 0; i < bm.size(); i++){
            size_t found = s.find(bm[i], current_position);
            if(found == string::npos){
                status = false;
                break;
            }else{
                current_position = found + 1;
            }
        }
        if(status){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
 
}
