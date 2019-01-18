#include <iostream>
using namespace std;

void  InsertSort(int a[],int right,int step=1)
{
	for (int i = 1; i < right; i=i+step)
	{
			int temp = a[i];
			for (int j = i - 1; j>=0; j--)
			{
				if (temp < a[j])
				{
					a[j + 1] = a[j];
					a[j] = temp;
				}
			}
	}

}
void show(int a[], int left, int right)
{
	for (int i = left; i < right; i++)
		cout << a[i]<<" ";
	cout << endl;
}


void ShellSort(int a[], int left, int right)
{
	int steps[] = {5,3,1};
	int t = sizeof(steps) / sizeof(int);
	for (int i = 0; i < t; i++)
	{
		for (int j = left; (j+steps[i]) < right; j=j++)
		{
			int temp = a[j + steps[i]];

			for (int k = j + steps[i]; k - steps[i] >= 0; k = k - steps[i])
			{
				if (temp < a[k-steps[i]])
				{
					a[k] = a[k-steps[i]];
					a[k - steps[i]] = temp;
				}
			}
		}
		cout << "shellµÚ"<<i+1<<"ÌËÅÅÐò£º" << endl;
		show(a,left,right);
	}

}

int main()
{
	int a[] = { 36, 42, 65, 98, 76, 14, 57, 36 };
	int n = sizeof(a) / sizeof(int);
	printf("Î´ÅÅÐòµÄÊý¾Ý£º\n");
	show(a,0,n);

	InsertSort(a,n);
	printf("Ö±½Ó²åÈëÅÅÐò£º\n");
    show(a, 0, n);

	int b[] = { 36, 42, 65, 98, 76, 14, 57, 36 };
	ShellSort(b,0,n);
	//printf("Ï£¶ûÅÅÐò£º\n");
	//show(b, 0, n);
	return 0;


}