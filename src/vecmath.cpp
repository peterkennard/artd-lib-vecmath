#include "artd/vecmath.h"

ARTD_BEGIN

/**
 *  orthonormalize the 3x3 part of the incomming matrix (vectors)
 *  and makes sure they are orthogonal.
 *  return the result, aseme as glm::orthonormalize for a mat3
 */
glm::mat4 orthonormalize(const glm::mat4 &M) {
    glm::mat4 R = M;
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

ARTD_END