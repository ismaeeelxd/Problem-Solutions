/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:

    int dfs(unordered_map<int, Employee*> &idToEmp, bool (&vis)[] , int id){
        vis[id] = 1;
        Employee* employee = idToEmp[id];
        int imp = 0;
        for(auto e : employee->subordinates){
            if(!vis[e]){
                imp+=dfs(idToEmp,vis,e);
            }
        }
        return imp + employee->importance;
    }

    int getImportance(vector<Employee*> employees, int id) {
        bool vis[2001]={0};

        unordered_map<int, Employee*> idToEmp;
        for (Employee* emp : employees) {
            idToEmp[emp->id] = emp;
        }

        return dfs(idToEmp,vis,id);
    }
};
