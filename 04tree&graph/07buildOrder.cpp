// https://godbolt.org/z/rxKxK6a81

// similar: https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>

using namespace std;
/*
build order:

1.Question: given a set of projects, 
         and their dependency(proj1, proj2),which means p2 depend on p1.
         Implement an algo to build the order for these projects.
         all projects should be built after all its dependencies.
2. example:
        // my input :project and dependency lists
        project list-->vec[]: {a b c d e f}
        dependencies[][]:{[a,b],[f,b],[b,d],[f,a],[d,c]};
        // my output should be : a list of built_order project list
        output[]
3. approach:

        --->for each projects: build an adjcency list
        --->and for each project: build a indegree list, means the number of pre-projects

        1）. build the order from 0 indegree project and then search its adj list.
            ---->    use a queue to store the 0 indegree project
        2) // BFS topology sort        
        2). remove the 0 indegree project after queue.
        3). if all projects are used up(cnt), then we build a correct order,
            otherwise, return error.

*/

vector<char> projectOrder(vector<char> &projects,vector<vector<char>> &dependencies){
    vector<char> res;
    // num of projects
    int numP = projects.size();
    // adj and indegree list
    vector<vector<char>> adjList(numP);
    unordered_map<char, int> indegree(numP);

    // !!!! Initialize indegree for all projects
    // note here: miss here , we may miss the 
    for (char p : projects) {
        indegree[p] = 0;
    }

    for(auto &pre : dependencies){
        // char preProject = pre[0];
        // char nextProject = pre[1];
        // adjList[preProject].push_back(nextProject);
        // indegree[nextProject]++;
        indegree[pre[1]] ++;
        adjList[pre[0]].push_back(pre[1]);
    }

    queue<char> q;
    // enqueue all 0 indegree projects
    for(auto &pair: indegree){
        if(pair.second == 0){
            q.push(pair.first);
        }
    }

    
    //BFS traverse, topology sort
    while(!q.empty()){
        char curP = q.front();
        q.pop();
        numP--;

        for(auto adj : adjList[curP]){
            indegree[adj]--;
            if(indegree[adj] == 0){
                q.push(adj);
            }
        }
        res.push_back(curP);
    
    }

    // Check if we used up all projects
    if ( numP-- != 0) {
        cout << "Error: There is a cycle in the graph or some projects are not reachable" << endl;
        return {};
    }
   
    return res;

}

int main(){
    vector<char> projects = {'a', 'b' ,'c','d' ,'e' ,'f'};

    vector<vector<char>> dependencies={
        {'a','d'},
        {'f','b'},
        {'b','d'},
        {'f','a'},
        {'d','c'}
    };

    cout << "The build order is :\n";


   vector<char> res =  projectOrder(projects, dependencies);

   for(auto p : res){
    cout << p << ", ";
   } 
   
    return 0;
}



