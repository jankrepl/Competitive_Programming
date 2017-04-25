// Name: 537_Complex_Number_Multiplication
// WWWW: https://leetcode.com/problems/complex-number-multiplication
// Author: Jan Krepl


class Solution {
public:
    pair<int, int> unstring_complex(string &a){
        // from an expression a+bi we extract the real and imaginary part as integerss
        size_t index = a.find('+');
        string real_string = a.substr(0,index);
        string imaginary_string = a.substr(index + 1);
    
        return make_pair(stoi(real_string), stoi(imaginary_string));
    
    }
    
    string string_complex(pair<int,int> &zipped){
        return to_string(zipped.first) + '+' + to_string(zipped.second) + 'i';
    }
    
    
    string complexNumberMultiply(string a, string b) {
        pair<int,int> complex_a = unstring_complex(a);
        pair<int,int> complex_b = unstring_complex(b);
    
        // let c is the result of multiplication of a and b
        pair<int,int> complex_c = make_pair(complex_a.first*complex_b.first - complex_a.second*complex_b.second,
                                            complex_a.first*complex_b.second + complex_a.second*complex_b.first);
        return string_complex(complex_c);
        
    }
};