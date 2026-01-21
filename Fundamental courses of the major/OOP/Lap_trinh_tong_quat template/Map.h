#include <iostream>
#include "List.h"
using namespace std;

template<typename K, typename V, template<typename U> class C>
class Map
{
private:
    C<K> key;
    C<V> value;

public:
    Map();
    ~Map();
};

template<typename K, typename V, template<typename U> class C>
Map<K, V, C>::Map()
{
    cout << "Map" << endl;
}

template<typename K, typename V, template<typename U> class C>
Map<K, V, C>::~Map()
{
}

template class Map<int, double, List>;

