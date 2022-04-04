/*
Algorithmic Thinking！！Divide and Conquer 
1.Determine the pivot: q[l]、q[(l+r)/2]、q[random];
2.Adjust section:The left section less than x, and the right section larger than x; 
3.Deal with the left section and right section by recursion;

Algorithmic technique
Firtly, understand the algorithmic thinking.
secondly, remember the template for quickly complishing.
Last, repeating coding the template for 3-5 times.
*/
#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r){
	if(l >= r) return ;
	
	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while(i < j){
		do i ++ ; while(q[i] < x);
		do j -- ; while(q[j] > x);
		if(i < j) swap(q[i], q[j]);
	}
	
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}
int main(){
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &q[i]);
	
	quick_sort(q, 0, n - 1);
	
	for(int i = 0; i < n; i++) printf("%d", q[i]);
	
	return 0;
} 


