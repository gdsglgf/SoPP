#include <iostream>
#include "Bigraph.h"

using namespace std;

extern int counter;     /// ʹ��ȫ�ֱ���

int main()
{
    Bigraph g("data.txt", "output-data.txt");
    //g.openOutputFile();
    g.execute();
    cout << "The total search times is " << counter << endl;

    return 0;
}
