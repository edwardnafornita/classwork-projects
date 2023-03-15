public class Heap {
    private int[] heap;
    private int size;
    private int index;

    public Heap(int size) {
        this.size = size;
        this.index = -1;
        this.heap = new int[size];
    }

    public void insert(int value) {
        if (index >= size) {
            System.out.println("Error: No more space allocated in heap.");
        }
        else {
            heap[++index] = value;
            upheap();
        }
    }

    public void upheap() {
        int currentPosition = index, parentIndex = (currentPosition - 1) / 2;

        while (parentIndex >= 0 && heap[currentPosition] < heap[parentIndex]) {
            int temp = heap[currentPosition];
            heap[currentPosition] = heap[parentIndex];
            heap[parentIndex] = temp;

            currentPosition = parentIndex;
            parentIndex = (currentPosition - 1) / 2;
        }
    }

    public int removeMin() {
        if (isEmpty()) {
            return -1;
        }

        int minimumValue = heap[0];
        heap[0] = heap[index--];
        heap[index + 1] = 0;
        downheap(index);

        return minimumValue;
    }

    public void downheap(int lastIndex) {
        if (lastIndex <= 0) {
            return;
        }

        int currentIndex = 0;

        while (currentIndex <= lastIndex) {
            int leftChild = (currentIndex * 2) + 1, rightChild = (currentIndex * 2) + 2;

            if (leftChild > lastIndex) {
                break;
            }

            int valueToSwap;
            if (rightChild > lastIndex) {
                valueToSwap = leftChild;
            } else if (heap[leftChild] < heap[rightChild]) {
                valueToSwap = leftChild;
            } else {
                valueToSwap = rightChild;
            }

            if (heap[currentIndex] < heap[valueToSwap]) {
                break;
            }
            int temp = heap[valueToSwap];
            heap[valueToSwap] = heap[currentIndex];
            heap[currentIndex] = temp;

            currentIndex = valueToSwap;
        }
    }

    public boolean isEmpty() {
        if (size <= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    public int size() {
        return size;
    }

    public int min() {
        return heap[0];
    }

    public void print() {
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                System.out.println(heap[i] + "]");
            } else if (i == 0) {
                System.out.print("[" + heap[i] + ",");
            } else {
                System.out.print(heap[i] + ",");
            }
        }
    }

    public static void main(String[] args) {
        Heap newHeap = new Heap(5);
        newHeap.insert(99);
        newHeap.insert(2);
        newHeap.insert(456);
        newHeap.insert(1);
        newHeap.insert(10);
        newHeap.print();
        newHeap.removeMin();
        newHeap.print();
        newHeap.insert(1);
        newHeap.print();
        System.out.println(newHeap.size());
    }
}