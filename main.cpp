#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
	int findLucky(vector<int>& arr) {
		int res = -1;
		int counter = 0;
		int maxElement = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] > maxElement)
				maxElement = arr[i];
		}
		for (int i = (arr.size() -1); i > -1; i--)
		{
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] == maxElement)
					counter++;
			}
			if (maxElement == counter) {
				res = maxElement;
				break;
			}
			else {
				maxElement = maxElement - 1;
				counter = 0;
			}
		}
		return res;
	}
};

int main() {
	vector<int> items;
	int item;
	string line;
	getline(cin, line);
	istringstream is(line);
	while (is >> item) {
		items.push_back(item);
	}
	Solution solution;
	cout << solution.findLucky(items);
	return 0;
}