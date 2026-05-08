#include <unordered_map>

template <typename Key, typename Value>
class KeyValueStorage {
private:
    
    std::unordered_map<Key, Value> data;

public:
    void Insert(const Key& key, const Value& value) {
        data[key] = value;
    }

    void Remove(const Key& key) {
        data.erase(key);
    }

    bool Find(const Key& key, Value* const  value = nullptr) const;
};

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* const value) const {
    auto it = data.find(key);
    if(value != nullptr){
        if(it != data.end()){
            *value = it->second;
        }
    }
    return it != data.end();
}


// bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* const value) const {
//     auto it = std::find(data.begin(), data.end(), key);
//     auto val = *it;
//     if (value != nullptr)
//         value = &val;
//     return it != data.end();
// }