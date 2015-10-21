import java.util.Arrays;

public class QuickSort {
    private static int partition(int[] data, int p, int q) {
        int x = data[p];
        int i = p;
        for (int j = p + 1; j <= q; j++) {
            if (data[j] <= x) {
                i++;
                CommUtil.swap(data, i, j);
            }
        }
        CommUtil.swap(data, p, i);
        return i;
    }

    private static void quickSort(int[] data, int p, int r) {
        if (r > p) {
            int q = partition(data, p, r);
            quickSort(data, p, q - 1);
            quickSort(data, q + 1, r);
        }
    }

    public static void quickSort(int[] data) {
        quickSort(data, 0, data.length - 1);
    }

    public static void main(String[] args) {
        int[] data = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        System.out.println(Arrays.toString(data));
        quickSort(data);
        System.out.println(Arrays.toString(data));
    }
}