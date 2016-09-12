using namespace std;
#include<iostream>
#include<algorithm>
#include"VLI.h";
#include"convert.h";

// START Constructors
VLI::VLI(){
	
}

VLI::VLI(int input) {
	char input2str[MAX_INT_STRING_LENGTH] = "";
	int2str(input, input2str);
	setVLIFromString(input2str);
}

VLI::VLI(const char input[]) {
	setVLIFromString(input);
}
// END Constructors

// START Getters and Setters
int VLI::getSign() {
	if (isNegative) {
		return -1;
	}
	return 1;
}

VLI VLI::getAbsValue() {
	return NULL;
}

void VLI::setSign() {
}
// END Getters and Setters

// START Arithmetic
VLI VLI::addVLI(VLI vli1, VLI vli2) {
	return NULL;
}

VLI VLI::subVLI(VLI vli1, VLI vli2) {
	return NULL;
}
// END Arithmetic

// START Predicate
bool VLI::isEQ(VLI vli1, VLI vli2) {
	return NULL;
}

bool VLI::isGT(VLI vli1, VLI vli2) {
	return NULL;
}

bool VLI::isLT(VLI vli1, VLI vli2) {
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

void VLI::toCstring(char output[]) {
}

void VLI::print() {
	bool firstNonZero = false;
	if (isNegative) {
		cout << '-';
	}
	for (int i = 0; i < VLI_SIZE; i++) {
		if(firstNonZero==false&&num[i] != 0) {
			firstNonZero = true;
		}
		if (firstNonZero) {
			cout << (int)num[i];
		}
	}
	cout << endl;
}

void VLI::setVLIFromString(const char input[]) {
	int size;

	clearVLI();

	size = strlen(input) - 1;
	if (input[0] == '-') {
		isNegative = true;
	}

	for (int x = 0; x <= size; x++)
	{
		if (input[size - x] != '-') {
			num[VLI_SIZE - x - 1] = input[size - x] - '0';
		}
	}
}
// END Misc