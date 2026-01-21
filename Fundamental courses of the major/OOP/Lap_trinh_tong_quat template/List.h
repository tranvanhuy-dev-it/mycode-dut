#include <iostream>
using namespace std;

template <typename L>
class List
{

private:
public:
    List();
    ~List();
};

template<typename L>
List<L>::List()
{
    cout << "List\n";
}

template<typename L>
List<L>::~List()
{
    cout << "Huy List\n";
}
