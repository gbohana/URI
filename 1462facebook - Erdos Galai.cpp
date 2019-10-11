/*This code implements the Erdos Galai theorem in a non-efficient way*/
/*This results in a TLE on URI*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

//erdos-galai
int main() {
	int n;
	while (cin >> n) {
		int ai;
		vector <int> vec; 
		int sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> ai; //ai = grau do v�rtice
			vec.push_back(ai);
			sum += ai;
		}
		sort(vec.begin(), vec.end(), greater<int>());
		if (sum % 2 != 0 || vec[0] > n) {
			cout << "impossivel" << endl;
			continue;
		} else if (vec[0]==0){
			cout << "possivel" << endl;
			continue;
		}
		bool possible = true;
		
		int soma = 0; //lado esquerdo da inequacao

		for (int i = 1; i < n; i++) {
			soma += vec[i-1]; //soma dos graus at� agora
			int l = i * (i - 1);
			
			int m = 0; //somatorio da esquerda
			for (long long int j = i + 1; j <= n; j++) {
				m += min(vec[j-1], i);
			}
		
			if (soma > l + m) {
				possible = false;
				break;
			}

		}
		
		if (possible) {
			cout << "possivel" << endl;
		}
		else {
			cout << "impossivel" << endl;
		}
	}
}