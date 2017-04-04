// Name: Insertion_Sort_Part_1
// WWWW: https://www.hackerrank.com/challenges/insertionsort1
// Author: Jan Krepl

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void print_me(vector<int> ar){
    for(int i = 0; i < ar.size(); i++){
        cout << ar[i] << " ";
    }
    cout << endl;
    return;
}
void insertionSort(vector <int>  ar) {
    int culprit = ar.back();
    bool suc = false;
    for(int i = ar.size() - 2; i >= 0; i--){
        if(ar[i] >= culprit){
            ar[i+1] = ar[i];
            print_me(ar);
        }else{
            ar[i+1] = culprit;
            print_me(ar);
            suc = true;
            break;

            
        }
    }
            if(!suc){
                ar.front() = culprit;
                print_me(ar);
                
         }
    return;


}
int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

    insertionSort(_ar);
    return 0;
}
