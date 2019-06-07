#include <bits/stdc++.h>

#define pb(x) push_back(x);
typedef long long int ll;

using namespace std;

ll n_edges;
vector<ll> previous, order;

void make_set(ll v){
    previous[v] = v;
    order[v] = 0;
}

ll find_set(ll v){
    if(v == previous[v]) return v;
    return previous[v] = find_set(previous[v]);
}

void union_sets(ll a, ll b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(order[a] < order[b]) swap(a,b);
        previous[b] = a;
        if(order[a] == order[b]) order[a]++;
    }
}

struct Edge {
    ll u, v, w;
    bool operator<(Edge const& other){
        return w < other.w;
    }
};

void copy_edge(Edge &a, Edge b){
    a.u = b.u;
    a.v = b.v;
    a.w = b.w;
}

ll get_max(vector<Edge> &graph){
    ll m = graph[0].w;
    for(ll i = 1; i < graph.size(); i++)
        m = max(m,graph[i].w);
    return m;
}

void count_sort(vector<Edge> &graph, ll tpot){
    vector<Edge> output(graph.size());
    ll i, count[10];
    for(i = 0; i < 10; i++) count[i] = 0;
    
    for(i = 0; i < graph.size(); i++) 
        count[ (graph[i].w/tpot)%10 ]++;
    
    for(i = 1; i < 10; i++) count[i] += count[i-1];

    for(i = graph.size()-1; i >= 0; i--){
        copy_edge(output[ count[ (graph[i].w/tpot)%10 ] - 1],graph[i]);
        count[ (graph[i].w/tpot)%10 ]--;
    }

    for(i = 0; i < graph.size(); i++) copy_edge(graph[i],output[i]);
}

void radix_sort(vector<Edge> &graph){
    ll m = get_max(graph);
    for(ll tpot = 1; m/tpot > 0; tpot *= 10) count_sort(graph, tpot);
}

void merge(vector<Edge> &graph, ll l, ll m, ll r){
    ll i,j,k;
    ll a = m - l + 1;
    ll b = r - m;
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

void merge_sort(vector<Edge> &graph, ll l, ll r){
    if(l < r){
        ll m = l+(r-l)/2;
        merge_sort(graph,l,m);
        merge_sort(graph,m+1,r);
        merge(graph,l,m,r);
    }
}

void print_edges(vector<Edge> &graph){
    cout << "------------" << endl;
    for(ll i = 0; i < graph.size(); i++)
        cout <<"Edge between: " << graph[i].u << " and " << graph[i].v << " - weighted:" << graph[i].w << endl;
    cout << "------------" << endl;
}

ll kruskal(vector<Edge> &graph, bool fun_sort, vector<Edge> &agm){
    ll result = 0;
    previous.resize(n_edges); order.resize(n_edges);

    for(ll i = 0; i < n_edges; i++) make_set(i);
    
    if(fun_sort) radix_sort(graph);
    else merge_sort(graph,0,graph.size()-1);

    for(Edge e: graph){
        if(find_set(e.u) != find_set(e.v)){
            result += e.w;
            agm.pb(e);
            union_sets(e.u,e.v);
        }
    }
    return result;
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
    for(ll i=0; i < n_edges; i++){
        Edge uv;
        input >> uv.u >> uv.v >> uv.w;
        edges.pb(uv);
    }

    ll result = kruskal(edges,fun_sort,agm);
    
    output << result << endl;
    for(ll i=0; i < agm.size(); i++)
        output << agm[i].u <<" "<< agm[i].v <<" "<< agm[i].w << endl;

    return 0;

}
