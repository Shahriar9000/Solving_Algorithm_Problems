#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;




void solution(string AS)
{
	char current_longest_char;
	int count = 1;
	int max_count = 0;
	char ch;
	for (int i = 0; i < AS.size(); ++i)
	{	

		ch = AS[i];
		
		if (ch == AS[i+1])
		{
			count++;
		}
		else
		{	
		
			if (count > max_count)
			{
				current_longest_char = ch;
				max_count = count;
			}
			
			count = 1;
		}

		
	}

	cout<< "[" << current_longest_char << " : " << max_count <<  "]" << endl;


}

vector<int> toIntVector(string str)
{
	std::vector<int> out;
	std::string i;
	std::istringstream tokenStream(str);
	while (std::getline(tokenStream, i, ','))
	{
		out.push_back(atoi(i.c_str()));
	}
	return out;
}

int main()
{
	// Read in from stdin, solve the problem, and write answer to stdout.

	string AS;
	cin >> AS;
	solution(AS);
}