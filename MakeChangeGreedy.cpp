#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

int main()
{
	int amount, amount1;
	int i = 0, k = 0;
	int solution[20];
	std::string dinoms;
	int dinom[20];
	cout << "Enter the amount to make change : ";
	cin >> amount;
	cin.ignore();
	cout << "Enter denominations (space seperated and in descending order): ";
	getline(cin, dinoms);

	std::istringstream buf(dinoms);
	std::istream_iterator<std::string> beg(buf), end;
	std::vector<std::string> tokens(beg, end);
	for(auto& s: tokens){
		dinom[i] = std::stoi(s);
		i++;
	}
	
	//make change using greedy algorithm.	
	amount1 = amount;
	for (int j = 0 ; j < i ; j++) {
		if(amount>=dinom[j]) {
			solution[k] = amount1/dinom[j];
			k++;
			amount1 = amount1%dinom[j];
		}
		else {
			solution[k] = 0;
			k++;
		}
	}

	//output
	int total_coins = 0;
	cout << "solution : \n";
	for (int j = 0 ; j<i ; j++) {
		if(solution[j]!=0){
			cout << dinom[j] << " X " << solution[j] << " = " << dinom[j]*solution[j] << "\n";
			total_coins += solution[j];
		}
	}
	cout << "Total number of coins : " << total_coins << "\n";
}


