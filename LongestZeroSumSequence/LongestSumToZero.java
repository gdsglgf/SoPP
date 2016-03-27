import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LongestSumToZero {
    /**
     * 将字符串类型的整数数组转换成整数类型的数组
     * @param elements 字符串类型的整数数组
     * @return 整数类型的数组
     */
    public static int[] toInts(String[] elements) {
        int[] arr = new int[elements.length];
        for (int i = 0; i < elements.length; i++) {
            arr[i] = Integer.parseInt(elements[i]);
        }
        return arr;
    }

    /**
     * 计算数组前i项和, 使用数组返回
     * @param arr 整数数组
     * @return 前i项和数组
     */
    public static int[] addSums(int[] arr) {
        int[] sums = new int[arr.length];
        sums[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            sums[i] = arr[i];
            sums[i] += sums[i - 1];
        }
        return sums;
    }

    /**
     * 使用HashMap进行查找
     * @param sums 数组前i项和
     * @return 如果未找到, 返回null; 反之, 返回整型数组{起始下标, 结束下标}.
     */
    public static int[] findLongestSumToZeroIndexUsingMap(int[] sums) {
        Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
        int sumOfMaxLength = sums[0];
        int maxLength = 0;
        char typeOfFind = 'n';  // not found
        for (int i = 0; i < sums.length; i++) {
              List<Integer> indexs = map.get(sums[i]);
              if (indexs == null) {
                    indexs = new ArrayList<Integer>();
                    indexs.add(i);
                    map.put(sums[i], indexs);
              } else {
                    indexs.add(i);
                    int currentLength = i - indexs.get(0);
                    if (currentLength > maxLength) {
                        sumOfMaxLength = sums[i];
                        maxLength = currentLength;
                        typeOfFind = 'm';   // found in middle
                    }
              }
              if (sums[i] == 0 && i + 1 >= maxLength) {
                  sumOfMaxLength = 0;
                  maxLength = i + 1;
                  typeOfFind = 'l';     // found in first half of sequence
              }
        }
        
        switch(typeOfFind) {
        case 'm':
            int begin = map.get(sumOfMaxLength).get(0);
            int end = begin + maxLength;
            return new int[] {begin + 1, end};
        case 'l':
            return new int[] {0, maxLength - 1};
        }
        
        return null;
    }

    /**
     * 使用数组遍历方式进行查找
     * @param sums 数组前i项和
     * @return 如果未找到, 返回null; 反之, 返回整型数组{起始下标, 结束下标}.
     */
    public static int[] findLongestSumToZeroIndex(int[] sums) {
        int from = 0;
        int to = -1;
        for (int i = 0; i < sums.length; i++) {
            if (sums[i] == 0) {   // 前i项和为0
                if (i + 1 > to - from + 1) {
                    from = 0;
                    to = i;
                }
            } else {
                int lastIndex = i;
                // 查找后续项相等的最大下标
                for (int j = sums.length - 1; j > i; j--) {
                    if (sums[j] == sums[i]) {
                        lastIndex = j;
                        break;
                    }
                }
                if (lastIndex != i && lastIndex - i > to - from + 1) {
                    from = i + 1;
                    to = lastIndex;
                }
            }
        }
        if (to == -1) {
            return null; // not found
        } else {
            return new int[] { from, to };
        }
    }

    /**
     * 蛮力搜索
     */
    public static int[] longest(int[] arr) {
        int from = -1;
        int to = -1;
        for (int i = 0; i < arr.length; i++) {
            int sum = 0;
            for (int j = i; j < arr.length; j++) {
                sum += arr[j];
                if (sum == 0 && (j - i > to - from || from == -1)) {
                    from = i;
                    to = j;
                }
            }
        }
        if (from == -1) {
            return null; // not found
        } else {
            return new int[] { from, to };
        }
    }

    /**
     * 显示查找结果
     * @param indexs 查找结果
     * @param arr 输入数组
     */
    private static void showResult(int[] indexs, int[] arr) {
        if (indexs == null) {
            System.out.println("False");
        } else {
            for (int i = indexs[0]; i <= indexs[1]; i++) {
                System.out.printf("%d ", arr[i]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
            String[] elements = line.split(" ");

            // string array to int array
            int[] arr = toInts(elements);

            // sums from 0 to i element
            int[] sums = addSums(arr);

            System.out.println("Calling findLongestSumToZeroIndex...");
            showResult(findLongestSumToZeroIndex(sums), arr);
            System.out.println("Calling findLongestSumToZeroIndexUsingMap...");
            showResult(findLongestSumToZeroIndexUsingMap(sums), arr);
            System.out.println("Longest");
            showResult(longest(arr), arr);
        }
    }
}