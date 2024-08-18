#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>

using namespace std;

class CuckooHashMap {
private:
    vector<int> table1;
    vector<int> table2;
    hash<int> hash1;
    hash<int> hash2;
    size_t capacity;
    size_t size;

    void rehash() {
        // Rehashing logic
        vector<int> oldTable1 = table1;
        vector<int> oldTable2 = table2;
        capacity *= 2;
        table1.resize(capacity, -1);
        table2.resize(capacity, -1);
        size = 0;

        for (int key : oldTable1) {
            if (key != -1) insert(key);
        }
        for (int key : oldTable2) {
            if (key != -1) insert(key);
        }
    }

public:
    CuckooHashMap(size_t cap) : capacity(cap), size(0) {
        table1.resize(capacity, -1);
        table2.resize(capacity, -1);
    }

    void insert(int key) {
        if (size >= capacity / 2) rehash();
        size_t idx1 = hash1(key) % capacity;
        size_t idx2 = hash2(key) % capacity;

        while (true) {
            if (table1[idx1] == -1) {
                table1[idx1] = key;
                size++;
                return;
            } else if (table2[idx2] == -1) {
                table2[idx2] = key;
                size++;
                return;
            } else {
                std::swap(key, table1[idx1]);
                idx1 = hash1(key) % capacity;
                std::swap(key, table2[idx2]);
                idx2 = hash2(key) % capacity;
            }
        }
    }

    bool search(int key) {
        size_t idx1 = hash1(key) % capacity;
        size_t idx2 = hash2(key) % capacity;
        return table1[idx1] == key || table2[idx2] == key;
    }
};

int main() {
    CuckooHashMap map(5);
    map.insert(10);
    map.insert(20);
    std::cout << "Search 10: " << map.search(10) << std::endl;
    std::cout << "Search 30: " << map.search(30) << std::endl;
    return 0;
}