// Name: Password_cracker
// WWWW: https://www.hackerrank.com/challenges/password-cracker
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
#include <cstring>
#include <tuple>

using namespace std;




pair<bool, vector<string>> func(string &s, vector<string> &all_passwords, vector<string> &chopped_so_far){
    if(s.size() == 0){
        return make_pair(true, chopped_so_far);
    }else{
        for(vector<string>::iterator it = all_passwords.begin(); it != all_passwords.end(); it++){
            if(s.substr(0,it->size()) == *it){
                // string is contained!
                vector<string> chopped_so_far_new = chopped_so_far;
                chopped_so_far_new.push_back(*it);
                string s_new(s.begin() + it->size(), s.end());

                return func(s_new, all_passwords, chopped_so_far_new);
            }
        }
        return make_pair(false, chopped_so_far);
    }

}

void print_me(vector<string> &pws){
    for(int i = 0; i < pws.size(); i++) {
        cout << pws[i] << " ";
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<string> all_passwords(n);
        for(int i = 0; i < n; i++){
            cin >> all_passwords[i];
        }
        string attempt;
        cin >> attempt;

        vector<string> chopped_so_far(0);
        pair<bool, vector<string>> zipped_result = func(attempt, all_passwords,chopped_so_far);

        if(zipped_result.first){
            print_me(zipped_result.second);
        }else{
            cout << "WRONG PASSWORD" << endl;
        }

    }
}



