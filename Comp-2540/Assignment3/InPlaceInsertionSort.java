public class InPlaceInsertionSort {
    public static void sort(int[] arr) {
        int temp = 0, length = arr.length;
        for (int i = 1; i < length; i++) {
            temp = arr[i];
            int j = i - 1;
            for (; (j >= 0 && arr[j] > temp); j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }

    public static void print(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (i == 0) {
                System.out.print("[" + arr[i] + ", ");
                continue;
            }
            if (i + 1 >= arr.length) {
                System.out.print(arr[i] + "]");
                System.out.println();
                break;
            }
            System.out.print(arr[i] + ", ");
        }
    }

    public static void main(String[] args) {
        int[] arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, arr3 = {1, 2, 4, 5, 3, 7, 8, 10, 11, 9, 6};
        System.out.println("Before:");
        print(arr);
        print(arr2);
        print(arr3);
        System.out.println("After:");
        sort(arr);
        sort(arr2);
        sort(arr3);
        print(arr);
        print(arr2);
        print(arr3);
    }
}