/*
Algorithmic Thinking--Based on quick_sort to select TOP K
1.Determine the pivot: q[l], q[(l+r)/2], q[random];
2.Adjust section:The left section less than x, and the right section larger than x; <key step>
After the two steps, there are sl numbers which less than x ( <= x)
3.if k <= sl, deal the left section by recursion.
  if k > sl, deal the right section by recursion.

Time complexity:Average--O(n) 
    The every times expect to deal the sequence length n, n/2, n/4 ......
	n + n/2 + n/4 + ... = n(1 + 1/2 + 1/4 + ...) <= 2n
	Worst--O(n^2)
Space complexity:O(1) 
Stability of Sorting Algorithms:Unstable
Attention:
I.Whole sequence TOP K, is the right sequence TOP (K - sl)
II.After one time recursion, the i == j or i == j + 1;
*/
#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N];

int quick_select(int left, int right, int k){
    if(left >= right) return q[left];
    int i = left - 1, j = right + 1, pivot = q[i + j >> 1];
    
    while(i < j){
        while(q[ -- j] > pivot);
        while(q[ ++ i] < pivot);
        if(i < j) swap(q[i], q[j]);
    }
    
    int sl = j - left + 1;
    if(k <= sl)
    return quick_select(left, j, k);
    else
    return quick_select(j + 1, right, k - sl);
    
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    
    printf("%d", quick_select(0, n - 1, k));
    
    return 0;
}
