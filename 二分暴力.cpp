/*
*	Writer:huwei Cheng
*  Number:19120332
*  Date:2019/09/22
*/
#include"iostream"
using namespace std;
/*
*N�����Ӹ���
*K����Ҫ�и������������
*  i��ѭ������
*L�������ӳ��ȸ�������
*lenNum���ָ����ӳ��ȵĸ���
*maxLen�����ӵ������
*/
double lenNum = 100.0;
double maxLen = 0.0;
void brute_force(double *L, double left, double right, int N, int K)
{
	if ((int)(left*100) <(int)( right*100))//��ĿҪ������λС���������ж���Ч���ֳ���Ϊ3��ֵ����
	{
		double mid = (left + right) / 2.0;
		int i, lenNum = 0;
		for (i = 0; i < N; i++)
			lenNum += (int)(L[i] / mid);
		if (lenNum > K)//˵����ʱ��mid��С���ֵ����ӹ��࣬��Ҫ�������ӳ���
			brute_force(L, mid, right, N, K);
		else if (lenNum < K)//˵����ʱ��mid���󣬷ֵ����ӽ��٣���Ҫ��С���ӳ���
			brute_force(L, left, mid, N, K);
		else//�ҳ�������ӳ���
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