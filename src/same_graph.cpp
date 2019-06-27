#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);

    ofstream output;
    
    int density,n_digits;
    long long int vertex;
    ostringstream name;
    string file_name;

    vertex = atoi(argv[1]);
    if(vertex != 1000 && vertex != 10000) return 0;

    long long int n_edges = vertex*(vertex-1)/2;

    srand (time(NULL));
    
    vector<vector<long long int> > edges(n_edges,vector<long long int>(3));

    for(n_digits = 1; n_digits <= 15; n_digits++){
        long long int e = 0;
        for(long long int i = 1; i < vertex; i++){
            for(long long int j = 0; j < i; j++){
                edges[e][0] = i;
                edges[e][1] = j;
                edges[e][2] = rand() % (int)(pow(10,n_digits));
                e++;
            }
        }

        random_shuffle(edges.begin(),edges.end());
        
        for(density = 5; density <= 100; density += 5){

            long long int n = n_edges*(0.01*density);
            
            name << "graph-"
                 << setw(3) << setfill('0') << to_string(density) << '-'
                 << setw(2) << setfill('0') << to_string(n_digits)<< '-'
                 << setw(6) << setfill('0') << to_string(vertex);
            file_name = name.str();
            name.str("");

            output.open(file_name);
            output << n << endl;
            for(long long int i = 0; i < n; i++){
                output << edges[i][0] <<" "<< edges[i][1] <<" "<< setfill('0') << setw(n_digits) << edges[i][2] << endl;
            }
            output.close();
        }

    }

    return 0;

}
