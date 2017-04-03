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

//Problem 345


bool my_comparison(pair<pair<int,int>,int> lhs, pair<pair<int,int>,int> rhs){
    return lhs.second < rhs.second;
}


int main() {

    //read in the matrix [15][15]
    vector<vector<int>> my_matrix;
    vector<int> temp;
    for (int i = 0; i <= 14; i++) {
        my_matrix.push_back(temp);
    }

    my_matrix[0] = {7, 53, 183, 439, 863, 497, 383, 563, 79, 973, 287, 63, 343, 169, 583};
    my_matrix[1] = {627, 343, 773, 959, 943, 767, 473, 103, 699, 303, 957, 703, 583, 639, 913};
    my_matrix[2] = {447, 283, 463, 29, 23, 487, 463, 993, 119, 883, 327, 493, 423, 159, 743};
    my_matrix[3] = {217, 623, 3, 399, 853, 407, 103, 983, 89, 463, 290, 516, 212, 462, 350};
    my_matrix[4] = {960, 376, 682, 962, 300, 780, 486, 502, 912, 800, 250, 346, 172, 812, 350};
    my_matrix[5] = {870, 456, 192, 162, 593, 473, 915, 45, 989, 873, 823, 965, 425, 329, 803};
    my_matrix[6] = {973, 965, 905, 919, 133, 673, 665, 235, 509, 613, 673, 815, 165, 992, 326};
    my_matrix[7] = {322, 148, 972, 962, 286, 255, 941, 541, 265, 323, 925, 281, 601, 95, 973};
    my_matrix[8] = {445, 721, 11, 525, 473, 65, 511, 164, 138, 672, 18, 428, 154, 448, 848};
    my_matrix[9] = {414, 456, 310, 312, 798, 104, 566, 520, 302, 248, 694, 976, 430, 392, 198};
    my_matrix[10] = {184, 829, 373, 181, 631, 101, 969, 613, 840, 740, 778, 458, 284, 760, 390};
    my_matrix[11] = {821, 461, 843, 513, 17, 901, 711, 993, 293, 157, 274, 94, 192, 156, 574};
    my_matrix[12] = {34, 124, 4, 878, 450, 476, 712, 914, 838, 669, 875, 299, 823, 329, 699};
    my_matrix[13] = {815, 559, 813, 459, 522, 788, 168, 586, 966, 232, 308, 833, 251, 631, 107};
    my_matrix[14] = {813, 883, 451, 509, 615, 77, 281, 613, 459, 205, 380, 274, 302, 35, 805};


    vector<pair<pair<int,int>,int>> flattened;

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++ ){
            flattened.push_back(make_pair(make_pair(i,j),my_matrix[i][j]));
        }
    }

    sort(flattened.begin(),flattened.end(),my_comparison);

    set<int> used_rows;
    set<int> used_columns;

    int counter = 0;
    int found_number = 0;
    int trials = 0;

    vector<int> winners;
    for( vector<pair<pair<int,int>,int>>::iterator it = flattened.end() - 1; it >=flattened.begin(); it--){
        bool rows_check = used_rows.insert(it->first.first).second;
        bool columns_check = used_columns.insert(it->first.second).second;

        if(rows_check && columns_check){
            counter += it->second;
            found_number++;
            winners.push_back(it->second);
        }else if(!rows_check && columns_check){
            //need to delete
            used_columns.erase(it->first.second);
        }else if(rows_check && !columns_check){
            used_rows.erase(it->first.first);

        }else{

        }

        if(found_number == 15){
            break;
        }
        trials++;
    }
    cout << counter << " DONE IN trials: " << trials << endl;
    print_vector<int>(winners);
}
