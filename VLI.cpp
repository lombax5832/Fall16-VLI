using namespace std;
#include<iostream>
#include<algorithm>
#include"VLI.h";

// Function Declarations
int firstNonXIndex(const char[], int, char);
bool greaterVLIFirst(const VLI, const VLI, VLI&, VLI&);

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
void VLI::addVLI(const VLI vli1, const VLI vli2) {

	VLI tempVLI1, tempVLI2;
	clearVLI();
	greaterVLIFirst(vli1, vli2, tempVLI1, tempVLI2);

	if (tempVLI1.getSign() != tempVLI2.getSign()) {
		tempVLI2.setSign(tempVLI2.getSign()*-1);
		subVLI(tempVLI1, tempVLI2);
		return;
	}
	setSign(tempVLI1.getSign());
	// tempCarry10 is the amount to carry to the next vli element
	int tempCarry10 = 0;
	// tempAdd is how much we add to the current vli element
	int tempAdd = 0;

	// adds elements starting at the last one
	for (int i = VLI_SIZE - 1; i >= min(VLI_SIZE - tempVLI1.getVLILength(),
		VLI_SIZE - tempVLI2.getVLILength())-1; i--) {

		tempAdd = tempVLI1.num[i] + tempVLI2.num[i] + tempCarry10;
		num[i] = tempAdd % 10;
		tempCarry10 = tempAdd / 10;
		tempAdd = 0;
	}
}

void VLI::subVLI(const VLI vli1, const VLI vli2) {
	// Need 2 temporary VLI objects
	VLI tempVLI1, tempVLI2;
	clearVLI();

	// This function will make tempVLI1 the greater of the 2 vli objects
	if (greaterVLIFirst(vli1, vli2, tempVLI1, tempVLI2)) {
		setSign(-1);
	}

	if (tempVLI1.getSign() != tempVLI2.getSign()) {
		tempVLI2.setSign(tempVLI2.getSign()*-1);
		addVLI(tempVLI1, tempVLI2);
		return;
	}
	else {
		setSign(tempVLI1.getSign());
	}

	// tempSub is how much we subtract from the current vli element
	int tempSub = 0;

	int mostSignificantIndex = (VLI_SIZE - tempVLI1.getVLILength());

	// subtracts elements starting at the last one
	for (int i = (VLI_SIZE - 1); i >= mostSignificantIndex; i--) {

		tempSub = tempVLI1.num[i] - tempVLI2.num[i];

		// if tempSub is negative, we have to borrow a 1 from somewhere
		if (tempSub < 0) {
			for (int j = (i - 1); j >= mostSignificantIndex; j--) {
				if (tempVLI1.num[j] > 0) {

					tempVLI1.num[j]--;

					for (int k = j + 1; k < i; k++) {
						tempVLI1.num[k] = 9;
					}
					break;
				}
			}

			tempVLI1.num[i] += 10;
			tempSub = tempVLI1.num[i] - tempVLI2.num[i];

		}
		num[i] = tempSub;
		tempSub = 0;
	}
}

bool greaterVLIFirst(const VLI vli1, const VLI vli2, VLI& tempVLI1, VLI& tempVLI2) {
	VLI absVLI1, absVLI2;
	absVLI1.getAbsValue(vli1);
	absVLI2.getAbsValue(vli2);
	if (absVLI2.isGT(absVLI1)) {

		tempVLI1.copyVLI(absVLI2);
		tempVLI1.setSign(vli2.getSign());

		tempVLI2.copyVLI(absVLI1);
		tempVLI2.setSign(vli1.getSign());
		return true;
	}
	else {

		tempVLI1.copyVLI(absVLI1);
		tempVLI1.setSign(vli1.getSign());

		tempVLI2.copyVLI(absVLI2);
		tempVLI2.setSign(vli2.getSign());
	}
	return false;
}

// END Arithmetic

// START Predicate
bool VLI::isEQ(const VLI vli2) const{
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

bool VLI::isGT(const VLI vli2) const {
	if (!isNegative && vli2.isNegative) {
		return true;
	}
	else if (isNegative && !vli2.isNegative) {
		return false;
	}
	else if (isNegative == vli2.isNegative) {
		int vlilength = max(getVLILength(), vli2.getVLILength());// Amount of digits in the VLI
		for (int i = VLI_SIZE - vlilength; i < VLI_SIZE; i++) {
			if ((getSign()*num[i]) > (vli2.getSign()*vli2.num[i])) {
				return true;
			}
			else if ((getSign()*num[i]) < (vli2.getSign()*vli2.num[i])) {
				return false;
			}
		}
		return false;
	}
}

bool VLI::isLT(const VLI vli2) const{
	return(!isGT(vli2)&&!isEQ(vli2));
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