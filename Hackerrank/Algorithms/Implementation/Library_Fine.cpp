// Name: Library_Fine
// WWWW: https://www.hackerrank.com/challenges/library-fine
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d1; 
    int m1; 
    int y1; 
    scanf("%d %d %d",&d1,&m1,&y1);
    int d2; 
    int m2; 
    int y2; 
    scanf("%d %d %d",&d2,&m2,&y2);
    if(y1 > y2){
        cout << 10000;
    }else if(y1 == y2){
        if(m1 > m2){
            cout << (m1 - m2)*500;
            
        }else if(m1 == m2){
            if(d1 > d2){
                cout << (d1 - d2)*15;
            }else{
                            cout << 0;
            }
            
        }else{
                        cout << 0;

            
        }
    }else{
        cout << 0;
        
    }
    return 0;
}

