#include "stdafx.h";
#include<iostream>
#include<vector>
#include<set>
#include <conio.h>
#include <map>
using namespace std;

int NumOfRepeat(vector<int>& input) {

	vector<int> rep_num;
	for (int i = 0; i < input.size(); i++) {
		int pos = abs(input[i]);
		if (input[pos - 1] < 0) 
			rep_num.push_back(abs(input[i]));
		else
			input[pos - 1] = -1 * input[pos - 1];
	}


	return rep_num.size();

}

int main() {

	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(7);
	a.push_back(7);
	a.push_back(11);
	a.push_back(11);


	std::cout << endl <<"Num 0f repeated nums =  " << NumOfRepeat(a) << endl;
	_getch();
	return 0;
}