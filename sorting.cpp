#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
using std::vector;
using std::swap;

vector<int> partition2(vector<int> &a, int l, int r) {
    int v=a[l], j=l, m=l;
    for (int i=l+1; i<=r; i++){
        //cout<<"i "<<i<<endl;
      if (a[i]>v) continue;
      else if (a[i]==v) {
          swap(a[i], a[++m]);
      }
      else {
          j++; m++;
          if (j!=m){
              swap(a[i], a[j]);
              swap(a[i], a[m]);
          } else {
              swap(a[i], a[j]);
          }
          
          
          
      }
        //for (auto& q:a) cout<<q<<" ";
        //cout<<endl;
  }
  swap(a[l], a[j--]);
    //cout<<j<<" "<<m<<endl;
    return {j, m};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    vector<int> p;
    int p1, p2;
    while (l<r){
        p=partition2(a, l, r);
        p1=p[0];
        p2=p[1]+1;
        if (p1-l<r-p2){
            if (p1-l+1>1) randomized_quick_sort(a, l, p1);
            l=p2;
        } else {
            if (r-p2+1>1) randomized_quick_sort(a, p2, r);
            r=p1;
        }
    }
        
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
