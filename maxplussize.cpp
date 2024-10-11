#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//A. Max Plus Size Codeforces Round 975 (Div. 2)
int main() {
    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int n;
        cin >> n;  // length of array
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];  // input array elements
        }

        // We need to calculate the maximum possible score
        int max_value = 0;  // This will store the max value of selected red elements
        int count = 0;      // This will store how many elements we selected as red

        // We will iterate and pick every alternate element starting from index 0 or 1
        for (int i = 0; i < n; i += 2) {
            max_value = max(max_value, a[i]);  // Track the maximum red value
            count++;  // We select this element
        }

        // There could be a better solution by starting from index 1, so we compare both
        int max_value_alt = 0;
        int count_alt = 0;
        for (int i = 1; i < n; i += 2) {
            max_value_alt = max(max_value_alt, a[i]);
            count_alt++;
        }

        // Compute the score for both possible starting points and take the maximum
        int score1 = max_value + count;  // score starting from index 0
        int score2 = max_value_alt + count_alt;  // score starting from index 1
        
        cout << max(score1, score2) << endl;
    }
    return 0;
}
