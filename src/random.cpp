#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <string>

using namespace std;

class Solution {
public:
  Solution();
  array<int, 7> pick_lotto_numbers();
  array<int, 7> pick_joker_numbers();
  int pick_a_random_postion(vector<int>);
  string array_to_string(array<int, 7> a);
private:
};

Solution::Solution(){}

array<int, 7> Solution::pick_lotto_numbers() {
  array<int, 7> row;
  vector<int> pot =  { { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 } };

  for (int i = 0; i != 7; ++i)
  {
      int pos = pick_a_random_postion(pot);
      row[i] = pot.at(pos);
      pot.erase(pot.begin() + pos);
  }
  sort(row.begin(), row.end());
  return row;
}

array<int, 7> Solution::pick_joker_numbers() {
  array<int, 7> a;
  random_device rnd;
  uniform_int_distribution<int> d(0, 9);

  for (int i = 0; i != 7; ++i)
  {
    a[i] = d(rnd);
  }

  return a;
}

int Solution::pick_a_random_postion(vector<int> v)
{
  random_device rnd;
  uniform_int_distribution<int> d(0,v.size() - 1);
  return d(rnd);
}

string Solution::array_to_string(array<int, 7> a){
  string s;
  for (auto item : a)
  {
    if (item < 10)
    {
      s += " " + to_string(item) + " ";
    } else {
      s += to_string(item) + " ";
    }
  }
  return s;
}

int main() {
  Solution solution;
  array<int, 7> a1 = solution.pick_lotto_numbers();
  array<int, 7> a2 = solution.pick_lotto_numbers();
  array<int, 7> a3 = solution.pick_lotto_numbers();
  array<int, 7> j  = solution.pick_joker_numbers();

  cout << "rad 1: " << solution.array_to_string(a1) << endl;
  cout << "rad 2: " << solution.array_to_string(a2) << endl;
  cout << "rad 3: " << solution.array_to_string(a3) << endl;

  cout << "joker: " << solution.array_to_string(j) << endl;
  return 0;
}
