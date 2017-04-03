// Find the difference between the sum of squares of the first 100
// natural numbers and the square of the sum

#include<iostream>
using namespace std;

int main() {

	unsigned int squaresum = 0;
	unsigned int sumsquare = 0;

	for(unsigned int i = 1; i < 101; ++i) {

		sumsquare += i*i;
		squaresum += i;

		}

	cout << squaresum*squaresum - sumsquare << endl;

	return 0;

	}