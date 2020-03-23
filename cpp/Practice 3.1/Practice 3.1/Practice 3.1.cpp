#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

int func(string str)
{
	int maxSize = 0;
	int i = 0;
	while (str[i])
	{
		int size = 0, count = 0, j = i;

		while ((str[j] != ' ') || (j != str.length() - 1)) { size++; j++; cout << j << endl; }

		j = i;
		for (int k = j + size; j < k - 1; j++)
			if ((((int)str[j + 1] - (int)str[j]) == 1) || (((int)str[j + 1] - (int)str[j]) == -1)) count++;
			else break;

		if (count == size) maxSize += 1;
		else maxSize = 0; //incorrect

		i+=size - 1;

		cout << i << endl;
	}
	return maxSize;
}

int main()
{
	string str;
	getline(cin, str);
	cout << str << endl;

	int maxSize = func(str);

	if (maxSize) cout << maxSize << endl;
	else cout << "NO" << endl;

	return 0;
};