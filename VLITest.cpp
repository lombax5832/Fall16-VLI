using namespace std;
#include<iostream>
#include"VLI.h";

int main() {
	char testArray[VLI_SIZE] = { 0 };
	char testArray2[VLI_SIZE] = { 0 };
	char testArray3[VLI_SIZE] = { 0 };
	int testInt = 0;
/*	for (int i = 0; i < VLI_SIZE; i++) {
		testArray[i] = 0;
	}*/
	cout << "Enter a string: ";
	cin >> testArray2;
	cout << "Enter another string: ";
	cin >> testArray3;
	VLI vli1(testArray2);
	VLI vli2(testArray3);
	VLI vli3;

	vli3.addVLI(vli1, vli2);
	vli3.print();
	return 0;
}