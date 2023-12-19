#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <limits>
#include <memory>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers
#include "Atividade01/Headers/image_utils.h"
#include "Atividade02/Headers/vec3.h"
#include "Atividade03/Headers/object3D.h"
#include "Atividade04/Headers/ray.h"
#include "Atividade04/Headers/interval.h"


#endif