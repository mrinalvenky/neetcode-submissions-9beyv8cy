class TreeNode {
    private char val;
    private boolean isEnd;
    private Map<Character, TreeNode> children;

    public TreeNode() {
        this.val = '*';
        this.isEnd = false;
        this.children = new HashMap<>();
    }

    public TreeNode(char c) {
        this.val = c;
        this.isEnd = false;
        this.children = new HashMap<>();
    }

    public TreeNode addChild(char c) {
        TreeNode child = new TreeNode(c);
        this.children.put(c, child);
        return child;
    }

    public TreeNode getChild(char c) {
        return this.children.get(c);
    }

    public TreeNode getOrAddChild(char c) {
        if (!children.containsKey(c)) {
            children.put(c, new TreeNode(c));
        }
        return children.get(c);
    }

    public char getVal() { return this.val; }
    public boolean getIsEnd() { return this.isEnd; }
    public void setIsEnd() { this.isEnd = true; }
}

class PrefixTree {
    private TreeNode root;

    public PrefixTree() {
        this.root = new TreeNode('*');
    }

    public void insert(String word) {
        TreeNode cur = this.root;
        for (int i = 0; i < word.length(); i++) {
            cur = cur.getOrAddChild(word.charAt(i));
        }
        cur.setIsEnd();
    }

    public boolean search(String word) {
        TreeNode cur = this.root;
        int i = 0;
        while (cur != null && i < word.length()) {
            cur = cur.getChild(word.charAt(i));
            i++;
        }
        return cur != null && cur.getIsEnd();
    }

    public boolean startsWith(String prefix) {
        TreeNode cur = this.root;
        int i = 0;
        while (cur != null && i < prefix.length()) {
            cur = cur.getChild(prefix.charAt(i));
            i++;
        }
        return cur != null;
    }
}