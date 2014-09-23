#include <bits/stdc++.h>
#include<chrono>
#include<random>

#define ui unsigned int

using namespace std;


int main()
{  
    /**************************************************************/
    /*     Generating Random Graph                                */     
    /*                                                            */      
    /**************************************************************/
    ui n=10000;
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  
  std::default_random_engine generator (seed);

  std::uniform_int_distribution<ui> distribution(1,n);
    
    
        vector<list <ui> > G(n+1);
    
    
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
           
            G[i].unique();
            G[n5].unique();
            G[n4].unique();
            G[n3].unique();
            G[n2].unique();
            G[n1].unique();
         
        
              if(G[i].size()<10 && G[n5].size()<10)  
            {
                G[i].push_back(n5);
                G[n5].push_back(i);
            }    
            
            G[i].unique();
            G[n5].unique();
           
              if(G[i].size()<10 && G[n4].size()<10)  
            {
                G[i].push_back(n4);
                G[n4].push_back(i);
            }    
            
            G[i].unique();
            G[n4].unique();
           
              if(G[i].size()<10 && G[n3].size()<10)  
            {
                G[i].push_back(n3);
                G[n3].push_back(i);
            }    
           
            G[i].unique();
            G[n3].unique();
            
              if(G[i].size()<10 && G[n2].size()<10)  
            {
                G[i].push_back(n2);
                G[n2].push_back(i);
            }    
            
            G[i].unique();
            G[n2].unique();
             
              if(G[i].size()<10 && G[n1].size()<10)  
            {
                G[i].push_back(n1);
                G[n1].push_back(i);
            }    
            
            G[i].unique();
            G[n1].unique();
        
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
    
    
        
    distribution.reset();
   
    ui s=50;
    
    /**************************************************************/
    /*     Testing Expander Graph                                 */     
    /*                                                            */      
    /**************************************************************/
    
    while(s--)
        {
            ui v;
        v = distribution(generator);
        
        vector< ui> pairs1;
        
        for(ui m=1; m<=(sqrt(n)); ++m)
            {
                ui w=v;
                
            std::uniform_int_distribution<ui> dVertex (1,10);
            
             for(ui l=1; l<= log2(n);++l)
                {
                    ui temp=w;
             
                    list<ui>::iterator it=G[temp].begin();   
                    
                    w = dVertex(generator);
                                 
                
                if(w<G[temp].size())
                    { 
                        while(w--)
                            it++;
                        
                        w=*it;                       
                       
                    }
                    
                    else
                        w=temp;
                    
            }  
            
            
            pairs1.push_back(w);
            
        } 
            sort(pairs1.begin(),pairs1.end());
                    
            ui collision= pairs1.size();
                
            vector<ui>::iterator it;
            
            it = unique (pairs1.begin(), pairs1.end());   
            
            pairs1.resize(distance(pairs1.begin(),it) ); 
    
            collision = collision- pairs1.size();
             if(collision < (((sqrt(n))*((sqrt(n))-1))/(2*n)))
                {cout<<"Reject"<<endl;return 0;}
             
        
    } 
        cout<<"Accept"<<endl;
    
    

return 0;
}
