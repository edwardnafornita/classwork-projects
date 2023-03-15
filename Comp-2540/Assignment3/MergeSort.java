public class MergeSort extends Merge {

    public static Queue<Integer> sort(Queue<Integer> arr) {
        int length = arr.size();
        if (length <= 0) {
            System.out.println("Queue is empty! Nothing to sort.");
            return arr;
        }
        if (length == 1) {
            return arr;
        } else {
            Queue<Integer> L = new Queue<Integer>(), G = new Queue<Integer>();
            for (int i = 0; i < length / 2; i++) {
                L.enqueue(arr.dequeue());
            }
            do {
                G.enqueue(arr.dequeue());
            } while (!arr.isEmpty());
            
            L = sort(L);
            G = sort(G);

            return merge(L, G);
        }
    }

    public static void main(String[] args) {
        Queue<Integer> arr = new Queue<Integer>(), arr2 = new Queue<Integer>(), arr3 = new Queue<Integer>();

        // arr will contain {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
        for (int i = 10; i > 0; i--) {
            arr.enqueue(i);
        }

        // arr2 will contain {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        for (int i = 1; i <= 10; i++) {
            arr2.enqueue(i);
        }
        
        // arr3 will contain {1, 2, 4, 5, 3, 7, 8, 10, 11, 9, 6}
        arr3.enqueue(1);
        arr3.enqueue(2);
        arr3.enqueue(4);
        arr3.enqueue(5);
        arr3.enqueue(3);
        arr3.enqueue(7);
        arr3.enqueue(8);
        arr3.enqueue(10);
        arr3.enqueue(11);
        arr3.enqueue(9);
        arr3.enqueue(6);

        Queue<Integer> sortedArr = sort(arr), sortedArr2 = sort(arr2), sortedArr3 = sort(arr3);

        sortedArr.dequeueAll();
        sortedArr2.dequeueAll();
        sortedArr3.dequeueAll();
    }
}
