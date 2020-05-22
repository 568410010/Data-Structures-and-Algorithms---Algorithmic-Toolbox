#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    unordered_map<int, int> cnt;
    for (int& num:a){
        
        if (++cnt[num]>a.size()/2) return 1;
        //cout<<num<<" "<<cnt[num]<<endl;
    }
        
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
