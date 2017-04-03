// helloworld.cpp
#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
using namespace std;

//void magic(int my_array[15][15], int array_size){
//    for(int i = array_size - 2; i>=1; i--){
//        for(int j = 0; j < array_size; j++){
//            my_array[i][j] = max(my_array[i+1][j],my_array[i+1][j+1]);
//        }
//
//    }
//
//
//}


int main()
{
    // Parameters
    const int array_size = 15;
    string path_txt = "/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_18.txt";

    // Initialization and definitions
    int my_array[array_size][array_size];
    string my_output_string;
    ifstream my_input_file;

    my_input_file.open(path_txt);

    int row = 0;
    while(getline(my_input_file, my_output_string)){
        int upper_limit = my_output_string.size();
        for(int i = 0; i < upper_limit; i+=3 ){
            my_array[row][i/3] = (my_output_string[i]-'0')*10 + (my_output_string[i+1]-'0');
        }
        row++;

    }

    for(int i = array_size - 2; i >= 1; i--){
        for(int j = 0; j < array_size; j++){
            my_array[i][j] += max(my_array[i+1][j],my_array[i+1][j+1]);
        }

    }

    cout<<max(my_array[1][0]+my_array[0][0],my_array[1][1]+my_array[0][0])<<endl;

}
