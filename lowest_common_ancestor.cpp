#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> actual_path;

void print_path(std::vector<int> v)
{
	cout << "{";
	for (int j = 0; j < v.size(); ++j)
	{

		cout << v[j];
		if (j < v.size()-1)
		{
			cout << ",";
		}
	}

	cout << "}" <<endl;

}

void find_path(vector<int> A, std::vector<int> current_path, int target, int index)
{
	if (index < A.size())
	{
		if (A[index] == target)
		{	

			current_path.push_back(A[index]);
			actual_path = current_path;


		}
		else
		{
			current_path.push_back(A[index]);

			find_path(A, current_path, target, (2*index)+1);
			find_path(A, current_path, target, (2*index)+2);

		}
	}
}


void solution(vector<int> A, int target1, int target2)
{
	std::vector<int> empty;
	find_path(A, empty, target1, 0);
	print_path(actual_path);
	std::vector<int> target1_path = actual_path;
	find_path(A, empty, target2, 0);
	print_path(actual_path);
	std::vector<int> target2_path = actual_path;


	std::vector<int> smaller_path;
	std::vector<int> larger_path;

	if (target1_path.size() < target2_path.size())
	{
		smaller_path = target1_path;
		larger_path = target2_path;
	}
	else
	{
		smaller_path = target2_path;
		larger_path = target1_path;
	}

	int i = 0;
	int lca = 0;
	while ( i < smaller_path.size())
	{
		if (smaller_path[i] != larger_path[i])
		{
			lca = smaller_path[i-1];
			break;
		}

		i++;
	}

	if (i >= smaller_path.size())
	{
		cout << "NO common ancestor" << endl;
	}
	else
	{
		cout << "Lowest common ancestor is " << lca << endl;
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
	int target1, target2;
	cout << "target1: ";
	cin >> target1;
	cout << endl;
	cout << "target2: ";
	cin >> target2;
	cout << endl;
	solution(toIntVector(AS), target1, target2);
}