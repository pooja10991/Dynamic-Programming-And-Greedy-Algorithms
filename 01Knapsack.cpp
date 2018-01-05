#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

int main()
{
	int w, n, weightAlla[25], valuesAlla[25];
	int i = 0, j = 0;
	char ws[5], ns[5];
	std::string weightAll, valuesAll;
	cout << "Enter no of elements : ";
	cin >> ns;
	n = std::stoi(ns);
	cout << "Enter total weight : ";
	cin >> ws;
	w = std::stoi(ws);
	cin.ignore();
	std::cout << "Enter Weights of all elements (space seperated) : ";
	getline(cin, weightAll);

	std::cout << "Enter Values of all elements (space seperated) : ";
	getline(cin, valuesAll);

	std::istringstream buf(weightAll);
	std::istream_iterator<std::string> beg(buf), end;
	std::vector<std::string> tokensW(beg, end);
	for(auto& s: tokensW){
		weightAlla[i] = std::stoi(s);
		i++;
	}

	std::istringstream buf1(valuesAll);
	std::istream_iterator<std::string> beg1(buf1), end1;
	std::vector<std::string> tokensV(beg1, end1);
	for(auto& s1: tokensV){
		valuesAlla[j] = std::stoi(s1);
		j++;
	}

	if (j!=n && i!=n)
	{
		cout << "The number of weights or values does not match with total number of elements.";
		return -1;
	}

	//Define Table
	int table[n][w+1];

	//Initialize Table
	for(int k = 0 ; k < n ; k++) {
		table[k][0] = 0;
	}

	//Fill the Table
	int a = 0, b = 0;
	for(int k = 1 ; k <= w ; k++) {
		for(int l = 0 ; l < n ; l++) {
			if(l==0){
				if(weightAlla[l] <= k){
					table[l][k] = valuesAlla[l];
				}
				else{
					table[l][k] = 0;
				}
			}
			else {
				a = 0;
				b = table[l-1][k];
				if(weightAlla[l] > k){
					table[l][k] = b;
				}
				else{
					a = valuesAlla[l]+table[l-1][k-weightAlla[l]];
					table[l][k] = (a<b)?b:a;
				}
			}
		}
	}

	//Printing the table
	for(int k = 0 ; k < n ; k++) {
		for(int l = 0 ; l <= w ; l++) {
			cout << table[k][l] << "  ";
		}
		cout << "\n";
	}
	cout<<"Total value is : "<< table[n-1][w]<<"\n";

	//Finding the solution/backtracking
	int k = w;
	int l = n-1;
	int solution[25];
	int p = 0;
	while(l>=0 && k>=0) {
		if(l==0) {
			if(k>=weightAlla[l]){
				solution[p] = 1;
				k = k-weightAlla[l];
				p++;
				l--;
			}
			else {
				l--;
			}
		}
		else {
			if(table[l][k] != table[l-1][k]) {
				solution[p] = l+1;
				p++;
				k = k-weightAlla[l];
				l--;
				//k = k-weightAlla[l];
			}
			else {
				l--;
			}
		}
	}
	cout << p;
	cout << "solution is/items are : ";
	for(int m=p-1;m>=0;m--){
		cout << solution[m] << " ";
	}
	cout << "\n";
}
