#ifndef GENERICCONTAINER_H
#define GENERICCONTAINER_H

#include <vector>

template <typename T>
class GenericContainer {
private:
    std::vector<T> items;
public:
    void add(const T& item) {
        items.push_back(item);
    }

    const std::vector<T>& getItems() const {
        return items;
    }

    // 특정 인덱스의 요소 반환 (예외 처리)
    T get(size_t index) const {
        if (index >= items.size()) {
            throw std::out_of_range("Index out of range in GenericContainer.");
        }
        return items[index];
    }

    size_t size() const {
        return items.size();
    }
};

#endif
