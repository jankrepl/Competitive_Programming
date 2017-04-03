//
// Created by Jan Krepl on 08.01.17.
//

#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <math.h>
#include <set>
#include <vector>
#include "Toolkit_classes.h"


using namespace std;




biginteger biginteger::operator+(biginteger rhs) {
        vector<int> smaller, bigger;

    if(rhs.a.size()>= this->a.size()){
        smaller = this->a;
        bigger = rhs.a;

    }else{
        smaller = rhs.a;
        bigger = this->a;
    }


    biginteger temp;


    int remainder = 0;
    int sum = 0;
    vector<int>::iterator it_big = bigger.end() - 1;

    for(vector<int>::iterator it = smaller.end() - 1; it >= smaller.begin(); it--){
        sum = (*it + *it_big + remainder) % 10;
       remainder = (*it + *it_big + remainder) / 10;

        temp.a.push_back(sum);
        if(it_big != bigger.begin()) {
            it_big--;
        }
    }

    if (bigger.size() == smaller.size() && remainder == 0){


    }else if(bigger.size() == smaller.size() && remainder > 0){
        temp.a.push_back(remainder);

    }else{
        while (it_big >= bigger.begin()) {
            sum = (*it_big + remainder) % 10; // % 10 added
            remainder = (*it_big + remainder) / 10;
            temp.a.push_back(sum);


//            remainder = 0;
            if(it_big == bigger.begin()){
                if(remainder > 0){
                    temp.a.push_back(remainder);
                    break;
                }else{
                    break;
                }
            }else{
                it_big--;
            }
        }
    }
    reverse(temp.a.begin(),temp.a.end());
    return temp;

}




void biginteger::print() {
    for(vector<int>::iterator it = this->a.begin(); it < this->a.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

}


biginteger::biginteger(const vector<int> &a) : a(a) {}

biginteger::biginteger() {
    a = {};

}


int biginteger::size() {
    return a.size();
}

biginteger biginteger::concatenate(biginteger rhs) {
    biginteger temp;
    temp = *this;

    temp.a.insert(temp.a.end(),rhs.a.begin(),rhs.a.end());

    return temp;
}

bool biginteger::operator>(biginteger rhs) {
    if (this->size() > rhs.size()) {
        return true;
    } else if (this->size() < rhs.size()) {
        return false;
    } else {
        for(int i = 0; i < rhs.size(); i++){
            if(this->a.at(i) > rhs.a.at(i)){
                return true;
            }else if(this->a.at(i) < rhs.a.at(i)){
                return false;
            }else{
                continue;
            }
        }
    }
    return false;
}

bool biginteger::operator<(biginteger rhs) {
    return rhs>*this;

}

bool biginteger::operator==(biginteger rhs) {

    return (!(*this>rhs)&&!(*this<rhs));
}

bool biginteger::is_pandi_9() {
    biginteger m = *this;
    if (m.a.size() != 9){
        return false;
    }
    for(int i = 0; i < 9; i++){
        if(find(m.a.begin(), m.a.end(), i + 1) == m.a.end()){
            return false;
        }
    }
    return true;
}

biginteger biginteger::multiply(int m) {
    biginteger copy = *this;
    biginteger result = copy;
    for (int i = 1; i < m; i++){
        result = result + copy;
    }
    return result;
}

bool biginteger::is_pandi_any() {
    vector<int> digits;
    digits = this->a;

    if (digits.size() > 9){
        return false;
    }
    for(int i = 0; i < digits.size(); i++){
        if(find(digits.begin(), digits.end(), i + 1) == digits.end()){
            return false;
        }
    }
    return true;

}

biginteger biginteger::operator^(int rhs) {
    biginteger copy = *this;
    biginteger temp = copy;

    for(int i = 1; i < rhs; i++){
        temp = temp*copy;
    }

    return temp;
}

biginteger biginteger::operator*(biginteger rhs) {
    biginteger up;
    biginteger down;

    if(this->size() >= rhs.size()){
        up = *this;
        down = rhs;
    }else{
        down = *this;
        up = rhs;
    }

    vector<int> up_vector = up.a;
    vector<int> down_vector = down.a;

    biginteger overall_sum({0});

    for(vector<int>::iterator it_down = down_vector.end() - 1; it_down >= down_vector.begin(); it_down-- ){

        vector<int>::iterator it_up = up_vector.end() - 1;
        int remainder = 0;
        int to_add = 0;
        biginteger temp_sum({0});
        vector<int> temp_sum_vector;
        while(it_up >= up_vector.begin()) {

            to_add = (*it_down * (*it_up) + remainder) % 10;

            temp_sum_vector.push_back(to_add);

            remainder = (*it_down * (*it_up)  + remainder) / 10;
            if(it_up == up_vector.begin()) {
                break;
            }else{
                it_up--;
            }
        }
        if(remainder > 0){
            temp_sum_vector.push_back(remainder);

        }
        reverse(temp_sum_vector.begin(),temp_sum_vector.end());
       for(int i = 1; i < distance(it_down,down_vector.end()); i++){
            temp_sum_vector.push_back(0);
        }
        temp_sum.a = temp_sum_vector;
        overall_sum = overall_sum + temp_sum;
    }

    return overall_sum;
}

int biginteger::sum_digits() {
    int output = 0;
    for(vector<int>::iterator it = a.begin(); it < a.end(); it++){
        output += *it;
    }
    return output;
}

biginteger biginteger:: reverse_me() {
    biginteger output = *this;
    reverse(output.a.begin(),output.a.end());
    return output;
}

bool biginteger::is_palindrome() {

        int my_vector_size = this->a.size();
        vector<int> r_copy = this->a;
        reverse(r_copy.begin(),r_copy.end());
        for(int i = 0; i < my_vector_size/2; i++ ){
            if(r_copy[i] != this->a[i]){
                return false;
            }
        }
        return true;

}

biginteger biginteger::last_digits(int digits) {
        if(this->size()<= digits){
            return *this;
        }else{
            vector<int>::iterator finish = this->a.end();
            vector<int>::iterator start = this->a.end() - digits;
            vector<int> output(start,finish);
            biginteger output_bi(output);
            return output_bi;
        }
}

vector<int> biginteger::export_odd_digits() {
    vector<int> temp;

    for(int i = 0; i < this->size(); i += 2){
        temp.push_back(a[i]);
    }

    return temp;
}





