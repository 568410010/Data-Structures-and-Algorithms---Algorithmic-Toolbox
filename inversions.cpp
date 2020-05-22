#include <iostream>
#include <vector>
using namespace std;
using std::vector;
long long total;
vector<int> mergesort(vector<int>& nums){
    //for (int& i:nums) cout<<i<<" ";
    //cout<<endl;
    if (nums.size()<2) return nums;
    vector<int> ans, a, b;
    for (int i=0; i<nums.size(); i++){
        if (i<nums.size()/2) a.push_back(nums[i]);
        else b.push_back(nums[i]);
    }
    a=mergesort(a);
    b=mergesort(b);
    while (!a.empty() || !b.empty()){
        if (!a.empty() && !b.empty()){
            if (a[0]<=b[0]){
                ans.push_back(a[0]);
                a.erase(a.begin());
            } else {
                ans.push_back(b[0]);
                b.erase(b.begin());
                total+=a.size();
            }
        } else if (a.empty()){
            for (int& num:b){
                ans.push_back(num);
            }
            break;
        } else {
            for (int& num:a){
                ans.push_back(num);
            }
            break;
        }
    }
    
    return ans;
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
    total=0;
    mergesort(a);
    //cout<<"total "<<total<<endl;
    return total;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << get_number_of_inversions(a, 0, a.size()) << '\n';
}
