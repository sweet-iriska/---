#include <iostream>
#include <random>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <ctime>
using namespace std;

//нечетные умножить на 2, четные увеличить на 1

class FunctorClass
{
public:

	int operator()(int &n){
		if (n % 2 == 0) {
			n = 2 * n;
		}
		else {
			n++;
		}
		return n;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	vector<int> v;
	generate_n(back_inserter(v), 10, []() mutable{return rand() % 10; });
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;

	int evenCount = 0;
	int evenCount1 = 0;
	for_each(v.begin(), v.end(), [&evenCount](int &n) {
		
		if (n % 2 == 0) {
			n = 2 * n;
		}
		else {
			n++;
		}
		return n;
	});

	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	for_each(v.begin(), v.end(), FunctorClass());
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	ofstream file;
	file.open("1.txt", ios::out | ios::app);
	if (!file)
	{
		cout << "Error!";
		cin.sync(), cin.get();

		return 1;
	}
	copy(begin(v), end(v), ostream_iterator<int>(file, " "));
	file.close();
	_getwch();
	return 0;
}