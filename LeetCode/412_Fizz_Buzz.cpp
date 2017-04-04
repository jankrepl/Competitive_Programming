// Name: 412_Fizz_Buzz
// WWWW: https://leetcode.com/problems/fizz-buzz
// Author: Jan Krepl

class Solution {
public:
    string jan_conversion(int n){

        ostringstream convert;  

        convert << n;     

        return convert.str(); 
    }
    vector<string> fizzBuzz(int n) {
        vector<string> output;
        for(int i = 1; i <= n; i++){
            if(i % 3 == 0 && i % 5 == 0){
                output.push_back("FizzBuzz");
                continue;
                
            }else if(i % 3 == 0 && i % 5 != 0){
                output.push_back("Fizz");
                continue;
                
            }else if(i % 3 != 0 && i % 5 == 0){
                output.push_back("Buzz");
                continue;
                
            }else{
                output.push_back(jan_conversion(i));
                continue;
            }
        }
        return output;
    }
};