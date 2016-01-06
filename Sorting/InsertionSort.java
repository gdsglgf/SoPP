import java.util.Arrays;

public class InsertionSort {

    private static void insert(int[] data, int j) {
        int key = data[j];
        int i = j - 1;
        while (i >= 0 && data[i] > key) {
            data[i + 1] = data[i];        // move one position to the right
            i--;
        }
        data[i + 1] = key;
    }

    public static int[] insertionSort(int[] data) {
        int[] dest = CommUtil.arrayCopy(data);
        for (int j = 1; j < dest.length; j++) {
            insert(dest, j);
        }
        return dest;
    }

    public static int[] recurrsiveInsertionSort(int[] data) {
        int[] dest = CommUtil.arrayCopy(data);
        recurrsiveInsertionSort(dest, dest.length);
        return dest;
    }

    private static void recurrsiveInsertionSort(int[] data, int n) {
        if (n > 1) {
            recurrsiveInsertionSort(data, n - 1);
            insert(data, n - 1);
        }
    }

    public static void main(String[] args) {
        int[] data = {3, 2, 1};
        System.out.println(Arrays.toString(data));
        System.out.println(Arrays.toString(insertionSort(data)));
        System.out.println(Arrays.toString(recurrsiveInsertionSort(data)));
    }
}