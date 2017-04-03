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
#include <ctime>

#define loop(iterator,upperlimit) for(int iterator = 1; iterator <= upperlimit; iterator++)


using namespace std;
//problem 205

//You will generate all possible 15-tuples ...first 9 represent the dice of peter ..the remaining 4 represent dice of colin
//then you simply count


int main(){

    vector<vector<int>> all_possible_tuples;
    long overall_iterator = 0;
    long peter_wins = 0;
    loop(p1,4){
        loop(p2,4){
            loop(p3,4){
                loop(p4,4){
                    loop(p5,4){
                        loop(p6,4){
                            loop(p7,4){
                                loop(p8,4){
                                    loop(p9,4){
                                        loop(c1,6){
                                            loop(c2,6){
                                                loop(c3,6){
                                                    loop(c4,6){
                                                        loop(c5,6){
                                                            loop(c6,6){
                                                                if(p1+p2+p3+p4+p5+p6+p7+p8+p9 > c1+c2+c3+c4+c5+c6){
                                                                    peter_wins++;
                                                                };
                                                                overall_iterator++;
                                                                
                                                                
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }
    double result = (double)peter_wins/overall_iterator;
    cout << result << endl;
    printf("%4.7f",result);
}




