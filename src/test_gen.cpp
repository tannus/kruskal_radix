#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){

    ifstream input(argv[1]);
    ofstream output(argv[2]);
    
    int density,n_digits;
    long long int vertex;

    input >> density >> n_digits >> vertex; 

    long long int n_edges = vertex*(vertex-1)/2;

    srand (time(NULL));

    vector<vector<long long int> > edges(n_edges,vector<long long int>(3));

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

    long long int n = n_edges*(0.01*density);

    output << n << endl;
    for(long long int i = 0; i < n; i++){
        output << edges[i][0] <<" "<< edges[i][1] <<" "<< setfill('0') << setw(n_digits) << edges[i][2] << endl;
    }

    return 0;

}
