#include "stdafx.h"
#include <iostream>
//#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#include <string>
#include "MyStringClass.h"


char * ReverseUtil(char *String,char *reverse ,int *len,int *revIndex) {
	if (*len < 0) {
		reverse[*revIndex] = '\0';
		return reverse;

	}

	reverse[*revIndex] = String[*len];
	*revIndex = *revIndex + 1;
	*len = *len - 1;
	return (ReverseUtil(String, reverse,len,revIndex));
}

char * Reverse(char *orig) {

	if (orig == NULL) {
		return NULL;
	}
	int i =0;
	int len = strlen(orig);
	int arrayLen = len - 1;
	char *reverse = new char[len+1];
	memset(reverse, 0, len + 1);
	return(ReverseUtil(orig,reverse,&arrayLen,&i));
	
	
}

void PrintReverse(char *orig, int len) {
	if (len >= 0) {
		cout << orig[len];
		PrintReverse(orig,len-1);
		
	}
}

int main(){

	char * orig = "Hello World No Problem " ;
//	char *rev = Reverse(orig);
	PrintReverse(orig,strlen(orig) -1);
	getchar();
 	return 0;

}