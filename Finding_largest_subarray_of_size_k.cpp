#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int> > set;

bool isSubArray(vector<int> A, vector<int> subset)
{
  int index = -1;
  std::vector<int>::iterator it = std::find(A.begin(), A.end(), subset[0]);
  if (it != A.end())
    index = std::distance(A.begin(), it);
  
  if (index != -1)
  {
    for (int i = 0; i < subset.size(); i++)
    {
      if (subset[i] != A[index])
        return false;
      index++;
    }
    return true;
  }
  else 
    return false;

}

void find_diff(std::vector<int> A, std::vector<int> subset , int n, int i, int K)
{
  if (i == n)
  {
    if (subset.size() == K)
    {
      if (isSubArray(A, subset))
      {
        set.push_back(subset);
      }
    }
  }
  else
  {
    find_diff(A, subset, n, i+1, K);
    subset.push_back(A[i]);
    find_diff(A, subset, n, i+1, K);
  }
}

vector<int> findLargestSubArray(vector<int> x, vector<int> y)
{
  vector<int> maximum = x;
  for (int i = 0; i < x.size(); ++i)
  {
    if (x[i] != y[i])
    {
      if (x[i] > y[i])
      {
        maximum = x;
      }
      else
      {
        maximum = y;
      }
    }

  }
  return maximum;
}

vector<int> LargestSubArray()
{
  int index = -1;
  vector<int> maximum = set[0];
  
  for (int j = 0; j < set.size(); j++)
  {
    maximum = findLargestSubArray(maximum, set[j]);
  }

  return maximum;
    
}

vector<int> solution(vector<int> N, int K) 
{
  // Your solution goes here.

  int n = N.size();
 
  std::vector<int> empty;
  find_diff (N, empty, n, 0, K);

  return LargestSubArray();

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

string fromIntVector(vector<int> arr)
{
  string out = "";
  for (int i=0; i<arr.size(); i++) {
    out += to_string(arr[i]);
    if (i != arr.size() - 1) {
      out += ",";
    }
  }
  return out;
}

int main()
{
  // Read from stdin, solve the problem, write answer to stdout.
  string arrS;
  int K;
  cin >> arrS >> K;
  vector<int> N = toIntVector(arrS);
  cout << fromIntVector(solution(N, K));

  //solution(N, K);
}
