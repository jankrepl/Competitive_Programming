// Name: Largest_Permutation
// WWWW: https://www.hackerrank.com/challenges/largest-permutation
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <algorithm>
using namespace std;

void print_me(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


int main() {
        /* Strategy */
    // We will just do the stupidest algorithm...go from the left of a and make sure the element is equal to the
    // highest possible number..if not..we swap it with the positon where the largest element is..
    // we do this k times...and also at each iteration start where we left before + 1
    
        /* Hacks */
    // we avoid using finds by creating a ifnder table
    
    int N,K;
    cin >> N >> K;
    vector<int> a(N);
    vector<int> finder(N + 1); //ith element in finder = position of element i in vector a
    for(int i = 0; i < N; i++){
        cin >> a[i];
        finder[a[i]] = i;
    }
    
    // we can easily use the finder table to look for elements 


    for(int i = 0; i < N && K > 0; i++){
        if(a[i] == N - i){
            continue;
        }else{
            //find where in a N - i is and swap it
            a[finder[N-i]] = a[i]; // 
            finder[a[i]] = finder[N-i];
            a[i] = N - i;
            finder[N-i] = i;

            K--;
        }
    }

    
    print_me(a);


    
    return 0;
    
    
}
