/*
 * ProjectF
 * matrixMul.cpp
 * CS4080 - Raheja - Group Final Project
 * Jake Wagner, Chris Rauch, Scott Ha
 * 
 * This file contains the C++ implementaion of the classic matrix 
 * mulitplication algorithm. It will be called from the main fortran
 * driver computeCheck.f90, which monitors its execuion speed, but is
 * entirely stand alone functional.
 * 
 * IMPORTANT NOTE: for ease of use with the fortran driver no arguments
 * 		are passed and matrix values are hard-coded. Please ensure that
 * 		the values match those for the corresponding function in the
 * 		main fortran driver, computeCheck.f90 before evaluation.
 * 
 */
 //Includes
#include <iostream>
#include <ctime>
using namespace std;

//	MAIN	===========================================================
int main() {
	//RESOURCES **********
	const int row = 800;
	const int col = 800;
	const bool display = false;
	clock_t timer;
	int a[row][col], 
	    b[row][col], 
	    c[row][col];
	
	//ALGORITHM *********
	//initialize Matrices A and B
	for(int i=1; i<=row; ++i) {
	  for(int j=1; j<=col; ++j){
	    a[i-1][j-1] = (i + j) % 100;
	    b[i-1][j-1] = (i + j) % 100;	
	  }
	}
	if(display){
		cout << "\nMatrix A ==========\n";
		for(int i=0; i<row; ++i) {
			cout << "   ";
			for(int j=0; j<col; ++j) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\nMatrix B ==========\n";
		for(int i=0; i<row; ++i) {
			cout << "   ";
			for(int j=0; j<col; ++j) {
				cout << b[i][j] << " ";
			}
			cout << endl;
		}
	
	}
	
	//start the timer
	timer = clock();
	// multiply A and B and save result C
	for(int i = 0; i<row; ++i) {
		for(int j=0; j<col; ++j) {
			c[i][j] = 0; 
            for (int k = 0; k < col; ++k) 
                c[i][j] += a[i][k] * b[k][j];
		}
	}
	//save time
	timer = clock() - timer;
	if(display){
		cout << "\nMatrix C ==========\n\n";
		for(int i=0; i<row; ++i) {
			cout << "   ";
			for(int j=0; j<col; ++j) {
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	//display the resulting time
	cout << " C++: " << (timer / double(CLOCKS_PER_SEC)) << " seconds\n";
	     
	//exit
	return 0;
}
