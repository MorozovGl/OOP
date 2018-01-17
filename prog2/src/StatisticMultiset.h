//
// Created by Morozov Gleb on 22.11.17.
//

#pragma once

#include <vector>
#include <set>
#include <list>
#include <fstream>
#include <map>

template<class T>
class StatisticMultiset {

private:
    std::multiset<T> multset;
    T min;
    T max;
    float avg;
    mutable T countUnder;
    mutable T countAbove;
    mutable std::vector<float> countAboveCache;
    mutable std::vector<float> countUnderCache;
    mutable std::map<float, int> countAboveAns;
    mutable std::map<float, int> countUnderAns;

public:
    StatisticMultiset() = default;
    ~StatisticMultiset() = default;
    void AddNum( const T& numbers);
    void AddNum( const std::multiset<T>& numbers );
    void AddNum( const std::vector<T>& numbers );
    void AddNum( const std::list<T>& numbers );
    void AddNums( const StatisticMultiset& a_stat_set );
    void AddNumsFromFile( const char* filename );
    T GetMax() const;
    T GetMin() const;
    float GetAvg() const;
    int GetCountUnder( float threshold ) const;
    int GetCountAbove( float threshold ) const;
};

template<class T>
void StatisticMultiset<T>::AddNum( const T& numbers){
    if(numbers < min) min = numbers;
    if(numbers > max) max = numbers;
    multset.insert(numbers);
    if (multset.size() == 1) { max = numbers; min = numbers; avg = numbers; }
    else avg = (avg*(multset.size() - 1) + numbers) / multset.size();
}

template<class T>
void StatisticMultiset<T>::AddNum( const std::multiset<T>& numbers ){
    for(auto &it : numbers)
        AddNum(it);
}

template<class T>
void StatisticMultiset<T>::AddNum( const std::vector<T>& numbers ){
    for(auto &it : numbers)
        AddNum(it);
}

template<class T>
void StatisticMultiset<T>::AddNum( const std::list<T>& numbers ){
    for(auto &it : numbers)
        AddNum(it);
}

template<class T>
void StatisticMultiset<T>::AddNums( const StatisticMultiset& a_stat_set ){
    if(this != &a_stat_set)
        AddNum(a_stat_set.multset);
}

template<class T>
void StatisticMultiset<T>::AddNumsFromFile( const char* filename ){
    std::ifstream cin(filename);
    T x;
    while (!cin.eof()) {
        cin >> x;
        AddNum(x);
    }
}
template<class T>
float StatisticMultiset<T>::GetAvg() const {
    return avg;
}

template<class T>
T StatisticMultiset<T>::GetMin() const {
    return min;
}

template<class T>
T StatisticMultiset<T>::GetMax() const {
    return max;
}

template<class T>
int StatisticMultiset<T>::GetCountUnder( float threshold ) const{
    auto request = std::find(countUnderCache.begin(), countUnderCache.end(), threshold);
    if(request == countUnderCache.end()) {
        int ans = 0;
        countUnderCache.push_back(threshold);
        int count = 0;
        for (auto &it : multset)
            if (it < threshold) count++;
        countUnder = count;
        countUnderAns.insert(std::make_pair(threshold, countUnder));
        return countUnder;
    }
    else return countUnderAns[*request];

}


template<class T>
int StatisticMultiset<T>::GetCountAbove( float threshold ) const{
    auto request = std::find(countAboveCache.begin(), countAboveCache.end(), threshold);
    if(request == countAboveCache.end()) {
        countAboveCache.push_back(threshold);
        int count = 0;
        for (auto &it : multset)
            if (it < threshold) count++;
        countAbove = count;
        countAboveAns.insert(std::make_pair(threshold, countAbove));
        return countAbove;
    }
    else return countAboveAns[*request];

}
