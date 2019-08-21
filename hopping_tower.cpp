#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> actual_path;


bool is_hoppable(vector<int> A, int index, int dest)
{
	if (dest >= A.size())
	{
		return true;
	}
	else if (A[index] == 0)
	{
		return false;
	}
	else
	{
		for (int i = 1; i <= A[index]; ++i)
		{
			if (is_hoppable(A, i+index, i+dest))
			{
				return true;
			}
			
			
		}
	}

}


void solution(vector<int> A)
{
	if (is_hoppable(A, 0, 0))
	{
		cout << "You can hop your way out" <<endl;
	}
	else
	{
		cout << "Not hoppable sorry" << endl;
	}
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
	solution(toIntVector(AS));
}