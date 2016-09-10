#pragma once
using namespace std;
#include<iostream>

const int VLI_SIZE = 100;

class VLI {
public:
	// Constructors
	VLI();
	VLI(int);
	VLI(const char[]);

	// Getters and Setters
	int getSign();
	VLI getAbsValue();
	void setSign();

	// Arithmetic
	VLI addVLI(VLI, VLI);
	VLI subVLI(VLI, VLI);

	// Predicate
	bool isEQ(VLI, VLI);
	bool isGT(VLI, VLI);
	bool isLT(VLI, VLI);

	// Misc
	void toCstring(char[]);
	void print();
private:
	// Data Storage
	char sign;
	char num[VLI_SIZE];
};