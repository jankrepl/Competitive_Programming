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



using namespace std;
//problem 357







int main(){
    //Let me create a prime checking vector..so that we save time..which is very useful:D...the highest needed prime is 100 000 000 /1 + 1 = 100 000 001 ...I create one more
    //just in case:D:D:D
    vector<bool> prime_check(100000002,false);
    for(long i = 0; i <= 100000001; i++){
        bool temp = is_prime(i); //by the way u needed to improve the prime algorithm here..becasue before it was too costly..going to sqrt(x) with divisors is enough..see below
        if(temp){
            prime_check[i] = true;
        }
        if(i%1000000 == 0){
            cout << i << endl;
        }
    }

    // And the following is the actual computation...small hacks..but yeh...
    long total_sum = 3; // 1,2 is included
    for(long i = 4; i <= 100000000; i += 2){//lets say i is odd => i/1 + 1 will be even..and therefore cant be prime..so why not to exclude it right away..right?
                /*JUST A COUNTER*/
        if(i % 100000 == 0){
            cout << 1.0*i/1000000 << "% is done"<<endl;
        }
        ////////////////////////////////////////////////

        bool passed_property = true;
        //We want to use the fact that all divisors come in pairs..a|b => b/a|b..however our condition is exactly the same
        //for both numbers in the given pair..so we can only check the lower one
        long divisor = 1; //1 is already accounted for loop i+=2..the lower pairs are always below square root


        while(divisor <= sqrt(i)){
            if(i % divisor == 0){
                if(!prime_check[divisor + i/divisor]){
                    passed_property = false;
                    break;
                }

            }

            divisor++;
        }
        //decide whether to add this number to the overall su
        if(passed_property){
            total_sum += i;
//            cout << "+" << i << "=" << total_sum << endl;
        }

    }
    cout <<"FINAL " << total_sum;
}







