#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.h"
#include "../../Atividade02/Headers/vec3.h"
#include "../../Atividade05/Headers/material.h"


class triangle : public hittable {
  public:
    triangle(point3 _v1, point3 _v2, point3 _v3, shared_ptr<material> _material, vec3 _normal) 
      : v1(_v1), v2(_v2), v3(_v3), mat(_material), normal(_normal) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 v1v2 = v2 - v1;
        vec3 v1v3 = v3 - v1;
        vec3 N = cross(v1v2,v1v3);

        float NdotRayDirection = dot(N,r.direction());
        if (fabs(NdotRayDirection) < 1e-8)
            return false;

        float d = dot(-N,v1);
        float t = -(dot(N,r.origin()) + d) / NdotRayDirection;
        if (t < 0) return false;
    
        vec3 P = r.at(t);
        vec3 C;
        vec3 edge1 = v2 - v1; 
        vec3 vp1 = P - v1;
        C = cross(edge1,vp1);
        if (dot(N,C) < 0) return false;
    
        // edge 1
        vec3 edge2 = v3 - v2; 
        vec3 vp2 = P - v2;
        C = cross(edge2,vp2);
        if (dot(N,C) < 0)  return false;
    
        // edge 2
        vec3 edge3 = v1 - v3; 
        vec3 vp3 = P - v3;
        C = cross(edge3,vp3);
        if (dot(N,C) < 0) return false;

        rec.t = t;
        rec.p = r.at(rec.t);
        vec3 outward_normal = rec.p;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        return true;
    }

  private:
    point3 v1, v2, v3;
    shared_ptr<material> mat;
    vec3 normal;

};

#endif