#include<iostream>

using namespace std;

int main(void)
{
	int t, n, m;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> m;
		char* str1 = new char[n];
		char* str2 = new char[m];
		for (int j = 0; j < n; j++)
		{
			cin >> str1[j];
		}
		for (int k = 0; k < m; k++)
		{
			cin >> str2[k];
		}

		//getNext
		int* next = new int[n];
		next[0] = -1;
		int j = 0;
		int k = -1;

		while (j < n)
		{
			if (k == -1 || str1[k] == str1[j])
			{
				next[++j] = ++k;
			}
			else
			{
				k = next[k];
			}
		}

		//match
		int count = 0;
		for (int g = 0; g < m; g++)
		{
			j = g;
			int h = 0;
			while (h < n&&j < m)
			{
				if (j < g || str1[h] == str2[j])
				{
					h++;
					j++;
					if (j - g > count)count = j - g;
				}
				else
				{
					j = g + next[j - g];
					if (j - g > count)count = j - g;
				}
			}
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}