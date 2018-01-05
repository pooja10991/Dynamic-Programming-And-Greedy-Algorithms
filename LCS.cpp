#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
using namespace std;

int main()
{
	int i = 0;
	char str1[50], str2[50];
	cout << "Enter first string : ";
	cin >> str1;
	cout << str1;
	std::cout << "Enter second string : ";
	cin >> str2;

	int n1 = strlen(str1);
	int n2 = strlen(str2);

	//Define Table
	int table[n1+1][n2+1];
	char solution[50];
	int bt[n1][n2];

	//Initialize Table
	for(int k = 0 ; k <= n1 ; k++) {
		table[k][0] = 0;
	}

	for(int k = 0 ; k <= n2 ; k++) {
		table[0][k] = 0;
	}

	//Fill the Table
	int a = 0, b = 0;
	for(int k = 1 ; k <= n2 ; k++) {
		for(int l = 1 ; l <= n1 ; l++) {
			if(str1[l-1] == str2[k-1])
			{
				table[l][k] = table[l-1][k-1]+1;
				bt[l][k] = 0;
			}
			else
			{
				table[l][k] = table[l-1][k] > table[l][k-1] ? table[l-1][k] : table[l][k-1];
				bt[l][k] = table[l-1][k] >= table[l][k-1] ? 2 : 1;
			}
		}
	}

	//Printing the table
	for(int k = 0 ; k <= n1 ; k++) {
		for(int l = 0 ; l <= n2 ; l++) {
			cout << table[k][l] << " " << bt[k][l] << "  ";
		}
		cout << "\n";
	}
	cout<<"The length of LCS is : "<< table[n1][n2]<<"\n";

	//Finding the solution/backtracking
	int k = n2;
	int l = n1;
	int p = 0;
	while(l>=0 && k>=0) {
		if(bt[l][k] == 0) {
			solution[p] = str1[l-1];
			p++;
			l--;
			k--;
		}
		else if (bt[l][k] == 2)
			l--;
		else if (bt[l][k] == 1)
			k--;
	}
	cout << "LCS : ";
	for(int m=p-1;m>=0;m--){
		cout << solution[m] << " ";
	}
	cout << "\n";
}

