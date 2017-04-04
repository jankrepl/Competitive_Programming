// Name: Lisas_Workbook
// WWWW: https://www.hackerrank.com/challenges/lisa-workbook
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    int n,k;
    cin >> n >> k;
    vector<int> count_per_chapter(n+1,0);
    for(int i = 1; i <= n; i++){
        cin >> count_per_chapter[i];
    }
    long all_problems = accumulate(count_per_chapter.begin(),count_per_chapter.end(),0);
    vector<int> cumulative(n+1,0);
    for(int i = 1;  i < n+1; i++){
        cumulative[i] = cumulative[i - 1] + count_per_chapter[i];
    }

    int page_counter = 1;
    int problem_counter = 1; //within a chapter

    int result = 0;
    int n_topics = cumulative[1];
    int index_in_cum = 1;
    for(int i = 1; i <= all_problems; i++){
        if(page_counter == problem_counter){
            result++;
        }
        if(i == n_topics){
            index_in_cum++;
            n_topics = cumulative[index_in_cum];
            problem_counter = 0;
            page_counter++;
        }else if(i != n_topics && problem_counter%k == 0 ){
            page_counter++;
        }else{

        }

        problem_counter++;


    }



    cout << result;
    return 0;
}
