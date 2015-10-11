import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.*;

public class LongestSumToZero {
	public static void main (String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
            String[] elements = line.split(" ");

            // string array to int array
            int[] arr = new int[elements.length];
    		for (int i = 0; i < elements.length; i++) {
    			arr[i] = Integer.parseInt(elements[i]);
    		}

            // sums from 0 to i element
    		int[] sums = new int[arr.length];
            sums[0] = arr[0];
            for (int i = 1; i < arr.length; i++) {
            	sums[i] = arr[i];
            	sums[i] += sums[i - 1];
//            	System.out.printf("i=%d, sum=%d\n", i, sums[i]);
            }

            // store indexs(as value) with the same sum(as key) in map
            Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
            List<Integer> indexs = null;
            for (int i = 0; i < sums.length; i++) {
                  indexs = map.get(sums[i]);
                  if (indexs == null) {
                        indexs = new ArrayList<Integer>();
                        indexs.add(i);
                        map.put(sums[i], indexs);
                  } else {
                        indexs.add(i);
                  }
            }


            int maxLength = 0;
            int resultSum = 0;
            int from = 0;
            int to = 0;

            // find the longest sequence that sum is not equal to zero
            for (int i = 0; i < sums.length; i++) {
            	if (sums[i] != 0) {
            		indexs = map.get(sums[i]);
            		int size = indexs.size();
            		if (size > 1) {
            			int curLength = indexs.get(size - 1) - indexs.get(0) + 1;
            			if (curLength > maxLength) {
            				maxLength = curLength;
            				from = indexs.get(0);
            				to = indexs.get(size - 1);
            				resultSum = sums[i];
            			}
            		}
            	}
            }

            // 
            indexs = map.get(0);
            if (indexs != null) {
            	int curLength = indexs.get(indexs.size() - 1) + 1;
            	if (maxLength <= curLength) {
            		maxLength = curLength;
            		from = 0;
            		to = curLength - 1;
            		resultSum = 0;
            	}
            }

            if (resultSum == 0) {
            	if (from == to && arr[from] != 0) {
            		System.out.println("Longest suquence with sum to zero not found!");
            		continue;
            	}
            	for (int i = from; i <= to; i++) {
            		System.out.printf("%d ", arr[i]);
            	}
            } else {
            	for (int i = from + 1; i <= to; i++) {
            		System.out.printf("%d ", arr[i]);
            	}
            }
            
            System.out.println();

        }
    }
}