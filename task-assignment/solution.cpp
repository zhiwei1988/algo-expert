#include <vector>
using namespace std;

typedef struct {
	int value;
	int index;
} Task_S;

// 解题思路：
// 以 task 的耗时按升序排序
// 耗时最长的任务和耗时最短的任务组合，总的耗时最短
vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
  vector<vector<int>> results;
	vector<Task_S> taskHelps;
	for (int i = 0; i < tasks.size(); i++) {
		Task_S taskHelp {};
		taskHelp.value = tasks[i];
		taskHelp.index = i;
		taskHelps.push_back(taskHelp);
	}
	
	std::sort(taskHelps.begin(), taskHelps.end(), [] (auto left, auto right) {
		return left.value < right.value;
	});
	
	int left = 0;
	int right = taskHelps.size() - 1;
	while (left < right) {
		vector<int> result;
		result.push_back(taskHelps[left].index);
		result.push_back(taskHelps[right].index);
		results.push_back(result);
		left++;
		right--;
	}
  return results;
}
