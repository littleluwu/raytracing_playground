#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>

class mat2{
    public:
        double e[2][2];

    mat2() : e{{0,0},{0,0}} {}
    mat2(double e0, double e1, 
        double e2, double e3) : e{{e0, e1},{e2, e3}} {}
        
    double operator[](int i) const { return e[i/2][i%2]; }
    double& operator[](int i) { return e[i/2][i%2]; }
    double at(int i, int j) const{ return e[i][j]; }

    mat2& operator+=(const mat2 a){
        for(int i = 0; i < 2; i++){
            e[i][0] += a.at(i,0);
            e[i][1] += a.at(i,1);
        }
        return *this;
    }

    mat2& operator-=(const mat2 a){
        for(int i = 0; i < 2; i++){
            e[i][0] -= a.at(i,0);
            e[i][1] -= a.at(i,1);
        }
        return *this;
    }

    mat2& operator*=(const double k){
        for(int i = 0; i < 2; i++){
            e[i][0] *= k;
            e[i][1] *= k;
        }
        return *this;
    }

    mat2& operator*=(const mat2 a){
        for(int i = 0; i < 2; i++){
            double aux[2];

            aux[0] = e[i][0] * a.at(0,0) + e[i][1] * a.at(1,0); 
            aux[1] = e[i][0] * a.at(0,1) + e[i][1] * a.at(1,1); 

            e[i][0] = aux[0];
            e[i][1] = aux[1];
        }
        return *this;
    }

};

// Vector Utility Functions
inline std::ostream& operator<<(std::ostream &out, const mat2 &a) {
    return out << a.e[0] << ' ' << a.e[1] << '\n' << a.e[2] << ' ' << a.e[3];
}

inline mat2 operator+(const mat2 &a, const mat2 &b) {
    return mat2(
            a.at(0,0) + b.at(0,0),
            a.at(0,1) + b.at(0,1),
            a.at(1,0) + b.at(1,0),
            a.at(1,1) + b.at(1,1));
}

inline mat2 operator-(const mat2 &a, const mat2 &b) {
    return mat2(
            a.at(0,0) - b.at(0,0),
            a.at(0,1) - b.at(0,1),
            a.at(1,0) - b.at(1,0),
            a.at(1,1) - b.at(1,1));
}

inline mat2 operator*(const mat2 &a, const mat2 &b){
    return mat2(
        a.at(0,0) * b.at(0,0) + a.at(0,1) * b.at(1,0),
        a.at(0,0) * b.at(0,1) + a.at(0,1) * b.at(1,1),
        a.at(1,0) * b.at(0,0) + a.at(1,1) * b.at(1,0),
        a.at(1,0) * b.at(0,1) + a.at(1,1) * b.at(1,1) 
    );
}

inline mat2 operator*(double k, const mat2 &a) {
    return mat2(
            a.at(0,0)*k,
            a.at(0,1)*k,
            a.at(1,0)*k,
            a.at(1,1)*k);
}

inline mat2 operator*(const mat2 &a, double k) {
    return k * a;
}

inline mat2 operator/(mat2 a, double k) {
    return (1/k) * a;
}

#endif