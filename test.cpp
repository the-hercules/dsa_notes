#include <bits/stdc++.h>

using namespace std;

int calculate_sum_of_shifted_elements(vector<int>& list1) {
  // Sort the list in ascending order.
  sort(list1.begin(), list1.end());

  // Create a map to store the original index of each element in the unsorted list.
  unordered_map<int, int> index_map;
  for (int i = 0; i < list1.size(); ++i) {
    index_map[list1[i]] = i;
  }

  // Calculate the sum of (element*position it shifted) for each element in the sorted list.
  int sum = 0;
  for (int i = 0; i < list1.size(); ++i) {
    int original_index = index_map[list1[i]];
    int position_in_sorted_array = abs(i - original_index);
    sum += list1[i] * position_in_sorted_array;
  }

  return sum;
}

int main() {
  vector<int> list1 = {3, 5, 1, 4, 2};
  int sum=0;
  int sum = calculate_sum_of_shifted_elements(list1);
  cout << sum << endl;

  return 0;
}