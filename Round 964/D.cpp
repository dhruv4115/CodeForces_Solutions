#include<iostream>
typedef long long ll;
#include<map>
#include<vector>
#include <string>
#include <limits>
#include <climits>
#include<set>
#include <algorithm> // For sort
using namespace std;
    

std::string replaceQuestionMarks(const std::string &s, const std::string &t) {
    std::string result = s;
    int t_index = 0;
    int n = s.length();
    int m = t.length();

    // Replace '?' with characters from 't'
    for (int i = 0; i < n; ++i) {
        if (result[i] == '?') {
            if (t_index < m) {
                result[i] = t[t_index];
                ++t_index;
            } else {
                result[i] = 'a';  // Replace remaining '?' with 'a'
            }
        }
    }

    // Check if 't' is a subsequence of the result
    int j = 0;
    for (int i = 0; i < result.length(); ++i) {
        if (j < m && result[i] == t[j]) {
            ++j;
        }
    }

    if (j == m) {
        return result;
    } else {
        return "NO";
    }
}


int main(){
    ios_base::sync_with_stdio(false);


    int t;
    cin>>t;

    std::vector<std::string> results;
    results.reserve(t);

    while (t--)
    {
        std::string s, t;
        std::cin >> s >> t;
        std::string result = replaceQuestionMarks(s, t);
        if (result == "NO") {
            results.push_back("NO");
        } else {
            results.push_back("YES");
            results.push_back(result);
        }
    }

    for (const auto &result : results) {
        std::cout << result << std::endl;
    }
    return 0;
    
}