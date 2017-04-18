// Name: Separate_the_Numbers
// WWW: https://www.hackerrank.com/challenges/separate-the-numbers
// Author: Jan Krepl


#include <bits/stdc++.h>

using namespace std;

long to_num(string s, int digits_start){
    string substring = s.substr(0,digits_start);
    return stol(substring);
}


string to_str(long n){
    vector<int> digits;

    while(n > 0){
        digits.push_back(int(n%10));
        n /= 10;
    }
    reverse(digits.begin(),digits.end());

    string output(digits.size(),' ');

    for(int i = 0; i < digits.size(); i++){
        output[i] = char(digits[i] + 48);
    }
    return output;



}
int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;

        bool is_beatiful = false;
        long starter_n = - 1;
        if((s[0] - 48) == 0){
            goto label;
        }
        //starting integer size loop
        for(int i = 1; i <= s.size()/2; i++){
            //lets generate a 32 digit string and check if the original is the same
            string created =s.substr(0,i);
            starter_n = to_num(s.substr(0,i),i);
            long next_n = starter_n;
            string next_s;
            while(created.size()<32) {
                next_n += 1;
                next_s = to_str(next_n);
                created += next_s;
            }
            if(created.substr(0,s.size()) == s){
                is_beatiful = true;
                break;

            }


        }
        label:
        if(is_beatiful){
            cout << "YES " << starter_n << endl;
        }else{
            cout << "NO" << endl;
        }
        // your code goes here
    }

    return 0;
}
