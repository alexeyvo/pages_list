#ifndef PAGEDLIST_H
#define PAGEDLIST_H

#include <string>
#include <vector>
#include <algorithm>
#include <boost/btree/btree_set.hpp>

class PagedList
{
  boost::btree::btree_set<int, boost::btree::default_traits, std::greater<int>> _btree;
  unsigned _page_size;
public:
  PagedList(const std::string &filename, unsigned page_size);
  std::vector<int> get_page(size_t index);
  bool insert(int value);
  bool erase(int value);
};

#endif // PAGEDLIST_H
