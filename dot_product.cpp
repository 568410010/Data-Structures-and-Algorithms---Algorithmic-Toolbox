#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
    long long ans=0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0; i<a.size(); i++){
        ans+=(long long) a[i]*b[i];
    }
    return ans;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}