// Name: Ice_Cream_Parlor
// WWWW: https://www.hackerrank.com/challenges/icecream-parlor
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class IceCream {
    
    public: 
        int cost; 
        int index;

        IceCream(int cost, int index) {
            this->cost = cost;
            this->index = index;
       }
};

bool compare(IceCream a, IceCream b){
    return a.cost < b.cost;
}
    
int binarySearch(int first, int last, vector<IceCream> arr, int search) {
    for(int i = first; i <= last; i++){
        if(arr[i].cost == search){
            return arr[i].index;
        }
    }
    return -1;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].cost;
            //since we sorted the array ..we can only search in the reamining elements of the array
            if(search >= arr[i].cost) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;

                }
            }
        }

    }

}

