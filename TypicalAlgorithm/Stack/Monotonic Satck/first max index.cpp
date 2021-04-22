//给一个数组，返回一个大小相同的数组。返回的数组的第i个位置的值应当是，对于原数组中的第i个元素，至少往右走多少步，才能遇到一个比自己大的元素

#include<vector>
#include<stack>
using namespace std;

vector<int> nextExceed(vector<int> &input) {
	vector<int> result (input.size(), -1);
	stack<int> monoStack;
	for(int i = 0; i < input.size(); ++i) {	
		while(!monoStack.empty() && input[monoStack.top()] < input[i]) {
			result[monoStack.top()] = i - monoStack.top();
			monoStack.pop();
		}
		monoStack.push(i);
	}
	return result;
}

