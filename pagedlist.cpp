#include "pagedlist.h"
#include <iostream>

PagedList::PagedList(const std::string &filename, unsigned page_size) : _btree(filename, boost::btree::flags::truncate)
{
  _page_size = page_size;
}

std::vector<int> PagedList::get_page(size_t index)
{
  std::vector<int> page;
  page.reserve(_page_size);

  auto it = _btree.begin();
  // TODO: replace std::advance(O(n) complexity) with select() from order statictic tree(gives O(log n) complexity)
  // https://en.wikipedia.org/wiki/Order_statistic_tree
  std::advance(it, index * _page_size);
  for (; it != _btree.end() && page.size() < _page_size; ++it)
    page.push_back(*it);

  return page;
}

bool PagedList::insert(int value)
{
  return _btree.insert(value).second;
}

bool PagedList::erase(int value)
{
  return _btree.erase(value) > 0;
}
