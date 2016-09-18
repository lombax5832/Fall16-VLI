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
		Parameters:		
						input: int to convert to new VLI
	*/
	VLI(int input);

	/*
		Description:	Convert from cstring constructor for VLI
		Pre:			String of ascii characters of numbers ('0'-'9')
						with optional leading negative sign ('-')
		Post:			Initializes a new VLI with converted value of inputted cstring
		Parameters:		
						input: cstring to convert to new VLI
	*/
	VLI(const char input[]);

// Getters and Setters

	/*
		Description:	Returns the sign of VLI object
		Pre:			Called as member of VLI object
		Post:			Returns sign of VLI object
		Returns:		( 1 ) if positive and ( -1 ) if negative
	*/
	int getSign() const;

	/*
		Description:	Sets the calling VLI equal to the absolute value of the passed VLI
		Pre:			Called as member of VLI object
		Post:			Returns ( 1 ) if positive and ( -1 ) if negative
		Parameters:		
						input: VLI to get Absolute Value of
	*/
	void getAbsValue(const VLI input);

	/*
		Description:	Returns the number of digits in VLI object
		Pre:			Called as member of VLI object
		Post:			Returns number of digits in VLI
		Returns:		Number of digits in VLI
	*/
	int getVLILength() const;

	/*
		Description:	Returns the number of digits in VLI object
		Pre:			Called as member of VLI object
						input is initialized integer
		Post:			If input < 0, sign is -, otherwise it is positive
		Parameters:		
						input: sign to set VLI to
	*/
	void setSign(int input);

// Arithmetic

	/*
		Description:	Sets calling VLI equal to vli1 + vli2
		Pre:			Called as member of VLI object
		Post:			Calling VLI object is set to be equal to vli1 + vli2
		Parameters:		
						vli1: First VLI object to add
						vli2: Second VLI object to add
	*/
	void addVLI(const VLI vli1, const VLI vli2);

	/*
		Description:	Sets calling VLI equal to vli1 - vli2
		Pre:			Called as member of VLI object
		Post:			Calling VLI object is set to be equal to vli1 - vli2
		Parameters:		
						vli1: VLI object to subtract from
						vli2: VLI object to subtract
	*/
	void subVLI(const VLI vli1, const VLI vli2);

// Predicate

	/*
		Description:	Returns if the value of the calling vli object 
							is equal to the passed vli object
		Pre:			Called as member of VLI object
		Post:			Calling VLI object is compared to passed VLI object
		Parameters:		
						vli: VLI object to compare to
		Returns:		True if calling vli object is equal to passed vli object
						False otherwise
	*/
	bool isEQ(const VLI vli) const;

	/*
		Description:	Returns if the value of the calling vli object 
							is greater than the passed vli object
		Pre:			Called as member of VLI object
		Post:			Calling VLI object is compared to passed VLI object
		Parameters:		
						vli: VLI object to compare to
		Returns:		True if calling vli object is greater than passed vli object
						False otherwise
	*/
	bool isGT(const VLI vli) const;

	/*
		Description:	Returns if the value of the calling vli object 
							is less than the passed vli object
		Pre:			Called as member of VLI object
		Post:			Calling VLI object is compared to passed VLI object
		Parameters:		
						vli: VLI object to compare to
		Returns:		True if calling vli object is less than passed vli object
						False otherwise
	*/
	bool isLT(const VLI vli) const;

// Misc

	/*
		Description:	Sets every digit in VLI equal to 0 and sign to positive
		Pre:			Called as member of VLI object
		Post:			Calling VLI object is initialized/cleared
	*/
	void clearVLI();

	/*
		Description:	Outputs a cstring with value equal to VLI object
		Pre:			Called as member of VLI object
						Passed char array is large enough to hold value of VLI
		Post:			Calling VLI object is converted into a cstring
		Parameters:		
						output: cstring to output value of VLI object to
	*/
	void toCstring(char output[]) const;

	/*
		Description:	Prints the value of the calling VLI object
		Pre:			Called as member of VLI object
		Post:			VLI object will be printed out to the console
	*/
	void print() const;

	/*
		Description:	Sets value of VLI from passed input cstring
		Pre:			Called as member of VLI object
						Passed cstring has an optional leading negative
							and must have a terminating null character
		Post:			VLI object will be set equal to value of input string
		Parameters:		
						input: cstring to set value of VLI object to
	*/
	void setVLIFromString(const char input[]);

	/*
		Description:	Sets value of VLI from passed input cstring
		Pre:			Called as member of VLI object
						Passed cstring has an optional leading negative
							and must have a terminating null character
		Post:			VLI object will be set equal to value of input string
		Parameters:		
						input: cstring to set value of VLI object to
	*/
	void copyVLI(const VLI input);
private:
// Data Storage

	/*
		Description:	True if the VLI object is to be a negative value
	*/
	bool isNegative;

	/*
		Description:	Stores each individual digit in a character array
						The char array is used because it uses less memory than
							an integer array
						Less significant digits are on the right
						[ 0, 0, . . . , d1, d2, d3 . . . ]
						There is no null terminator
	*/
	char num[VLI_SIZE];
};