/*This code implements Havel-Hakimi's algorithm*/
/*It works for small imput but currently gets a "Wrong 20%" on URI*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<long long int> vec, int n) {
	//vec � S' (Havel�Hakimi algorithm)
	if (vec.empty())
		return false;
	sort(vec.begin(), vec.end(), greater<int>());
	if (vec[0] > n)
		return false;
	if (vec[0]==0) { //vec s� tem 0
		return true;
	} 
	else if (all_of(vec.begin(), vec.end(), [](int i) {return i>=0; }) ) { //vec nao tem negativo
		
		long long int d = vec[0]; //cout << d << endl;
		/*apaga vec[0] e subtrai 1 dos vec[0] primeiros*/
		vec.erase(vec.begin()); //cout << vec[0] << " "<<vec.size()<<endl; 
		//if ((n-1-d) >= 0) { //garantir que n�o vai acessar fora do vec
			for (int i = 0; i < d; i++) {
				vec[i]--; //apagando arestas
			}
		/*}
		else {
			return false;
		}*/
		return possible(vec, n - 1);
	} 
	return false;
	
}

int main() {
	int N;
	while (cin>>N) {
		long long int ai;
		vector<long long int> vec;
		long long int sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> ai; //ai = grau do v�rtice
			vec.push_back(ai);
			sum += ai;
		}
		if (sum % 2 != 0) {
			cout << "impossivel" << endl;
			continue;
		}
		if (possible(vec, N)) {
			cout << "possivel" << endl;
		}
		else {
			cout << "impossivel" << endl;
		}
	}
}