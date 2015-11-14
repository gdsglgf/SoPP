import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;

/** 蛮力搜索算法 */
public class BruteForce {
    public static int match(String text, String pattern) {
        if (text == null || pattern == null || pattern.equals("")) {
            return -1;
        }

        int textLength = text.length();
        int patternLength = pattern.length();
        int size = textLength - patternLength;
        for (int i = 0; i <= size; i++) {
            boolean isMatch = true;
            for (int j = i, k = 0; k < patternLength; k++, j++) {
                if (text.charAt(j) != pattern.charAt(k)) {  // 从左向右比较
                    isMatch = false;    // 未匹配成功
                    break;
                }
            }
            if (isMatch) {
                return i;    // 匹配成功, 返回
            }
        }
        return -1;
    }

    public static int match2(String text, String pattern) {
        if (text == null || pattern == null || pattern.equals("")
            || text.length() < pattern.length()) {
            return -1;
        }

        int textLength = text.length();
        int patternLength = pattern.length();
        int p = 0;      // 模式串下标
        int t = 0;      // 文本串下标
        while (p < patternLength && t < textLength) {
            if (text.charAt(t) == pattern.charAt(p)) {
                p++;
                t++;
            } else {
                t = t - p + 1;      // 计算文本串比较的起始位置, t - p为上一次比较的起始位置
                p = 0;
            }
        }
        if (p >= patternLength) {
            return t - p;
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
            System.out.printf("%d = %d\n", match(elements[0], elements[1]), match2(elements[0], elements[1]));
        }
        sc.close();
    }
}