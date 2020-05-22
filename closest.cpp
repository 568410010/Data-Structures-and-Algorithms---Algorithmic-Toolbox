#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <float.h>
#include <cstdlib>
#include<ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
using std::vector;
using std::string;
using std::pair;
using std::min;


long double dis(vector<pair<int, int>>& points, int& l, int& r){
    unsigned long long int ans1=(unsigned long long int) (points[l].first-points[r].first)*(points[l].first-points[r].first);
    unsigned long long int ans2=(unsigned long long int) (points[l].second-points[r].second)*(points[l].second-points[r].second);
    //cout<<"before1 "<<points[l].first-points[r].first<<" before2 "<<points[l].second-points[r].second<<endl;
    //cout<<"ans1 "<<ans1<<" ans2 "<<ans2<<endl;
    return (long double) pow(ans1+ans2, 0.5);
}

int binary_search(vector<pair<int, int>>& points, double v, int& l, int& r){
    int left=l, right=r, mid;
    while (left<right){
        mid=(left+right)/2;
        if (points[mid].first<v) left=mid+1;
        else right=mid-1;
    }
    return left;
}

long double MinDis(vector<pair<int, int>>& points, int l, int r){
    if (l==r) return DBL_MAX;
    else if (l+1==r)
        return dis(points, l, r);
    long double leftD, rightD, D, split=points[(l+r)/2].first, d;
    leftD=MinDis(points, l, (l+r)/2);
    rightD=MinDis(points, (l+r)/2+1, r);
    D=leftD<rightD? leftD:rightD;
    int start=binary_search(points, split-D, l, r);
    for (int i=start; i<=r; i++){
        if (points[i].first>split+D) break;
        for (int j=i+1; j<=r && j<=i+6; j++){
            d=dis(points, i, j);
            if (d<D) D=d;
        }
    }
    return D;
}
long double minimal_distance(vector<int> x, vector<int> y) {
    long double ans=0;
    vector<pair<int, int>> points;
    for (int i=0; i<x.size(); i++) points.push_back(make_pair(x[i], y[i]));
    sort(points.begin(), points.end());
    ans=MinDis(points, 0, (int) points.size()-1);
    return ans;
}
double naive(vector<int> x, vector<int> y){
    double ans=DBL_MAX, d;
    for (int i=0; i<x.size(); i++){
        for (int j=i+1; j<x.size(); j++){
            d=pow((unsigned long long int) pow(x[i]-x[j], 2) +(unsigned long long int)pow(y[i]-y[j], 2) ,0.5);
            if (d<ans) ans=d;
        }
    }
    return ans;
}

int main() {
    /*
    srand((unsigned) time(NULL));
    size_t n=1000;
    vector<int> x(n);
    vector<int> y(n);
    
    for (size_t i = 0; i < n; i++) {
        x[i]=rand()%2000000000-1000000000;
        y[i]=rand()%2000000000-1000000000;
    }
    cout<<n<<" "<<x[0]<<y[0]<<endl;
    */
    //cout<<a<<endl;
    
      size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
      
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
  //std::cout << std::setprecision(9) << naive(x, y) << "\n";

}
