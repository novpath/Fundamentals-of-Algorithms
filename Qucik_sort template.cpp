/*
Algorithmic Thinking--Divide and Conquer 
1.Determine the pivot: q[l], q[(l+r)/2], q[random];
2.Adjust section:The left section less than x, and the right section larger than x; <key step>
3.Deal with the left section and right section by recursion;
Algorithmic technique
Firtly, understand the algorithmic thinking.
secondly, remember the template for quickly complishing.
Last, repeating code the template for 3-5 times.
How to adjust section?
Method 1:
1.Create two array--a[], b[];
2.Traverse every q[l~r] element, if q[i]<=x; x->a[];
  if q[i]>x; x->b[];("->" means insert)
3.a[]->q[], b[]->q[]; 
Method 2:
1.Two pointers move from the left and right respectively.
2.The left pointer 'i' move while the q[i] < x;
  The right pointer 'j' move while the q[j] > x;
3.Swap q[i], q[j];
Time complexity:Average--O(nlogn)  Worst--O(n^2)
Space complexity:O(1) 
Stability of Sorting Algorithms:Unstable
*/
#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int left, int right){
    if(left >= right) return;
    int i = left - 1, j = right + 1, pivot = q[i + j >> 1];
    
    while(i < j){
        while(q[--j] > pivot);
        while(q[++i] < pivot);
        if(i < j) swap(q[i], q[j]);
    }
    
    quick_sort(q, left, j);
    quick_sort(q, j + 1, right);
}

int main(){
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &q[i]);
	
	quick_sort(q, 0, n - 1);
	
	for(int i = 0; i < n; i++) {
		printf("%d", q[i]);
		if(i < n - 1)
		printf(" ");
	}
	
	return 0;
} 
