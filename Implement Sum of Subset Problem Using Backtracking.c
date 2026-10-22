# include <stdio.h>
int arr[100], subset[100];
int n, target;
int found = 0;

void subsetSum(int index, int sum, int size)
{
	if (sum == target)
	{
		found = 1;
		for (int i = 0; i < size; i++)
		{
			printf("%d ", subset[i]);
		}
		printf("\n");
		return;
	}
	if(index == n || sum > target)
		return;
	subsetSum(index + 1, sum, size);
	subset[size] = arr[index];
	subsetSum(index + 1, sum + arr[index], size + 1);



}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &target);
	subsetSum(0, 0, 0);
	if (!found)
		printf("-1");
	return 0;
}
