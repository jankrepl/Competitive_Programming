// Name: Maximum_Perimeter_Triangle
// WWWW: https://www.hackerrank.com/challenges/maximum-perimeter-triangle
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool is_ndegenerate(int a, int b, int c){
    return (a + b > c && a + c > b && b + c > a);

}
void print_me(vector<long long> &a){
    if(a[0] == -1){
        cout << -1;
        return;
    }
    sort(a.begin(),a.end());
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
}
int main() {
    int n;
    cin >> n;
    vector<long long> sticks;
    vector<long long> winner(3,-1);
    int p = n;
    while(p--){
        int temp;
        cin >> temp;
        sticks.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(is_ndegenerate(sticks[i],sticks[j],sticks[k])){
                    if(sticks[i]+sticks[j]+sticks[k] > winner[0]+winner[1]+winner[2]){
                        winner[0] = sticks[i];
                        winner[1] = sticks[j];
                        winner[2] = sticks[k];


                    }else if(sticks[i]+sticks[j]+sticks[k] == winner[0]+winner[1]+winner[2]){
                        if(max(max(sticks[i],sticks[j]),sticks[k]) > max(max(winner[0],winner[1]),winner[2])){
                            winner[0] = sticks[i];
                            winner[1] = sticks[j];
                            winner[2] = sticks[k];
                        }else if(max(max(sticks[i],sticks[j]),sticks[k]) == max(max(winner[0],winner[1]),winner[2])){
                            if(min(min(sticks[i],sticks[j]),sticks[k]) > min(min(winner[0],winner[1]),winner[2])){
                                winner[0] = sticks[i];
                                winner[1] = sticks[j];
                                winner[2] = sticks[k];

                            }else{

                            }

                        }else{

                        }

                    }else{
                        continue;
                    }

                }

            }
        }
    }
    print_me(winner);
    return 0;
}
