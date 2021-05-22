#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    unsigned value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token  Token_stream:: get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '{': case '}':
    case '&': case '~': case '|': case '!': case '^':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            unsigned val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

unsigned expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses

unsigned primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '!':
        {
            unsigned d = primary();
            d = !d;
            return d;
        }
    case '~':
        {
            unsigned d = primary();
            d = ~d;
            return d;
        }
    case '(': case '{':    // handle '(' expression ')'
        {
            unsigned d = expression();
            t = ts.get();
            if (t.kind != ')' && t.kind != '}') error("')' or '}' expected");
            return d;
        }
    case 'x':
        return 0;
    case '8':
        // we use '8' to represent a number
    {
        return t.value;  // return the number's value
    }
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

unsigned term2()
{
    unsigned left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '&':
            left &= primary();
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}
// deal with *, /, and %
unsigned term1()
{
    unsigned left = term2();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '^':
            left ^= term2();
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
unsigned expression()
{
    unsigned left = term1();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch(t.kind) {
        case '|':
            left |= term1();    // evaluate Term and add
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}


int main()
try
{
    unsigned val;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'x') break; // 'q' for quit
        if (t.kind == '='){        // ';' for "print now"
            cout << "=" << val << '\n';
            continue;
        }
        else
        ts.putback(t);
        val = expression();
    }
	keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
	keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
	keep_window_open();
    return 2;
}
