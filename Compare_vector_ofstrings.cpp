#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void print_vector(std::vector<string> v)
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

vector<string> tostringvector(string str)
{
  vector<string> out;
  string i;
  istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(i);
  }
  return out;
}

int smallest_character_occurence(string str)
{
  char small_char = str[0];
  for (int i = 0; i < str.size(); ++i)
  {
    if (str[i] < small_char)
    {
      small_char = str[i];
    }
  }

  int count = 0;
  for (int i = 0; i < str.size(); ++i)
  {
    if (small_char == str[i])
    {
      count++;    }
  }

  return count;
}



vector<int> solution(string A, string B) 
{
    
  std::vector<string> A_string = tostringvector(A);
  std::vector<string> B_string = tostringvector(B);
  std::vector<int> C;
  // print_vector(A_string);
  // print_vector(B_string);
  for (int i = 0; i < B_string.size(); ++i)
  {
    int count = 0;
    for (int j = 0; j < A_string.size(); ++j)
    {
      if (smallest_character_occurence(A_string[j]) < smallest_character_occurence(B_string[i]))
      {
        count++;
      }
    }

    C.push_back(count);

  }

  return C; 
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
  // Read in from stdin, solve the problem, and write answer to stdout.
  string A, B;
  cin >> A >> B;
  cout << "["<<fromIntVector(solution(A, B)) << "]"<< endl;
}