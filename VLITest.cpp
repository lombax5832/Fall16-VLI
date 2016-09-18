using namespace std;
#include<iostream>
#include"VLI.h";

int main() {
	while (true) {
		char testArray1[VLI_SIZE] = { 0 };
		char testArray2[VLI_SIZE] = { 0 };
		char testArray3[VLI_SIZE] = { 0 };
		int testInt = 0;
		/*	for (int i = 0; i < VLI_SIZE; i++) {
				testArray[i] = 0;
			}*/
		
		cout << "Enter a string up to 100 digits: ";
		cin >> testArray1;
		cout << "Enter another string ip to 100 digits: ";
		cin >> testArray2;
		cout << endl;

		VLI vli1(testArray1);
		VLI vli2(testArray2);
		VLI vli3;

		
		
		cout << "AddVLInt: ";
		vli3.addVLI(vli1, vli2);
		vli3.print();
		
		cout << "subVLInt: ";
		vli3.subVLI(vli1, vli2);
		vli3.print();

		cout << "isEQ: ";
		vli1.isEQ(vli2) ? cout << "VLI1 = VLI2" : cout << "VLI1 != VLI2";
		cout << endl;

		cout << "isGT: ";
		vli1.isGT(vli2) ? cout << "VLI1 > VLI2" : cout << "VLI1 !> VLI2";
		cout << endl;

		cout << "isLT: " ;
		vli1.isLT(vli2) ? cout << "VLI1 < VLI2" : cout << "VLI1 !< VLI2";
		cout << endl;

		cout << "toCstring: ";
		vli1.toCstring(testArray3);
		cout << testArray3;
		cout << endl << endl;
	}
	return 0;
}