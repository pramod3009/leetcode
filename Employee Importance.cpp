/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int bfs(map<int, Employee*> &m, int id){
        map<int,int> v;
        queue<int> q;
        q.push(id);
        int value = 0;
        while(not q.empty()){
            int e = q.front();
            q.pop();
            value+=m[e]->importance;
            v[e] = 1;
            vector<int> neighbours = m[e]->subordinates;
            
            for(int a:neighbours){
                if(v.find(a) == v.end()){
                    q.push(a);
                }
            }
        }
        return value;
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        if(not employees.size()){
            return 0;
        }
        map<int, Employee*> m;
        for(int i =0 ; i < employees.size();i++){
            m[employees[i]->id] = employees[i];
        }
        return bfs(m, id);
        
    }
};