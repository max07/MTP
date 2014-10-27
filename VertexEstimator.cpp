/* Vertex Estimator */
#include <bits/stdc++.h>
#include<chrono>
#include<random>

typedef unsigned long long ui;

using namespace std;


int main(int argc, char* argv[])
{  
	ui n;
	ui d;
	vector<vector<ui> > G;
	if ( argc != 5 ) /* argc should be 4 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s <number_of_nodes> <min_degree> <input_graph> <output_file>", argv[0] );
    }
	else 
    {
        // argv[3] is a filename to open
        ifstream file(argv[3]);

        if (file.is_open()){	
			n = argv[1];
			d = argv[2];
			G.resize(1);	
            string ngbr;
		   while(getline(file, ngbr)){
				vector<ui> nodes;
				stringstream  linestream(ngbr);
				ui value;
				while(lineStream >> value){
					 nodes.push_back(value);
				}
				G.push_back(nodes);
			}
			file.close();
		}		

		else{
			cout << "Unable to open file\n";
			return 0;
		}
        }
    }

     
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  
  std::default_random_engine generator (seed);

  std::uniform_int_distribution<ui> distribution(1,n);    
	
	double u = 1;
    double phi = 0.5;
    /**************************************************************/
    /*     Vertex Testser                                         */     
    /*                                                            */      
    /**************************************************************/
    
        ui v;
        v = distribution(generator);
        
        vector<ui> pairs1;
        bool accept = false;
    
        while(!accept){
		for(ui loop = 0; loop<20; ++loop){
			for(ui m=1; m<=8*pow(n,(1+u)/2); ++m){
                ui w=v;
                
				std::uniform_int_distribution<ui> dVertex (1,2*d);
            
				for(ui l=1; l<= ((2*logn)/pow(phi,2));++l){
					ui temp=w;
             
					w = dVertex(generator);
                
					if (w < G[temp].size())
						w = G[temp][w];    
					else
						w=temp;
				}  
            
				pairs1.push_back(w);
            
			} 
			sort(pairs1.begin(),pairs1.end());
                    
            ui collisions= pairs1.size();
                
            vector<ui>::iterator it;
            
            it = unique (pairs1.begin(), pairs1.end());   
            
            pairs1.resize(distance(pairs1.begin(),it) ); 
    
            collisions = collisions- pairs1.size();
    
            if( collisions >= ((m*(m-1)*(1+2*pow(n,(-u)/4))/(2*n)))){
               cout<<"Reject"<<endl;
			   phi = phi - (phi/2);
            }
			else{
				cout<<"Accept"<<endl;
				phi = phi + (phi/2);
			}
		}
		
		accept = true;	
     }
return 0;
}
