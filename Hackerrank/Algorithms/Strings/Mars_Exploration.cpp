// Name: Mars_Exploration
// WWWW: https://www.hackerrank.com/challenges/mars-exploration
// Author: Jan Krepl

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string S;
    cin >> S;
    
    int size = S.size();
    int position = 0;
    int counter = 0;
    //logic here is that 0,2,3,5,6,8,.... is S and 1,4,7,... is O
    
    while(position != size){
        if((position + 2) % 3 == 0){
            //compare with O
            if(S[position] != 'O'){
                counter++;
            }
        }else{
            //compare with S
            if(S[position] != 'S'){
                counter++;
                
            }
        }
        position++;
    }
    cout << counter;
    return 0;
}
