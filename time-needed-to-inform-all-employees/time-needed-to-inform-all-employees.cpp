class Solution {
 	void dfs(unordered_map<int, vector<int>>&hm, int i, vector<int>& informTime, int &res, int curr) {

 		curr += informTime[i];
 		res = max(res, curr);

 		for (auto it = hm[i].begin(); it != hm[i].end(); it++)
 			dfs(hm, *it, informTime, res, curr);
 	}
 public:
 	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

 		unordered_map<int, vector<int>>hm;
 		for (int i = 0; i < n; i++)
 			if (manager[i] != -1) hm[manager[i]].push_back(i);

 		int res = 0, curr = 0;
 		dfs(hm, headID, informTime, res, curr);
 		return res;
 	}
 };