#pragma once

#include "math/vec3.hpp"

template <typename T>
class TRay
{
public:
    TVec3<T>(void) {}
    TVec3<T>(const TVec3<T> &origin, const TVec3<T> &direction) : m_origin(origin), m_direction(direction) {}

protected:
    TVec3<T> m_origin;
    TVec3<T> m_direction;
};

using ray = TRay<float>;
using dray = TRay<double>