#include <bits/stdc++.h>

#define pb(x) push_back(x);

using namespace std;

int n_edges;
vector<int> previous, order;

void make_set(int v){
    previous[v] = v;
    order[v] = 0;
}

int find_set(int v){
    if(v == previous[v]) return v;
    return previous[v] = find_set(previous[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(order[a] < order[b]) swap(a,b);
        previous[b] = a;
        if(order[a] == order[b]) order[a]++;
    }
}

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other){
        return w < other.w;
    }
};

int get_max(vector<Edge> &graph){
    int m = graph[0].w;
    for(int i = 1; i < graph.size(); i++)
        m = max(m,graph[i].w);
    return m;
}

void count_sort(vector<Edge> &graph, int tpot){
    vector<Edge> output(graph.size());
    int i, count[10];
    for(i = 0; i < 10; i++) count[i] = 0;
    
    for(i = 0; i < graph.size(); i++) 
        count[ (graph[i].w/tpot)%10 ]++;
    
    for(i = 0; i < 10; i++) count[i] += count[i-1];
    
    for(i = graph.size()-1; i >= 0; i--){
        output[ count[ (graph[i].w/tpot)%10 ] - 1].u = graph[i].u;
        output[ count[ (graph[i].w/tpot)%10 ] - 1].v = graph[i].v;
        output[ count[ (graph[i].w/tpot)%10 ] - 1].w = graph[i].w;
        count[ (graph[i].w/tpot)%10 ]--;
    }

    for(i = 0; i < graph.size(); i++) graph[i] = output[i];
}

void radix_sort(vector<Edge> &graph){
    int m = get_max(graph);
    for(int tpot = 1; m/tpot > 0; tpot *= 10) count_sort(graph, tpot);
}

void copy_edge(Edge &a, Edge b){
    a.u = b.u;
    a.v = b.v;
    a.w = b.w;
}

void merge(vector<Edge> &graph, int l, int m, int r){
    int i,j,k;
    int a = m - l + 1;
    int b = r - m;
    vector<Edge> left(a), right(b);
    for(i = 0; i < a; i++){
        copy_edge(left[i],graph[l+i]);
    }
    for(j = 0; j < b; j++){
        copy_edge(right[j],graph[m+1+j]);
    }
    i = 0; j = 0; k = l;
    while(i < a && j < b){
        if(left[i].w <= right[j].w){
            copy_edge(graph[k],left[i]);
            i++;
        }
        else{
            copy_edge(graph[k],right[j]);
            j++;
        }
        k++;
    }

    while(i < a){
        copy_edge(graph[k],left[i]);
        i++; k++;
    }
    
    while(j < b){
        copy_edge(graph[k],right[j]);
        j++; k++;
    }
}

void merge_sort(vector<Edge> &graph, int l, int r){
    if(l < r){
        int m = l+(r-l)/2;
        merge_sort(graph,l,m);
        merge_sort(graph,m+1,r);
        merge(graph,l,m,r);
    }
}

void print_edges(vector<Edge> &graph){
    cout << "------------" << endl;
    for(int i = 0; i < graph.size(); i++)
        cout <<"Edge between: " << graph[i].u << " and " << graph[i].v << " - weighted:" << graph[i].w << endl;
    cout << "------------" << endl;
}

int kruskal(vector<Edge> &graph, bool fun_sort, vector<Edge> &agm){
    int result = 0;
    previous.resize(n_edges); order.resize(n_edges);

    for(int i = 0; i < n_edges; i++) make_set(i);
    
    print_edges(graph);
    if(fun_sort) radix_sort(graph);
    else merge_sort(graph,0,graph.size()-1);
    print_edges(graph);

    for(Edge e: graph){
        if(find_set(e.u) != find_set(e.v)){
            result += e.w;
            agm.pb(e);
            union_sets(e.u,e.v);
        }
    }
}

bool set_arg(string c){
    int d = stoi(c);
    if(d == 0) return false;
    else return true;
}

int main(int argc, char** argv){

    ifstream input(argv[1]);
    ofstream output(argv[2]);
    string c = argv[3];
    bool fun_sort = set_arg(c);

    vector<Edge> edges;
    vector<Edge> agm;

    input >> n_edges;
    for(int i=0; i < n_edges; i++){
        Edge uv;
        input >> uv.u >> uv.v >> uv.w;
        edges.pb(uv);
    }

    int result = kruskal(edges,fun_sort,agm);
    
    output << result << endl;
    for(int i=0; i < agm.size(); i++)
        output << agm[i].u <<" "<< agm[i].v <<" "<< agm[i].w << endl;

    return 0;

}
