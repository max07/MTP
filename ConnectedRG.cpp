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

    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  
  std::default_random_engine generator (seed);

  std::uniform_int_distribution<ui> distribution(1,n);
    
    
        vector<vector <ui> > G(n+1);
    
    
    for(ui i=1;i<=n;++i)
        {
        ui n1=0,n2=0,n3=0,n4=0,n5=0;
    while(n1==n2)
        {
        while(n2==n3)
            {
            while(n3==n4)
                {
                while(n4==n5)
                    {
                    while(n5==i || n5==0)
                        {
                        n5=distribution(generator);
                    }
                    n4=distribution(generator);
                }        
                n3=distribution(generator);
            }
            n2=distribution(generator);
        }
        n1=distribution(generator);
    }
           
            
              if(G[i].size()<10 && G[n5].size()<10 && (find(G[i].begin(), G[i].end(), n5)==G[i].end()))  
            {
                G[i].push_back(n5);
                G[n5].push_back(i);
            }    
            
              if(G[i].size()<10 && G[n4].size()<10 && (find(G[i].begin(), G[i].end(), n4)==G[i].end()))  
            {
                G[i].push_back(n4);
                G[n4].push_back(i);
            }    
            
              if(G[i].size()<10 && G[n3].size()<10 && (find(G[i].begin(), G[i].end(), n3)==G[i].end()))  
            {
                G[i].push_back(n3);
                G[n3].push_back(i);
            }    
           
              if(G[i].size()<10 && G[n2].size()<10 && (find(G[i].begin(), G[i].end(), n2)==G[i].end()))  
            {
                G[i].push_back(n2);
                G[n2].push_back(i);
            }    
             
              if(G[i].size()<10 && G[n1].size()<10 && (find(G[i].begin(), G[i].end(), n1)==G[i].end()))  
            {
                G[i].push_back(n1);
                G[n1].push_back(i);
            }    
                    
            if(G[i].size()<5)
                  i--;
            
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
    
    for(int i=0; i<visited.size(); ++i){
        cout<<"visited["<<i<<"]: "<<visited[i]<<" "<<endl;
    }
return 0;
}
