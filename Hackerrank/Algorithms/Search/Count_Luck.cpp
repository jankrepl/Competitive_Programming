// Name: Count_Luck
// WWWW: https://www.hackerrank.com/challenges/count-luck
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


vector<vector<int>> create_al(vector<string> &matrix,int N, int M){
    vector<vector<int>> output;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            vector<int> one_line;
            if(matrix[i][j] == 'X'){
                output.push_back(one_line);
            }else{
                if(j - 1 >= 0 && matrix[i][j-1] != 'X'){
                    one_line.push_back(i*M + j - 1);

                }
                if(j + 1 < M && matrix[i][j+1] != 'X'){
                    one_line.push_back(i*M + j + 1);

                }
                if(i - 1 >= 0  && matrix[i - 1][j] != 'X'){
                    one_line.push_back((i-1)*M + j);

                }
                if(i + 1 < N  && matrix[i+1][j] != 'X'){
                    one_line.push_back((i+1)*M + j);
                }
                output.push_back(one_line);

            }
        }
    }
    return output;
}

void backtracker(int a,int b,vector<int> &previous, vector<int> &path){
    if(a == b){
        path.push_back(b);
        return;
        //end the recursion
    }else{
        path.push_back(b);
        return backtracker(a,previous[b],previous,path);
    }
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M;
        int start;
        int end;
        vector<string> matrix(N, string(M, 'a'));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 'M') {
                    start = M * i + j;
                }
                if (matrix[i][j] == '*') {
                    end = M * i + j;
                }
            }
        }
        cin >> K;

        vector<vector<int>> al = create_al(matrix, N, M);

        //BFS
        vector<int> visited(N * M, 0);
        int a = start;
        vector<int> previous(N * M, -1);
        queue<int> my_queue;

        my_queue.push(a);
        while (!my_queue.empty()) {
            int to_investigate = my_queue.front();
            my_queue.pop();

            visited[to_investigate] = 1;

            for (vector<int>::iterator it = al[to_investigate].begin(); it < al[to_investigate].end(); it++) {
                if (visited[*it] == 0) {
                    my_queue.push(*it);
                    previous[*it] = to_investigate;
                }
            }
        }

//now we simply use the previous vector to deduce/BACKTRACK the path

        vector<int> path;

        backtracker(a, end, previous, path);
        reverse(path.begin(), path.end());

        int counter = 0;
        for(int i = 0; i < path.size() - 1; i++){
            if(al[path[i]].size() >= 2){
                int indexx = path[i];
                //now more directions mean that that at least 2 neighbours lie in a different row and column of the matrix..
                for(int j = 0; j < al[indexx].size(); j++){
                    for(int m = 0; m < al[indexx].size(); m++){
                        if(al[indexx][j]%M != al[indexx][m]%M || (al[indexx][j]/M != al[indexx][m]/M )){
                            //different row and different column
                            if(i == 0 || ((al[indexx][m] != path[i - 1 ]) && (al[indexx][j] != path[i-1]))){
                                counter++;
                                goto jump2;

                            }
                        }
                    }
                }
            }
            jump2:;

        }
        if(counter == K){
            cout << "Impressed" << endl;

        }else{
            cout << "Oops!" << endl;
        }

    }

}

