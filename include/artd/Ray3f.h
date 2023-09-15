#pragma once

#include "artd/vecmath.h"
#include "artd/Vec3f.h"
#include <limits>


ARTD_BEGIN

#define INL ARTD_ALWAYS_INLINE

class ARTD_API_LIB_VECMATH Ray3f
{
private:

    /**
     * origin of ray
     */
    Vec3f  	    origin_;
    /**
     * direction of ray (normalized)
     */
    Vec3f       direction_;
    Vec3f       invDir_;

    void init()
    {
        if(direction_.x == 0)
            invDir_.x = std::numeric_limits<float>::max(); // Float.MAX_VALUE;
        else
            invDir_.x = 1.f / direction_.x;

        if(direction_.y == 0)
            invDir_.y = std::numeric_limits<float>::max(); // Float.MAX_VALUE;
        else
            invDir_.y = 1.f / direction_.y;

        if(direction_.z == 0)
            invDir_.z = std::numeric_limits<float>::max(); // Float.MAX_VALUE;
        else
            invDir_.z = 1.f / direction_.z;
    }

public:
    Ray3f() {}

    Ray3f(const glm::vec3 &origin, const glm::vec3 &direction)
        : origin_(origin), direction_(direction)
    {
        init();
    }
    Ray3f(const Ray3f &src)
        : origin_(src.origin_), direction_(src.direction_), invDir_(src.invDir_)
    {
    }

    /**
     * set this to value of src
     * @param src
     * @return this
     */
    INL Ray3f &set(const Ray3f &src)
    {
        origin_.set(src.origin_);
        direction_.set(src.direction_);
        invDir_.set(src.invDir_);
        return(*this);
    }
    /**
     * set values of ray
     * @param origin ray's point of origin
     * @param pre-normalized direction of ray
     * @return this
     */
    INL const Ray3f &set(const glm::vec3 &origin, const glm::vec3 &direction)
    {
        origin_.set(origin);
        direction_.set(direction);
        init();
        return(*this);
    }
    INL const Vec3f &origin() const
    {
        return(origin_);
    }
    INL void setOrigin(Vec3f val)
    {
        origin_.set(val);
    }
    INL const Vec3f &direction()
    {
        return(direction_);
    }
    INL void setDirection(Vec3f val)
    {
        direction_.set(val);
        init();
    }
    INL const Vec3f &invDir() const
    {
        return(invDir_);
    }
    INL Vec3f &invDir()
    {
        return(invDir_);
    }
//    Ray3f transform(Affine4f m)
//    {
//        m.transformEq(origin_);
//        m.rotate(direction_);
//        return(this);
//    }
//    public Ray3f inverseTransform(Affine4f m)
//    {
//        m.unTransformEq(origin_);
//        m.inverseRotate(direction_);
//        init();
//        return(this);
//    }
    /**
    Compute parameterized projection along the ray.
    @param s the scale along the ray to travel. If direction is normalized, the scale is a distance.
    @return the point position + (s * direction)
    */
    Vec3f positionAlong(float s)
    {
        return(Vec3f(origin_.x+s*direction_.x,origin_.y+s*direction_.y,origin_.z+s*direction_.z));
    }
};

#undef INL

ARTD_END
