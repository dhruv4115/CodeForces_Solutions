#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Card {
    int width, height, index;
};

bool compare(const Card &a, const Card &b) {
    if (a.width == b.width) return a.height < b.height;
    return a.width < b.width;
}

int main() {
    int n, gift_w, gift_h;
    cin >> n >> gift_w >> gift_h;

    vector<Card> cards;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        if (w > gift_w && h > gift_h) cards.push_back({w, h, i + 1});
    }

    sort(cards.begin(), cards.end(), compare);

    int m = cards.size();
    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> lengths(m, 1), previous(m, -1);
    int max_len = 1, last_index = 0;

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (cards[j].width < cards[i].width && cards[j].height < cards[i].height) {
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    previous[i] = j;
                }
            }
        }
        if (lengths[i] > max_len) {
            max_len = lengths[i];
            last_index = i;
        }
    }

    vector<int> sequence;
    while (last_index != -1) {
        sequence.push_back(cards[last_index].index);
        last_index = previous[last_index];
    }

    cout << max_len << endl;
    for (int i = sequence.size() - 1; i >= 0; i--) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}
