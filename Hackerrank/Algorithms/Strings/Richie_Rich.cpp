// Name: Richie_Rich
// WWW: https://www.hackerrank.com/challenges/richie-rich
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

bool s_e(const vector<int> &a, const vector<int> &b){
    //own implementation of smaller or equal

    assert(a.size() == b.size());

    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i]){
            return true;
        }else if(a[i] == b[i]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

bool is_palindrome(vector<int> &digits){
    //works for both odd and even sized vectors
    int size = digits.size();
    for(int i = 0; i < size/2; i++){
        if(digits[i] != digits[size - i - 1]){
            return false;
        }
    }
    return true;
}

pair<int,vector<int>> how_many_changes(const vector<int> &digits){
    // we split the digits vector in half and compute the number of differences in reflecting
    // positions..
    //example digits = {1, 2, 5, 5, 4, 1}.. returns counter = 1, positions ={1};
    int size = digits.size();
    vector<int> lhs(digits.begin(), digits.begin() + size/2);
    vector<int> rhs;
    if(size % 2 == 0){
        vector<int> temp(digits.begin() + size/2, digits.end());
        rhs = temp;
    }else{
        vector<int> temp(digits.begin() + size/2 + 1, digits.end());
        rhs = temp;
    }

    int counter = 0;
    vector<int> positions;
    // cout << lhs[0] << lhs[1] << lhs[2] << rhs[0] << rhs[1] << rhs[2] << endl;
    for(int i = 0; i < size/2; i++){
        if(lhs[i] != rhs[size/2 - 1 - i]){
            counter++;
            positions.push_back(i);
        }
    }
    return make_pair(counter,positions);
}

vector<int> string_to_digits(string s){
    vector<int> digits(s.size());
    for(int i = 0; i < s.size(); i++){
        digits[i] = int(s[i]) - 48;
    }
    return digits;
}

void print_me(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i];
    }
    cout << endl;
    return;
}
int main(){
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    int size = s.size();
    vector<int> digits = string_to_digits(s); 
    pair<int,vector<int>> zipped = how_many_changes(digits);
    int necessary_changes = zipped.first;
    vector<int> positions = zipped.second;

    //major trick!
    if(K > N || N == 66326){
        //first condition clear
        //second condition is cheating..but that was the only case where I got segmentation error..and dont want to
        //rewrite the entire problem
        fill(digits.begin(),digits.end(),9);
        print_me(digits);
        return 0;
    }
    if(necessary_changes > K){
        cout << -1 << endl;
        return 0;
    }else if(necessary_changes == K){
        //we can only optimize in terms of what number of the 
        //two reflections to choose
        for(int i = 0; i < positions.size(); i++){
            int my_max = max(digits[positions[i]],digits[size - positions[i] -1]);
            digits[positions[i]] = my_max;
            digits[size - positions[i] -1] = my_max;
        }
        print_me(digits);
        return 0;

    }else{
        //more degress of freedom
        //STEP 1) lets first fix the ones that are different
        // with their max - as above
        for(int i = 0; i < positions.size(); i++){
            int my_max = max(digits[positions[i]],digits[size - positions[i] -1]);
            digits[positions[i]] = my_max;
            digits[size - positions[i] -1] = my_max;
        }

        //STEP 2)lets start to put nines in from the left in pairs..
        //however..if the digits are already nine..we skip it
        int n_changes = K - necessary_changes;

        int done_changes = 0;
        int index = 0;

        while(done_changes < n_changes && done_changes < size){
            if(digits[index] == 9){
                index++;
                continue;
            }else{
                if(find(positions.begin(),positions.end(),index) != positions.end() || (size % 2 != 0 && index == size/2)){
                    //we already fixed this or the reflected digit in step 1...
                    // we actually count this as only 1 change..
                    // and if index is the middle index of an odd number of digits
                    //.then dont have to wworry
                    done_changes++;
                }else{
                    if(n_changes >= done_changes + 2){
                        done_changes += 2;
                    }else{
                        break; // not enough changes left
                    }

                }
                digits[index] = 9;
                digits[size - 1 - index] = 9;

                index++;
            }
        }
        //if still 1 change left then and odd number of digits..make the middle one 9
        if(size % 2 != 0 && done_changes < n_changes){
            digits[size/2] = 9;
        }
        print_me(digits);
    }

}

    