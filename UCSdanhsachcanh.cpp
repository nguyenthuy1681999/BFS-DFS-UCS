#include <iostream>
#include <vector>
#include <list>
#include <queue>         
#include <algorithm>
#include<stdlib.h>

using namespace std;
struct pQ
{
	list<int> path;
	int cost;
	bool operator>(const pQ& rhs) const
	{
		return cost > rhs.cost;
	}
};

class mycomparison
{
public:
	bool operator() (pQ p1, pQ p2) const
	{
		return (p1>p2);
	}
};

class Graph
{
	int V;
	vector<int> *adj;
	vector<int> *wgt;
public:
	Graph(int V);
	void addEdge(int v, int w, int wgt);
	void UCS(int s, int t);
	void displayPath(struct pQ f);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V];
	wgt = new vector<int>[V];
}

void Graph::addEdge(int v, int w, int wt) {
	adj[v].push_back(w);
	wgt[v].push_back(wt);
}

void Graph::UCS(int s, int t)
{
	int current=0, pos=0;
	typedef priority_queue<pQ,vector<pQ>,mycomparison> mypq_type;
	mypq_type pq;

	pQ vstart;

	vstart.path.push_back(s);
	vstart.cost = 0;

	vector<int>::iterator i;
	pq.push(vstart);

	while(!pq.empty())
	{
		pQ currentPQ, tempPQ;
		current = pq.top().path.back();
		currentPQ = pq.top();
		pq.pop();
		if(current == t)
		{
			displayPath(currentPQ);
			exit(0);
		}
		else{
			for (i = adj[current].begin(); i != adj[current].end(); ++i)
			{
				tempPQ = currentPQ;
				tempPQ.path.push_back(*i);
				pos = find(adj[current].begin(), adj[current].end(), *i) - adj[current].begin();
				tempPQ.cost += wgt[current].at(pos);
				pq.push(tempPQ);
			}
		}
	}
}

void Graph::displayPath(struct pQ p)
{
  list<int>::iterator i;
	cout<<"Duong di: ";
  for (i = p.path.begin(); i != p.path.end(); ++i)
  {
    cout<<"->"<<*i;
  }
	cout<<endl;
  cout<<"Chi phi: "<<p.cost;
}

int main()
{
	int n,e, a, b, c;
	int vstart, vend;
	cout<<"Nhap so dinh: ";
	cin>>n;
	cout<<"Nhap so canh: ";
	cin>>e;
	Graph g(e);
	cout<<"Nhap danh sach canh: ";
	for(int i = 0 ; i < e; i++)
	{
		cin>>a>>b>>c;
		g.addEdge(a, b, c);
	}
	cout<<"Nhap dinh start: ";
	cin>>vstart;
	cout<<"Nhap dinh goal : ";
	cin>>vend;

	g.UCS(vstart, vend);
	return 0;
}


