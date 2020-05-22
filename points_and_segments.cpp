#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdint>
#define __STDC_LIMIT_MACROS
#include <stdint.h>

using namespace std;
using std::vector;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> ans(points.size(), 0);
    vector<pair<int, int>> ps;
    for (int i=0; i<starts.size(); i++) ps.push_back(make_pair(starts[i], -1));
    for (int i=0; i<ends.size(); i++) ps.push_back(make_pair(ends[i], points.size()));
    for (int i=0; i<points.size(); i++) ps.push_back(make_pair(points[i], i));
    sort(ps.begin(), ps.end());
    int start=0, end=0;
    for (auto& p:ps){
        if (p.second==-1) start++;
        else if (p.second==points.size()) end++;
        else ans[p.second]+=start-end;
        //cout<<"p "<<p.first<<" type "<<p.second<<endl;
    }
    
    return ans;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
      for (size_t j = 0; j < starts.size(); j++) {
        cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
      }
    }
    return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
    /*
    cout<<endl;
    vector<int> cnt2 = naive_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
      std::cout << cnt2[i] << ' ';
    }*/
}
