//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
  int left = 0;
  int right = nums.size() - 1;
  int idx = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      idx = mid;
      if (isSearchingLeft) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }

  return idx;
}

vector<int> searchRange(vector<int>& nums, int target) {
  vector<int> result = {-1, -1};
  int left = binarySearch(nums, target, true);
  int right = binarySearch(nums, target, false);
  result[0] = left;
  result[1] = right;
  return result;
}

int main() {
  int size;
  cout << "Enter the size of the vector: ";
  cin >> size;

  vector<int> nums(size);
  cout << "Enter the elements of the vector (space separated): ";
  for (int i = 0; i < size; ++i) {
    cin >> nums[i];
  }

  int target;
  cout << "Enter the target value to search: ";
  cin >> target;

  vector<int> range = searchRange(nums, target);

  if (range[0] == -1) {
    cout << "Target not found in the vector." << endl;
  } else {
    cout << "Target found in range [" << range[0] << ", " << range[1] << "]" << endl;
  }

  return 0;
}
