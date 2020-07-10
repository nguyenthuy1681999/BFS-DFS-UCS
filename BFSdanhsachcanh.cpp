#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int visit[1005];
int truoc[1005];
int n,m,u,v;
void BFS(int u,int v){
    queue<int> q;
    q.push(u);
    visit[u]=1;
    while(!q.empty()){
        int t=q.front();q.pop();
        if(t==v) return;
        for(int i=1;i<=n;i++){
            if(a[t][i] && visit[i]==0){
                visit[i]=1;
                truoc[i]=t;
                q.push(t);
                q.push(i);
            }
        }
    }
}
void DuongDi(int u,int v){
    if(!visit[v]){
        cout<<"khong co duong di"<<endl;
    }
    else{
    	cout<< "duong di la: ";
        vector<int>dd;
        while(v!=u){
            dd.push_back(v);
            v=truoc[v];
        }
        dd.push_back(u);
        reverse(dd.begin(),dd.end());
        for(int i=0;i<dd.size();i++){
            cout<<dd[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    memset(a,0,sizeof(a));
    memset(truoc,0,sizeof(truoc));
    memset(visit,0,sizeof(visit));
	cout<<"nhap so dinh: ";cin>>n;
	cout<<"nhap so canh: ";cin>>m;
	cout<<"nhap dinh bat dau: ";cin>>u;
	cout<<"nhap dinh ket thuc: ";cin>>v;
    int p,q,i;
    for(i=0;i<m;i++){
        cin>>p>>q;
        a[p][q]=a[q][p]=1;
    }
    BFS(u,v);
    DuongDi(u,v);
}
