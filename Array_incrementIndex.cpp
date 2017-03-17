#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
#include "conio.h"


using namespace std;



int main() {

	int i;
	int buffer[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	int buffer32[16];

	int Finalbuffer32[2][1][2][2] = { {  {{1,2},{3,4}} } ,{ { { 11,22 },{ 33,44 } } } };
	//{ { {1,2} {2,6} }   { 11,15 } , { 12,16 } };
	
	cout << Finalbuffer32[1][0][1][0];
	getchar();
	return 1;
};

	

	/*int sindex = 0, dstindex = 0;
	int width = 2, height = 2;

	for (int i = 2; i >=0; i--) {
		sindex = i;
		for (int r = 0; r < width; r++) {
			for (int c = 0; c < height; c++) {
				buffer32[dstindex] = buffer[sindex];
				++dstindex;
				sindex += 4;

			}
		}
	}

	for (int fa = 0; fa <= 12; fa++) {
		cout << Finalbuffer32[fa] << "\t";
	}
	cout << endl << endl;
	for (int i1 = 0; i1 <= 12; i1++) {
		cout << buffer32[i1] << "\t";
	}

	*/
	