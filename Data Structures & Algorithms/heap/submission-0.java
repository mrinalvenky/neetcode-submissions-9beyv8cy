class MinHeap {
    private ArrayList<Integer> heapArr;

    public MinHeap() {
        heapArr = new ArrayList<>();
        heapArr.add(-1);
    }

    public void push(int val) {
        heapArr.add(val);
        bubbleUp(heapArr.size() - 1);
    }

    public Integer pop() {
        if (heapArr.size() <= 1) {
            return -1;
        }
        if (heapArr.size() == 2) return heapArr.remove(1);
        Integer ret = heapArr.get(1);
        heapArr.set(1, heapArr.remove(heapArr.size() - 1));
        if (heapArr.size() > 1) {
            bubbleDown(1);
        }
        return ret;
    }

    public Integer top() {
        return (heapArr.size() > 1) ? heapArr.get(1) : -1;
    }

    public void heapify(List<Integer> nums) {
        this.heapArr = new ArrayList<>();
        heapArr.add(-1);
        heapArr.addAll(nums);
        for (int i = heapArr.size() / 2; i >= 1; i--) {
            bubbleDown(i);
        }
    }

    private void swap(int i, int j) {
        int temp = heapArr.get(i);
        heapArr.set(i, heapArr.get(j));
        heapArr.set(j, temp);
    }

    private void bubbleDown(int idx) {
        int child = 2 * idx;
        while (child < heapArr.size()) {
            if (child + 1 < heapArr.size() && heapArr.get(child) > heapArr.get(child + 1)) {
                child++;
            }

            if (heapArr.get(child) >= heapArr.get(idx)) break;

            swap(child, idx);
            idx = child;
            child = 2 * idx;
        }
    }
    private void bubbleUp(int idx) {
        int parent = idx/2;
        while (idx > 1 && heapArr.get(parent) > heapArr.get(idx) ) {
            swap(idx, parent);
            idx = parent;
            parent = idx / 2;
        }

    }
}
