
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"
#include <math.h>
#include <set>
#include <vector>
#include "Toolkit_classes.h"
using namespace std;

class jarmilka{
public:
    jarmilka(int a, int b){
        generate(a,b);
    }

    void show(){
        print_vector<int>(powers);
        cout << endl;
        print_vector<int>(bases);
        cout << endl;
    }
private:
    vector<int> bases;
    vector<int> powers;



    void generate (int a, int b) {
        vector<int> temp = prime_factorization<int>(a);

        if(temp.size() > 1) {

            vector<int> bases_generated;
            vector<int> powers_generated;

            //Define all neccesary iterators over my 3 vectors

            int current_position = 0;
            int pow_iterator = 0;
            int base_iterator = 0;

            while (current_position != temp.size()) {

                bases_generated.push_back(temp[current_position]);

                powers_generated.push_back(1);

                while (temp[current_position] == temp[current_position + 1]) {
                    powers_generated[pow_iterator]++;
                    current_position++;
                    if(current_position == temp.size()){
                        break;
                    }
                }

                if(current_position == temp.size()){
                    if(temp.back() == bases_generated.back()){
                        break;
                    }else{
                        bases_generated.push_back((int &&)temp.back());
                        powers_generated.push_back(1);
                        break;
                    }
                }else{
                    current_position++;
                }

                base_iterator++;
                pow_iterator++;


            }

            // Multiply b* all elements of powers
            for(vector<int>::iterator it = powers_generated.begin(); it < powers_generated.end(); it++) {
                *it *= b;
            }

                bases = bases_generated;
                powers = powers_generated;

        }else{
            vector<int> bases_generated(1,a);
            vector<int> powers_generated(1,b);

            bases = bases_generated;
            powers = powers_generated;

        }
    }


    friend bool operator==(jarmilka m, jarmilka n);
};

bool operator==(jarmilka m, jarmilka n) {
    return m.bases == n.bases && m.powers == n.powers;


}


int main() {

    vector<jarmilka> database;
    cout<< "MAx size is: "<<database.max_size();
    int counter = 0;
    for (int a = 2; a <= 100; a++){
        for(int b = 2; b <= 100; b++){
            jarmilka tester(a,b);

            if(find(database.begin(),database.end(),tester)==database.end()){
                database.push_back(tester);
                counter ++;
            }
        }
    }
    cout << database.size() << " Counter: " << counter;

}
