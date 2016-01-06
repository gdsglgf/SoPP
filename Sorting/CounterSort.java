import java.util.Arrays;

public class CounterSort {
    public static int[] counterSort(int[] data, int k) {
        int[] sorted = new int[data.length];
        int[] counter = new int[k];    // 假设数据取值范围在区间[0, k - 1]内
        for (int i = 0; i < counter.length; i++) {
            counter[i] = 0;
        }
        for (int i = 0; i < data.length; i++) {
            counter[data[i]]++;     // 对数据data[i]进行计数
        }
        for (int i = 1; i < counter.length; i++) {
            counter[i] += counter[i - 1];   // 对小于等于data[i]的进行统计
        }
        for (int i = data.length - 1; i >= 0; i--) {
            counter[data[i]]--;     // 计算data[i]的排好序的数组中的位置
            sorted[counter[data[i]]] = data[i];     // 将data[i]放到对应的位置中
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