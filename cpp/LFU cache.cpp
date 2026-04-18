#include <unordered_map>
#include <list>

using namespace std;

struct Node {
    int key;
    int value;
    int freq;
};

class LFUCache {
private:
    int capacity;
    int minFreq;
    // Map key to the iterator of the node in the corresponding frequency list
    unordered_map<int, list<Node>::iterator> keyMap;
    // Map frequency to a list of nodes with that frequency (LRU order within each list)
    unordered_map<int, list<Node>> freqMap;

    void updateFreq(int key) {
        auto it = keyMap[key];
        int f = it->freq;
        int v = it->value;
        
        // 1. Remove the node from its current frequency list
        freqMap[f].erase(it);
        if (freqMap[f].empty()) {
            freqMap.erase(f);
            // If this was the only item at the lowest frequency, increment minFreq
            if (f == minFreq) {
                minFreq++;
            }
        }

        // 2. Insert the node into the next frequency list (freq + 1)
        int newFreq = f + 1;
        freqMap[newFreq].push_front({key, v, newFreq});
        keyMap[key] = freqMap[newFreq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) return -1;
        updateFreq(key);
        return keyMap[key]->value;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        // If key exists, update value and frequency
        if (keyMap.find(key) != keyMap.end()) {
            keyMap[key]->value = value;
            updateFreq(key);
        } else {
            // If capacity is full, evict the LRU node from the LFU list
            if (keyMap.size() >= capacity) {
                int keyToRemove = freqMap[minFreq].back().key;
                keyMap.erase(keyToRemove);
                freqMap[minFreq].pop_back();
                if (freqMap[minFreq].empty()) {
                    freqMap.erase(minFreq);
                }
            }
            // Add new key with initial frequency of 1
            minFreq = 1;
            freqMap[minFreq].push_front({key, value, 1});
            keyMap[key] = freqMap[minFreq].begin();
        }
    }
};
