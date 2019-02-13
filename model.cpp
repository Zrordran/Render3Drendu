#include "model.h"
#include "tgaimage.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>


model::model(std::string filename){
    std::cout << filename << std::endl;
     std::ifstream fichier(filename);
     if(fichier){
         std::string ligne;
         int j = 0;
         while(std::getline(fichier, ligne)){
             if(ligne.size() > 0){
                 j++;
                 std::istringstream iss(ligne);
                 std::vector<std::string> results((std::istream_iterator<std::string>(iss)),std::istream_iterator<std::string>());
                 if(results[0] == "v"){
                     verts_.push_back(stof(results[1]));
                     verts_.push_back(stof(results[2]));
                     verts_.push_back(stof(results[3]));
                 }else if(results[0] == "f"){
                     int nVertex[3];
                     for(int i = 1; i < 4; i++){
                         std::string s = results[i];
                         std::string delimiter = "/";
                         std::string token = s.substr(0, s.find(delimiter));
                         s.erase(0, s.find(delimiter) + delimiter.length());
                         std::string token2 = s.substr(0, s.find(delimiter));
                         faces_.push_back(std::stoi(token));
                         nVertex[i-1] = std::stoi(token2);
                     }
                     nVertex_.push_back(Point(nVertex[0], nVertex[1], nVertex[2]));
                 }else if(results[0] == "vt"){
                     Vector v = Vector(std::stof(results[1]),std::stof(results[2]),std::stof(results[3]));
                     textures_.push_back(v);
                 }
             }
         }
         load_texture(filename,imgText);
     }
}

model::~model() {

}

int model::nverts() {
    return verts_.size()/3;
}

int model::nfaces() {
    return faces_.size()/3;
}

int model::ntext() {
    return textures_.size();
}

std::vector<float> model::vert(int i) {
    std::vector<float> res;
    res.push_back(verts_[(i-1)*3]);
    res.push_back(verts_[((i-1)*3)+1]);
    res.push_back(verts_[((i-1)*3)+2]);
    return res;
}

std::vector<int> model::face(int idx) {
    std::vector<int> res;
    res.push_back(faces_[(idx-1)*3]);
    res.push_back(faces_[((idx-1)*3)+1]);
    res.push_back(faces_[((idx-1)*3)+2]);
    return res;
}

Vector model::text(int idx) {
    return textures_[idx];
}

void model::load_texture(std::string filename, TGAImage &img) {
    filename = filename.substr(0,filename.find_last_of(".")) + "_diffuse.tga";
    std::cout << (img.read_tga_file(filename.c_str()) ? "ok" : "fail") << std::endl;
    img.flip_vertically();
}

std::vector<Vector> model::uv(int iface) {
    Point idx = nVertex_[iface-1];
    std::vector<Vector> res;
    res.push_back(Vector(textures_[idx.x-1].x, textures_[idx.x-1].y,0.f));
    res.push_back(Vector(textures_[idx.y-1].x, textures_[idx.y-1].y,0.f));
    res.push_back(Vector(textures_[idx.z-1].x, textures_[idx.z-1].y,0.f));
    return res;
}

TGAColor model::diffuse(Vector uv) {
    return imgText.get(uv.x, uv.y);
}