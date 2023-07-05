#pragma once

#include "Vector3.h"

template<typename T = float>
class CVecBox3 final
{
	static_assert(std::is_arithmetic<T>::value, "T는 원시 타입이어야만 합니다.");
public:
    T left, right, up, down, top, bottom;

public:
    CVecBox3() : left(T()), right(T()), up(T()), down(T()), top(T()), bottom(T()) {}
    ~CVecBox3() {}
};

