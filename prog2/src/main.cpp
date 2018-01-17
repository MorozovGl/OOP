#include "StatisticMultiset.h"

#include <iostream>

int main() {
    StatisticMultiset<int> mset, mset2;
    mset.AddNum(5);
    mset.AddNum(25);
    std::cout << mset.GetAvg() << '\n';
    mset2.AddNum(3);
    mset2.AddNum(7);
    mset.AddNums(mset2);
    std::cout << mset.GetAvg() << '\n';
    std::cout << mset.GetCountAbove(5) << '\n';
    std::cout << mset.GetCountAbove(5) << '\n';
    std::cout << mset.GetMin();

    return 0;
}