#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int max_ = -100;
vector <int> max_sub_arr;

bool if_sub_array(std::vector<int> A, std::vector<int> sub_array)
{
	bool ret = false;
	int x = sub_array[0];
	int i = 0;
	for (; i < A.size(); i++)
	{
		if (x == A[i])
		{
			break;
		}
	}

	for (int j = 0; j < sub_array.size(); ++j)
	{
		if (sub_array[j] == A[i])
		{
			ret = true;      
		}
		else
		{
			ret = false;
			break ;
		}
	}

	return ret;

}


void find_diff(std::vector<int> A, std::vector<int> subset ,int n, int i)
{
	if (i == n)
	{


		if (if_sub_array(A, subset))
		{
			int sum = 0;
			for (int j = 0; j < subset.size(); ++j)
			{
				sum = sum + subset[j];
			}
			if (max_ <= sum)
			{
				max_ = sum;
				max_sub_arr = subset;
				
			}
		}

	}
	else
	{


		find_diff(A, subset, n, i+1);
		subset.push_back(A[i]);
		find_diff(A, subset, n, i+1);


	}

}


void solution(vector<int> A)
{
	int n = A.size();

 
	std::vector<int> empty;
	find_diff (A, empty, n, 0);

	
		cout << "{";
		for (int j = 0; j < max_sub_arr.size(); ++j)
		{

			cout << max_sub_arr[j];
			if (j < max_sub_arr.size()-1)
			{
				cout << ",";
			}
		}

		cout << "}" <<endl;

	


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