using namespace std;
#include<iostream>
#include<algorithm>
#include<string>

#include"VLI.h";

// Function Declarations
int firstNonXIndex(const char[], int, char);

// START Constructors
VLI::VLI() {
	char inputString[] = { 0 };
	setVLIFromString(inputString);
}

VLI::VLI(int input) {
	clearVLI();
	int temp = 0; // Holds modified input while adding to VLI
	int remainder = 0;

	(input < 0) ? setSign(-1) : setSign(1); // Set sign of VLI to sign of input

	temp = abs(input); // Set temp to be the abs val of the input

	int i = 1; // Iterates through the VLI

	while (temp != 0) {
		remainder = temp % 10; // Remainder is the last digit of temp
		num[VLI_SIZE - i] = remainder;
		temp /= 10; // Removes last digit of temp
		i++;
	}
}

VLI::VLI(const char input[]) {
	setVLIFromString(input);
}
// END Constructors

// START Getters and Setters
int VLI::getSign() const {
	if (isNegative) {
		return -1;
	}
	return 1;
}

void VLI::getAbsValue(const VLI input){
	copyVLI(input);
	setSign(1); // Always positive
}

int VLI::getVLILength() const {
	for (int i = 0; i < VLI_SIZE; i++) {
		if (num[i] != 0) {
			return VLI_SIZE - i;
		}
	}
	return 1;
}

void VLI::setSign(int inputSign) {
	if (inputSign < 0) {
		isNegative = true;
	}
	else {
		isNegative = false;
	}
}
// END Getters and Setters

// START Arithmetic
bool VLI::addVLI(const VLI vli1, const VLI vli2) {
	// tempCarry10 is the amount to carry to the next vli element
	int tempCarry10 = 0;
	// tempAdd is how much we add to the current vli element
	int tempAdd = 0;

	// adds elements starting at the last one
	for (int i = VLI_SIZE - 1; i >= min(VLI_SIZE - vli1.getVLILength() - 1, VLI_SIZE - vli2.getVLILength() - 1); i--) {

		tempAdd = vli1.num[i] + vli2.num[i] + tempCarry10;
		num[i] = tempAdd % 10;
		tempCarry10 = tempAdd / 10;
		tempAdd = 0;
		if (i == 0 && tempCarry10 != 0)
			return false;
	}

	return true;
}

bool VLI::subVLI(VLI vli1, VLI vli2) {
	return false;
}
// END Arithmetic

// START Predicate
bool VLI::isEQ(VLI vli2) const{
	// Only run loop if both VLIs are the same length and sign
	if ((getVLILength() == vli2.getVLILength())&&(getSign()==vli2.getSign())) {
		int vliLength = getVLILength();// Amount of digits in the VLI
		for (int i = VLI_SIZE-vliLength; i < vliLength; i++) {
			if (num[i] == vli2.num[i]) { // We only care about when these are different
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool VLI::isGT(VLI vli2) const{
	return NULL;
}

bool VLI::isLT(VLI vli2) const{
	return NULL;
}
// END Predicate

// START Misc
void VLI::clearVLI() {
	isNegative = false;
	for (int i = 0; i < VLI_SIZE; i++) {
		num[i] = 0;
	}
}

void VLI::toCstring(char output[]) const{
	for (int i = VLI_SIZE - getVLILength(), j = 0; i < VLI_SIZE; i++, j++) {
		if (j == 0 && isNegative) {
			output[j] = '-';
			j++;
		}

		output[j] = num[i] + '0';
		output[j + 1] = '\0';
	}
}

void VLI::print() const{
	bool firstNonZero = false;//Tracks whether or not we hit the first non-zero
	if (isNegative) {
		cout << '-';
	}
	for (int i = 0; i < VLI_SIZE; i++) {
		if (firstNonZero == false && num[i] != 0) {
			firstNonZero = true;
		}
		if (firstNonZero || (i == VLI_SIZE - 1)) {
			cout << (int)num[i];
		}
	}
	cout << endl;
}

void VLI::setVLIFromString(const char input[]) {
	clearVLI();

	int size = strlen(input) - 1;

	int firstValidChar = firstNonXIndex(input, 0, '0');
	//Sets the sign of the VLI to the input's sign
	if (input[firstValidChar] == '-') {
		if ((firstNonXIndex(input, firstValidChar + 1, '0') == size)&&(input[size]=='0')) {
			setSign(1);
		}
		else {
			setSign(-1);
		}
	}
	else {
		setSign(1);
	}

	for (int inputIndex = 0, outputIndex = 0; inputIndex <= size; inputIndex++, outputIndex++)
	{
		if (input[size - inputIndex]<'0' || input[size - inputIndex]>'9') {
			outputIndex--;
		}
		else if (input[size - inputIndex] != '-') {
			num[VLI_SIZE - outputIndex - 1] = input[size - inputIndex] - '0';
		}
	}
}

void VLI::copyVLI(const VLI input) {
	setSign(input.getSign()); // Set signs to be equal
	for (int i = firstNonXIndex(input.num, 0, 0); i < VLI_SIZE; i++) {
		num[i] = input.num[i]; // Set every value in array to be equal
	}
}

int firstNonXIndex(const char input[], int start, char X) {
	int size = strlen(input);//Length of string
	for (int i = start; i < size; i++) {
		if (input[i] != X) {//Return the first index where input[i]!='0'
			return i;
		}
	}
	return size - 1;
}
// END Misc