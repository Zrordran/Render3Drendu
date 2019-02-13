#ifndef MOTEURRENDU3D_MODEL_H
#define MOTEURRENDU3D_MODEL_H

#include <vector>
#include <fstream>
#include "Point.h"
#include "Vector.h"
#include "tgaimage.h"

class model{

private:
    std::vector<float> verts_;
    std::vector<int> faces_;
    std::vector<Vector> textures_;
    std::vector<Point> nVertex_;
public:
    model(std::string filename);
    ~model();
    int nverts();
    int nfaces();
    int ntext();
    std::vector<float> vert(int i);
    std::vector<int> face(int idx);
    Vector text(int idx);
    void load_texture(std::string filename, TGAImage &img);
    std::vector<Vector> uv(int iface);
    TGAColor diffuse(Vector uv);

    TGAImage imgText;
};


#endif //MOTEURRENDU3D_MODEL_H

