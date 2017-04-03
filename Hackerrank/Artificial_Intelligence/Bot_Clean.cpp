// Name: Bot_Clean
// WWWW: https://www.hackerrank.com/challenges/botclean
// Author: Jan Krepl

#include<iostream>
#include<vector>
using namespace std;

void next_move(int posr, int posc, vector<string> board) {
    // If standing on a dirty cell, clean it
    if(board[posr][posc] == 'd'){
        cout << "CLEAN" << endl;
        return;
    }

    /* Find closest algorithm */
    
    // Save all dirty cells as pairs in a vector - Determine which one is the closest
    vector<pair<int,int>> all_shits;
    vector<int> all_shits_distances;
    pair<int,int> winner_shit = make_pair(0,0);
    int min_distance = 100;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(board[i][j] == 'd' && !((i == posr) && (j == posc))){
                all_shits.push_back(make_pair(i,j));
                int distance = abs(posr - i) + abs(posc - j);
                all_shits_distances.push_back(distance);
                if(distance < min_distance){
                    min_distance = distance;
                    winner_shit = make_pair(i,j);
                }
            }
        }
    }

    pair<int, int> difference_coordinates = make_pair(posr - winner_shit.first, posc - winner_shit.second);

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
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i = 0; i < 5 ; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}