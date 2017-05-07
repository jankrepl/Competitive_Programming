// Name: Marks_and_Toys
// WWWW: https://www.hackerrank.com/challenges/mark-and-toys
// Author: Jan Krepl



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

/* Strategy very clear */

int main() 
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }
    
    int answer = 0;
    
    sort(prices.begin(), prices.end());
    vector<int> cum_prices(n);
    partial_sum(prices.begin(), prices.end(), cum_prices.begin());
    
    answer = distance(cum_prices.begin() ,find_if(cum_prices.begin(), cum_prices.end(), [&k](int i){return i > k;}));
    
    cout << answer << endl;
    
    return 0;
}
