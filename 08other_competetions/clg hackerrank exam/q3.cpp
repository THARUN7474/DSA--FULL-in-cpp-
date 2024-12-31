#include <bits/stdc++.h>
using namespace std;

#define ll long long


bool canPlaceStations(vector<ll>& locations, ll n, ll k, ll dist) {
    ll count = 1;
    ll lastPosition = locations[0];

    for (ll i = 1; i < n; ++i) {
        if (locations[i] - lastPosition >= dist) {
            count++;
            lastPosition = locations[i];
        }
        if (count >= k) return true;
    }
    return false;
}

ll largestMinDist(vector<ll>& locations, ll n, ll k) {
    sort(locations.begin(), locations.end());

    ll left = 1; 
    ll right = locations[n-1] - locations[0]; 
    ll result = 0;

    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (canPlaceStations(locations, n, k, mid)) {
            result = mid; 
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return result;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> locations(n);
    for (ll i = 0; i < n; ++i) {
        cin >> locations[i];
    }

    cout << largestMinDist(locations, n, k) << endl;
    return 0;
}
