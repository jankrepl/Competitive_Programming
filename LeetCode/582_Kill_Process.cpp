// Name: 582_Kill_Process
// WWWW: https://leetcode.com/problems/kill-process
// Author: Jan Krepl


/* Strategy */
// create adjacency list 
// DFS



class Solution {
public:
void dfs(int node, vector<bool> &visited, vector<vector<int>> &al){
  visited[node] = true;
    int size = al[node].size();
  for(int i = 0; i < size; i++){
    if(!visited[al[node][i]]){
      dfs(al[node][i],visited, al);
    }
  }
}


vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
  // create adjacency list - children are the only neighbours
  int max_id = *max_element(pid.begin(), pid.end());
  vector<bool> visited(max_id + 1,false);
    vector<vector<int>> al(max_id + 1);
  for(int i = 0; i < pid.size(); i++){
    al[ppid[i]].push_back(pid[i]);
  }
  
  dfs(kill, visited, al);

  vector<int> output;
  for(int i = 0; i <  int(visited.size()); i++){
    if(visited[i]){
      output.push_back(i);
    }
  }
  return output;

}
};