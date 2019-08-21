#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


std::vector<std::vector<int> > set;

void find_diff(std::vector<int> A, std::vector<int> subset ,int n, int i)
{
  if (i == n)
  {
    int sum = 0;
    
    
    for (int j = 0; j < subset.size(); ++j)
    {
      sum = sum + subset[j];
    }


    if (sum == 10)
    {
    	set.push_back(subset);
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

  for (int i = 0; i < set.size(); ++i)
  {
    cout << "{";
    for (int j = 0; j < set[i].size(); ++j)
    {

      cout << set[i][j];
      if (j < set[i].size()-1)
      {
        cout << ",";
      }
    }

    cout << "}" <<endl;

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