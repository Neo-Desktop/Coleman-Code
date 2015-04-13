#include "stdhead.h"

using namespace std;

class CenteredOut
{
public:
    ostream &m_file;
    CenteredOut(ostream &o = cout):m_file(o){};

    template <typename T>
    CenteredOut &operator<<(const T &a) {
        m_file<<a;
        return *this;
    }

    CenteredOut &operator<<(ostream& (*pf) (ostream&)){
        m_file<<pf;
        return *this;
    }
};