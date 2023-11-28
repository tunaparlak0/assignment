//*******************************************************************************************************************************
//**                       Name: Tuna Parlak                                                                                   **
//**                       Number:b221202022                                                                                   ** 
//**    Assignment: Write down a C++ program which calculates the integral of 𝒇(𝒙) = 𝒙^3 + 𝟒𝒙 using the “Reiman Sums”formula   **
//*******************************************************************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;
struct sums {
	float lhfSum, rhfSum, midpointSum;//variables about sums of terms
};
struct values {
	float lhf, rhf, midpoint;//variables about values of ..th term 
};
int main() {
	sums s;
	values v;
	float a, b, n;  //variables about interval
	float epsilon,delta; //variables about function
	int sayi; // ..th term of partition
	sayi = 0;
	s.lhfSum = 0;
	s.rhfSum = 0;
	s.midpointSum = 0;
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

		cout << setw(4) << "i" << setw(14) << "x[i]" << setw(16) << "epsilon[i]" << setw(12) << "LHF" << setw(14) << "RHF" << setw(12) << "MF" << endl;

		cout << "--------------------------------------------------------------------------" << endl;
		//for loop for calculating values
		for (float i = a; i < b; i += delta) {
				sayi++;//increasing the term of partition
				// calculating ..th term of lhf,rhf,midpoint values according to integral of 𝒇(𝒙) = 𝒙^3 + 𝟒𝒙
				v.lhf = pow(i, 3) + 4 * i;
				v.rhf = pow((i + delta), 3) + 4 * (i + delta);
				v.midpoint = pow(epsilon, 3) + 4 * epsilon;

				s.lhfSum = s.lhfSum + v.lhf * delta;//summing the lhf values
				s.rhfSum = s.rhfSum + v.rhf * delta;//summing the rhf values
				s.midpointSum = s.midpointSum + v.midpoint * delta;//summing the midpoint values
				//printing values
				cout << setw(4) << sayi << setw(12) << i << setw(14) << epsilon << setw(15) << v.lhf << setw(14) << v.rhf << setw(14) << v.midpoint << endl;
				epsilon = epsilon + delta;//increasing the epsilon value
			
		}
		//printing the bottom part of the sample output screen
		cout << "--------------------------------------" << endl;
		cout << "-----------INTEGRAL RESULTS-----------" << endl;
		cout << "f(x)= x^3 + 4x from " << "[" << a << "," << b << "]" << " with " << n << " intervals" << endl;
		cout << "--------------------------------------" << endl;
		cout << "MIDPOINT RULE" << setw(9) << ": " << s.midpointSum << endl;
		cout << "LEFT HAND RULE" << setw(8) << ": " << s.lhfSum << endl;
		cout << "RIGHT HAND RULE" << setw(7) << ": " << s.rhfSum << endl;
	}
	else {
		cout << "Please enter the small number first..." << endl;
	
	}
}