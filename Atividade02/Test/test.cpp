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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
