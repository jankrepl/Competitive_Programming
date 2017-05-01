// Algorithm: Set_Union
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
// We start with a vector of elements and keep on merging(union) them in pairs ->
// this results in some partition of the original vector into subsets that are disjoint

// The goal is to model this process, design a convenion data structure and 
// write both intermediary functions and end functions (number of disjoint subsets, 
// size of the subeset containint element i)



/* Tips and tricks */



/* Example problem */
// You have a group of cosmonauts and you are given in pairs which cosmonauts are from the same country
// Determine how many contries there are, and how many pairs of distict nationality 
// cosmonauts are there


/* Implementation #1 */

// INTUITION
// To each element we assign a parent -- at the beginning, each elemenet is its own parent
// When merging uniting two elements we will just change the ULTIMATE parent of one of them
// to be eqaual to the ultimate parent of the other

// GRAPHICAL INTUITION
// We put all elements on the same line ... when uniting we stack one element on top of the other 
// when uniting elements that are in (possibily different) stacks already...we just find the 
// the ultimate parent(the top elements of their stacks) and just stack the stacks on themselves


// INITIALIZE
const int N = 10; // number of elements 
vector<int> pset(N); // parent set - pset[i] = parent of element i

void initialize_pset(){
  // just singletos..each element is in th
  iota(pset.begin(), pset.end(), 1);
}

// HELPER FUNCTIONS
int find_parent(int i){
    //Find ultimate parent
     
  return (pset[i] == i ? i : find_parent(pset[i]));

}

void set_union(int i, int j){
    // redefine one ultimate parent to be equal to the other ultimate parent
  pset[find_parent(i)] = find_parent(j);

}

// END FUNCTIONS
int number_of_sets(){
  // our goal is to count the number of distinct ultimate parents
  set<int> counter;
  for(int i = 0; i < N; i++){
    counter.insert(find_parent(i));
  }
  return counter.size();
}

int size_of_set(int i){
    // size of set where i belongs to
  int counter = 0;
  for(int j = 0; j < N; i++){
    if(find_parent(j) == find_parent(i)){
      counter++;
    }
  }
  return counter;
}