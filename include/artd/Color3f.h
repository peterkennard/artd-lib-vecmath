#pragma once

#include "artd/Vec3f.h"

ARTD_BEGIN

#define INL ARTD_ALWAYS_INLINE

class ARTD_API_LIB_VECMATH Color3f
    : public glm::vec3
{
    typedef glm::vec3 super;
public:
    static INL float byteToFloat1(int c) {
        return(((float)((uint8_t)c))*(1.0f/255.0f));
    }

    INL Color3f() {
    }

    INL Color3f(int r, int g, int b)
        : super(byteToFloat1(r),byteToFloat1(g),byteToFloat1(b))
    {}

    INL Color3f(float r, float g, float b)
         : super(r,g,b)
    {}

    INL Color3f(const glm::vec3 &src)
        : super(src)
    {}

    INL Color3f &set(int r, int g, int b) {
          this->r = byteToFloat1(r);
          this->g = byteToFloat1(g);
          this->b = byteToFloat1(b);
          return(*this);
      }

    INL Color3f &set(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
        return(*this);
    }
    INL Color3f &set(const glm::vec3 &src)  {
        super::operator=(src);
        return(*this);
    }
};

class ARTD_API_LIB_VECMATH Color4f
    : public glm::vec4
{
    typedef glm::vec4 super;
public:

    INL Color4f() {
    }

    INL Color4f(const glm::vec4 &src)
        : super(src)
    {}

    INL Color4f(int r, int g, int b)
        : super(Color3f::byteToFloat1(r),
                Color3f::byteToFloat1(g),
                Color3f::byteToFloat1(b), 1.f)
    {}

    INL Color4f(int r, int g, int b, int a)
        : super(Color3f::byteToFloat1(r),
                Color3f::byteToFloat1(g),
                Color3f::byteToFloat1(b),
                Color3f::byteToFloat1(a))
    {}

    INL Color4f(float r, float g, float b, float a = 1.f)
         : super(r,g,b,a)
    {}

    INL Color4f &set(float r, float g, float b, float a = 1.f) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
        return(*this);
    }
    INL Color4f &set(int r, int g, int b, int a = 0x0FF) {
        this->r = Color3f::byteToFloat1(r);
        this->g = Color3f::byteToFloat1(g);
        this->b = Color3f::byteToFloat1(b);
        this->a = Color3f::byteToFloat1(a);
        return(*this);
    }

};


#undef INL

ARTD_END


