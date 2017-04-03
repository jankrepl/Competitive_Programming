#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

using namespace std;


int main() {
    biginteger final_sum(number_to_vector_of_digits(0));
    int piiiica = 0;
    set<int> reseni;
    for(int i = 1; i < 10000; i++){
        vector<int> iii = number_to_vector_of_digits(i);
        biginteger b_i(iii);
        for(int j = i + 1; j < 10000; j++){
            vector<int> jjj = number_to_vector_of_digits(j);
            vector<int> product_digits = number_to_vector_of_digits(i*j);


            if(iii.size() + jjj.size() + product_digits.size() !=9){
                continue;
            }
            biginteger b_j(jjj);
            biginteger prod;
            prod = b_j.multiply(i);
            biginteger concat;
            concat=b_i.concatenate(b_j.concatenate(prod));
            if(concat.is_pandi_9()){
//                concat.print();
                cout << i << "x" << j << "=";
                prod.print();
                final_sum = final_sum + concat;
                final_sum.print();
                reseni.insert(i*j);


            }
        }
    }
    cout << "THE FINAL result :";
    final_sum.print();

    for(set<int>::iterator it = reseni.begin(); it != reseni.end(); it++){
        piiiica += *it;
    }

    cout << "a skutecne je to toto: " << piiiica;
//    biginteger m(number_to_vector_of_digits(123456789));
//    biginteger n(number_to_vector_of_digits(1));
//    biginteger result;
//
//    result =  n.multiply(1);
//    result.print();
//    result =  n.multiply(2);
//    result.print();
//    result =  n.concatenate(n.multiply(3));
//    result.print();

//    bool test = n > m.;
//    bool test2 = n < m;
//    bool test3 = n == m;
//    bool test4 = m.is_pandi_9();
//    result.print();
//    cout << test << " "<< test2 <<" "<< test3<<" "<< test4;
//    return 0;
}
