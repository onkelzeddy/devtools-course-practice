// Copyright 2023 Zorin Oleg

#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

#include <list>
#include <algorithm>
#include <stdexcept>

template<class T>
class PriorityQueue {
  std::list<T> data;
 public:
  PriorityQueue();
  explicit PriorityQueue(const T);
  PriorityQueue(const PriorityQueue &other);

  void put(const T &value);
  void pop();
  const T &top() const;

  T get();
  bool empty() const;
  size_t size() const;
  void clear();
  PriorityQueue& operator=(const PriorityQueue& other);
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
