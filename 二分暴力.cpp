/*
*	Writer:huwei Cheng
*  Number:19120332
*  Date:2019/09/22
*/
#include"iostream"
using namespace std;
/*
*N：绳子个数
*K：需要切割出的绳子条数
*  i：循环变量
*L：各绳子长度浮点数组
*lenNum：分割绳子长度的个数
*maxLen：绳子的最长长度
*/
double lenNum = 100.0;
double maxLen = 0.0;
void brute_force(double *L, double left, double right, int N, int K)
{
	if ((int)(left*100) <(int)( right*100))//题目要求保留两位小数，所以判断有效数字长度为3的值即可
	{
		double mid = (left + right) / 2.0;
		int i, lenNum = 0;
		for (i = 0; i < N; i++)
			lenNum += (int)(L[i] / mid);
		if (lenNum > K)//说明此时的mid过小，分得绳子过多，需要增大绳子长度
			brute_force(L, mid, right, N, K);
		else if (lenNum < K)//说明此时的mid过大，分得绳子较少，需要减小绳子长度
			brute_force(L, left, mid, N, K);
		else//找出最大绳子长度
		{
			maxLen = mid;
			brute_force(L, mid + 0.01, right, N, K);
		}
	}
}
int main()
{
	int N, K,i;
	double *L;
	cin >> N >> K;
	L = new double[N];
	for (i = 0; i < N; i++)
		cin >> L[i];
	brute_force(L, 0.0, lenNum, N, K);
	printf("%.2lf\n", maxLen);
	system("pause");
	return 0;
}