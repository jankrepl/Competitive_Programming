// Name: 572_Subtree_of_Another_Tree
// WWWW: https://leetcode.com/problems/subtree-of-another-tree
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


struct TreeNode {
     int val;
      TreeNode *left;
       TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 


// U can imagine in a way that they have build a binary tree somewhere,
// and thats why the input is two pointers to tree nodes

// Strategy:
// Define a helper function - is_equal <- recursively
// issubtree -> you go from node s to its children etc and always check whether the subtree starting there is_equal to t

class Solution {
  bool is_equal(TreeNode* a, TreeNode* b){

    // YOU CANNOT COMPARE  (==) POINTERS...because if trees stored separately, then doesnt work

    // two trees are equal if the current nodes are the same
    // and the left and right subtrees are the equal

    // Base case
    if(a == NULL && b == NULL){
      // both nodes are in the end layer
      return true;
    }

    if(a == NULL ^ b == NULL){
      // only one of them end branch
      return false;
    }

    // Inductive step

    return a -> val == b -> val && is_equal(a -> left, b -> left) && is_equal(a -> right , b -> right);

  }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {

        // base cases
        if(t == NULL){
          // empty tree is a subtree of anything:D
          return true;
        }

        if(s == NULL){
          // if we recursively got all the way to the bottom of the tree ..then subtree t wasnt found
          return false;
        }


        if(is_equal(s,t)){
          return true;
        }

        // recursive step -> go to children
        return isSubtree(s -> left, t) || isSubtree(s -> right, t);
    }
};

