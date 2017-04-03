#ifndef PROJECT_EULER_TOOLKIT_TOOLKIT_FUNCTIONS_H
#define PROJECT_EULER_TOOLKIT_TOOLKIT_FUNCTIONS_H

//Headers
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <math.h>
#include <string>
#include <vector>
#include <set>
#include <map>

//Namespaces
using namespace std;

//FOO - Declarations
long factorial(long x);



bool is_prime(long x);

vector<int> number_to_vector_of_digits(long x);

template <class T>
vector<T> prime_factorization(T x);

//FOO - Definitions
int alphabetical_value(string s){
    //DESCRIPTION: Outputs the sum of all character order in the alphabet
    //INPUTS: A,B,.....,Z
    //EXAMPLE: alphabetical_value("COLIN") = 53
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += s[i] - 'A' + 1;
    }
    return sum;
}

vector<int> binary_conversion(int x){
    //read from left to right
    vector<int> temp;
    while(x > 0){
            temp.push_back(x % 2);
            x /=2;
    }
    return temp;
}

long combination_number(int n, int k ){
    vector<int> numerator;
    vector<int> denominator;

    int difference = n - k;

    while(n > 1){
        vector<int> temp = prime_factorization<int>(n);
        numerator.insert(numerator.end(),temp.begin(),temp.end());
        --n;
    }

    while(k > 1){
        vector<int> temp = prime_factorization<int>(k);
        denominator.insert(denominator.end(),temp.begin(),temp.end());
        --k;
    }

    while(difference > 1){
        vector<int> temp = prime_factorization<int>(difference);
        denominator.insert(denominator.end(),temp.begin(),temp.end());
        --difference;
    }
//

    // For the set_symmetric_difference algorithm to work,
    // the source ranges must be ordered!
    vector<int> sortedV1(numerator);
    vector<int> sortedV2(denominator);

    sort(sortedV1.begin(),sortedV1.end());
    sort(sortedV2.begin(),sortedV2.end());

    // Now that we have sorted ranges (i.e., containers), find the differences
    vector<int> vDifferences_numerator;
    vector<int> vDifferences_denominator;

    set_difference(
            sortedV1.begin(),
            sortedV1.end(),
            sortedV2.begin(),
            sortedV2.end(),
            back_inserter(vDifferences_numerator));

    set_difference(
            sortedV2.begin(),
            sortedV2.end(),
            sortedV1.begin(),
            sortedV1.end(),
            back_inserter(vDifferences_denominator));



    // ... do something with the differences

    if(vDifferences_denominator.empty()){
        vDifferences_denominator.push_back(1);
    }

    if(vDifferences_numerator.empty()){
        vDifferences_denominator.push_back(1);
    }
    long final_numerator = 1;
    long final_denominator = 1;

    for (vector<int>::iterator it = vDifferences_numerator.begin(); it < vDifferences_numerator.end(); it++ ){
        final_numerator *= *it;
    }

    for (vector<int>::iterator it = vDifferences_denominator.begin(); it < vDifferences_denominator.end(); it++ ){
        final_denominator *= *it;
    }

    return final_numerator/final_denominator;


}

long combination_number_stupid(int up, int down){
    long numerator = 1;
    if (down >= up - down) {
        for (int i = up; i > down; i--) {
            numerator *= i;

        }
        return numerator/factorial(up - down);
    }else{
        for (int i = up; i > up - down; i--) {
            numerator *= i;

        }
        return numerator/factorial(down);
    }
    ;
}


long factorial(long x){
    if(x == 1 || x == 0){
        return 1;
    }else{

        return x*factorial(x-1);
    }

}



bool is_alphabetically_above(string s_1, string s_2){
    //DESCRIPTION: Outputs true if first string is first in the dictionary
    int iterations = min(s_1.size(),s_2.size());

    for(int i = 0; i < iterations; i++){
        if(s_1[i] < s_2[i]){
            return true;
        }else if (s_1[i] == s_2[i]){
            continue;
        }else{
            return false;
        }
    }
    return (s_1.size() < s_2.size())?true:false;
}



bool is_heptagonal(long x){
    double a = 5/2.0;
    double b = - 3.0/2;
    double c = -x*1.0;


    double determinant = b*b - 4*a*c;
    double solution = (-b + sqrt(determinant))/(2*a);

    return floor(solution) == solution;
}

bool is_hexagonal(long x){
    double a = 2.0;
    double b = - 1.0;
    double c = -x*1.0;


    double determinant = b*b - 4*a*c;
    double solution = (-b + sqrt(determinant))/(2*a);

    return floor(solution) == solution;
}

bool is_octagonal(long x){
    double a = 3.0;
    double b = - 2.0;
    double c = -x*1.0;


    double determinant = b*b - 4*a*c;
    double solution = (-b + sqrt(determinant))/(2*a);

    return floor(solution) == solution;
}


bool is_pandigital(long x) {
    vector<int> digits = number_to_vector_of_digits(x);
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

bool is_pandigital_with_zero(long x) {
    vector<int> digits = number_to_vector_of_digits(x);
    if (digits.size() > 10){
        return false;
    }
    for(int i = 0; i < digits.size(); i++){
        if(find(digits.begin(), digits.end(), i ) == digits.end()){
            return false;
        }
    }
    return true;

}

bool is_pentagonal(long x){
    double a = 3.0/2;
    double b = - 1.0/2;
    double c = -x*1.0;


    double determinant = b*b - 4*a*c;
    double solution = (-b + sqrt(determinant))/(2*a);

    return floor(solution) == solution;
}

bool is_permutation(vector<int> x, vector<int> y){
    if(x.size() != y.size()){
        return false;
    }
    // The algorithm here is to use elements of x to find in y and if found..delete in both vectors
    while(!x.empty()){
        vector<int>::iterator index_y = find(y.begin(),y.end(),x.back());
        if( index_y!= y.end()){
            x.pop_back();
            y.erase(index_y);
        }else{
            return false;
        }
    }
    return true;

}
int totient(int n){
    int counter = 0;

    for(int i = 1; i < n ; i++){
        if(__gcd(n,i) == 1){
            counter ++;
        }
    }
    return counter;
}


bool is_square(long x){
    double a = 1.0;
    double b = 0.0;
    double c = -x;

    double discriminant = b*b - 4*a*c;

    double solution = (-b + sqrt(discriminant))/(2*a);
    double rhs = floor(solution) + 0.0;
    return solution == rhs;

}

bool is_triangular(long x){
    double a = 1.0/2;
    double b = 1.0/2;
    double c = -x;

    double discriminant = b*b - 4*a*c;

    double solution = (-b + sqrt(discriminant))/(2*a);
    double rhs = floor(solution) + 0.0;
    return solution == rhs;

}


vector<long> list_all_primes(long x){
    //very stupid algorithm
    vector<long> temp;
    for(long i = 2; i <= x; i++){
        if(is_prime(i)){
            temp.push_back(i);
        }
    }
    return temp;

}

vector<int> long_division_one_in_numerator(int den){
    int num = 1;
    vector<int> final = {};
    vector<int> num_storage = {};

    // Now it is necessary to determine the starting position.
    bool goon = 1;

    while(goon){
        final.push_back(num/den);
        num = (num - final.back()*den)*10;
        //
        goon = find(num_storage.begin(),num_storage.end(),num)==num_storage.end();
        num_storage.push_back(num);

        //
    }
    //final.pop_back();
    return final;
}

int number_of_digits(long x){
    int counter = 1;
    while(x >= 10){
        x /= 10;
        counter++;

    }
    return counter;
}

vector<int> number_to_vector_of_digits(long x) {
    vector<int> temp;

    if(x == 0){
        temp = {0};
        return temp;
    }

    while(x >= 1){
        temp.push_back(x % 10);
        x /= 10;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

bool is_prime(long x) {
    if((x % 2 == 0) && (x > 2)){
        return false;
    }

    long divisor = 2;
    while(divisor*divisor <= x){ //divisors always come in pairs ..if a|x => x/a|x ...you just check until the square root;
        if(x%divisor == 0 ){
            return false;
        }
        divisor++;
    }
    return !(x == 0 || x == 1);

}

void print_ascii_map(){
    for(unsigned short i = 1; i <= 256; i++){
        cout << i << " is: " << (char)i << endl;
    }
}

void print_limits(){
    //DESCRIPTION: Prints maximal and minimal values of the most important types
    cout << "type\tlowest\thighest\n";

    // char
    cout << "char\t"
         << numeric_limits<char>::lowest() << '\t'
         << numeric_limits<char>::max() << '\n';


    // short int
    cout << "short\t"
         << numeric_limits<short>::lowest() << '\t'
         << numeric_limits<short>::max() << '\n';

    // unsigned short int
    cout << "unsigned short\t"
         << numeric_limits<unsigned short>::lowest() << '\t'
         << numeric_limits<unsigned short>::max() << '\n';


    // int
    cout << "int\t"
              << numeric_limits<int>::lowest() << '\t'
              << numeric_limits<int>::max() << '\n';

    // unsigned integer
    cout << "unsigned int\t"
         << numeric_limits<unsigned int>::lowest() << '\t'
         << numeric_limits<unsigned int>::max() << '\n';


    // long
    cout << "long\t"
         << numeric_limits<long>::lowest() << '\t'
         << numeric_limits<long>::max() << '\n';


    // long long
    cout << "long long\t"
         << numeric_limits<long long>::lowest() << '\t'
         << numeric_limits<long long>::max() << '\n';

    // unsigned long long
    cout << "unsigned long long\t"
         << numeric_limits<unsigned long long>::lowest() << '\t'
         << numeric_limits<unsigned long long>::max() << '\n';
}

template <class T>
void print_vector(vector<T> x){
    //EXAMPLE:print_vector<int>(x) or print_vector<long>(x) <<-- depends on the input vector;
    for(int i = 0 ; i < x.size(); i++ ){
        cout << x[i] <<" ";

    }
}

template <class T>
vector<T> prime_factorization(T x){
    if(x < 0){
        x = - x;
    };
    vector<T> temp = {};
    long divisor = 2;

    while(x > 1){
        if(x % divisor == 0){
            x /= divisor;
            temp.push_back(divisor);
        }else{
            divisor++;
        }
    }


    return temp;

}


set<vector<int>> permutations(vector<int> input, bool printflag){
    //Input: vector of integers
    //Output: set of all permutations of this vector (without repetition and order matters)
    set<vector<int>> output;
    do{
        output.insert(input);
        if(printflag) {
            print_vector<int>(input);
            cout << endl;
        }
    }while(next_permutation(input.begin(),input.end()));
return output;

}
string read_txt_file(string path){
    //DESCRIPTION: Creates one string out of all lines of a txt file
    //EXAMPLE: read_txt_file("/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_22.txt")
    string concat, temp;
    ifstream my_input_file (path);

    while(getline(my_input_file, temp)){
        concat += temp;
    }

    return concat;
}

long sum_all_divisors(long x){
    //DESCRIPTION: Sum of all divisors of x smaller than x (including 1)
    int divisor = 1;
    long sum = 0;
    while(divisor < x/2 + 1){
        if(x%divisor == 0){
            sum += divisor;
        }
        ++divisor;
    }
    return sum;

}

long vector_of_digits_to_number(vector<int> x){
    int exponent = 0;
    int i = x.size() - 1;
    long temp  = 0;
    while(i>=0){
        temp += x[i]*pow(10,exponent);
        exponent++;

        i--;
    }
    return temp;
}

#endif //PROJECT_EULER_TOOLKIT_TOOLKIT_FUNCTIONS_H
