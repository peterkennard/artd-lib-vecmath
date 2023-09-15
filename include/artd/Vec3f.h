#pragma once

#include "vecmath_base.h"
#include "glm/vec3.hpp"

ARTD_BEGIN

#define INL ARTD_ALWAYS_INLINE

class ARTD_API_LIB_VECMATH Vec3f
    : public glm::vec3
{
    typedef glm::vec3 super;
public:
    INL Vec3f() {
    }
    INL Vec3f(float x, float y, float z)
         : super(x,y,z)
    {}

    INL Vec3f(const glm::vec3 &src)
        : super(src)
    {}

    INL Vec3f &set(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
        return(*this);
    }
    INL Vec3f &set(const glm::vec3 &src)  {
        super::operator=(src);
        return(*this);
    }
};



#undef INL

ARTD_END