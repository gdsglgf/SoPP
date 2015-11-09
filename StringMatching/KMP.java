import java.util.Arrays;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;

public class KMP {
    public static int[] partialMatchTable(String p) {
        int length = p.length();
        int[] pmt = new int[length];
        for (int i = 0; i < length; i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                int m = 0;
                int n = i - j + 1;
                //System.out.printf("i = %d, m=%d, n=%d ---->", i, m, n);
                while(n <= i && p.charAt(m) == p.charAt(n)) {
                    m++;
                    n++;
                }
                //System.out.printf("m=%d, n=%d\n", m, n);
                if (n > i && m > max) {
                    max = m;
                }
            }
            pmt[i] = max;
        }
        return pmt;
    }

    public static int match(String text, String pattern) {
        if (text == null || pattern == null || pattern.equals("") 
            || text.length() < pattern.length()) {
            return -1;
        }

        int textLength = text.length();
        int patternLength = pattern.length();
        int size = textLength - patternLength;
        int[] pmt = partialMatchTable(pattern);
        for (int i = 0; i <= size; ) {
            int k = 0;
            for (int j = i; k < patternLength; k++, j++) {
                if (text.charAt(j) != pattern.charAt(k)) {  // 从左向右比较 k为未匹配的下标
                    break;
                }
            }

            if (k == patternLength) {
                return i;   // 匹配成功
            } else if (k == 0) {
                i++;    // 第一个字符不匹配, 后移一位
                //System.out.println("step=1");
            } else {
                // k为匹配串长度, pmt[k - 1]为模式串的前缀与其匹配的后缀的最大长度
                // 作用是将最长前缀与其匹配的最长后缀进行对齐
                i += (k - pmt[k - 1]);  
                //System.out.printf("length=%d, step=%d\n", k, k - pmt[k - 1]);
            }
            //System.out.printf("i = %d\n", i);
        }
        return -1;
    }

    public static void main (String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(args[0]));
        String line;
        while (sc.hasNext()) {
            line = sc.nextLine();
            line = line.trim();
            String[] elements = line.split(" \\| ");
            System.out.println(match(elements[0], elements[1]));
        }
        sc.close();
        System.out.println(Arrays.toString(partialMatchTable("abcdabc")));
        System.out.println(Arrays.toString(partialMatchTable("abababca")));
        System.out.println(match("bacbababaabcbab", "abababca"));
    }

}