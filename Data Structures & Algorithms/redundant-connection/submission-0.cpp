class DSU
{
    public:
    vector<int> size;
    vector<int> parent;

    DSU(int V)
    {
        size.assign(V, 1);
        parent.assign(V, 0); 

        for(int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(x == parent[x])
        {
           return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
        {
            return false; 
        }

        if(size[x_parent] > size[y_parent])
        {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent]; 
        }
        else
        {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }

        return true;
    }
};

class Solution {
public:
    DSU *dsuObj;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();

        dsuObj = new DSU(V + 1);

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            

            if(!dsuObj->Union(u, v))
            {
                return it;
            }
        }
        
        return {};
    }
};
