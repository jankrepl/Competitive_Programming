// Name: Designer_PDF_Viewer
// WWWW: https://www.hackerrank.com/challenges/designer-pdf-viewer
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
    int n = 26;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    string word;
    cin >> word;
    
    //map each letter in word to its height and just keep the survivor
    int winner_height = 0;
    for(int i = 0; i < word.size(); i++){
        int height = h[(int)(word[i] - 97)];
        winner_height = max(height, winner_height);
    }
    
    
    cout << word.size()*winner_height;
}
