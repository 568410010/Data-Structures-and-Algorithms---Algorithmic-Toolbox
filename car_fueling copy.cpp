#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int ans=0, reachable=tank, last=0;
    stops.push_back(dist);
    for (int i=0; i<stops.size(); i++){
        if (stops[i]>reachable){
            ans++;
            if (last>=stops[i]) reachable=last;
            else return -1;
        }
        last=stops[i] + tank;
        //cout<<"last "<<last<<" reachable "<<reachable<<endl;
        //cout<<"ans "<<ans<<endl;
    }
    return ans;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
