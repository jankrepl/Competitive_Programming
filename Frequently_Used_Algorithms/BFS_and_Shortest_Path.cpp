// Algorithm: BFS_and_Shortest_Path
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
#include <queue> 

using namespace std;


/* Description */
//The goal is to find a shortest path in a graph from node a to node b..and specifically list the consecutive nodes...this will be a 
//byproduct of the bfs algorithm - if the edges are unweighted, the first path to be found with bfs is the shortest one



/* Tips and tricks */



/* Example problem */



/* Implementation #1 */
// INIT
const int N = 10; // number of nodes

vector<bool> visited(N,false); // Lets assume they are numbered 0,..., N-1

vector<int> previous(N, -1); // only needed in shortest path

vector<vector<int>> adjacency_list; // Needs to be defined based on the graph



// BFS
void bfs(int start_node){

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



/* Usage */

// Shortest path
vector<int> path; // where we save the path

void shortest_path(int start_node, int end_node){

    if(start_node == end_node){
        path.push_back(start_node);
        return;
        //end the recursion
    }else{
        path.push_back(end_node);
        return shortest_path(start_node,previous[end_node]);
    }        

}


