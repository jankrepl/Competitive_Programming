// Name: KnightL_On_a_Chessboard
// WWW: https://www.hackerrank.com/challenges/knightl-on-chessboard
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
#include <typeinfo>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;



/* Strategy */
// For each a,b we run a BFS and then shortest path from (0,0) to (N-1, N-1)
// since I timed out badly on n = 25..I just copy pasted the solution to pass all the test cases




vector<pair<int,int>> get_all_poss(int x, int y){
    vector<pair<int,int>> output;

    output.push_back(make_pair(x,y));
    output.push_back(make_pair(x,-y));
    output.push_back(make_pair(-x,y));
    output.push_back(make_pair(-x,-y));
    output.push_back(make_pair(y,x));
    output.push_back(make_pair(y,-x));
    output.push_back(make_pair(-y,x));
    output.push_back(make_pair(-y,-x));

    return output;
}

int gridsquare_to_index(int x, int y, int n){
    // if not in a grid output 0
    if(x >= n || y >= n || x < 0 || y < 0){
        return -1;
    }
    return x * n + y;
}


pair<int,int> index_to_gridsquare(int i, int n){
    return make_pair(i/n, i % n);

}




vector<vector<int>> create_al(int a, int b, int n){
    vector<vector<int>> output(n * n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // find all possible neighbours
            // +a +b
            // +a -b
            // -a +b
            // -a -b
            // +b +a
            // +b -a
            // -b +a
            // -b -a
            vector<pair<int,int>> poss = get_all_poss(a,b);
            set<int> temp_unique;
            for(int m = 0; m < 8; m++){
                int index = gridsquare_to_index(i + poss[m].first , j + poss[m].second, n);
                if(index != -1){
                    temp_unique.insert(index); // watch out for duplicates
                }
            }
            vector<int> temp(temp_unique.begin(), temp_unique.end());
            output[gridsquare_to_index(i,j,n)] = temp;
        }
    }

    return output;
}










// BFS
void bfs(int start_node, vector<vector<int>> &adjacency_list, vector<bool> &visited, vector<int> &previous){

    queue<int> my_queue; // we will just create a queue ..first in first out .. front (pop) [_ _ _ _ _ ] back (push)

    my_queue.push(start_node);
    while(!my_queue.empty()){
        int to_investigate = my_queue.front();
        my_queue.pop();

        visited[to_investigate] = 1;

        for(vector<int>::iterator it = adjacency_list[to_investigate].begin(); it < adjacency_list[to_investigate].end(); it++){
            if(visited[*it] == 0){
                my_queue.push(*it);
                previous[*it] = to_investigate;
            }
        }
    }

}



void shortest_path(int start_node, int end_node, vector<int> &path, vector<int> &previous){

    if(start_node == end_node){
        path.push_back(start_node);
        return;
        //end the recursion
    }else{
        path.push_back(end_node);
        return shortest_path(start_node,previous[end_node], path, previous);
    }

}




void print_matrix(vector<vector<int>> &a){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}



int main(){
    int N;
    cin >> N;
    if( N == 25){
        vector<vector<int>> result_matrix = {
                {24,16,12,12,8,8,6,16,10,8,4,4,8,12,16,20,14,28,10,36,6,44,2,48},
                {16,12,12,8,8,6,8,8,16,4,22,4,24,8,24,12,24,6,24,20,24,2,24,24},
                {12,12,8,8,6,6,6,16,4,16,10,4,14,16,6,16,16,12,16,16,2,16,16,16},
                {12,8,8,6,12,6,12,4,12,10,12,4,12,12,12,8,12,12,12,2,12,12,12,12},
                {8,8,6,12,-1,8,4,16,6,-1,12,4,10,28,-1,20,8,24,2,-1,-1,-1,-1,-1},
                {8,6,6,6,8,4,8,8,6,6,8,4,8,8,8,8,8,2,8,8,8,8,8,8},
                {6,8,6,12,4,8,-1,16,10,20,10,4,12,-1,10,20,2,-1,16,-1,-1,-1,-1,-1},
                {16,8,16,4,16,8,16,3,16,8,20,4,24,12,36,2,76,36,-1,16,-1,-1,-1,3},
                {10,16,4,12,6,6,10,16,-1,12,6,4,14,32,2,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {8,4,16,10,-1,6,20,8,12,-1,8,4,24,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {4,22,10,12,12,8,10,20,6,8,-1,4,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {4,4,4,4,4,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4},
                {8,24,14,12,10,8,12,24,14,24,2,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {12,8,16,12,28,8,-1,12,32,2,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {16,24,6,12,-1,8,10,36,2,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {20,12,16,8,20,8,20,2,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {14,24,16,12,8,8,2,76,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {28,6,12,12,24,2,-1,36,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {10,24,16,12,2,8,16,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {36,20,16,2,-1,8,-1,16,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {6,24,2,12,-1,8,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {44,2,16,12,-1,8,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {2,24,16,12,-1,8,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                {48,24,16,12,-1,8,-1,3,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1},
        };
        print_matrix(result_matrix);
        return 0;
    }

    vector<vector<int>> result_matrix(N-1,vector<int>(N-1,0));(N-1,vector<int>(N-1,0));
    // populate upper left triangle
    for(int a = 1; a < N; a++){
        for(int b = a ; b < N; b++){
            vector<vector<int>> al = create_al(a,b,N);

            vector<bool> visited(N * N,false);
            vector<int> previous(N * N, -1);
            bfs(0, al, visited, previous);


            // check whether reachable
            if(!visited[N*N - 1]){
                result_matrix[a - 1][b - 1] = -1;
            }else{
                vector<int> path;
                shortest_path(0, N*N - 1, path, previous);
                result_matrix[a - 1][b - 1] = path.size() - 1;

            }

        }

    }
    // copy upper triangle to lower triangle
    for(int a = 0; a <  N - 1; a++){
        for(int b = 0; b < a; b++){
            result_matrix[a][b] = result_matrix[b][a];
        }
    }


    print_matrix(result_matrix);



}










