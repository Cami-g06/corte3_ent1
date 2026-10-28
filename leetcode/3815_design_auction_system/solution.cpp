#include <unordered_map>
#include <set>

using namespace std;

class AuctionSystem {
private:

    unordered_map<long long, int> bidValue;

    unordered_map<int, set<pair<int,int>>> itemBids;

    long long makeKey(int userId, int itemId) {
        return ((long long)userId << 32) | itemId;
    }

public:

    AuctionSystem() {}

    void addBid(int userId,
                int itemId,
                int bidAmount) {

        long long key = makeKey(userId, itemId);

        if (bidValue.count(key)) {

            int oldBid = bidValue[key];

            itemBids[itemId].erase(
                {oldBid, userId});
        }

        bidValue[key] = bidAmount;

        itemBids[itemId].insert(
            {bidAmount, userId});
    }

    void updateBid(int userId,
                   int itemId,
                   int newAmount) {

        long long key = makeKey(userId, itemId);

        int oldAmount = bidValue[key];

        itemBids[itemId].erase(
            {oldAmount, userId});

        bidValue[key] = newAmount;

        itemBids[itemId].insert(
            {newAmount, userId});
    }

    void removeBid(int userId,
                   int itemId) {

        long long key = makeKey(userId, itemId);

        int amount = bidValue[key];

        itemBids[itemId].erase(
            {amount, userId});

        bidValue.erase(key);

        if (itemBids[itemId].empty()) {
            itemBids.erase(itemId);
        }
    }

    int getHighestBidder(int itemId) {

        if (itemBids.find(itemId) ==
            itemBids.end()) {

            return -1;
        }

        auto it = itemBids[itemId].rbegin();

        return it->second;
    }
};