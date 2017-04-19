// Name: Larrys_Array
// WWWW: https://www.hackerrank.com/challenges/larrys-array
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
/* Strategy */
// We will use a kind of bubble sort algorithm .. we will go from left to right always selecting a substring of
//size 3..we will rotate until the smallest of the 3 elements is in the first position
//to the next triplet
//we will pass through the vector at max 10000times ...if at any point it is not sorted..we proclaim it unsortable by the
//rotation algorithm


void rotate_left(vector<int> &s, int start_index){

    int start = s[start_index];
    int middle = s[start_index + 1];
    int end = s[start_index + 2];

    s[start_index] = middle;
    s[start_index + 1] = end;
    s[start_index + 2] = start;
    return;
}

void print_me(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i];
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int max_iter = 10000;
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> a_sorted = a;
        sort(a_sorted.begin(),a_sorted.end());

        int n_iter = 0;
        while(n_iter < max_iter){
            for(int i = 0; i < a.size() - 2; i++){
                if(a[i] > a[i+1] || a[i + 1] > a[i + 2]){
                    while(a[i] > a[i + 1] || a[i] > a[i + 2]){
                        rotate_left(a,i);
                    }
                }
            }
            if(a == a_sorted){
                break;
            }else{
                n_iter++;
            }
        }
        cout << ((n_iter == max_iter) ? "NO" : "YES") << endl;

    }
}
