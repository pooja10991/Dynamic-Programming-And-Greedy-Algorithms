#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

int main()
{
	int amount, denom[25];
	int i = 0;
	std::string denoms;
	cout << "Enter amount to make change : ";
	cin >> amount;
	cin.ignore();
	std::cout << "Enter denominations (space seperated and in ascending order) : ";
	getline(cin, denoms);

	std::istringstream buf(denoms);
	std::istream_iterator<std::string> beg(buf), end;
	std::vector<std::string> tokens(beg, end);
	for(auto& s: tokens){
		denom[i] = std::stoi(s);
		i++;
	}

	//Define Table
	int table[i][amount+1];
	int solution[25];

	//Initialize Table
	for(int k = 0 ; k < i ; k++) {
		table[k][0] = 0;
		solution[k] = 0;
	}

	//Fill the Table
	int a = 0, b = 0;
	for(int k = 1 ; k <= amount ; k++) {
		for(int l = 0 ; l < i ; l++) {
			if(l==0){
				if(denom[l] <= k){
					table[l][k] = k/denom[l];
				}
				else{
					table[l][k] = 0;
				}
			}
			else {
				a = 0;
				b = table[l-1][k];
				if(denom[l] > k || k-denom[l]<0){
					table[l][k] = b;
				}
				else{
					a = 1+table[l][k-denom[l]];
					//a = (k/denom[l])+table[l-1][k%denom[l]];
					table[l][k] = (a<b)?a:b;
				}
			}

		}
	}

	//Printing the table
	for(int k = 0 ; k < i ; k++) {
		for(int l = 0 ; l <= amount ; l++) {
			cout << table[k][l] << "  ";
		}
		cout << "\n";
	}
	cout<<"Total no of coins used : "<< table[i-1][amount]<<"\n";

	//Finding the solution/backtracking
	int k = amount;
	int l = i-1;
	int p = 0;
	while(l>=0 && k>=0) {
		if(table[l][k] != table[l-1][k]) {
			p = l;
			if(denom[l]<=k) {
				solution[p] = k/denom[l];
			}
			else{
				solution[p] = 0;
			}
			k = k%denom[l];
			l--;
		}
		else {
			l--;
		}
	}
	cout << "solution : \n";
	for(int m=0;m<i;m++){
		if(solution[m]!=0){
			cout << denom[m] << " X " << solution[m] << " = " << denom[m]*solution[m] << "\n";
		}
	}
}

