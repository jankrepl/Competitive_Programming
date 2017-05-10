// Name: Even_Tree
// WWWW: https://www.hackerrank.com/challenges/even-tree
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
// Step 1) Create a node class
// Step 2) Create tree as vector of pointers to nodes
// Step 3) Go from the lowest layer...if a subtree starting from that child has even number of vertices
        // just cut it out and count the cut

int answer = 0;
class Node{
public:
  vector<Node*> neighbours;
 
  bool visited = false;

  int count_me(){
    this->visited = true;
    int counter = 0;
    for(auto it : neighbours){
      if(!(it->visited)){
          counter += it->count_me();
      }
    }
    if(counter % 2 != 0){
      answer++;
    }
    return counter + 1;
  }

};



int main(){
  int N,M;
  cin >> N >> M;

  // initialize all pointers to nodes
  vector<Node*> tree; 

  // allocate memory
  for(int i = 0; i < N; i++){  // numbering is shifted by 1
    tree.push_back(new Node);
  }

  // read in edges and populate tree
  for(int i = 0; i < M; i++){
    int t1, t2;
    cin >> t1 >> t2;

    tree[t1 - 1]->neighbours.push_back(tree[t2 - 1]);
    tree[t2 - 1]->neighbours.push_back(tree[t1 - 1]);

  }

  tree[0]->count_me();
  cout << answer - 1 << endl;




}
