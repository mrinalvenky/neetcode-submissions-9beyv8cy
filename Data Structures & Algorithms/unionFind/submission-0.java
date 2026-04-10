class UnionFind {
    private int[] parent;
    private int[] sizes;
    private int components;

    public UnionFind(int n) {
        parent = new int[n];
        sizes = new int[n];
        components = n;
        for (int i = 0; i < n ; i++) {
            parent[i]  = i;
            sizes[i] = 1;
        }
    }

    public int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public boolean isSameComponent(int x, int y) {
        return (find(x) == find(y));
    }

    public boolean union(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            if (sizes[root_x] > sizes[root_y]) {
                parent[root_y] = root_x;
                sizes[root_x] += sizes[root_y];
            } else {
                parent[root_x] = root_y;
                sizes[root_y] += sizes[root_x];
            }
            components--;
            return true;
        }
        return false;
    }

    public int getNumComponents() {
        return components;
    }
}
