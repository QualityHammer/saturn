#pragma once

#include <array>
#include <vector>
#include <map>
#include <unordered_map>

template<class T, std::size_t N>
using Array = std::array<T, N>;
template<class Key, class T>
using Map = std::map<Key, T>;
template<class Key, class T>
using UnorderedMap = std::unordered_map<Key, T>;
template<class T>
using Vector = std::vector<T>;
