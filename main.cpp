#include <iostream>
#include "boost/type_index.hpp"

class err_c
{
    static const std::size_t msgcnt = 32;
    static const char *messages[msgcnt];

    int _err;

public:
    enum {
        OK, NULL_POINTER, OUT_OF_RANGE, INVALID_ARG, UNKNOWN_COMMAND,
    };

    err_c(int err) : _err(err) { }
    const char *operator()() { return messages[_err]; }
};

const char *err_c::messages[err_c::msgcnt] = {
         "OK", "null pointer", "out of range", "invalid arg", "unknown command"
};

int foo(void *p) {
    if (!p) {
        // can not work. Return
        return err_c::NULL_POINTER;
    } else {
        // do any work here
        // ...
        return 0;
    }
}

int main (void)
{
    using boost::typeindex::type_id_with_cvr;

    static int x;
    std::cout << "foo result is: " << err_c(foo(&x))() << std::endl;
    std::cout << "foo result is: " << err_c(foo(nullptr))() << std::endl;

    auto x1 = {0};
    auto x2 = 0;
    std::cout << "typeof(x1): " << type_id_with_cvr<decltype(x1)>().pretty_name() << std::endl;
    std::cout << "typeof(x2): " << type_id_with_cvr<decltype(x2)>().pretty_name() << std::endl;

    auto arg = x2;
    std::cout << "typeof(arg): " << type_id_with_cvr<decltype(arg)>().pretty_name() << std::endl;
    std::cout << "typeof((arg)): " << type_id_with_cvr<decltype((arg))>().pretty_name() << std::endl;
    
    return 0;
}