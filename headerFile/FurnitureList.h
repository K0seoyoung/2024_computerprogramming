#ifndef FURNITURELIST_H
#define FURNITURELIST_H

#include <vector>
#include <algorithm>

template <typename T>
class FurnitureList {
private:
    std::vector<T*> items;
public:
    ~FurnitureList() {
        for (auto it : items) {
            delete it;
        }
    }

    void add(T* item) {
        items.push_back(item);
    }

    const std::vector<T*>& getItems() const {
        return items;
    }

    void sortBySize() {
        std::sort(items.begin(), items.end(), [](T* a, T* b) {
            return (*a) < (*b);
        });
    }
};

#endif
