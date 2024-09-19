#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, queue<int>& q, vector<int>& answer, vector<bool>& visited){
	q.push(0);

	
	while(!q.empty()){
		int top = q.front();
		
		q.pop();
		answer.push_back(top);
		
		for(auto it: graph[top]){
			if(!visited[it]){
				q.push(it);
				visited[it] = true;
			}
			
		}
		
	}

}

void print(vector<char> nodes, vector<int> answer){
	for(int i = 0; i<answer.size(); i++){
		cout<<nodes[answer[i]]<<endl;
	}
}

int main(){
	queue<int> q;
	// vector<vector<int>> graph; this will give segmentation fault
	// 1. When you declare vector<int> v;, it’s an empty vector that can grow as you push_back() elements.
	// 2. Similarly, vector<vector<int>> graph; is an empty vector of vectors that can grow when you add sub-vectors, but it initially has no elements.
	// In your case, you're accessing specific indices like graph[0], graph[1], etc., directly. This requires those indices to exist.
	// If you don't initialize the graph with some size (e.g., vector<vector<int>> graph(5);), the vector starts off empty. Trying to access graph[0] or graph[1] will result in an out-of-bounds error because no sub-vectors have been added yet.
	vector<vector<int>> graph(5);
	vector<char> nodes;
	vector<int> answer;
	vector<bool> visited(5, false);
	// This is how you make an alphabet array
	for(char i = 'a'; i<='z'; i++){
		nodes.push_back(i);
	}

	graph[0] = {1,2};
	graph[1] = {2,3};
	graph[2] = {};
	graph[3] = {4};
	graph[4] = {};

	// other way that does not need to mention the size of the vector
	// graph.push_back({1, 2});    // This adds a vector {1, 2} to graph[0]
	// graph.push_back({2, 3});  

	bfs(graph, q, answer, visited);
	print(nodes, answer);
}

