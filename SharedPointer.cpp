/*
* C++ Program to Implement Heap Sort
*/


#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include<vector>


using namespace std;

class RC {

private:
	int mCount;
public:
	RC() :mCount(0) {};
	void addRef() { ++mCount; }
	void deleteRef() { --mCount; }
	int getrefCount() { return mCount; }

};

template <typename T> class SmartPointer {

private:

	T * mPdata;
	RC *mReference;

public:

	SmartPointer():mPdata(NULL),mReference(NULL) {	
		/*mReference = new RC();
		mReference->addRef();*/
	}
	~SmartPointer() {
		if (mReference) {
			mReference->deleteRef();
			if (mReference->getrefCount() == 0) {
				//mPdata = NULL;
				delete mPdata;
				delete mReference;
			}
		}
	}

	SmartPointer(T* obj) {
		mPdata = obj;
		mReference = new RC();
		mReference->addRef();
	}

	SmartPointer(const SmartPointer<T> &sp) :mPdata(sp.mPdata),mReference(sp.mReference) {

		//copy constructor
		//copies the data and reference pointer
		//and increment the reference count
		mReference->addRef();
	}
	
	T& operator *() {
		return *mPdata;
	}

	T* operator ->() {
		return mPdata;
	}

	SmartPointer<T> operator =(const SmartPointer<T> &sp) {
		
		mPdata = sp.mPdata;
		mReference = sp.mReference; 
		
		mReference->addRef();
		return *this;
	}
};

class person {

private:
	int mAge;
	char *mName;
public:
	person(char *name, int age) :mName(name),mAge(age) {
		}


	void SetName(char *name) { mName = name; }

void display() { 
	cout << mName << "\t" << mAge << "\t" << endl; 
}

void shout() {
	cout << "\n\n\n\ Oooooooooooooooooo \n\n\n";
}
};


void copyConsDemo(SmartPointer<person> sp) {
	sp->display();
}
int main() {

	SmartPointer<person> p((new person("nam", 35)));
	//p->display();
	//copyConsDemo(p); // Calls Copy Constructor, as its a function call. Parameter is copied using 
	// copy the constructor
	p->shout();
	SmartPointer<person> q(p);
	q->SetName("Amit");
	q->display();
	return 0;
}