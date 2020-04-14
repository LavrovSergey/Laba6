#include <iostream>
#include <fstream>
using namespace std;

void fill_the_matrix(int n, int**m) {
	int a;
	int b;
	ifstream f("txt.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> a;
			if (a==0) { m[i][j]=0; cout << m[i][j] << " ";
			}
			else if (a == 1) { m[i][j] = 1; cout << m[i][j] << " ";
			}
			
		}
	}
}

void dfs(int s, int** m, bool*used, int n) {
	used[s] = 1;
	for (int i = 0; i < n; i++) {
		if (used[i] == 0 && m[s][i] == 1)
			dfs(i, m, used, n);
	}
}

int main()
{
	char a=' ';
	int n=0;
	ifstream f("txt.txt");
	while (a != '\n') {  f.get(a); if (isdigit(a)) n++; }
	f.close();
	int** m = new int* [n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n];
	}
	bool *used=new bool[n]{};
	int count = 0;
	fill_the_matrix(n, m);
	

	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			dfs(i, m, used, n);
			count++;
		}
	}

	cout <<"There are "<< count << endl;

	return 0;
}