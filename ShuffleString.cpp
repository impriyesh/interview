#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include "conio.h"

using namespace std;

void continueShuffle(vector<char> &shuffeRes,unordered_map<char, int> &charsCountMap,size_t total) {

	if (total == shuffeRes.size()) {
		cout << "found one solution: ";
		for (char ch : shuffeRes) {
			cout << ch;
		}
		cout << std::endl;
		return;
	}
	char neiborChar = '\0';
	if (shuffeRes.size() > 0) {
		neiborChar = shuffeRes.back();
	}

	unordered_map<char, int>::iterator it = charsCountMap.begin();
	while (it != charsCountMap.end()) {
		if (it->first != neiborChar && it->second != 0) {
			it->second--;
		shuffeRes.push_back(it->first);
		continueShuffle(shuffeRes, charsCountMap, total);		
		}
 			++it;
	}
}


void shuffleChar(std::string chars) {
	unordered_map<char, int> charsCount;
	vector<char> shuffeRes;

	for (char ch : chars) {
		charsCount[ch]++;
	}

	continueShuffle(shuffeRes, charsCount, chars.size());
}


int main()
{
	string input("AAB");
	shuffleChar(input);
	_getch();
	return 0;
}