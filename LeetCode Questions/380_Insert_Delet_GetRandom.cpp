// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class RandomizedSet
{
private:
    vector<int> nums;
    unordered_map<int, int> m;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (m.find(val) != m.end())
            return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (m.find(val) == m.end())
            return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        RandomizedSet *obj = new RandomizedSet();
        bool param_1 = obj->insert(1);
        bool param_2 = obj->remove(2);
        int param_3 = obj->getRandom();
        cout << param_1 << " " << param_2 << " " << param_3 << endl;
    }
    return 0;
}