#include <bits/stdc++.h>
using namespace std;

class Min_Heap
{
    vector<pair<int,int>>heap;
    unordered_map<int,int> key_index;
    public:
    void heapify1(int i)
    {
        if(i==0)return;
        int pi = (i-1)/2;
        if(heap[i].second<heap[pi].second)
        {
            swap(heap[i],heap[pi]);
            key_index[heap[i].first] = i;
            key_index[heap[pi].first] =pi;
            heapify1(pi);
        }
    }
    void heapify2(int i)
    {
        int li = 2*i + 1;
        int ri = 2*i + 2;
        int si = i;
        if(li<heap.size()&&heap[li].second<heap[si].second)
        {
            si = li;
        }
        if(ri<heap.size()&&heap[ri].second<heap[si].second)
        {
            si = ri;
        }
        if(si != i)
        {
            swap(heap[i],heap[si]);
             key_index[heap[i].first] = i;
            key_index[heap[si].first] =si;
            heapify2(si);
        }
    }

    void insert (int k ,int v)
    {
        heap.push_back({k,v});
        int i = heap.size()-1;
        key_index[k]=i;
        heapify1(i);
    }

    pair<int,int> extract_min()
    {
        pair<int,int> ele = heap[0];
        heap[0]= heap.back();
        heap.pop_back();
        key_index.erase(ele.first);
        if(!heap.empty())
        {
            key_index[heap[0].first] = 0;
            heapify2(0);
        }
        return ele;
    }

    void decrease_key(int k,int v)
    {
        int i = key_index[k];
        heap[i].second = v;
        heapify1(i);
    }

    bool is_empty()
    {
        return heap.empty();
    }

};

void dijkstra_algorithm(vector<vector<pair<int,int>>>&adj,int v,int src)
{
    vector<int>dist(v,INT_MAX);
    Min_Heap h;
    dist[src]=0;
    for(int i =0;i<v;i++)
    {
        h.insert(i,dist[i]);
    }

    while (!h.is_empty())
    {
        pair<int,int> min_ele = h.extract_min();
        int u = min_ele.first;

        for(auto it : adj[u])
        {
            int new_node = it.first;
            int weight = it.second;

            if(dist[u]+ weight < dist[new_node])
            {
                dist[new_node] = dist[u]+ weight;
                h.decrease_key(new_node,dist[new_node]);
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        cout << "Vertex "<<i<<": "<<"Distance "<<dist[i]<<endl;
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v);
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin >>x>>y>>w;
        adj[x].push_back({y,w});
    }
    dijkstra_algorithm(adj,v,0);
    return 0;
}