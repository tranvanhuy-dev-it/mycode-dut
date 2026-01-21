class RealSet;
class IntSet
{
private:
    int *p;
    int n;
public:
    IntSet(const int& = 2);
    ~IntSet();
    void ShowIntSet();
    void SetToReal(RealSet&);
};