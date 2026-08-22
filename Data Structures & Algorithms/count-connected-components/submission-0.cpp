
class DSU
{
    public:
    vector<int>parent;
    vector<int>size;

    DSU() {}

    void init(int n)
    {
        parent.resize(n);
        size.resize(n);
        
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if(parent[x] == x) return x;

        parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int x, int y)
    {
       int x_parent = find(x);
       int y_parent = find(y);

       if(x_parent == y_parent ) return false;

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
    DSU DsuObj;
    int countComponents(int n, vector<vector<int>>& edges) {
    
//  int n = isConnected.size();
        DsuObj.init(n);
        int ans  = n;

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            if(DsuObj.unite(u,v))
            {
                n--;
            }
        }

        // int ans = 0;
        // for(int i = 0;i<n;i++)
        // {
        //     if(DsuObj.parent[i] == i) ans++;
        // }

        return n;
     
    }
};