// Name: Closing_the_Tweets
// Problem_Code: TWTCLOSE
// WWW: https://www.codechef.com/problems/TWTCLOSE
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility> 
#include <map>


using namespace std;

void print_tweet(vector<int> tweet){
    for(int i = 1; i < tweet.size(); i++){
        cout << tweet[i] << " ";
    }
    cout << endl;
}


int main(){
    int N, K;
    cin >> N >> K;

    //create tweet database ... ith element == 1 means that ith tweet is open

    vector<int> tweets(N + 1, 0); // 0th element not used

    // get the first line and throw it away .. otherwise it wont work
    string s;
    getline(cin,s);

    while(K--){
        getline (cin,s); //reads entire line ... including spaces 

        //check if s contains a space
        size_t index = s.find(" ");
        if(index == string::npos){
            fill(tweets.begin(), tweets.end(),0);
        }else{
            int tweet_id = stoi(s.substr(index + 1)); // should even work without the substring
            if(tweets[tweet_id] == 0){
                tweets[tweet_id]++;
            }else{
                tweets[tweet_id] = 0;
            }
        }
        //print_tweet(tweets);
        cout << accumulate(tweets.begin(), tweets.end(), 0) << endl;
    }
}

    