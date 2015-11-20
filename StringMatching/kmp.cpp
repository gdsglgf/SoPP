#include <iostream>
#include <string>
using namespace std;

void print(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void compute_prefix_function(int *pi, string p)
{
    int m = p.size();
    pi[0] = 0;
    int k = 0;
    for (int q = 1; q < m; q++)
    {
        while (k > 0 && p[k] != p[q])
        {
            k = pi[k];
        }
        if (p[k] == p[q])
        {
            k++;
        }
        pi[q] = k;
    }
}

void kmp_matcher(string t, string p)
{
    int n = t.size();
    int m = p.size();
    int *pi = new int[m];
    compute_prefix_function(pi, p);
    print(pi, m);
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && p[q] != t[i])
        {
            q = pi[q];
        }
        if (p[q] == t[i])
        {
            q++;
        }
        if (q == m)
        {
            cout << "Pattern occurs with shift:" << i - q + 1 << endl;
            q = pi[q - 1] + 1;
        }
    }
    delete [] pi;
}

void compute_prefix_function2(int *pi, string p)
{
    int m = p.size();
    pi[0] = -1;
    int k = -1;
    for (int q = 1; q < m; q++)
    {
        while (k > -1 && p[k + 1] != p[q])
        {
            k = pi[k];
        }
        if (p[k + 1] == p[q])
        {
            k++;
        }
        pi[q] = k;

    }
}

void kmp_matcher2(string t, string p)
{
    int n = t.size();
    int m = p.size();
    int *pi = new int[m];
    compute_prefix_function2(pi, p);
    print(pi, m);
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (pi[j] == -1)
            {
                i++;
            }
            i += pi[j] + 1;
            j = 0;
        }

        if (j == m)
        {
            cout << "Found: " << i - j << endl;
            j = pi[j - 1] + 1;
        }
    }

    delete [] pi;
}

int main()
{
    kmp_matcher("bacbababababcabab", "ababababca");
    kmp_matcher2("bacbababababcabab", "ababababca");
    
    kmp_matcher("bacbababababcabab", "ba");
    kmp_matcher2("bacbababababcabab", "ba");
    
    kmp_matcher2("bacbababababcabab", "ab");
    kmp_matcher2("bacbababababcabab", "aba");
    return 0;
}
