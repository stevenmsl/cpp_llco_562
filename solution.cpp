#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol562;
using namespace std;

/*takeaways
  - we scan the matrix from left to right, top to bottom
    so we can just check the previous position wile summing
    up how many 1's we have accumulated so far in a given
    direction
  - when we enter a location that is occupied by a one ,
    we look at what we have accumulated previously in
    all directions and add one to each of them, and
    check if we need to update the global max value
*/
int Solution::longestLine(vector<vector<int>> &matrix)
{
  const int m = matrix.size();
  const int n = matrix[0].size();

  /*dp[i][j][d]
    - records how many consecutive 1's you have
      accumulated when you are in coordinate (i.j)
      moving along direction "d"
  */
  auto dp = vector<vector<vector<int>>>(
      m, vector<vector<int>>(
             n, vector<int>(4, 0)));

  /* store direction instruction of how to move to the
     previous position in all 4 directions under the
     assumption the matrix is scanned from left to
     right, top to bottom
    - horizontal: one left
    - vertical: one up
    - diagonal: one up and one left
    - anti-diagonal: one up and one right
  */
  const auto dirs = vector<pair<int, int>>{
      {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};

  auto result = 0;

  for (auto i = 0; i < m; i++)
    for (auto j = 0; j < n; j++)
      if (matrix[i][j] == 1)
        for (auto d = 0; d < 4; d++)
        {
          /* find the previous location in this dirction */
          auto px = i + dirs[d].first;
          auto py = j + dirs[d].second;
          dp[i][j][d] = px >= 0 && px < m && py >= 0 && py < n
                            ? dp[px][py][d] + 1
                            : 1;
          /*record the longest one */
          result = max(result, dp[i][j][d]);
        }

  return result;
}