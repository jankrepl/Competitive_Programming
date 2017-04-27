// Algorithm: DFS
// Author: Jan Krepl

/* Libraries */
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


/* Description */
// Depth First Search. Find all nodes that can be reached
// from a given starting node

/* Tips and tricks */


/* Example problem */


/* Implementation #1 */

const int N = 10; // number of nodes

vector<bool> visited(N,false); // Lets assume they are numbered 0,..., N-1

vector<vector<int>> adjacency_list; // Needs to be defined based on the graph


void dfs(int start_node){
    visited[start_node] = true;
    for(int i = 0; i < adjacency_list[start_node].size(); i++){
        if(!visited[adjacency_list[start_node][i]]){
            dfs(adjacency_list[start_node][i]);
        }
    }

}





// We can easily check if the graph is connected after running dfs
bool is_connected(){
    return all_of(visited.begin(), visited.end(),[](bool a){return a;});
}



