#include <iostream>

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
    static int x;
    std::cout << "foo result is: " << err_c(foo(&x))() << std::endl;
    std::cout << "foo result is: " << err_c(foo(nullptr))() << std::endl;
    return 0;
}