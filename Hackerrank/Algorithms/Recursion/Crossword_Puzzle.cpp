// Name: Crossword_Puzzle
// WWWW: https://www.hackerrank.com/challenges/crossword-puzzle
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <assert.h>
#include <cstring>
#include <tuple>

using namespace std;


// Helper functions


vector<string> sort_words(vector<string> &words_before){
    // sort a vector of strings based on their size
    vector<string> words_after = words_before;
    sort(words_after.begin(), words_after.end(), [](string a, string b){return a.size() < b.size();});
    reverse(words_after.begin(), words_after.end());
    return words_after;
}


vector<string> comma_separated_strings(string &s){
    // parse a string and output vector<string>
    vector<string> output;

    bool found = true;
    int new_index = 0;
    int old_index = 0;

    while(found){
        size_t it = s.find(';', new_index);
        if(it != string::npos){
            new_index = it + 1;
            output.push_back(s.substr(old_index , new_index - old_index - 1));
            old_index = new_index;
        }else{
            output.push_back(s.substr(new_index));
            found = false;
        }
    }

    return output;
}


void print_table(vector<vector<char>> &grid){
    // prints the curent table
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

bool is_filled(vector<vector<char>> &a){
    // Check whether a contains no '-' characters
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(a[i][j] == '-'){
                return false;
            }
        }
    }
    return true;
}


vector<pair<pair<int,int>,char>> where_can_I_embed(vector<vector<char>> &grid, string &word){
    // find all start positions and orientations where word can be embedded
    vector<pair<pair<int,int>,char>> output;
    // { ((1,2),'H'), ((7,3),'V'),... }
    int size = word.size();

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(grid[i][j] == '+'){
                continue;
            }

            // horizontal
            if(size + j <= 10){
                for(int c = j; c < j + size; c++){
                    if(grid[i][c] != '-' && grid[i][c] != word[c-j]){
                        goto jump_1;
                    }
                }
                output.push_back(make_pair(make_pair(i,j),'H'));
                jump_1:;
            }

            // vertical

            if(size + i <= 10){
                for(int r = i; r < i + size; r++){
                    if(grid[r][j] != '-' && grid[r][j] != word[r-i]){
                        goto jump_2;
                    }
                }

                //
                output.push_back(make_pair(make_pair(i,j),'V')) ;
                jump_2:;
            }

        }
    }
    return output;
}


vector<vector<char>> fill_me(vector<vector<char>> &grid, string &word, pair<pair<int,int>,char> position){
    // We assume that the given position can really be filled with our word..and
    // therefore we do not do checks
    vector<vector<char>> grid_after = grid;

    char orient = position.second;
    pair<int, int> start = position.first;

    int word_size = word.size();
    // check if
    int index_word = 0;
    if(orient == 'H'){

        for(int j = start.second; j < start.second + word_size; j++){
            grid_after[start.first][j] = word[index_word];
            index_word++;
        }


    }else{
        for(int i = start.first; i < start.first + word_size; i++){
            grid_after[i][start.second] = word[index_word];
            index_word++;
        }
    }

    return grid_after;
}


// recursion function
pair<bool, vector<vector<char>>> func(vector<string> &words, vector<vector<char>> &grid_before){
    //logic: create a function that plugs one word into the grid and then
    // return the same functions and dont give it the possibility to
    // take the same word as before...
    //..we do it as long as words.size > 0
    if(words.size() == 0){
        if(is_filled(grid_before)){
            return make_pair(true, grid_before);

        }else{
            return make_pair(false, grid_before);
            // should not get here, but just in case
        }
    }else{
        string word_temp = words.front();
        vector<pair<pair<int,int>,char>> positions = where_can_I_embed(grid_before, word_temp);


        if(positions.size() == 0){
            return make_pair(false, grid_before);
        }else{
            for(auto it: positions){
                vector<vector<char>> grid_after = fill_me(grid_before,word_temp,it);
                //print_table(grid_after); // debug
                //cout << endl;
                vector<string> new_words(words.begin() + 1, words.end());
                pair<bool, vector<vector<char>>> zipped_result = func(new_words, grid_after);
                if(zipped_result.first){
                    return zipped_result;
                }
            }
        }
        // should not get here
        return make_pair(false, grid_before);

    }
}


int main(){
    vector<vector<char>> a(10,vector<char>(10));
    for(int i = 0; i < 10; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 10; j++){
            a[i][j] = s[j];
        }
    }

    vector<vector<char>> orig_a = a;

    string csv;
    cin >> csv;

    // convert comma separate csv to vector of strings
    vector<string> words = comma_separated_strings(csv);
    words = sort_words(words);

    pair<bool, vector<vector<char>>> result_zipped  = func(words,a);
    print_table(result_zipped.second);

}
