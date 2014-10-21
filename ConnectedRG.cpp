#include <bits/stdc++.h>
#include<chrono>
#include<random>

typedef unsigned long long ui;

using namespace std;


int main()
{  
    /**************************************************************/
    /*     Generating Random Graph                                */     
    /*                                                            */      
    /**************************************************************/
    ui n=500;
	cout<<"Enter no of nodes: "<<endl;
	cin>>n;
	
	ui d=2;
	cout<<"Enter minimum Degree of each Node: "<<endl;
	cin>>d;
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  
  std::default_random_engine generator (seed);

  std::uniform_int_distribution<ui> distribution(1,n);
    
    
        vector<vector <ui> > G(n+1);
    
    
    for(ui i=1;i<=n;++i)
        {
			
				ui neighbour = distribution(generator);
				if(G[i].size()<2*d && G[neighbour].size()<2*d && (find(G[i].begin(), G[i].end(), neighbour)==G[i].end()))  
				{
					G[i].push_back(neighbour);
					G[neighbour].push_back(i);
				}    
				
				if(G[i].size()< d){
					--i;
				}
    }   
    for(ui i=1;i<=n;++i)
        {
        cout<<"Node "<<i<<": " ;
        for(auto it = G[i].begin(); it != G[i].end();++it)
            {
               cout<<" "<<*it;
        }
       cout<<endl;
    }
    
    /**************************************************************/
    /*     Testing Connectivity  of Graph                         */     
    /*     Using BFS                                              */      
    /**************************************************************/
    
    vector<bool> visited (n+1,false);
    visited[0] = true;
    visited[1] = true;
    queue<ui> q;
    q.push(1);
    while(!q.empty()){
        ui temp = q.front();
        for(ui i=0; i< G[temp].size(); ++i){
            if(!visited[G[temp][i]])
            q.push(G[temp][i]);
            visited[G[temp][i]] = true;
        }
        q.pop();
    }
    if(find(visited.begin(),visited.end(),false) == visited.end())    
        cout<<"Connected"<<endl;
    else
        cout<<"Multiple Components"<<endl;
   /* 
    for(int i=0; i<visited.size(); ++i){
        cout<<"visited["<<i<<"]: "<<visited[i]<<" "<<endl;
    }*/
return 0;
}
