#pragma once
using namespace std;
#include<iostream>

// Constants
const int VLI_SIZE = 100;
//const char ASCII_0 = '0';
//const char ASCII_9 = '9';

class VLI {
public:
	// Constructors
	VLI();
	VLI(int);
	VLI(const char[]);

	// Getters and Setters
	int getSign() const;
	VLI getAbsValue() const;
	int getVLILength() const;
	void setSign(int);

	// Arithmetic
	bool addVLI(VLI, VLI);
	bool subVLI(VLI, VLI);

	// Predicate
	bool isEQ(VLI, VLI);
	bool isGT(VLI, VLI);
	bool isLT(VLI, VLI);

	// Misc
	void clearVLI();
	void toCstring(char[]);
	void print();
	void setVLIFromString(const char[]);
private:
	// Data Storage
	bool isNegative;
	char num[VLI_SIZE];
};