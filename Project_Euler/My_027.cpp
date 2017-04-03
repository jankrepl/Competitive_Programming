#include <iostream>
#include "Toolkit_functions.h"
#include <vector>
using namespace std;


class coefficient_object{
    //Constructor
public:
    coefficient_object(int a, int b) : a(a), b(b) {
        longest_streak = find_longest_streak(a,b);
    }
    //Members
public:
    int a;
    int b;
    int longest_streak;
    //Methods
private:
    int find_longest_streak(int a, int b){
        int streak = 0;
        for (int i = 0; true; i++){
            if (!is_prime(i*i + a*i + b)){
                break;
            }
            streak++;
        }
        return streak;
    }


};




int main() {
    int a = -999; //iterators
    int b = -1000; //iterators
    int streak_winning = 0;
    int solution;
    while(a < 1000){
        b = -1000;
        while(b <= 1000){
            coefficient_object tester(a,b);
            if(streak_winning < tester.longest_streak){
                streak_winning = tester.longest_streak;
                solution = a*b;
            }
            b++;
        }
        a++;
    }
    cout << streak_winning << solution;
}

