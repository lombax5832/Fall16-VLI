#pragma once

/**
*	Author:			Alexei Snytkine
*	Description:	Module used to convert integers and doubles into 
*					strings, also to see if a string is a valid identifier
*	Date Created:	9/3/16
*	Date Modified:	9/5/16
*/

// Maximum amount of characters need to store an integer or double,
//	including null char, sign & decimal
const int MAX_INT_STRING_LENGTH = 12;
const int MAX_DOUBLE_STRING_LENGTH = 20;
// ASCII values of certain characters
const int ASCII_0 = 48;
const int ASCII_9 = 57;
const int ASCII_A = 65;
const int ASCII_UNDERSCORE = 95;
const int ASCII_LOWERCASE_A = 97;

/*
	Description:	Convert an integer into a string
	Pre:			Valid Integer
					Sufficiently Large char Array
	Post:			Char array will be a string that prints the same text 
					as given int
	Parameters:		
					input: int to convert to string
					output: char array to insert characters into
*/
void int2str(int input, char output[]);

/*
	Description:	Return an integer from given string
	Pre:			Valid String
					Sufficiently Large char Array
	Post:			Returned value will include all numerical characters 
					until the null character
	Parameters:		
					input: char array to convert to an int
*/
int str2int(const char input[]);

/*
	Description:	Convert an double into a string
	Pre:			Valid Double
					Sufficiently Large char Array
	Post:			Char array will be a string that prints the double in 
					scientific notation
	Parameters:		
					input: double to convert to string
					output: char array to insert characters into
*/
void double2str(double input, char output[]);

/*
	Description:	Convert an string into a double
	Pre:			Valid String
					Sufficiently Large char Array
	Post:			Returned value will include all numerical characters 
					until the null character
	Parameters:		
					input: char array to convert to a double
*/
double str2double(const char[]);

/*
	Description:	Return whether or not a string is a valid identifier
	Pre:			Valid String
	Post:			Returned value will say if the input is a valid identifier
	Parameters:		
					input: char array to check
*/
bool isIdentifier(const char[]);