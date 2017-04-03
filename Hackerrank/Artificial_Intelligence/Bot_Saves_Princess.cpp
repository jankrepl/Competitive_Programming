# Name: Bot_Saves_Princess
# WWWW: https://www.hackerrank.com/challenges/saveprincess
# Author: Jan Krepl


#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    vector<string> corner_string; // clockwise Upper left = 1 Upper right = 2,...
    if(grid[0][0] == 'p'){
        corner_string.push_back("UP");
        corner_string.push_back("LEFT");
        
    }else if(grid[0][n - 1] == 'p'){
        corner_string.push_back("UP");
        corner_string.push_back("RIGHT");
        
    }else if(grid[n - 1][n - 1] == 'p'){
        corner_string.push_back("DOWN");
        corner_string.push_back("RIGHT");
        
    }else{
        corner_string.push_back("DOWN");
        corner_string.push_back("LEFT");
    }

    for(int i = 1; i <= n/2; i++){
        cout << corner_string[0] << endl;
    
    }
    for(int i = 1; i <= n/2; i++){
        cout << corner_string[1] << endl;
    }
}
int main(void){
    int m;
    vector <string> grid;
    cin >> m;
    for(int i = 0; i < m; i++) {
        string s; 
        cin >> s;
        grid.push_back(s);
    }
    displayPathtoPrincess(m,grid);
}