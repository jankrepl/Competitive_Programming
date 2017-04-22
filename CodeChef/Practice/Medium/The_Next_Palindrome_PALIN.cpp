// Name: The_Next_Palindrome
// Problem_Code: PALIN
// WWW: https://www.codechef.com/problems/PALIN
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility> 
#include <map>
#include <assert.h>   


using namespace std;

/* Strategy */
// 1)We extract the lhs of K - (including middle element if odd number of digits)
// 2)We reflect it and concatenate..(without middle element) if the result > K, we are done - return..if not we add 1 to the lhs
// 3)Iterate


/* Implementation issues */
// - we represent numbers as digits
// - it will be important to define a "plus one" operation on this object

vector<int> string_to_vector(string s){
    vector<int> output(s.size());
    for(int i = 0; i < s.size(); i++){
        output[i] = int(s[i]) - 48;
    }
    return output;
}

bool is_pali(vector<int> digits){
    int size = digits.size();
    for(int i = 0; i < size/2; i++){
        if(digits[i] != digits[size - i - 1]){
            return false;
        }
    }
    return true;
}

pair<vector<int>,bool> plus_one(vector<int> digits){
    // adds one to a number...and also returns a bool whether if was a borderline
    int size = digits.size();
    // borderline cases 9 99 999 9999 999999 - number of digits will change
    if(all_of(digits.begin(), digits.end(), [](int i){return i == 9;})){
        vector<int> temp(size + 1,0);
        temp[0] = 1;
        return make_pair(temp,true);
    }

    bool overflow = true;
    int index = size - 1;
    while(overflow){
        if(digits[index] == 9){
            digits[index] = 0;
            index--;

        }else{
            digits[index]++;
            overflow = false;
        }
    }
    return make_pair(digits,false);
}

vector<int> get_lhs(vector<int> digits, bool middle_element){
    vector<int> output;
    if(middle_element){
        vector<int> temp(digits.begin(), digits.begin() + digits.size()/2 + 1);
        output = temp;

    }else{
        vector<int> temp(digits.begin(), digits.begin() + digits.size()/2);
        output = temp;
    }
    return output;
}

vector<int> generate_pali(vector<int> lhs, bool middle_element){
    //if there is a middle element included, lhs do not reflect it
    vector<int> rhs;

    if(middle_element){
        vector<int> temp(lhs.begin(), lhs.end() - 1);
        rhs = temp;
    }else{
        rhs = lhs;
    }
    reverse(rhs.begin(), rhs.end());

    //prepare output
    lhs.insert(lhs.end(), rhs.begin(), rhs.end());
    return lhs;
}

void print_me(vector<int> digits){
    for(int i = 0; i < digits.size(); i++){
        cout << digits[i];
    }
    cout << endl;
}

bool is_bigger(vector<int> &a, vector<int> &b){
    // determines whether a > b (strictly)

    // sizes -- dont have to worry about leading zeros
    if(a.size() > b.size()){
        return true;
    }else if(a.size() < b.size()){
        return false;
    }else{
        for(int i = 0; i < a.size(); i++){
            if(a[i] > b[i]){
                return true;
            }else if(a[i] < b[i]){
                return false;
            }else{
                continue;
            }
        }
        return false;
    }
}



int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;

        //convert to vector of digits
        vector<int> original_digits = string_to_vector(s);
        // figure out the parity of digits
        bool is_odd = (original_digits.size() % 2 != 0);
        // create a stupid paligram (just reflection..keeping the same middle element)
        vector<int> digits = generate_pali(get_lhs(original_digits,is_odd), is_odd);


        bool found_bigger = false;

        while(!found_bigger){
            if(is_bigger(digits,original_digits)){
                found_bigger = true;

            }else{
                bool is_odd = (digits.size() % 2 != 0);

                //get lhs..if middle element..include
                vector<int> lhs = get_lhs(digits, is_odd);

                pair<vector<int>,bool> zipped = plus_one(lhs);
                if(zipped.second){
                    //if borderline
                    vector<int> temp(digits.size() + 1,0); //only add 1 digit
                    temp.front() = 1;
                    temp.back() = 1;
                    digits = temp;                
                }else{
                    digits = generate_pali(zipped.first, is_odd);

                }

            }

        }
        //cout << s << ": ";
        print_me(digits);
    }
}

