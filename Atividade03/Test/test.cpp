#include "../Headers/object3d.h"

#include <gtest/gtest.h>

TEST(model3d, obj_test){
    object3D bench("bench.obj");

    double x = bench.get_vertex(2)[1];   

    ASSERT_EQ(52.310474,x);

    x = bench.get_vertex(5)[2];

    ASSERT_EQ(28.734123,x);

    x = bench.get_normal(10)[1];

    ASSERT_EQ(0.999523,x);

    x = bench.get_normal(0)[2];

    ASSERT_EQ(1.000000,x);

    vector<int> id_vertices = bench.get_face_vertices(2);

    ASSERT_EQ(19,id_vertices[1]);

    id_vertices = bench.get_face_vertices(0);

    ASSERT_EQ(539,id_vertices[3]);

    vector<int> id_normals = bench.get_face_normals(2);

    ASSERT_EQ(12,id_normals[3]);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}