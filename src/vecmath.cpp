#include "artd/vecmath.h"
#include "glm/matrix.hpp"
#include "artd/Vec3f.h"
#include "artd/Vec4f.h"
#include "artd/Ray3f.h"
#include "artd/Matrix4f.h"

ARTD_BEGIN

/**
 *  orthonormalize the 3x3 part of the incomming matrix (vectors)
 *  and makes sure they are orthogonal.
 *  return the result, assume as glm::orthonormalize for a mat3
 */
Matrix4f orthonormalize(const glm::mat4 &M) {
    Matrix4f R = M;
    float s = 1.;
    glm::vec3 h;

    glm::vec3& v0 = reinterpret_cast<glm::vec3&>(R[0]);
    glm::vec3& v1 = reinterpret_cast<glm::vec3&>(R[1]);
    glm::vec3& v2 = reinterpret_cast<glm::vec3&>(R[2]);

    v2 = glm::normalize(v2);

    s = glm::dot(v1, v2);
    h = v2 * s;
    v1 -= h;

    v2 = glm::normalize(v2);


    s = glm::dot(v1, v2);
    h = v2 * s;
    v1 -= h;
    v1 = glm::normalize(v1);

    s = glm::dot(v0, v1);
    h = v1 * s;
    v0 = v0 - h;
    v0 = glm::normalize(v0);

    return(R);
}

ARTD_API_LIB_VECMATH void affineDecompose(const glm::mat4& pose, glm::mat4& rotation, glm::vec3& scale, glm::vec3& translation)
{
    // https://imcs.dvfu.ru/lib.int/docs/Programming/Graphics/Graphics%20Gems%20III.pdf
    // Graphics Gem III.3
    // p 108
    // Graham-Schmidt decomposition

    // first vector
    glm::vec3 x = glm::vec3(pose[0]);
    scale.x = glm::length(x);

    x *= 1.0f / scale.x; //  glm::normalize(x);

    // second vector
    glm::vec3 y = glm::vec3(pose[1]);
    y -= glm::dot(y, x) * x; // remove projection on first
    scale.y = glm::length(y);
    y *= 1.0f / scale.y; //  = glm::normalize(y);


    // third vector
    glm::vec3 z = glm::vec3(pose[2]);
    z -= glm::dot(z, x) * x + glm::dot(z, y) * y; // remove projection on first and second
    scale.z = glm::length(z);
    z *= 1.0f / scale.z; //  glm::normalize(z);

    if (std::isnan(scale.y)
        || std::isnan(scale.x)
        || std::isnan(scale.z))
    {
        AD_LOG(info) << "NAN scale !! " << scale;
    }

    // flip z if right handed
    bool isRightHanded = glm::dot(glm::cross(x, y), z) >= 0;
    if (!isRightHanded) {
        scale.z = -scale.z;
        z = -z;
    }

    rotation = glm::mat4(glm::mat3(x, y, z));
    translation = glm::vec3(pose[3]);
}

ARTD_END