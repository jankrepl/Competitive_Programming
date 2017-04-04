// Name: 500_Keyboard_Row
// WWWW: https://leetcode.com/problems/keyboard-row
// Author: Jan Krepl


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> U = {'Q','W','E','R','T','Y','U','I','O','P'};
        set<char> M = {'A','S','D','F','G','H','J','K','L'};
        set<char> L = {'Z','X','C','V','B','N','M'};
        
        vector<string> output;
        for(vector<string>::iterator it = words.begin(); it < words.end(); it++){
            string tested = *it;
            for(int i = 0; i < tested.size(); i++){
                tested[i] = toupper(tested[i]);
            }
            set<char> test_row;
            char row_of_interest;
            //find the corresponding set for the first character
            if(binary_search(U.begin(),U.end(),tested[0])){
                test_row = U;
            }else if(binary_search(M.begin(),M.end(),tested[0])){
                test_row = M;
            }else{
                test_row = L;
            }
            
            bool passed = true;
            for(int i = 1; i < tested.size(); i++){
                if(!binary_search(test_row.begin(),test_row.end(),tested[i])){
                    passed = false;
                }
            }
            if(passed){
                output.push_back(*it);
            }
        }
        return output; 
    }
};