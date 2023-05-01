// Copyright 2023 Zorin Oleg

#include "include/priority_queue.h"

template<class T>
PriorityQueue<T>::PriorityQueue() = default;

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &other)
    :data(other.data) {}

template<class T>
PriorityQueue<T> &PriorityQueue<T>::operator=(const PriorityQueue &other) {
  data = other.data;
  return *this;
}

template<class T>
void PriorityQueue<T>::put(const T &value) {
  auto position = std::upper_bound(data.begin(), data.end(), value);
  data.insert(position, value);
}

template<class T>
PriorityQueue<T>::PriorityQueue(const T value) {
    put(value);
}

template<class T>
const T &PriorityQueue<T>::top() const {
  if (empty())
    throw std::string("Cant top() because queue is empty");
  return data.back();
}

template<class T>
void PriorityQueue<T>::pop() {
  if (empty())
    throw std::string("Cant pop() because queue is empty");
  data.pop_back();
}

template<class T>
T PriorityQueue<T>::get() {
  if (empty())
    throw std::string("Cant get() because queue is empty");
  T value = data.back();
  data.pop_back();
  return value;
}

template<class T>
bool PriorityQueue<T>::empty() const {
  return data.empty();
}

template<class T>
size_t PriorityQueue<T>::size() const {
  return data.size();
}

template<class T>
void PriorityQueue<T>::clear() {
  data.clear();
}

template
class PriorityQueue<int>;
