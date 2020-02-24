#include <sys/time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define PAGE_SIZE 8192
#define TOTAL_MEM_SIZE (4096 * 8192)
#define L1_CACHE_LINE_SIZE 64 

using namespace std;

int main() {
    cout<<"# Bytes\t\tTime\n";
    for (long long i1=2; i1 < 1<<18; i1=i1<<1) {
        double total_time;
        int *a, *b;
        struct timeval t1, t2;
        long long num_iter, k, l, i;
    	long long num_cache_lines_guess = i1;
        
        b = a = (int *)malloc(TOTAL_MEM_SIZE);

    	for(k = 0; k < TOTAL_MEM_SIZE/PAGE_SIZE; k++, a += 2048)
        	*a = 1;

    	num_iter = TOTAL_MEM_SIZE / (num_cache_lines_guess * L1_CACHE_LINE_SIZE); 

    	gettimeofday(&t1,0);

    	for(a = b,k = 0; k < num_iter; k++, a = b) {
        	for(l = 0; l < num_cache_lines_guess; l++,a += 8)
            		i = *a;
    	}
        
        
    	gettimeofday(&t2,0);
   	total_time = ((t2.tv_sec-t1.tv_sec)*1000000000 + (t2.tv_usec-t1.tv_usec))*1000;
    	cout<<num_cache_lines_guess * L1_CACHE_LINE_SIZE<<"\t\t"<<total_time/num_iter<<"\n";
    }
    return 0;
}
