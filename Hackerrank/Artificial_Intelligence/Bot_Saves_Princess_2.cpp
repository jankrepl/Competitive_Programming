// Name: Bot_Saves_Princess_2
// WWWW: https://www.hackerrank.com/challenges/saveprincess2
// Author: Jan Krepl

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    //Determine which corner
    vector<string> corner_string;// clockwise UPper left = 1 UPper right = 2,...


    if (grid[0][0] == 'p') {
        corner_string.push_back("UP");
        corner_string.push_back("LEFT");

    } else if (grid[0][n - 1] == 'p') {
        corner_string.push_back("UP");
        corner_string.push_back("RIGHT");

    } else if (grid[n - 1][n - 1] == 'p') {
        corner_string.push_back("DOWN");
        corner_string.push_back("RIGHT");

    } else {
        corner_string.push_back("DOWN");
        corner_string.push_back("LEFT");
    }

    for (int i = 1; i <= n / 2; i++) {
        cout << corner_string[0] << endl;

    }
    for (int i = 1; i <= n / 2; i++) {
        cout << corner_string[1] << endl;
    }
}



void nextMove(int n, int r, int c, vector <string> grid){
    // Princess coordinates need to be determined first
    bool princess_found = false;
    int current_row = 0;

    pair<int,int> princess_coordinates = make_pair(0,0);

    while(!princess_found){
        string::iterator found = find(grid[current_row].begin(),grid[current_row].end(),'p');

        if(found != grid[current_row].end()){
            princess_coordinates = make_pair(current_row,distance(grid[current_row].begin(),found));
            break;
        }
        current_row++;

    }
    ///////////////////////
    // We will do a bot - princess coordinates difference..dx, dy
    // Case dx > 0 and dy > 0 : up or left
    // Case dx > 0 and dy <= 0 : up or right
    // Case dx <= 0 and dy > 0 : down or left
    // Case dx <= 0 and dy <= 0 : down or right
    // Then based on absolute size of the difference pick the direction...the bigger absolute difference..pick the size

    pair<int, int> difference_coordinates = make_pair(r - princess_coordinates.first, c - princess_coordinates.second);

    if(difference_coordinates.first > 0 && difference_coordinates.second > 0){
        if(abs(difference_coordinates.first) >= abs(difference_coordinates.second)){
            cout << "UP" << endl;
        }else{
            cout << "LEFT" << endl;
        }

    }else if(difference_coordinates.first > 0 && difference_coordinates.second <= 0){
        if(abs(difference_coordinates.first) >= abs(difference_coordinates.second)){
            cout << "UP" << endl;
        }else{
            cout << "RIGHT" << endl;

        }
    }else if(difference_coordinates.first <= 0 && difference_coordinates.second > 0){
        if(abs(difference_coordinates.first) >= abs(difference_coordinates.second)){
            cout << "DOWN" << endl;
        }else{
            cout << "LEFT" << endl;
        }
    }else if(difference_coordinates.first <= 0 && difference_coordinates.second <= 0){
        if(abs(difference_coordinates.first) >= abs(difference_coordinates.second)){
            cout << "DOWN" << endl;
        }else{
            cout << "RIGHT" << endl;
        }

    }else{

    }
}

int main(void) {

    int n, r, c;
    vector<string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
