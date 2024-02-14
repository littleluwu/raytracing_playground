#ifndef OBJ3D_H
#define OBJ3D_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "../../Atividade02/Headers/vec3.h"
#include "../../Atividade02/Headers/vec4.h"
#include "../../Atividade02/Headers/mat4.h"
#include "../../Atividade04/Headers/triangle.h"
#include "../../Atividade04/Headers/hittable_list.h"

// Scheff's Cat
// https://stackoverflow.com/questions/42315585/split-string-into-tokens-in-c-when-there-are-2-delimiters-in-a-row
char* strtoke(char *str, const char *delim)
{
  static char *start = NULL; /* stores string str for consecutive calls */
  char *token = NULL; /* found token */
  /* assign new start in case */
  if (str) start = str;
  /* check whether text to parse left */
  if (!start) return NULL;
  /* remember current start as found token */
  token = start;
  /* find next occurrence of delim */
  start = strpbrk(start, delim);
  /* replace delim with terminator and move start to follower */
  if (start) *start++ = '\0';
  /* done */
  return token;
}


using namespace std;

class object3D{
    public:
        vector<vec3> vertices;
        vector<vector<vec3>> faces;
        vector<vec3> normals;

        object3D(char *file_path) {
            load_obj(file_path);
        }

        vec3 get_vertex(int i){
            return vertices.at(i);
        }

        vec3 get_normal(int i){
            return normals.at(i);
        }

        vector<int> get_face_vertices(int i){
            vector<int> id;
            vector<vec3> face = faces.at(i);

            for (int j = 0; j < face.size(); j++){
                id.push_back((int)face.at(j)[0]);
            }
            return id;
        }

        vector<int> get_face_normals(int i){
            vector<int> id;
            vector<vec3> face = faces.at(i);

            for (int j = 0; j < face.size(); j++){
                id.push_back(face.at(j)[2]);
            }
            return id;
        }

        hittable_list add_to_world(hittable_list world, shared_ptr<material> mat){
            for (int ptr = 0; ptr < faces.size(); ptr++){
                vector<int> id = get_face_vertices(ptr);
                vector<int> normal = get_face_normals(ptr);
                if (id.size() == 3){
                    world.add(make_shared<triangle>(
                        get_vertex(id[0]),
                        get_vertex(id[1]),
                        get_vertex(id[2]),
                        mat,
                        normal_mean(normal[0],normal[1],normal[2])));
                }
                else{
                    world.add(make_shared<triangle>(
                        get_vertex(id[0]),
                        get_vertex(id[1]),
                        get_vertex(id[2]),
                        mat,
                        normal_mean(normal[0],normal[1],normal[2])));
                    world.add(make_shared<triangle>(
                        get_vertex(id[2]),
                        get_vertex(id[3]),
                        get_vertex(id[0]),
                        mat,
                        normal_mean(normal[0],normal[1],normal[2])));
                }
            }
            printf("to world\n");
            return world;
        }

        vec3 normal_mean(int i, int j, int k){
            vec3 mean = get_normal(i) + get_normal(j) + get_normal(k);
            return mean / 3;
        }

        void move(float x, float y, float z){
            mat4 t(
                vec4(1,0,0,x),
                vec4(0,1,0,y),
                vec4(0,0,1,z),
                vec4(0,0,0,1)
            );
            transform(t);
        }

        void scale(float x, float y, float z){
            mat4 t(
                vec4(x,0,0,0),
                vec4(0,y,0,0),
                vec4(0,0,z,0),
                vec4(0,0,0,1)
            );
            transform(t);
        }

        void rotateX(float theta){
            mat4 t(
                vec4(1,0,0,0),
                vec4(0,cos(theta),-sin(theta),0),
                vec4(0,sin(theta),cos(theta),0),
                vec4(0,0,0,1)
            );
            transform(t);
        }

        void rotateY(float theta){
            mat4 t(
                vec4(cos(theta),0,sin(theta),0),
                vec4(0,1,0,0),
                vec4(-sin(theta),0,cos(theta),0),
                vec4(0,0,0,1)
            );
            transform(t);
        }      

        void rotateZ(float theta){
            mat4 t(
                vec4(cos(theta),-sin(theta),0,0),
                vec4(sin(theta),cos(theta),0,0),
                vec4(0,0,1,0),
                vec4(0,0,0,1)
            );
            transform(t);
        }

        void toZero(){
            float x_mean = 0;
            float y_mean = 0;
            float z_mean = 0;
            for (int ptr = 0; ptr < vertices.size(); ptr++){
                vec3 p = vertices[ptr];
                x_mean += p[0];
                y_mean += p[1];
                z_mean += p[2];
            }

            x_mean = -x_mean / vertices.size();
            y_mean = -y_mean / vertices.size();
            z_mean = -z_mean / vertices.size();

            mat4 t(
                vec4(1,0,0,x_mean),
                vec4(0,1,0,y_mean),
                vec4(0,0,1,z_mean),
                vec4(0,0,0,1)
            );
            transform(t);
        }   
        

    private:
        void transform(mat4 t){
            for (int ptr = 0; ptr < vertices.size(); ptr++){
                vec4 p = vertices[ptr].toPoint4();
                p =  vecmult(p,t);
                vertices[ptr] = vec3(p[0],p[1],p[2]);
            }
        }

        void load_obj(char *file_path){
            ifstream f;
            string line;
            f.open(file_path);
            while(getline(f,line)){
                char *ptr;
                ptr = strtok(strdup(line.c_str())," ");
                if (ptr != NULL && strcmp(ptr,"v") == 0){
                    double a,b,c = 0;
                    ptr = strtok(NULL," ");
                    a = atof(ptr);

                    ptr = strtok(NULL," ");
                    b = atof(ptr);

                    ptr = strtok(NULL," ");
                    c = -atof(ptr);

                    vertices.push_back(vec3(a,b,c));
                }
                if (ptr != NULL && strcmp(ptr,"vn") == 0){
                    ptr = strtok(NULL," ");
                    double a = atof(ptr);

                    ptr = strtok(NULL," ");
                    double b = atof(ptr);

                    ptr = strtok(NULL," ");
                    double c = atof(ptr);
                    normals.push_back(vec3(a,b,c));
                }
                if (ptr != NULL && strcmp(ptr,"f") == 0){
                    char *face[4];
                    int size = 0;
                    while (ptr = strtok(NULL," ")){
                        face[size] = ptr;
                        size++;
                    }
                    vector <vec3> v;
                    for (int i = 0; i < size; i++){
                        int a,b,c = 0;
                        char *pEnd;

                        ptr = strtoke(face[i],"/");
                        if (ptr != NULL) a = strtol (ptr,&pEnd,10);

                        ptr = strtoke(NULL,"/");
                        if (ptr != NULL) b = strtol (ptr,&pEnd,10);
                        
                        ptr = strtoke(NULL,"/");
                        if (ptr != NULL) c = strtol (ptr,&pEnd,10);
                        
                        v.push_back(vec3(a-1,b-1,c-1));
                    }
                    faces.push_back(v);
                }
            }
        }

};

#endif