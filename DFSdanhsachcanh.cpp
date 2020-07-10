#include<bits/stdc++.h>
using namespace std;
int a[1001], check[1001],truoc[1001];
int n,m,u,s,t,g;
void DFS(int u,vector <int> v[]){
	stack <int> q;
	q.push(u);
	check[u]=1;
	while(!q.empty()){
		int tmp=q.top();
		q.pop();
		for(int i=0;i<v[tmp].size();i++){
			if(check[v[tmp][i]]==0){
				check[v[tmp][i]]=1;
				truoc[v[tmp][i]]=tmp;
				q.push(tmp);
				q.push(v[tmp][i]);
				break;
			}
		}
	}
}
main(){
	memset(check,0,sizeof(check));
	memset(truoc,-1,sizeof(truoc));
	vector <int> v[1001];
	cout<<"nhap so dinh: ";cin>>n;
	cout<<"nhap so canh: ";cin>>m;
	cout<<"nhap dinh bat dau: ";cin>>s;
	cout<<"nhap dinh ket thuc: ";cin>>g;
	int t1,t2;
	cout<<"nhap vao danh sách canh:"<<endl;
	for(int i=1;i<=m;i++){
		cin>>t1>>t2;
		v[t1].push_back(t2);
	}
	DFS(s,v);
	if(truoc[g]==-1) cout<<"Khong co duong di!";
	else{
		cout<<"duong di là ";
		vector <int> res;
		res.push_back(g);
		while(g!=s){
			g=truoc[g];
			res.push_back(g);
		}
		while(!res.empty()){
			cout<<res.back()<<" ";
			res.pop_back();
	}
	}
}
