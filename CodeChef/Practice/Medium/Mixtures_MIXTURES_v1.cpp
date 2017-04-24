// Name: Mixtures_v1
// Problem_Code: MIXTURES
// WWW: https://www.codechef.com/problems/MIXTURES
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

vector<int> mix_2_potions(vector<int> &potions, int index_1, int index_2){
    assert(abs(index_2 - index_1) == 1 && index_1 < index_2);

    vector<int> potions_c = potions;

    int new_color = (potions[index_1] + potions[index_2]) % 100;

    // very inefficient
    potions_c.erase(potions_c.begin() + index_1);
    potions_c[index_1] = new_color;
    return potions_c;
}


map<vector<int>, long> memo_table;


long f(vector<int> &potions){
    map<vector<int>,long>::iterator it = memo_table.find(potions);



    if(it != memo_table.end()){
        return it->second;
    }else{
        if(potions.size() == 2){
            // base case
            memo_table[potions] = potions[0]*potions[1];
            return memo_table[potions];

        }else{
            // induction case
            long min = 100000;

            for(int i = 0; i < potions.size() - 1; i++){
                int smoke = potions[i] * potions[i + 1];
                vector<int> temp_vector = mix_2_potions(potions,i,i+1);
                long temp = f(temp_vector) + smoke; // f(subportions) + smoke
                if(temp < min){
                    min = temp;
                }
            }
            memo_table[potions] = min;
            return memo_table[potions];
        }
    }
}

void print_me(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


int main(){
    /* Strategy */
    // We use the fact that this problem is just a function of the potions array -> f(potions)
    // lets define a notation
    // potions_i := potions after mixing i-th and (i+1)-th element
    // s_i := smoke after mixing i-th and (i+1)-th element

    // THE FOLLOWING RECURSIVE RELATIONSHIP HOLDS : (induction step)
    // f(potions) = min(s_0 + f(potions_0), ..., s_(N-2) + f(potions_N-2))

    // base case - input array has size two - ...then the solutions is just a*b

    // As you could imagine..this is just a recursified brute force (trying all possible
    // sequences of N - 1 mixed pairs)

    // thats why we create a memo table - map<vector<int>, long> and hope it will save us:D
    // and we will keep the memo table global..so that we are learning with each test case


    // Improvements -> f is symmetric..meaning that f(potions) = f(reverse(potions))
    while(cin){
        int N;
        cin >> N;
        vector<int> potions(N);
        for(int i = 0; i < N; i++){
            cin >> potions[i];
        }
        if(N == 1){
            cout << 0 << endl;
        }else{
            cout << f(potions) << endl;

        }
        //vector<int> temp = mix_2_potions(potions,1,2);
        //print_me(temp);
        cout << memo_table.size() << endl;
    }
}



