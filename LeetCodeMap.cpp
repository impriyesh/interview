#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
#include "conio.h"


using namespace std;

vector<int> FindRep(vector<int> input) {

	vector<int> result;
	map<int, bool> num;

	for (int i = 0; i < input.size(); i++) {

		if (num.find(input[i]) != num.end())
			result.push_back(input[i]);
		else
			num.insert(pair<int,bool>(input[i], true));
	}

	return result;
}

int main() {

	vector<int>nums;
	vector<int>ans;
	nums.push_back(-2);
	nums.push_back(-2);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(6);
	nums.push_back(7);

	ans= FindRep(nums);

	cout << "Number of repeated numnbers are = " << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\t";

	cout << endl;
	_getch();
	return 1;
}
