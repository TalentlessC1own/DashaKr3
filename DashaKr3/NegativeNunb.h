#pragma once


class NegativeNunb
{
public:
    NegativeNunb(double _numb, int _i, int _j)
        : numb(_numb), i(_i), j(_j)
    {}
    double numb;
    int i;
    int j;
    ~NegativeNunb() = default;
};

