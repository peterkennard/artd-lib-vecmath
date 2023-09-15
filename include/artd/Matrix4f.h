#pragma once

#include "artd/Logger.h"
#include "artd/glmLogIO.h"
#include "artd/vecmath_base.h"
#include "glm/matrix.hpp"
#include "artd/Vec4f.h"
#include "artd/Vec3f.h"
#include <glm/gtx/transform.hpp>

ARTD_BEGIN

#define INL ARTD_ALWAYS_INLINE

class ARTD_API_LIB_VECMATH Matrix4f
    : public glm::mat4
{
    typedef glm::mat4 super;
public:

    INL Matrix4f()
        : super(1.0f) // we default to identity glm does not !
    {
    }

    template<class OtherT>
    INL Matrix4f(const OtherT &ot)
        : super(ot)
    {
    }
    
    INL Matrix4f(double diag)
        : super(diag)
    {
    }

    INL const Vec4f &operator[](int ix) const {
        return(reinterpret_cast<const Vec4f &>(super::operator[](ix)));
    }

    INL Vec4f &operator[](int ix) {
        return(reinterpret_cast<Vec4f &>(super::operator[](ix)));
    }

    template<class OtherT>
    INL Matrix4f &operator=(const OtherT &ot) {
        super::operator=(ot);
        return(*this);
    }
};

inline Matrix4f affineCompose(const glm::vec3 &translation, const glm::mat4 &rotation, const glm::vec3 &scale ) {
    Matrix4f ret = glm::translate(translation) * rotation * glm::scale(scale);
    return(ret);
}

void ARTD_API_LIB_VECMATH affineDecompose(const glm::mat4& pose, glm::mat4& rotation, glm::vec3& scale, glm::vec3& translation);

#undef INL

ARTD_END
