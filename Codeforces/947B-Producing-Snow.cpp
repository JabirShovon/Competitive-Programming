// 947B-Producing-Snow.cpp : Defines the entry point for the console application.
//
// Reference: 1. ProblemSet Link: http://codeforces.com/contest/947/problem/B
//            2. Solution Link: http://codeforces.com/contest/947/submission/36159650
//            3. Editorial Link: http://codeforces.com/blog/entry/58286


#include "stdafx.h"
#include<cstdio>
#include<iostream>
using namespace std;

int N, V[100010], T[100010];
long long S[100010], a[100010], b[100010];
int main() {
   scanf("%d", &N);
   for (int i = 0; i<N; i++) cin >> V[ i];
   for (int i = 0; i<N; i++) cin >> T[ i], S[i + 1] = S[i] + T[i];
   for (int i = 0; i<N; i++) {
      int l = i, r = N + 1, mid;
      while (r - l>1) {
         mid = l + r >> 1;
         if (S[mid] - S[i]<V[i]) l = mid;
         else r = mid;
      }
      a[i]++; a[l]--; b[l] += V[i] - (S[l] - S[i]); 
      // a[] denotes the no of piles exist at ith day with T[i]th temp.
      // b[] denotes the leftover ice volume that is initially made in ith day, but vanishes on lth day
      // so any ice made at ith day will last till lth day. so from i to l-1, it should add 1, meaning its existance, and on lth 
      // day it should be -1, meaning it does not have full amount according to lth day's temp.
   }
   for (int i = 1; i<N; i++) a[i] += a[i - 1]; // to make sure an ice made on ith day and survives till (l-1)th day. since 
   // in the last for loop we already seen a[l]--, which makes sure that ice disappears on lth day. 
   for (int i = 0; i<N; i++) cout << a[i] * T[i] + b[i] << " ";

   return 0;
}

