// helloworld.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Determines the sum of all divisors of x (excluding itself)
long sum_of_divisors(int x){
    int divisor = 2;
    long sum = 1; //everything is divisible by zero
    while(divisor<=x/2){
        if(x%divisor == 0){
            sum += divisor;

        }
        ++divisor;
    }
    return sum;
}


// Determines whether x is abundant
bool is_abundant(int x){
    if (sum_of_divisors(x)>x) {
        return true;
    }else {
        return false;
    }
}



int main()
{
    vector<int> abundant_vector_final = {};

    for(int i = 1;i<=28123;++i){
        if(is_abundant(i)){
            abundant_vector_final.push_back(i);
        }
    }

    //create all sums
    vector<int> all_sums = {};
    int vector_size = abundant_vector_final.size();
    cout << vector_size<< endl;
    int mycleversum = 0;

    for (int i = 0; i<vector_size; i++){
        for (int j = i; j<vector_size; j++){
            mycleversum = abundant_vector_final[i]+abundant_vector_final[j];
            if(mycleversum<=28123 ) {
                if(find(all_sums.begin(),all_sums.end(),mycleversum)==all_sums.end()){
                all_sums.push_back(mycleversum);
                }
            }else{
                break;}
        }
    }

    cout << all_sums.back()<< endl;

    //Find all that are not in all_sums
    long sum_final  = 0;
    bool includenumber = true;
    for(int i =1; i<=28123; ++i){
        includenumber = find(all_sums.begin(), all_sums.end(), i) == all_sums.end();
        if(includenumber){
            sum_final += i;
        }

    }
    cout << sum_final  <<endl;
}
