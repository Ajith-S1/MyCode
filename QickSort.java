import java.util.Random;

public class QickSort  {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int arr[] = new int[n];
        Random cin = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = cin.nextInt() % 100000;
        }
        long t = System.nanoTime();
        sort(arr, 0, arr.length - 1);
        t = System.nanoTime() - t;
        System.out.println("\n Took " + t + " ns \n" + "\n Took " + t/1000 + " us \n" + "\n Took " + t/1000000 + " ms \n");
        if (args.length > 1) for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + ", ");
    }

    public static void sort(int arr[], int f, int r) {
        int pivot = f;
        int i = 0, j = r;
        for (i = f; i <= r && arr[i] <= arr[pivot]; i++);
        for (j = r; j >= f && arr[j] > arr[pivot]; j--);
        while (f < r) {
            if (i > j) {
                int t = arr[j];
                arr[j] = arr[pivot];
                arr[pivot] = t;
                if (j-1 > f) sort(arr, f, j-1);
                if (j+1 < r) sort(arr, j+1, r);
                break;
            }
            else {
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
                for (i++; i <= r && arr[i] <= arr[pivot]; i++);
                for (j--; j >= f && arr[j] > arr[pivot]; j--);
            }
        }
    }
}


