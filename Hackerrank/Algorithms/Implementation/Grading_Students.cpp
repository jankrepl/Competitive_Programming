// Name: Grading_students
// WWWW: https://www.hackerrank.com/challenges/grading
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

int determine_grade(int orig){
    if(orig < 38){
        return orig;
    }else{
        if((orig % 5) < 3){
            return orig;
        }else{
            return (orig + (5 - (orig % 5)));
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int grade;
        cin >> grade;
        cout << determine_grade(grade) << endl;
    }
}
