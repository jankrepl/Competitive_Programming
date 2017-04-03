#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

//Problem 58
//Takes like two hours...because you are creating the spiraling matrixes..even though having the corners of them is enough:S

using namespace std;



vector<vector<int>> add_layer(vector<vector<int>> before){
    vector<vector<int>> output = before;

    int side_size_old = before[1].size();
    int side_size_new = side_size_old + 2;
    int layer_size = side_size_new*side_size_new - side_size_old*side_size_old;

    vector<int> layer;
    for(int i = side_size_old*side_size_old + 1; i <= side_size_new*side_size_new; i++){
        layer.push_back(i);
    }

    vector<int>::iterator it = layer.begin();
    //east
    vector<int> east(side_size_old);
    for(int iterator = 0; iterator < side_size_old; iterator++){
        east[iterator] = *it;
        it++;
    }
    reverse(east.begin(),east.end());
    //north
    vector<int> north(side_size_new);
    for(int iterator = 0; iterator < side_size_new; iterator++){
        north[iterator] = *it;
        it++;
    }
    reverse(north.begin(),north.end());

    //west
    vector<int> west(side_size_old);
    for(int iterator = 0; iterator < side_size_old; iterator++){
        west[iterator] = *it;
        it++;
    }

    //south
    vector<int> south(side_size_new);
    for(int iterator = 0; iterator < side_size_new; iterator++){
        south[iterator] = *it;
        it++;
    }

    // Add front and back columns

    vector<vector<int>>::iterator matrix_iterator_1 = output.begin();
    output.insert(matrix_iterator_1,west);
    output.push_back(east);

    int column = 0;


    for(vector<vector<int>>::iterator matrix_iterator_2 = output.begin(); matrix_iterator_2 < output.end(); matrix_iterator_2++){

        (*matrix_iterator_2).insert((*matrix_iterator_2).begin(),north[column]);
        (*matrix_iterator_2).push_back(south[column]);
        column++;
    }

    return output;

}

void print_matrix(vector<vector<int>> matrix){
    // Matrix is a vector of columns!!so the first coordinate is the column coordinate
    int columns = matrix.size();
    int rows = matrix[0].size();
    cout << setw(4);
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            cout << (matrix[column])[row] << setw(4);
        }
        cout << endl;

    }
    cout << endl;
}

vector<int> extract_diagonals(vector<vector<int>> matrix){
    vector<int> extract;

    for(int i = 0 ; i < matrix.size(); i++){
        extract.push_back(matrix[i][i]);
        extract.push_back(matrix[i][matrix.size() - i - 1]);
        if(i == matrix.size() - i - 1){
            extract.pop_back();
        }

    }
    return extract;
}

double prime_ratio(vector<int> x){
    int prime_counter = 0;
    for(vector<int>::iterator it = x.begin(); it < x.end(); it++){
        if(is_prime(*it)){
            prime_counter++;
        }
    }
    return (prime_counter*1.0)/x.size();
}

int main() {
    vector<vector<int>> a;
    a = { {5,6,7},
          {4,1,8},
          {3,2,9}

    };

    bool not_reached = true;
    while(not_reached){
        a = add_layer(a);
        vector<int> diagonals = extract_diagonals(a);
        cout << prime_ratio(diagonals) << endl;
        if(prime_ratio(diagonals) < 0.1){
            not_reached = false;
        }

    }
    cout << a.size();
//    vector<vector<int>> enhanced = add_layer(a);
//    print_matrix(enhanced);
//    for(int i = 1; i < 10; i++){
//        enhanced = add_layer(enhanced);
//        print_matrix(enhanced);
//        vector<int> extract = extract_diagonals(enhanced);
//        print_vector(extract);
//    }
}

