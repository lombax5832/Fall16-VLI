#pragma once
/**
*	Authors:		Alexei Snytkine
*					Alexandros Psitos
*	Description:	Class that manages integer numbers up to 100 digits in size
*	Date Created:	9/10/16
*	Date Modified:	9/16/16
*/

// Constants
const int VLI_SIZE = 100;

class VLI {
public:
	// Constructors

/*
	Description:	Default constructor for VLI
	Pre:
	Post:			Initializes a new VLI with value of 0
*/
	VLI();

/*
	Description:	Convert from int constructor for VLI
	Pre:			Valid, initialized integer as input
	Post:			Initializes a new VLI with value of input
*/
	VLI(int input);

/*
	Description:	Convert from cstring constructor for VLI
	Pre:			String of ascii characters of numbers ('0'-'9')
					with optional leading negative sign ('-')
	Post:			Initializes a new VLI with value of input
*/
	VLI(const char input[]);

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