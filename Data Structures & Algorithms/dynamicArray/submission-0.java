class DynamicArray {
    private int capacity;
    private int length;
    private int[] arr; 

    public DynamicArray(int capacity) {
        this.capacity = capacity;
        this.arr = new int[capacity];
        this.length = 0;
        return;
    }

    public int get(int i) {
        return arr[i];
    }

    public void set(int i, int n) {
        arr[i] = n;
    }

    public void pushback(int n) {
        if (this.length == this.capacity) {
            this.resize();
        }
        this.arr[this.length] = n;
        this.length++;
    }

    public int popback() {
        length--;
        int ret = this.arr[this.length];
        return ret;
    }

    private void resize() {
        capacity *= 2;
        int[] newArr = new int[capacity];
        for (int i = 0; i < length; i++) {
            newArr[i] = arr[i];
        }
        arr = newArr;
    }

    public int getSize() {
        return length;
    }

    public int getCapacity() {
        return capacity;
    }
}
