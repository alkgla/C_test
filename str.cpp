#include <iostream>
#include <vector>
using namespace std;

/* 字符串全排列
如abc的全排列：abc, acb, bca, dac, cab, cba
思路：a不动，后面的bc交换得到abc,acb */

void Permutation(char *pStr, char *pBegin)
{
    if (*pBegin == '\0')
        printf("%s\n", pStr);
    else
    {
        for (char *pCh = pBegin; *pCh != '\0'; pCh++)
        {
            swap(*pBegin, *pCh);
            Permutation(pStr, pBegin + 1);
            swap(*pBegin, *pCh);
        }
    }
}
//k表示当前选取到第几个数，m表示共有多少个数
void Permutation(char *pStr, int k, int m)
{
    if (k == m)
    {
        static int num = 1; //局部静态变量，用来统计全排列的个数
        printf("第%d个排列\t%s\n", num++, pStr);
    }
    else
    {
        for (int i = k; i < m; i++)
        {
            swap(*(pStr + k), *(pStr + i));
            Permutation(pStr, k + 1, m);
            swap(*(pStr + k), *(pStr + i));
        }
    }
}

/* 字符串组合
如abc的组合有a、b、c、ab、ac、bc、abc 
思路：先从头扫描字符串的第一个字符。针对第一个字符，我们有两种选择：
    1.第一是把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符；
    2.第二是不把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选择m个字符
*/

void Combination(char *string, int number, vector<char> &result)
{
    if (number == 0)
    {
        static int num = 1;
        printf("第%d个组合\t", num++);

        vector<char>::iterator iter = result.begin();
        for (; iter != result.end(); ++iter)
            printf("%c", *iter);
        printf("\n");
        return;
    }
    if (*string == '\0')
        return;
    result.push_back(*string);
    Combination(string + 1, number - 1, result);
    result.pop_back();
    Combination(string + 1, number, result);
}

/* 入口 */
void Combination(char *string)
{
    vector<char> result;
    int i, length = sizeof(string) - 1;
    /* i 位数的组合 */
    for (i = 1; i <= length; ++i)
    {
        Combination(string, i, result);
    }
}
/* 组合思路2，利用位 */

void CombinationByte(char *string)
{
    int len = sizeof(string) - 1;
    for (int i = 0; i < (1 << len); ++i)
    {
        printf("%d: ====================\n", i);
        printf("{");

        for (int j = 0; j < len; ++j)
        {
            if (i & (1 << j))
            {                             // 判断s的二进制中哪些位为1，即代表取某一位
                printf("%c ", string[j]); //或者a[i]
                // printf("%d : %d\n", i, 1 << j);
            }
        }
        printf("}\n");
    }
}
int main()
{
    char str[] = "abc";
    // Permutation(str, str);
    // Permutation(str, 0, sizeof(str) - 1);
    // Combination(str);
    CombinationByte(str);
    system("pause");
}
