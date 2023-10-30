#include <iostream>
#include "../Headers/mat2.h"
#include "../Headers/mat3.h"
#include "../Headers/mat4.h"
#include "../Headers/vec3.h"
#include "../Headers/vec4.h"

#include <gtest/gtest.h>

TEST(VectorTests, vec_initialize){
    vec3 u(2,5,4);
    EXPECT_EQ(5,u[1]);

    vec3 v(2,7,1);
    EXPECT_EQ(2,v[0]);

    vec3 w(7,5,6);
    EXPECT_EQ(6,w[2]);

    vec4 x(1,2,3,4);
    EXPECT_EQ(4,x[3]);

    vec4 y(4,6,2,1);
    EXPECT_EQ(6,y[1]);
}

TEST(VectorTests, vec_op){
  vec3 u(2,5,4);
  vec3 v(2,7,1);
  vec3 w = u+v;
  EXPECT_EQ(12,w[1]);

  u *= 2;
  EXPECT_EQ(8,u[2]);

  vec3 x(3,6,9);
  x /= 3;
  EXPECT_EQ(1,x[0]);

  u /= 2;
  double y = dot(u,v);
  EXPECT_EQ(43,y);

  vec4 a(1,2,3,4);
  vec4 b(3,5,2,1);
  a += b;
  EXPECT_EQ(5,a[2]);

  b *= 3;
  EXPECT_EQ(3,b[3]);
}

TEST(MatrixTests,matrix_initialize){
  mat3 a(vec3(1,2,3),vec3(4,5,6),vec3(7,8,9));

  EXPECT_EQ(6,a.at(1,2));

  mat3 b(1,2,3,4,5,6,7,8,9);

  EXPECT_EQ(a.at(2,0),b.at(2,0));

  mat3 c({{1,2,3},{1,2,3},{1,2,3}});

  EXPECT_EQ(c.at(1,2),c.at(0,2));

  mat4 id(vec4(1,0,0,0),vec4(0,1,0,0),vec4(0,0,1,0),vec4(0,0,0,1));

  EXPECT_EQ(1,id.at(1,1));

  mat4 a(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);

  EXPECT_EQ(12,a.at(2,3));
}

TEST(MatrixTests,matrix_op){
  mat3 a(vec3(1,2,3),vec3(4,5,6),vec3(7,8,9));
  mat3 b(1,2,3,4,5,6,7,8,9);
  a += b;
  EXPECT_EQ(a.at(1,2),2*b.at(1,2));

  mat3 id(vec3(1,0,0),vec3(0,1,0),vec3(0,0,1));
  a *= id;
  EXPECT_EQ(a.at(1,2),2*b.at(1,2));

  b = 2*b;
  EXPECT_EQ(a.at(1,2),b.at(1,2));

  mat4 a(vec4(1,2,3,4),vec4(5,6,7,8),vec4(9,10,11,12),vec4(13,14,15,16));
  mat4 b(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
  a += b;
  EXPECT_EQ(a.at(3,2),2*b.at(3,2));

  mat4 id(vec4(1,0,0,0),vec4(0,1,0,0),vec4(0,0,1,0),vec4(0,0,0,1));
  a *= id;
  EXPECT_EQ(a.at(3,2),2*b.at(3,2));

  b = 2*b;
  EXPECT_EQ(a.at(3,2),b.at(3,2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
