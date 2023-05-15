#pragma once
#include <concepts>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <regex>
#include <string>
#include <map>
#include <queue>
#include <mutex>

#define STR(arg) string(arg)

using std::function;
using std::list;
using std::make_pair;
using std::make_shared;
using std::make_unique;
using std::map;
using std::mutex;
using std::queue;
using std::shared_ptr;
using std::string;
using std::vector;

template <typename T>
using sptr = std::shared_ptr<T>;

template <typename T>
using uptr = std::unique_ptr<T>;

template <typename T>
using wptr = std::weak_ptr<T>;
