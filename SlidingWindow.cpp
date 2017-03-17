
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "conio.h"

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {



}


int main()
{
	vector<int> nums, ans;
	int k = 3;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(-3);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(7);
	
	ans = maxSlidingWindow(nums,k);
	cout << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\t";
	_getch();
	return 0;
}