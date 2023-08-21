#pragma once
#ifndef __artd_glmLogIO_h
#define __artd_glmLogIO_h

#include "artd/vecmath_base.h"
#include <iosfwd>
#include <ostream>
#include <glm/fwd.hpp>

ARTD_API_LIB_VECMATH std::ostream& operator<<(std::ostream& os, const glm::ivec2 &v);
ARTD_API_LIB_VECMATH std::ostream& operator<<(std::ostream& os, const glm::uvec2 &v);
ARTD_API_LIB_VECMATH std::ostream& operator<<(std::ostream& os, const glm::vec2 &v);

ARTD_API_LIB_VECMATH std::ostream& operator<<(std::ostream& os, const glm::vec3 &v);
ARTD_API_LIB_VECMATH std::ostream& operator<<(std::ostream& os, const glm::vec4 &v);

ARTD_API_LIB_VECMATH std::ostream& operator<<(std::ostream& os, const glm::mat3 &v);
ARTD_API_LIB_VECMATH std::ostream& operator<<(std::ostream& os, const glm::mat4 &v);


#endif // __artd_glmLogIO_h
