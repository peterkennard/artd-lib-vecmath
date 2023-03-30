#include "artd/jlib-base"

// TODO: we need to handle this for building either static or dll libraries !!

#ifndef ARTD_API_LIB_VECMATH
    #ifdef BUILDING_artd_lib_vecmath
        #define ARTD_API_LIB_VECMATH ARTD_SHARED_LIBRARY_EXPORT
    #else
        #define ARTD_API_LIB_VECMATH ARTD_SHARED_LIBRARY_IMPORT
    #endif
#endif

#include "glm/glm.h"
