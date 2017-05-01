// Name: New_Year_Transportation
// CODE: 500A
// WWWW: http://codeforces.com/problemset/problem/500/A
// Author: Jan Krepl
// Tags: Graphs, DFS
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
#include <typeinfo>
#include <cstring> 
using namespace std;




vector<vector<int>> construct_al(vector<int> &portals, int n){
  // node 1 will be stored as node 0...
  vector<vector<int>> output(n);
  for(int i = 0; i < n - 1; i++){
    output[i].push_back(i + portals[i]);
  }
  return output;
}


void dfs(int start_node, vector<int> &visited, vector<vector<int>> &al){
  visited[start_node] = true;
  for(int i = 0; i < al[start_node].size(); i++){
    if(!visited[al[start_node][i]]){
      dfs(al[start_node][i],visited,al);
    }
  }
}

int main(){
  int n,t;
  cin >> n >> t;
  t--;
  vector<int> portals(n - 1);
  for(int i = 0; i < n - 1; i++){
    cin >> portals[i];
  }

  vector<int> visited(n);
  vector<vector<int>> al = construct_al(portals,n);

  dfs(0, visited, al);

  cout << (visited[t] ? "YES" : "NO") << endl;


}