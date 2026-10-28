#include <vector>
#include <algorithm>

using namespace std;

class ATM {
private:
    vector<long long> cnt;
    vector<int> value;

public:
    ATM() {
        cnt = vector<long long>(5, 0);
        value = {20, 50, 100, 200, 500};
    }

    void deposit(vector<int> banknotesCount) {

        for (int i = 0; i < 5; i++) {
            cnt[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {

        vector<int> used(5, 0);

        long long remaining = amount;

        for (int i = 4; i >= 0; i--) {

            long long take =
                min(cnt[i],
                    remaining / value[i]);

            used[i] = (int)take;

            remaining -= take * value[i];
        }

        if (remaining != 0) {
            return {-1};
        }

        for (int i = 0; i < 5; i++) {
            cnt[i] -= used[i];
        }

        return used;
    }
};