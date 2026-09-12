#include <stdio.h>
struct Result{
	int min;
	int max;
};
struct Result FindMinMax(int array[],int low,int high)
{
	struct Result result,left,right;
	if(low==high)
	{
		result.min=array[low];
		result.max=array[low];
		return result;
	 } 
	 if(high==low+1)
	 {
	 	if(array[low]>array[high])
	 	{
	 		result.min=array[high];
	 		result.max=array[low];
	 		
	 	
		 }
		 else
		 {
		 	result.max=array[high];
		 	result.min=array[low];
		 }
		 return result;
		 
	 }
	 int mid=(low+high)/2;
	 left=FindMinMax(array,low,mid);
	 right=FindMinMax(array,mid+1,high);
	 result.max=(left.max>right.max) ? left.max:right.max;
	 result.min=(left.min<right.min) ? left.min:right.min;
	 return result;
	 
}
int main()
{
	int array[100], n, i;
    struct Result result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    result =FindMinMax(array, 0, n - 1);

    printf("Maximum element = %d\n", result.max);
    printf("Minimum element = %d\n", result.min);

    return 0;
}
