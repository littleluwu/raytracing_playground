#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>
#include "vec4.h"

class mat4{
    public:
        double e[4][4];

    mat4() : e{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}} {}
    mat4(double e0, double e1, double e2, double e3, 
        double e4, double e5, double e6, double e7,
        double e8, double e9, double e10, double e11,
        double e12, double e13, double e14, double e15) : e{
            {e0, e1, e2, e3},
            {e4, e5, e6, e7},
            {e8, e9, e10, e11},
            {e12, e13, e14, e15}} {}
    mat4(vec4 u, vec4 v, vec4 w, vec4 x) : e{
        {u.e[0],u.e[1],u.e[2],u.e[3]},
        {v.e[0],v.e[1],v.e[2],v.e[3]},
        {w.e[0],w.e[1],w.e[2],w.e[3]},
        {x.e[0],x.e[1],x.e[2],x.e[3]}} {}
        
    vec4 operator[](int i) const { return vec4(e[i][0],e[i][1],e[i][2],e[i][3]); }
    vec4 operator[](int i) { return vec4(e[i][0],e[i][1],e[i][2],e[i][3]); }
    double at(int i, int j) const{ return e[i][j]; }

    mat4& operator+=(const mat4 a){
        for(int i = 0; i < 4; i++){
            e[i][0] += a.at(i,0);
            e[i][1] += a.at(i,1);
            e[i][2] += a.at(i,2);
            e[i][3] += a.at(i,3);
        }
        return *this;
    }

    mat4& operator-=(const mat4 a){
        for(int i = 0; i < 4; i++){
            e[i][0] -= a.at(i,0);
            e[i][1] -= a.at(i,1);
            e[i][2] -= a.at(i,2);
            e[i][3] += a.at(i,3);
        }
        return *this;
    }

    mat4& operator*=(const double k){
        for(int i = 0; i < 4; i++){
            e[i][0] *= k;
            e[i][1] *= k;
            e[i][2] *= k;
            e[i][3] *= k;
        }
        return *this;
    }

    vec4 operator*=(vec4 v){
        return vec4(
            (e[0][0] * v.e[0] + e[0][1] * v.e[1] + e[0][2] * v.e[2] + e[0][3] * v.e[3]),
            (e[1][0] * v.e[0] + e[1][1] * v.e[1] + e[1][2] * v.e[2] + e[1][3] * v.e[3]),
            (e[2][0] * v.e[0] + e[2][1] * v.e[1] + e[2][2] * v.e[2] + e[2][3] * v.e[3]),
            (e[3][0] * v.e[0] + e[3][1] * v.e[1] + e[3][2] * v.e[2] + e[3][3] * v.e[3])
        );
    }

    mat4& operator*=(const mat4 a){
        for(int i = 0; i < 4; i++){
            double aux[4];
            for(int j = 0; j < 4; j++){
                aux[j] = e[i][0] * a.at(0,j)
                        + e[i][1] * a.at(1,j)
                        + e[i][2] * a.at(2,j)
                        + e[i][3] * a.at(3,j);
            }
            e[i][0] = aux[0];
            e[i][1] = aux[1];
            e[i][2] = aux[2];
            e[i][3] = aux[3];
        }
        return *this;
    }

};

// Vector Utility Functions
inline std::ostream& operator<<(std::ostream &out, const mat4 &a) {
    return out << a.e[0] << '\n' << a.e[1] << '\n' << a.e[2] << '\n' << a.e[3];
}

inline mat4 operator+(const mat4 &a, const mat4 &b) {
    return mat4(
            (vec4)a.e[0] + (vec4)b.e[0],
            (vec4)a.e[1] + (vec4)b.e[1],
            (vec4)a.e[2] + (vec4)b.e[2],
            (vec4)a.e[3] + (vec4)b.e[3]);
}

inline mat4 operator-(const mat4 &a, const mat4 &b) {
    return mat4(
            (vec4)a.e[0] - (vec4)b.e[0],
            (vec4)a.e[1] - (vec4)b.e[1],
            (vec4)a.e[2] - (vec4)b.e[2],
            (vec4)a.e[3] - (vec4)b.e[3]);
}

inline mat4 operator*(const mat4 &a, const mat4 &b){
    return mat4(
        vec4(
            a.at(0,0) * b.at(0,0) + a.at(0,1) * b.at(1,0) + a.at(0,2) * b.at(2,0) + a.at(0,3) * b.at(3,0),
            a.at(0,0) * b.at(0,1) + a.at(0,1) * b.at(1,1) + a.at(0,2) * b.at(2,1) + a.at(0,3) * b.at(3,1),
            a.at(0,0) * b.at(0,2) + a.at(0,1) * b.at(1,2) + a.at(0,2) * b.at(2,2) + a.at(0,3) * b.at(3,2),
            a.at(0,0) * b.at(0,3) + a.at(0,1) * b.at(1,3) + a.at(0,2) * b.at(2,3) + a.at(0,3) * b.at(3,3)
        ),
        vec4(
            a.at(1,0) * b.at(0,0) + a.at(1,1) * b.at(1,0) + a.at(1,2) * b.at(2,0) + a.at(1,3) * b.at(3,0),
            a.at(1,0) * b.at(0,1) + a.at(1,1) * b.at(0,1) + a.at(1,2) * b.at(2,1) + a.at(1,3) * b.at(3,1),
            a.at(1,0) * b.at(0,2) + a.at(1,1) * b.at(0,2) + a.at(1,2) * b.at(2,2) + a.at(1,3) * b.at(3,2),
            a.at(1,0) * b.at(0,3) + a.at(1,1) * b.at(1,3) + a.at(1,2) * b.at(2,3) + a.at(1,3) * b.at(3,3)
        ),
        vec4(
            a.at(2,0) * b.at(0,0) + a.at(2,1) * b.at(1,0) + a.at(2,2) * b.at(2,0) + a.at(2,3) * b.at(3,0),
            a.at(2,0) * b.at(0,1) + a.at(2,1) * b.at(1,1) + a.at(2,2) * b.at(2,1) + a.at(2,3) * b.at(3,1),
            a.at(2,0) * b.at(0,2) + a.at(2,1) * b.at(1,2) + a.at(2,2) * b.at(2,2) + a.at(2,3) * b.at(3,2),
            a.at(2,0) * b.at(0,3) + a.at(2,1) * b.at(1,3) + a.at(2,2) * b.at(2,3) + a.at(2,3) * b.at(3,3)
        ),
        vec4(
            a.at(3,0) * b.at(0,0) + a.at(3,1) * b.at(1,0) + a.at(3,2) * b.at(2,0) + a.at(3,3) * b.at(3,0),
            a.at(3,0) * b.at(0,1) + a.at(3,1) * b.at(1,1) + a.at(3,2) * b.at(2,1) + a.at(3,3) * b.at(3,1),
            a.at(3,0) * b.at(0,2) + a.at(3,1) * b.at(1,2) + a.at(3,2) * b.at(2,2) + a.at(3,3) * b.at(3,2),
            a.at(3,0) * b.at(0,3) + a.at(3,1) * b.at(1,3) + a.at(3,2) * b.at(2,3) + a.at(3,3) * b.at(3,3)
        )
    );
}

vec4 vecmult(vec4 v, mat4 m){
        return vec4(
            (m.at(0,0) * v.e[0] + m.at(0,1) * v.e[1] + m.at(0,2) * v.e[2] + m.at(0,3) * v.e[3]),
            (m.at(1,0) * v.e[0] + m.at(1,1) * v.e[1] + m.at(1,2) * v.e[2] + m.at(1,3) * v.e[3]),
            (m.at(2,0) * v.e[0] + m.at(2,1) * v.e[1] + m.at(2,2) * v.e[2] + m.at(2,3) * v.e[3]),
            (m.at(3,0) * v.e[0] + m.at(3,1) * v.e[1] + m.at(3,2) * v.e[2] + m.at(3,3) * v.e[3])
        );
}


inline mat4 operator*(double k, const mat4 &a) {
    return mat4(
            (vec4)a.e[0] * k,
            (vec4)a.e[1] * k,
            (vec4)a.e[2] * k,
            (vec4)a.e[3] * k);  
}

inline mat4 operator*(const mat4 &a, double k) {
    return k * a;
}

inline mat4 operator/(mat4 a, double k) {
    return (1/k) * a;
}

#endif