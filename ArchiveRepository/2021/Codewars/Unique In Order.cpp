#include <string>
#include <vector>


template <typename ItSource, typename T> std::vector<T> generalization(const ItSource itBegin, const ItSource itEnd)
{
   std::vector<T> result;
   result.push_back(*itBegin);
  if(itBegin + 1 < itEnd){
  for(auto it = itBegin + 1; it != itEnd; ++it){
    if(*it != *(it - 1)) result.push_back(*it);
  }
  }
  return result;
}

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  if(iterable.empty()) return iterable;
  return generalization<typename std::vector<T>::const_iterator, T>(iterable.begin(), iterable.end());
}

std::vector<char> uniqueInOrder(const std::string& iterable){
  if(iterable.empty()) return std::vector<char>{};
  return generalization<std::string::const_iterator,char>(iterable.begin(), iterable.end());
}