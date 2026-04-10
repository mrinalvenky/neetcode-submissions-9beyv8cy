class Graph {
    Map<Integer, List<Integer>> adjList;
    public Graph() {
        adjList = new HashMap<>();
    }

    public void addEdge(int src, int dst) {
        adjList.computeIfAbsent(src, k -> new ArrayList<>()).add(dst);
    }

    public boolean removeEdge(int src, int dst) {
        if(!adjList.containsKey(src)) {
            return false;
        }
        return adjList.get(src).remove(Integer.valueOf(dst));
    }

    public boolean hasPath(int src, int dst) {
        // return hasPathBFS(src, dst);
        Set<Integer> visited = new HashSet<>();
        return hasPathDFS(src, dst, visited);
    }

    private boolean hasPathDFS(int src, int dst, Set<Integer> visited) {
        if (src == dst) {
            return true;
        }
        visited.add(src);
        for (int nei : adjList.getOrDefault(src, Collections.emptyList())) {
            if (!visited.contains(nei)) {
                if (hasPathDFS(nei, dst, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean hasPathBFS(int src, int dst) {
        Set<Integer> visited = new HashSet<>();
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offer(src);

        while(!queue.isEmpty()) {
            int node = queue.poll();
            if (node == dst) {
                return true;
            }
            visited.add(node);
            for (int nei: adjList.getOrDefault(node, Collections.emptyList())) {
                if (!visited.contains(nei)) {
                    visited.add(nei);
                    queue.offer(nei);
                }
            }
        }
        return false;
    }
}
