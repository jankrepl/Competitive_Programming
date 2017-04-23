// Name: Roman_to_Integer
// Problem_Code: 13
// WWW: https://leetcode.com/problems/roman-to-integer
// Author: Jan Krepl


class Solution {
public:
    void redefine_map(map<char,bool> &my_map, char key_to_leave){
        // in a string...a previous character is only one..so we will use this function
        // at each iteration
        for(map<char,bool>::iterator it = my_map.begin(); it != my_map.end(); it++){
            if(it->first != key_to_leave){
                it->second = false;
            }else{
                it->second = true;
            }
        }
    }
    
    char find_true(map<char,bool> &my_map){
        for(map<char,bool>::iterator it = my_map.begin(); it != my_map.end(); it++){
            if(it->second){
                return it->first;
            }
        }
        return 'Z'; // it means that that there is no previous character
    }
    
    int romanToInt(string s){
        //initialize my sum
        int counter = 0;
    
        // lets create a map
        map<char,bool> previous;
    
        // set up my map;
    
        previous['I'] = false;
        previous['V'] = false;
        previous['X'] = false;
        previous['L'] = false;
        previous['C'] = false;
        previous['D'] = false;
        previous['M'] = false;
    
        //lets start - backwards
            //the reason is that we can simply add the number one by one..
            // because a digit and its previous digit fully determine the number
        // problematic numbers - IV = 4 , IX = 9, 40 + .. = XL.., 90 + .. = XC..
        // 400 + .. = CD .., 900 + ii = CM
    
        int index = s.size();
        while(index--){
            if(s[index] == 'I'){
                if(find_true(previous) == 'V'){
                    counter--;
    
                }else if(find_true(previous) == 'X'){
                    counter--;
    
                }else{
                    counter++;
    
                }
    
            }else if(s[index] == 'V'){
                counter += 5;
    
            }else if(s[index] == 'X'){
                if(find_true(previous) == 'L'){
                    counter -= 10;
                }else if(find_true(previous) == 'C'){
                    counter -= 10;
                }else{
                    counter += 10;
                }
    
            }else if(s[index] == 'L'){
                counter += 50;
    
            }else if(s[index] == 'C'){
                if(find_true(previous) == 'D'){
                    counter -= 100;
                }else if(find_true(previous) == 'M'){
                    counter -= 100;
    
                }else{
                    counter += 100;
                }
    
            }else if(s[index] == 'D'){
                counter += 500;
    
            }else if(s[index] == 'M'){
                counter += 1000;
    
            }else{
                //pass
            }
            redefine_map(previous,s[index]);
        }
        return counter;
    }
};