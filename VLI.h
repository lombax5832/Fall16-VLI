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
	void subVLI(VLI, VLI);

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
	bool isEQ(VLI vli) const;

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
	bool isGT(VLI vli) const;

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
	bool isLT(VLI vli) const;

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