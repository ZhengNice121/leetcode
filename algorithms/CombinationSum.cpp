class Solution {
/*
The basic idea is deep first search. Treat each candidate as a direction to go to and treat its value as move cost, 
we need to find path which has a total cost equal to the target. The problem allows a candidate to be used mutiple 
times, so we can choose the same candidate at each step. Another thing is that the problem require unique paths, 
meaning [1,2] and [2,1] are same, a simple solution to avoid duplicates is "not looking back", which is choosing 
candidates that are after current one or the same as the current one, never before.
*/

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        
        if(!candidates.empty())
        {
            sort(candidates.begin(), candidates.end());
            DFS(candidates, 0, target, result, solution);
        }
        
        return result;
    }

/* DFS methods one
private:
    void DFS(vector<int>& candidates, int index, int target, vector<vector<int>> &result, vector<int> &solution)
    {
        if(index >= candidates.size())
            return;
        
        int temp = target - candidates[index];
        if(temp >= 0)
        {
            solution.push_back(candidates[index]);
            
            if(temp == 0)
            {
                result.push_back(solution);
            }
            else
            {
                DFS(candidates, index, temp, result, solution);
            }
            
            solution.pop_back();
        }
        
        DFS(candidates, index+1, target, result, solution);
    }
*/

private:
    void DFS(vector<int>& candidates, int begin, int target, vector<vector<int>> &result, vector<int> &solution)
    {
        if(target == 0)
        {    
            result.push_back(solution);
            return;
        }
        
        for(int i=begin; i<candidates.size(); i++)
        {
            if(target >= candidates[i])
            {
                solution.push_back(candidates[i]);
                DFS(candidates, i, target-candidates[i], result, solution);
                solution.pop_back();
            }
        }
        
    }
    
};