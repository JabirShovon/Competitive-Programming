// SoldierAndBadges-546B.cpp : Defines the entry point for the console application.
//
// Reference: 1. http://codeforces.com/problemset/problem/546/B
//            2. https://github.com/jackiehluo/practice/blob/master/codeforces/500s/546b-soldier-and-badges.cpp

#include "stdafx.h"
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1e5 + 1;
typedef vector<int> vi;
typedef pair<int, int> pii;

pii p[200050];
vi v;

int main()
{
   int n, m, res;
   string str;
   //int num[MAX] = {0};

   int in = 0, cost = 0, diff;

   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> in;
      v.push_back(in);
   }

   sort(v.begin(), v.begin() + n);

   for (int i = 1; i < n; ++i)
   {
      if (v[i] == v[i - 1])
         v[i]++, cost++;
      else if (v[i] < v[i - 1])
         diff = v[i - 1] - v[i],
         v[i] += diff, cost += diff,
         v[i]++, cost++;
   }
   cout << cost;
   return 0;
}

