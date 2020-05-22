#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> ans;
    sort(segments.begin(), segments.end(), [](Segment& s1, Segment& s2){return s1.end<s2.end || (s1.end==s2.end && s1.start<s2.start); });
    reverse(segments.begin(), segments.end());
    while (!segments.empty()){
        if (ans.empty() || segments.back().start>ans.back()){
            ans.push_back(segments.back().end);
        }
        segments.pop_back();
            
    }
    return ans;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
