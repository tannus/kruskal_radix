#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){

    ifstream input(argv[1]);
    ofstream output(argv[2]);
    
    int density,n_digits,vertex;

    input >> density >> n_digits >> vertex; 

    int n_edges = vertex*(vertex-1)/2;

    srand (time(NULL));

    vector<vector<int> > edges(n_edges,vector<int>(3));

    int e = 0;
    for(int i = 1; i < vertex; i++){
        for(int j = 0; j < i; j++){
            edges[e][0] = i;
            edges[e][1] = j;
            edges[e][2] = rand() % (int)(pow(10,n_digits));
            e++;
        }
    }

    random_shuffle(edges.begin(),edges.end());

    int n = n_edges*(0.01*density);
    cout << n <<" "<< n_edges << endl;

    for(int i = 0; i < n; i++){
        output << edges[i][0] <<" "<< edges[i][1] <<" "<< edges[i][2] << endl;
    }

    return 0;

}
