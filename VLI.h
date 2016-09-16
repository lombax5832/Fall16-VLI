#pragma once

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
	void getAbsValue(const VLI);
	int getVLILength() const;
	void setSign(int);

	// Arithmetic
	bool addVLI(const VLI, const VLI);
	bool subVLI(VLI, VLI);

	// Predicate
	bool isEQ(VLI) const;
	bool isGT(VLI) const;
	bool isLT(VLI) const;

	// Misc
	void clearVLI();
	void toCstring(char[]) const;
	void print() const;
	void setVLIFromString(const char[]);
	void copyVLI(const VLI);
private:
	// Data Storage
	bool isNegative;
	char num[VLI_SIZE];
};