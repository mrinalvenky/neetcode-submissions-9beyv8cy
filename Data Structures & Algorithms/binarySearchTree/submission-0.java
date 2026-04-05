class TreeNode {
    int key;
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int key, int val) {
        this.key = key;
        this.val = val;
        left = right = null;
    }
}
class TreeMap {
    TreeNode root;

    public TreeMap() {
        root = null;
    }

    public void insert(int key, int val) {
        TreeNode node = new TreeNode(key, val);
        if (root == null) {
            root = node;
            return;
        }
        TreeNode cur = root;
        while(true) {
            if (key < cur.key) {
                if (cur.left == null) {
                    cur.left = node;
                    return;
                }
                cur = cur.left;
            } else if (key > cur.key) {
                if (cur.right == null) {
                    cur.right = node;
                    return;
                }
                cur = cur.right;
            } else {
                cur.val = val;
                return;
            }
        }
    }

    public int get(int key) {
        TreeNode cur = root;
        while(cur != null) {
            if (cur.key == key) {
                return cur.val;
            }
            if (key < cur.key) {
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        return -1;
    }

    public int getMin() {
        TreeNode cur = root;
        if (cur == null) {
            return -1;
        }
        while(cur.left != null) {
            cur = cur.left;
        }
        return cur.val;
    }

    public int getMax() {
        TreeNode cur = root;
        if (cur == null) {
            return -1;
        }
        while(cur.right != null) {
            cur = cur.right;
        }
        return cur.val;
    }
    private TreeNode removeHelper(TreeNode cur, int key) {
        if (cur == null) {
            return null;
        }
        if (key < cur.key) {
            cur.left = removeHelper(cur.left, key);
        } else if (key > cur.key) {
            cur.right = removeHelper(cur.right, key);
        } else {
            if (cur.left == null) {
                return cur.right;
            } else if (cur.right == null) {
                return cur.left;
            } else {
                TreeNode successor = cur.right;
                while (successor.left != null) {
                    successor = successor.left;
                }
                cur.key = successor.key;
                cur.val = successor.val;
                cur.right = removeHelper(cur.right, successor.key);
            }
        }
        return cur;
    }

    public void remove(int key) {
       root = removeHelper(root, key);
    }

    private void inOrderTraversal(TreeNode cur, List<Integer> rlist) {
        if (cur == null) {
            return;
        }
        inOrderTraversal(cur.left, rlist);
        rlist.add(cur.key);
        inOrderTraversal(cur.right, rlist);
    }

    public List<Integer> getInorderKeys() {
        List<Integer> retList = new ArrayList<>();
        inOrderTraversal(root, retList);
        return retList;
    }
}
