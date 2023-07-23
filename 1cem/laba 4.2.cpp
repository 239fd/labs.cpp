#include <iostream>

using namespace std;

int main() {

	int n;	
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
	int k,k1,k2,b,b1;
	int j,l,pr;
	double* array = new double[n];
	k = 0;
	k2 = 0;
	pr = 1;

	int ch;
	cout << "1 - keyboard, 2 - random: ";
	cin >> ch;

	if (ch == 1) {
		for (int i = 0; i < n; i++) {

			cout << "array[" << i + 1 << "] = ";
			cin >> array[i];

		}
	}
	else {
		if (ch == 2) {
			for (int i = 0; i < n; i++)
			{

				array[i] = rand() % 40 - 20;

			}
			for (int i = 0; i < n; i++) {
				cout << "array[" << i + 1 << "]" << " = " << array[i] << endl;
			}
		}
		else {
			cout << "Mistake";
		}

	}


	for (int i = 0; i < n; i++) {
		j = 0;
		if (array[i] == 0) {
			k++;
			j = i + 1 ;
			break;
			
		}
	
	}

	k1 = j;
	b = k1 - 1;
	b1 = k1 - 1;
	if (k == 0) {
		cout << "No zero";
		return 0;
	}


	for (b += 1; b < n; b++) {
		
		if (array[b] == 0) {
			k2++;
			l = b;
			break;
		}

	}
	if (k2 == 0) {
		cout << "Only one zero";
		return 0;
	}
	

	if (b1 == l-1) {
		cout << "negr";
		return 0;
	}
	
	for (b1 += 1; b1 < l; b1++) {
		pr *= array[b1];
	}

	cout << pr;
	delete array;

}