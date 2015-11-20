#include <iostream>
#include <string>   /** C++标准库 */
#include <string.h>     /** C语言库 */

using namespace std;

/*从前面开始查找第一个匹配的位置*/
int indexOf(string text, string pattern)
{
    if (text.empty() || pattern.empty())
    {
        cout << "null or empety" << endl;
        return -1;
    }
    int tLen = text.size();
    int pLen = pattern.size();
    if (tLen < pLen)
    {
        return -1;
    }

    int t = 0, p = 0;
    while (t < tLen && p < pLen)
    {
        if (text[t] == pattern[p])
        {
            t++;
            p++;
        }
        else
        {
            t = t - p + 1;
            p = 0;
        }
    }
    if (p == pLen)
    {
        return t - p;
    }
    return -1;
}

/*从前面开始查找最后一个匹配的位置*/
int lastIndexOf(string text, string pattern)
{
    int tLen = text.size();
    int pLen = pattern.size();
    if (tLen < pLen)
    {
        return -1;
    }

    int t = 0, p = 0;
    int index = -1;
    while (t < tLen)
    {
        if (text[t] == pattern[p])
        {
            t++;
            p++;
            if (p == pLen)
            {
                index = t - p;
                t = index + 1;
                p = 0;
            }
        }
        else
        {
            t = t - p + 1;
            p = 0;
        }
    }

    return index;
}

/*从后面开始查找第一个匹配的位置*/
int lastIndexOfFromLast(string text, string pattern)
{
    int tLen = text.size();
    int pLen = pattern.size();

    if (tLen < pLen)
    {
        return -1;
    }

    int t = tLen - 1;
    int p = pLen - 1;
    while(t >= 0 && p >= 0)
    {
        if (text[t] == pattern[p])
        {
            t--;
            p--;
        }
        else
        {
            t = t + pLen - p - 2;
            p = pLen - 1;
        }
    }
    if (p == -1)
    {
        return t + 1;
    }
    return -1;
}

int strcmpare(string a, string b)
{
    int aLen = a.length();
    int bLen = b.length();
    int i = 0, j = 0;
    while (i < aLen && j < bLen)
    {
        int diff = a[i] - b[j];
        if (diff == 0)
        {
            i++;
            j++;
        }
        else
        {
            return diff;
        }
    }
    if (i < aLen)
    {
        return a[i];    // a > b
    }
    if (j < bLen)
    {
        return -b[j];   // a < b
    }
    return 0;       // a = b
}

void testMatch()
{
    freopen("data-c.txt", "r", stdin);
    string t, p;
    while(cin >> t >> p)
    {
        cout << t << "|" << p << ":";
        cout << (int)t.find(p) << ", ";
        cout << indexOf(t, p) << " | ";
        cout << (int)t.rfind(p) << ", ";
        cout << lastIndexOf(t, p) << ", ";
        cout << lastIndexOfFromLast(t, p) << endl;
    }
    fclose(stdin);
    cin.clear();
}

void testCmp()
{
    freopen("cmp.txt", "r", stdin);
    string t, p;
    while(cin >> t >> p)
    {
        cout << "" << t << ">" << p << ": ";
        cout << strcmpare(t, p) << endl;
    }
    fclose(stdin);
    cin.clear();    // 使得打开同一个文件时可用
}

void testStandradCmp()
{
    freopen("cmp.txt", "r", stdin);
    string t, p;
    while(cin >> t >> p)
    {
        cout << "" << t << ">" << p << ": ";
        cout << strcmp(t.c_str(), p.c_str()) << endl;
    }
    fclose(stdin);
    cin.clear();
}

int main()
{
    cout << "test string matching..." << endl;
    testMatch();
    cout << "user define strcmp..." << endl;
    testCmp();
    cout << "c standard strcmp..." << endl;
    testStandradCmp();

    return 0;
}
