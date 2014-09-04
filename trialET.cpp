#include<bits/stdc++.h>
#include<random>
#include<chrono>

#define ui unsigned int
using namespace std;

int main()
    {
    
    ui n=100;//,d=5,m,l,s; 
  //  double epsi;
    
   // cout<<"Enter the number of Nodes (n) where n > 49 : "<<endl;
   cin>>n;
  //  assert(n>49);
    
   // cout<<"Enter the degree of each node (d) where d > 3 : "<<endl;
  //  cin>>d;
//    assert(d > 3);
    
//    cout<<"Enter the value of epsilon (epsi) where 0 < epsi < 1  : "<<endl;
   // cin>>epsi;
 //   assert(epsi>0 && epsi<1);
    
    
  //  cout<<"Enter the value to repeat the loop (s) where  s>=48/epsi : "<<endl;
  //  cin>>s;
  //  assert(s>=48/epsi);
    
    
  //  cout<<"Enter the no of random walks (m) where  m>=s*12*sqrt(n)/(epsi^2) : "<<endl;
  //  cin>>m;
 //   assert(m>=(s*12*sqrt(n)/pow(epsi,2)));
    
 //   cout<<"Enter the length of random walk (l) where  l>=16*(d^2)*ln(n/epsi) : "<<endl;
 //   cin>>l;
 //   assert(l>=(16*pow(d,2)*log(n/epsi)));
    
    
    /**************************************************************/
    /*     Generating Random Graph                                */     
    /*                                                            */      
    /**************************************************************/
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  
  std::default_random_engine generator (seed);

  std::uniform_int_distribution<ui> distribution(1,n);
    
    
      register vector<set <ui> > G(n+1);
    
    std::pair<std::set<ui>::iterator,bool> newno;
    
    for(unsigned int i=1;i<=n;++i)
        {
           // ui out=5,in=5;
            ui sizev = G[i].size();
        
            while(sizev < 5)
        {
            ui neighbour;
            neighbour = distribution(generator);
            if(neighbour != i)
                {
            
                if(G[neighbour].size() < 5)
                {
                     G[i].insert(neighbour);
            
                if(newno.second==true)
                    { 
                        G[neighbour].insert(i);
                        sizev++;
                    }
                }
       
            }
    }   
  }   
    for(ui i=1;i<=n;++i)
        {
        cout<<"Node "<<i<<": " ;
        for(set<ui>::iterator it = G[i].begin(); it != G[i].end();++it)
            {
                cout<<" "<<*it;
        }
        cout<<endl;
    }

    
    /**************************************************************/
    /*     Random Walks & Expansion Tester                        */     
    /*                                                            */      
    /**************************************************************/

        /*
    
    distribution.reset();
    
    ui s=50;
    while(s--)
        {
            ui v;
        v = distribution(generator);
        vector< ui> pairs1;
        
        for(ui m=1; m<=(sqrt(n)); ++m)
            {
                ui w=v;
            std::uniform_int_distribution<ui> dVertex (1,5);
            for(ui l=1; l<= log2(n);++l)
                {
                    
                  std::set<ui>::iterator rnode;
                  rnode=G[w].begin();    
                    
                    w = dVertex(generator);
            
                    while(w--)
                    {
                        rnode++;
                    }
                    
                    w=*rnode;
                    
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
    
    
    */
    
    return 0;
}
