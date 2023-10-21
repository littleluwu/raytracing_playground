#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>
#include "vec3.h"

class mat3{
    public:
        double e[3][3];

    mat3() : e{{0,0,0},{0,0,0},{0,0,0}} {}
    mat3(double e0, double e1, double e2, 
        double e3, double e4, double e5,
        double e6, double e7, double e8) : e{
            {e0, e1, e2},
            {e3, e4, e5},
            {e6, e7, e8}} {}
    mat3(vec3 u, vec3 v, vec3 w) : e{
        {u.e[0],u.e[1],u.e[2]},
        {v.e[0],v.e[1],v.e[2]},
        {w.e[0],w.e[1],w.e[2]}} {}
        
    vec3 operator[](int i) const { return vec3(e[i][0],e[i][1],e[i][2]); }
    double at(int i, int j) const{ return e[i][j]; }

    mat3& operator+=(const mat3 a){
        for(int i = 0; i < 3; i++){
            e[i][0] += a.at(i,0);
            e[i][1] += a.at(i,1);
            e[i][2] += a.at(i,2);
        }
        return *this;
    }

    mat3& operator-=(const mat3 a){
        for(int i = 0; i < 3; i++){
            e[i][0] -= a.at(i,0);
            e[i][1] -= a.at(i,1);
            e[i][2] -= a.at(i,2);
        }
        return *this;
    }

    mat3& operator*=(const double k){
        for(int i = 0; i < 3; i++){
            e[i][0] *= k;
            e[i][1] *= k;
            e[i][2] *= k;
        }
        return *this;
    }

    vec3 operator*=(const vec3 v){
        return vec3(
            e[0][0] * v.e[0] + e[0][1] * v.e[1] + e[0][2] * v.e[2],
            e[1][0] * v.e[0] + e[1][1] * v.e[1] + e[1][2] * v.e[2],
            e[2][0] * v.e[0] + e[2][1] * v.e[1] + e[2][2] * v.e[2]
        );
    }

    mat3& operator*=(const mat3 a){
        for(int i = 0; i < 3; i++){
            double aux[3];
            for(int j = 0; j < 3; j++){
                aux[j] = e[i][0] * a.at(0,j)
                        + e[i][1] * a.at(1,j)
                        + e[i][2] * a.at(2,j);
            }
            e[i][0] = aux[0];
            e[i][1] = aux[1];
            e[i][2] = aux[2];
        }
        return *this;
    }

};

// Vector Utility Functions
inline std::ostream& operator<<(std::ostream &out, const mat3 &a) {
    return out << a.e[0] << '\n' << a.e[1] << '\n' << a.e[2];
}

inline mat3 operator+(const mat3 &a, const mat3 &b) {
    return mat3(
            (vec3)a.e[0] + (vec3)b.e[0],
            (vec3)a.e[1] + (vec3)b.e[1],
            (vec3)a.e[2] + (vec3)b.e[2]);
}

inline mat3 operator-(const mat3 &a, const mat3 &b) {
    return mat3(
            (vec3)a.e[0] - (vec3)b.e[0],
            (vec3)a.e[1] - (vec3)b.e[1],
            (vec3)a.e[2] - (vec3)b.e[2]);
}

inline mat3 operator*(const mat3 &a, const mat3 &b){
    return mat3(
        vec3(
            a.at(0,0) * b.at(0,0) + a.at(0,1) * b.at(1,0) + a.at(0,2) * b.at(2,0),
            a.at(0,0) * b.at(0,1) + a.at(0,1) * b.at(1,1) + a.at(0,2) * b.at(2,1),
            a.at(0,0) * b.at(0,2) + a.at(0,1) * b.at(1,2) + a.at(0,2) * b.at(2,2)
        ),
        vec3(
            a.at(1,0) * b.at(0,0) + a.at(1,1) * b.at(1,0) + a.at(1,2) * b.at(2,0),
            a.at(1,0) * b.at(0,1) + a.at(1,1) * b.at(0,1) + a.at(1,2) * b.at(2,1),
            a.at(1,0) * b.at(0,2) + a.at(1,1) * b.at(0,2) + a.at(1,2) * b.at(2,2)
        ),
        vec3(
            a.at(2,0) * b.at(0,0) + a.at(2,1) * b.at(1,0) + a.at(2,2) * b.at(2,0),
            a.at(2,0) * b.at(0,1) + a.at(2,1) * b.at(1,1) + a.at(2,2) * b.at(2,1),
            a.at(2,0) * b.at(0,2) + a.at(2,1) * b.at(1,2) + a.at(2,2) * b.at(2,2)
        )
    );
}

inline mat3 operator*(double k, const mat3 &a) {
    return mat3(
            (vec3)a.e[0] * k,
            (vec3)a.e[1] * k,
            (vec3)a.e[2] * k);  
}

inline mat3 operator*(const mat3 &a, double k) {
    return k * a;
}

inline mat3 operator/(mat3 a, double k) {
    return (1/k) * a;
}

#endif