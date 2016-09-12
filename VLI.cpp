using namespace std;
#include<iostream>
#include"VLI.h";

// START Constructors
VLI::VLI(){
	
}

VLI::VLI(int input) {

    
    }

VLI::VLI(const char input[]) { //NOT SURE IF WORKS YET. HAVEN"T TESTED IT
    int size;
    int num1;
    
    size = strlen(input);
    
    for( int x = 0; x< size; x++)
    {
        num1 = input[x] - '0';
    }
    
}
// END Constructors

// START Getters and Setters
int VLI::getSign() {
	return sign;
}

VLI VLI::getAbsValue() {
    
}

void VLI::setSign() {

}
// END Getters and Setters

// START Arithmetic
VLI VLI::addVLI(VLI vli1, VLI vli2) {

}

VLI VLI::subVLI(VLI vli1, VLI vli2) {

}
// END Arithmetic

// START Predicate
bool VLI::isEQ(VLI vli1, VLI vli2) {

}

bool VLI::isGT(VLI vli1, VLI vli2) {

}

bool VLI::isLT(VLI vli1, VLI vli2) {

}
// END Predicate

// START Misc
void VLI::toCstring(char output[]) {

}

void VLI::print() {

}
// END Misc