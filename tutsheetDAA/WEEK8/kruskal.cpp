#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int cost; 
    node(int first, int second, int price) {
        u = first;
        v = second;
        cost = price;
    }
};

bool comp(node a, node b) {
    return a.cost < b.cost; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N,m;
	cin >> N >> m;
	vector<node> roads; 
	for(int i = 0;i<m;i++) {
	    int u, v, cost;
	    cin >> u >> v >> cost; 
	    roads.push_back(node(u, v, cost)); 
	}
	sort(roads.begin(), roads.end(), comp); 
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
	
	int costP = 0;
	vector<pair<int,int>> mst; 
	for(auto it : roads) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        costP += it.cost; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << costP << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}