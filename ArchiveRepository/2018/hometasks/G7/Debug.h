#ifndef DEBUGG_H
#define DEBUGG_H

class Debug
{
public:
    constexpr Debug(bool b = true):hw(b), io(b), other(b){}
    constexpr Debug(bool h, bool i, bool o)
                    :hw(h), io(i), other(o){}
    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { io = b; }
    void set_other(bool b) { io = b; }
private:
    bool hw;
    bool io;
    bool other;
};
#endif // DEBUGG_H
