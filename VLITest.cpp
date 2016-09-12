using namespace std;
#include<iostream>
#include"VLI.h";

int main() {
	char testArray[VLI_SIZE] = { 0 };
	int testInt = 0;
	for (int i = 0; i < VLI_SIZE; i++) {
		testArray[i] = 0;
	}
	cout << "Enter an integer: ";
	cin >> testArray;
	VLI testVLI(testArray);
	testVLI.print();
	return 0;
}