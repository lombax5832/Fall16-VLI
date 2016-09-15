using namespace std;
#include<iostream>
#include<algorithm>
#include"VLI.h";
#include"convert.h";

// Function Declarations
int firstNonXIndex(const char[], char);

// START Constructors
VLI::VLI(){
	char inputString[] = { 0 };
	setVLIFromString(inputString);
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
int VLI::getSign() const {
	if (isNegative) {
		return -1;
	}
	return 1;
}

VLI VLI::getAbsValue() const {
	return NULL;
}

int VLI::getVLILength() const {
	for (int i = 0; i < VLI_SIZE; i++) {
		if (num[i] != 0) {
			return VLI_SIZE-i;
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
bool VLI::addVLI(VLI vli1, VLI vli2) {
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
bool VLI::isEQ(VLI vli1, VLI vli2) {
    if( vli1.getVLILength() > vli2.getVLILength()) {
        return false;
    }
    else if ( vli1.getVLILength() < vli2.getVLILength()) {
    
        return false;
    }
    else if(vli1.getVLILength() == vli2.getVLILength())
    {
        for( int i = 0; i< vli1.getVLILength(); i++) {
            
            if( vli1[i] > vli2[i]){
        
            return false;
        }
            else if( vli1[i] < vli2[i]) {
                return false;
            }
            else {
                return true;
            }
            
        }
    }
    
    //return NULL;
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
	for (int i = VLI_SIZE-getVLILength(), j = 0; i < VLI_SIZE; i++, j++) {
		if (j == 0 && isNegative) {
			output[j] = '-';
			j++;
		}

		output[j] = num[i] + '0';
		output[j + 1] = '\0';
	}
}

void VLI::print() {
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
	int size;

	clearVLI();

	size = strlen(input) - 1;
	if (input[firstNonXIndex(input, '0')] == '-') {
		isNegative = true;
	}

	for (int inputIndex = 0, outputIndex = 0; inputIndex <= size; inputIndex++, outputIndex++)
	{
		if (input[size - inputIndex]<'0' || input[size - inputIndex]>'9') {
			outputIndex--;
		}else if (input[size - inputIndex] != '-') {
			num[VLI_SIZE - outputIndex - 1] = input[size - inputIndex] - '0';
		}
	}
}

int firstNonXIndex(const char input[], char X) {
	int size = strlen(input);//Length of string
	for (int i = 0; i < size; i++) {
		if (input[i] != X) {//Return the first index where input[i]!='0'
			return i;
		}
	}
	return size-1;
}


// END Misc