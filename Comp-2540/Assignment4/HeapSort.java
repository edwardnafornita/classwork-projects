public class HeapSort {
    public static void sort(int[] array) {
        Heap heapArray = new Heap(array.length);

        for (int i = 0; i < array.length; i++) {
            heapArray.insert(array[i]);
        }

        for (int i = 0; i < array.length; i++) {
            array[i] = heapArray.removeMin();
        }
    }

    public static void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i == 0) {
                System.out.print("[" + array[i] + ",");
            } else if (i == array.length - 1) {
                System.out.println(array[i] + "]");
            } else {
                System.out.print(array[i] + ",");
            }
        }
    }

    public static void main(String[] args) {
        int[] array = {99, 42, 13, 89, 2, 56, 78, 12};
        sort(array);
        print(array);

        int[] array2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int[] array3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] array4 = {1, 3, 5, 7, 9, 10, 8, 6, 4, 2};
        sort(array2); 
        sort(array3); 
        sort(array4);
        print(array2); 
        print(array3); 
        print(array4); 
    }
}
