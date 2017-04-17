// Name: Forming_a_Magic_Square
// WWWW: https://www.hackerrank.com/challenges/magic-square-forming
// Author: Jan Krepl

/* Approach */
// Brute - force: We will google all 3x3 magic squares and to each we can assign the cost at which we can
//convert the starting one into 



#include <bits/stdc++.h>

using namespace std;


int cost(vector<vector<int>> &a, vector<vector<int>> &b){
	int result = 0;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			result += abs(a[i][j] - b[i][j]); 
		}
	}
	return result;
}



vector<vector<vector<int>>> all_ms  {
            {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
            {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
            {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
            {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
            {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
            {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
            {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
            {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
            };

int main(){
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];
       }
    }

    int result = 100000;
	for(vector<vector<vector<int>>>::iterator it = all_ms.begin(); it < all_ms.end(); it++){
		result = min(result, cost(*it, s));
	}
	cout << result;

}
