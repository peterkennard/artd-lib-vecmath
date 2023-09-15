#pragma once

#include "vecmath_base.h"
#include "glm/vec4.hpp"

ARTD_BEGIN

#define INL ARTD_ALWAYS_INLINE

class ARTD_API_LIB_VECMATH Vec4f
    : public glm::vec4
{
    typedef glm::vec4 super;
public:
    INL Vec4f() {
    }
    INL Vec4f(float x, float y, float z, float w)
         : super(x,y,z,w)
    {}

    INL Vec4f(const glm::vec4 &src)
        : super(src)
    {}

    INL Vec4f &set(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        return(*this);
    }
    INL Vec4f &set(const glm::vec4 &src)  {
        super::operator=(src);
        return(*this);
    }
};



#undef INL

ARTD_END
