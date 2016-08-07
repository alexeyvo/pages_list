#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include "pagedlist.h"

std::vector<int> get_randoms(size_t size)
{
  std::set<int> vals_without_duplicates;

  while (vals_without_duplicates.size() < size)
    vals_without_duplicates.insert(rand() % std::numeric_limits<int>::max());

  std::vector<int> v(vals_without_duplicates.begin(), vals_without_duplicates.end());
  return v;
}

int main(int, char *[])
{
  auto randoms = get_randoms(1000);

  const int page_size = 50;
  PagedList list("set.btr", page_size);
  for (size_t i = 0; i < randoms.size(); ++i)
    list.insert(randoms[i]);

  std::sort(randoms.begin(), randoms.end(), std::greater<int>());
  auto pages_count = randoms.size() / page_size;
  for (size_t i = 0; i < pages_count; ++i)
  {
    auto page = list.get_page(i);
    auto equal = std::equal(page.begin(), page.end(), randoms.begin() + i * page_size);
    std::cout << "page " << i << " equal " << equal << "\n";
  }

  return 0;
}
