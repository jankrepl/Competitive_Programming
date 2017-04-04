// Name: Connected_Cells_in_a_Grid
// WWWW: https://www.hackerrank.com/challenges/connected-cell-in-a-grid
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>




using namespace std;



void dfs(vector<int> &visited, vector<vector<int>> &aj, int j,int &counter){
    visited[j] = 1;
    counter++;
    for(vector<int>::const_iterator it = aj[j].begin(); it != aj[j].end(); it++){
        //avoid infinite depth:D
        if(visited[*it] == 0){
            dfs(visited,aj,*it,counter);

        }
    }

}

vector<int> my_neighbours(const vector<vector<int>> &a, int x,int y,int n,int m){
    vector<int> result;
    for(int i = - 1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if((x+i)>= n || (y+j) >= m || (x+i)< 0 ||(y+j) < 0){
                continue;
            }
            if(a[x+i][y+j] == 1 && ((i != 0) || (j != 0))){
                result.push_back((x+i)*m + y + j);
            }
        }
    }
    return result;

}




int main() {
    int n,m;
    cin >> n >> m;
    //Initialize our main vector
    vector<vector<int>> a(n,vector<int>(m,0));
    //Populate it with input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    //We create adjancency list
    vector<vector<int>> aj;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
//            if(a[i][j] == 0) continue;
            aj.push_back(my_neighbours(a,i,j,n,m));
        }
    }

    //Lets do DFS on each elemenet
    int i = (int)aj.size();
    int maximum = 0;
    while(i--){
        if(a[i/m][(i%m)] == 0){
            continue;
        }
        //its important to have a brand new visited for each d
        vector<int> visited(n*m,0);
        int counter = 0;
        //run dfs and the results are saved into a global variable counter
        dfs(visited,aj,i,counter);

        maximum = max(maximum,counter);



    }
    cout << maximum;


    return 0;
}