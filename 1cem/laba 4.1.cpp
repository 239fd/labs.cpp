#include <iostream>

using namespace std;

int main() {

	int n,k,k1;
	double sum,answer;
	k = 0;
	sum = 0;
	
	cout << "n = ";
	cin >> n;
	if (n > 20) {
		cout << "Mistake";
		return 0;
	}
	if (n < 0) {
		cout << "Mistake";
		return 0;
	}
	
	double* array = new double[n];
	
	for (int i = 0; i < n; i++) {

		cout << "Enter array[" << i+1 << "]: ";
		cin >> array[i];
	}

	for (int i = 0; i < n; i++) {

		if (array[i] < 0) {
			
			k++;
			sum += array[i];
		
		}
	}
	k1 = k + 1 - 1;

	delete array;

	answer = sum / k1;
	
	cout << answer;
}