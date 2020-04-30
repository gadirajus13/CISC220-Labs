#include <iostream>
#include <vector>
using namespace std;
//Sohan Gadiraju

int depthFirstSearch (vector<vector<int> > tree, int node, bool visit[], int& ans){
    visit[node] = true;
    int numNode = 0;

    for (int i = 0; i < tree[node].size(); i++) 
    { 
        int v = tree[node][i];
        if (!visit[v]) 
        { 
            int subtreeNodeCount = depthFirstSearch(tree, v, visit, ans); // Recursive call to count number of nodes in subtree
            if (subtreeNodeCount % 2 == 0){ 
                ans++; // If subtree has even nodes add 1 to removable nodes answer
            }    
            else{
                numNode += subtreeNodeCount; //If not we add subtree to rest of the count of Nodes
            } 
        }
    } 
    return numNode + 1;
}

int maxEdgesRemovable(vector<vector<int> > tree){
    bool visit[tree.size()-1];

    // Setting all booleans to false
    for (int i = 0; i < tree.size(); i++) {
        visit[i] = false; 
    }

    int ans = 0; // Passing as refrence so it can be modified
    depthFirstSearch(tree, 0, visit, ans);
    return ans;
}

int main(){
    vector<vector<int> > tree{  { 1, 2 },        // 0
                                {  },            // 1
                                { 3, 4 },        // 2
                                { 5, 6, 7 },     // 3
                                {  },            // 4
                                {  },            // 5
                                {  },            // 6
                                {  } };          // 7
    
    vector<vector<int> > tree2{  { 1, 2, 4 },    // 0
                                {  },            // 1
                                { 3 },           // 2
                                {  },            // 3
                                { 5 },           // 4
                                { 6, 7 },        // 5
                                {  },            // 6
                                {  } };          // 7

    for (int i = 0; i < tree.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < tree[i].size(); j++)
            cout << tree[i][j] << " ";cout << endl;
    }
    cout << "Max Edges Removable: " << maxEdgesRemovable(tree) << endl; 
    for (int i = 0; i < tree2.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < tree2[i].size(); j++)
            cout << tree2[i][j] << " ";cout << endl;
    }
    cout << "Max Edges Removable: " << maxEdgesRemovable(tree2) << endl; 

    return 0; 
}