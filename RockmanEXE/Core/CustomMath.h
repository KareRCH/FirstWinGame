#pragma once

#include "Define.h"


template<typename T>
//typename std::enable_if<std::is_floating_point<T>::value, bool>::type
inline bool Equals(T a, T b, T epsilon)
{
	return abs(a - b) <= epsilon;
}

// ���� Ÿ�Ե� ������ �����Ͽ� ������ �Լ�
template<typename T>
//typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
inline bool Equals_Ranged(T a, T b, T epsilon)
{
	return abs(a - b) <= epsilon;
}