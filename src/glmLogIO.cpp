#include "artd/glmLogIO.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

std::ostream& operator<<(std::ostream& os, const glm::vec2 &v) {
	os << "{ " << v.x << ",\t" << v.y << " }";
	return(os);
}

std::ostream& operator<<(std::ostream& os, const glm::ivec2 &v) {
	os << "{ " << v.x << ",\t" << v.y << " }";
	return(os);
}

std::ostream& operator<<(std::ostream& os, const glm::uvec2 &v) {
	os << "{ " << v.x << ",\t" << v.y << " }";
	return(os);
}

std::ostream& operator<<(std::ostream& os, const glm::vec3 &v) {
	os << "{ " << v.x << ",\t" << v.y << ",\t" << v.z << " }";
	return(os);
}

std::ostream& operator<<(std::ostream& os, const glm::dvec3 &v) {
	os << "{ " << v.x << ",\t" << v.y << ",\t" << v.z << " }";
	return(os);
}

std::ostream& operator<<(std::ostream& os, const glm::vec4 &v) {
	os << "{ " << v.x << ",\t" << v.y << ",\t" << v.z << ",\t" << v.w << " }";
	return(os);
}

std::ostream& operator<<(std::ostream& os, const glm::mat3 &m) {
    auto v = &m[0];
	os << "\n{\t";
	os         << v->x << ",\t" << v->y << ",\t" << v->z << ",\n";
    v = &m[1];
	os << "\t" << v->x << ",\t" << v->y << ",\t" << v->z << ",\n";
    v = &m[2];
	os << "\t" << v->x << ",\t" << v->y << ",\t" << v->z << "\t}\n";
    return(os);
}

std::ostream& operator<<(std::ostream& os, const glm::mat4 &m) {

    auto v = &m[0];
	os << "\n{\t";
	os         << v->x << ",\t" << v->y << ",\t" << v->z << ",\t" << v->w << ",\n";
    v = &m[1];
	os << "\t" << v->x << ",\t" << v->y << ",\t" << v->z << ",\t" << v->w << ",\n";
	v = &m[2];
	os << "\t" << v->x << ",\t" << v->y << ",\t" << v->z << ",\t" << v->w << ",\n";
	v = &m[3];
	os << "\t" << v->x << ",\t" << v->y << ",\t" << v->z << ",\t" << v->w << "\t}\n";
	return(os);
}

