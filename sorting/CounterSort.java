import java.util.Arrays;

public class CounterSort {
    public static int[] counterSort(int[] data, int k) {
        int[] sorted = new int[data.length];
        int[] counter = new int[k];    // 假设数据取值范围在区间[0, k - 1]内
        for (int i = 0; i < counter.length; i++) {
            counter[i] = 0;
        }
        for (int i = 0; i < data.length; i++) {
            counter[data[i]]++;
        }
        for (int i = 1; i < counter.length; i++) {
            counter[i] += counter[i - 1];
        }
        for (int i = data.length - 1; i >= 0; i--) {
            counter[data[i]]--;
            sorted[counter[data[i]]] = data[i];            
        }
        return sorted;
    }

    public static void main(String[] args) {
        int[] data = {9, 6, 3, 6, 5, 8, 3, 2, 1, 0};
        System.out.println(Arrays.toString(data));
        int[] sorted = counterSort(data, 10);
        System.out.println(Arrays.toString(sorted));
    }
}