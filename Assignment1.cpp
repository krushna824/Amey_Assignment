// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;

string reverse_words(string strInput)
{
	string strOutput = strInput;
	int nStart = 0;

	for (int i = 0 ; i <= strOutput.length(); ++i)
	{
		if (!isalpha(strOutput[i]) || i == strOutput.length())
		{
			int nLeft = nStart;
			int nRight = i - 1;

			while (nLeft < nRight)
			{
				if (isalpha(strOutput[nLeft]) && isalpha(strOutput[nRight]))
				{
					swap(strOutput[nLeft],strOutput[nRight]);
					nLeft++;
					nRight--;
				}
				else
				{
					if (!isalpha(strOutput[nLeft]))
					{
						nLeft++;
					}
					if (!isalpha(strOutput[nRight]))
					{
						nRight--;
					}
				}
			}
			nStart = i + 1;
		}
	}
	return strOutput;
}

int main()
{
	std::string test_str = "String; 2be reversed...";
	assert(reverse_words(test_str) == "gnirtS; 2eb desrever...");

	std::string test_str2 = "1234 678 45 $A$ #C#DDE";
	assert(reverse_words(test_str2) == "1234 678 45 $A$ #C#EDD");
	return 0;
}

