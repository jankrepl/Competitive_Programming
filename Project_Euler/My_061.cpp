#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"



using namespace std;
//problem 61

//You will create all permutations of the types...and for each permutation you will do step by step lookup in the following type




bool chainable(vector<int> lhs_digits, vector<int> rhs_digits){
    int size = (int)lhs_digits.size();
    vector<int> last_two({lhs_digits[size - 2],lhs_digits[size - 1]});
    vector<int> first_two({rhs_digits[0],rhs_digits[1]});

    return first_two == last_two;
}

int main(){


    //testing
    vector<vector<int>> triangle,square,pent,hex,hept,oct;
    vector<vector<vector<int>>> database;

    //generate vector of numbers of a specific tajp
    for(int i = 1000; i < 10000; i++){
        if(is_triangular(i)){
            triangle.push_back(number_to_vector_of_digits(i));
        }

        if(is_square(i)){
            square.push_back(number_to_vector_of_digits(i));
        }

        if(is_pentagonal(i)){
            pent.push_back(number_to_vector_of_digits(i));
        }

        if(is_hexagonal(i)){
            hex.push_back(number_to_vector_of_digits(i));
        }

        if(is_heptagonal(i)){
            hept.push_back(number_to_vector_of_digits(i));
        }

        if(is_octagonal(i)){
            oct.push_back(number_to_vector_of_digits(i));
        }

    }
    //put them all in a database
    database.push_back(triangle);
    database.push_back(square);
    database.push_back(pent);
    database.push_back(hex);
    database.push_back(hept);
    database.push_back(oct);

    //create all possible permutations of tajps order
    vector<int> all_tajps({0,1,2,3,4,5});
    set<vector<int>> all_tajps_perm = permutations(all_tajps,false);

    for( set<vector<int>>::iterator it = all_tajps_perm.begin(); it != all_tajps_perm.end(); it++){

        for(vector<vector<int>>::iterator i1 = database[(*it)[0]].begin(); i1 < database[(*it)[0]].end(); i1++ ){
            for(vector<vector<int>>::iterator i2 = database[(*it)[1]].begin(); i2 < database[(*it)[1]].end(); i2++ ){
                if(!chainable(*i1,*i2)){
                    continue;
                }
                for(vector<vector<int>>::iterator i3 = database[(*it)[2]].begin(); i3 < database[(*it)[2]].end(); i3++ ){

                    if(!chainable(*i2,*i3)){
                        continue;
                    }
                    for(vector<vector<int>>::iterator i4 = database[(*it)[3]].begin(); i4 < database[(*it)[3]].end(); i4++ ){

                        if(!chainable(*i3,*i4)){
                            continue;
                        }
                        for(vector<vector<int>>::iterator i5 = database[(*it)[4]].begin(); i5 < database[(*it)[4]].end(); i5++ ){

                            if(!chainable(*i4,*i5)){
                                continue;
                            }
                            for(vector<vector<int>>::iterator i6 = database[(*it)[5]].begin(); i6 < database[(*it)[5]].end(); i6++ ){

                                if(!chainable(*i5,*i6)){
                                    continue;
                                }

                                if(!chainable(*i6,*i1)){
                                    continue;
                                }else {
                                        cout << vector_of_digits_to_number(*i1) + vector_of_digits_to_number(*i2) + vector_of_digits_to_number(*i3) + vector_of_digits_to_number(*i4) + vector_of_digits_to_number(*i5) + vector_of_digits_to_number(*i6);
                                        cout << endl;
                                    }
                                }

                            }
                        }
                    }
                }
            }
        }
    }

//cout << chainable(number_to_vector_of_digits(1233),number_to_vector_of_digits(3343));





