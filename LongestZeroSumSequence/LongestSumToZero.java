import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.ObjectInputStream.GetField;
import java.util.*;

public class LongestSumToZero {
    public static int[] toInts(String[] elements) {
        int[] arr = new int[elements.length];
        for (int i = 0; i < elements.length; i++) {
            arr[i] = Integer.parseInt(elements[i]);
        }
        return arr;
    }
    
    public static int[] addSums(int[] arr) {
        int[] sums = new int[arr.length];
        sums[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            sums[i] = arr[i];
            sums[i] += sums[i - 1];
            System.out.printf("i=%d, sum=%d\n", i, sums[i]);
        }
        return sums;
    }
    
    public static int[] findLongestSumToZeroIndex(int[] sums) {
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

    public static void main (String[] args) throws IOException {
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
            
            int[] indexs = findLongestSumToZeroIndex(sums);
            if (indexs == null) {
                System.out.println("False");
            } else {
                for (int i = indexs[0]; i <= indexs[1]; i++) {
                    System.out.printf("%d ", arr[i]);
                }
                System.out.println();
            }
        }
    }
}