#include<bits/stdc++.h>
#include<random>
#include<chrono>

#define ui unsigned int
using namespace std;

int main()
    {
    ui n;
    cin>>n;
    
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  
  std::default_random_engine generator (seed);

  std::uniform_int_distribution<int> distribution(1,n);
    
    
        vector<set <ui> > G(n+1);
    
    
    for(unsigned int i=1;i<=n;++i)
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
            
        G[i].insert(n1);
        G[i].insert(n2);
        G[i].insert(n3);
        G[i].insert(n4);
        G[i].insert(n5);
        
        G[n1].insert(i);
        G[n2].insert(i);
        G[n3].insert(i);
        G[n4].insert(i);
        G[n5].insert(i);
        
  }   
    for(ui i=1;i<=n;++i)
        {
        cout<<i<<": " ;
        for(set<ui> :: iterator it = G[i].begin(); it != G[i].end();++it)
            {
                cout<<" "<<*it;
        }
        cout<<endl;
    }
    return 0;
}
