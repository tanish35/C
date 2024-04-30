#include <iostream>
#include <unordered_set>
#include <cstdlib>
using namespace std;
class RandomizedSet
{
public:
    unordered_set<int> s;
    RandomizedSet()
    {
    }
    bool insert(int val)
    {
        if (s.find(val) != s.end())
        {
            return false;
        }
        s.insert(val);
        return true;
    }
    bool remove(int val)
    {
        if (s.find(val) == s.end())
        {
            return false;
        }
        s.erase(val);
        return true;
    }
    int getRandom()
    {
        int size = s.size();
        int index = rand() % size;
        auto it = s.begin();
        advance(it, index);
        return *it;
    }
};
int main()
{
    RandomizedSet *obj = new RandomizedSet();
    cout << obj->insert(1) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->insert(3) << endl;
    cout << obj->insert(4) << endl;
    cout << obj->getRandom() << endl;
    return 0;
}