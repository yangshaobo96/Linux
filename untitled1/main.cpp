#include <iostream>
#include <functional>
#include <utility>
#include <vector>
using namespace std;
template<typename T>
void foo_impl(T s,std::true_type)
{
    cout<<"call int"<<endl;
}
template<typename T>
void foo_impl(T s,std::false_type)
{
    cout<<"call not int"<<endl;
}
template<typename T>
void foo(T s)
{
    foo_impl(s,std::is_integral<T>());
}
template<typename T1,typename T2>
typename std::common_type<T1,T2>::type fooo(const T1 &a ,const T2 &b)
{
    return a<b?a:b;
}
template<typename T>
T echo(T x)
{
    cout<<std::is_reference<T>()<<endl;
    return x;
}
int echo1(int x)
{
    return x;
}
class A
{
public:
    int a;
    A() {
        a=0;
    }
};
int main(int argc, char *argv[])
{
    std::vector<std::reference_wrapper<A>> b;
    std::vector<std::reference_wrapper<int>> c;
    std::vector<std::function<int(int)>> func;
    func.push_back(echo1);
    cout<<(*(func.begin()))(124)<<endl;
    return 0;
}
