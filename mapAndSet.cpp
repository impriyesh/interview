
#include "stdafx.h"
#include <iostream>
#include <map>
#include "conio.h"

using namespace std;
int main()
{
	std::map<char, int> mymap;

	// first insert function version (single parameter):
	mymap.insert(std::pair<char, int>('a', 100));
	mymap.insert(std::pair<char, int>('z', 200));

	std::pair<std::map<char, int>::iterator, bool> ret;
	
	ret = mymap.insert(std::pair<char, int>('z', 500)); 
	
	// ret is declared to store pair,
	// pair of type map iterator and boolean
	// Ask Amit what happens to the second boolean parameter of the map.by default 
	// false is set
	cout << "ret printing \t \n " << "ret.first->first  " << ret.first->first;
	cout << "ret.first->second ";
	cout << ret.first->second << "ret.second " << ret.second;
	if (ret.second == false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char, int>::iterator it = mymap.begin();
	mymap.insert(it, std::pair<char, int>('b', 300));  // max efficiency inserting
	mymap.insert(it, std::pair<char, int>('c', 400));  // no max efficiency inserting
	mymap.insert(it, std::pair<char, int>('d', 400));

	 // third insert function version (range insertion):
	//std::map<char, int> anothermap;
	//anothermap.insert(mymap.begin(), mymap.find('d'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	//std::cout << "anothermap contains:\n";
	//for (it = anothermap.begin(); it != anothermap.end(); ++it)
		//std::cout << it->first << " => " << it->second << '\n';

	_getch();
	return 0;
}