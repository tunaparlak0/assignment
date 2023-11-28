//*******************************************************************************************************************************
//**                       Name: Tuna Parlak                                                                                   **
//**                       Number:b221202022                                                                                   ** 
//**    Assignment: Write down a C++ program which calculates the integral of 𝒇(𝒙) = 𝒙𝟑 + 𝟒𝒙 using the “Reiman Sums”formula    **
//*******************************************************************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;
//defining function
float integ(float x) {
	float sonuc = pow (x,3) + 4 * x;
	return sonuc;
}
int main() {
	float a, b, n;  //variables about interval
	float epsilon,delta; //variables about function
	float lhf, rhf, midpoint; //variables about function result
	int sayi; // ..th term of partition
	sayi = 0;
	lhf = 0;
	rhf = 0;
	midpoint = 0;
	//asking for defining interval
	cout << "Please define the interval:";
	cin >> a >> b;
	if (a < b) {//small number should be entered first
		cout << "Please enter the number of intervals:";
		cin >> n;
		//defining variables about function
		delta = (b - a) / n;
		epsilon = a + delta / 2;
		//printing the top part of the sample output screen
		cout << "a:" << setw(3) << a << endl;
		cout << "b:" << setw(3) << b << endl;
		cout << "n:" << setw(3) << n << endl;
		cout << "--------------------------------------------------------------------------" << endl;

		cout << setw(5) << "i" << setw(12) << "x[i]" << setw(18) << "epsilon[i]" << setw(12) << "LHF" << setw(12) << "RHF" << setw(12) << "MF" << endl;

		cout << "--------------------------------------------------------------------------" << endl;
		//for loop for calculating values
		for (float i = a; i < b; i += delta) {
				sayi++;//increasing the term of partition
				lhf = lhf + integ(i) * delta;//summing the lhf results
				rhf = rhf + integ(i + delta) * delta;//summing the rhf results
				midpoint = midpoint + integ(epsilon) * delta;//summing the midpoint results
				//printing values
				cout << setw(4) << sayi << setw(12) << i << setw(15) << epsilon << setw(15) << integ(i) << setw(14) << integ(i + delta) << setw(14) << integ(epsilon) << endl;
				epsilon = epsilon + delta;//increasing the epsilon value
			
		}
		//printing the bottom part of the sample output screen
		cout << "--------------------------------" << endl;
		cout << "--------INTEGRAL RESULTS--------" << endl;
		cout << "f(x)= x^3 + 4x from " << "[" << a << "," << b << "]" << " with " << n << " intervals" << endl;
		cout << "--------------------------------" << endl;
		cout << "MIDPOINT RULE" << setw(9) << ": " << midpoint << endl;
		cout << "LEFT HAND RULE" << setw(8) << ": " << lhf << endl;
		cout << "RIGHT HAND RULE" << setw(7) << ": " << rhf << endl;
	}
	else {
		cout << "Please enter the small number first..." << endl;
	
	}
}