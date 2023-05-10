#ifndef __artd_vecmath_h
#define __artd_vecmath_h

#include "artd/vecmath_base.h"

ARTD_BEGIN

/**
 *  orthonormalize the 3x3 part of the incomming matrix (vectors)
 *  and makes sure they are orthogonal.
 *  return the result, aseme as glm::orthonormalize for a mat3
 */
ARTD_API_LIB_VECMATH glm::mat4 orthonormalize(const glm::mat4 &M);

ARTD_END

#endif // __artd_vecmath_h
