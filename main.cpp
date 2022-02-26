#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol562;

/*
 Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
*/
tuple<vector<vector<int>>, int>
testFixture1()
{
  auto matrix = vector<vector<int>>{
      {0, 1, 1, 0},
      {0, 1, 1, 0},
      {0, 0, 0, 1}};
  return make_tuple(matrix, 3);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::longestLine(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  return 0;
}