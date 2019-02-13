#include "Point.h"

Point::Point(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(){

}

int Point::getX(){
    return this->x;
}

int Point::getY() {
    return this->y;
}

int Point::getZ() {
    return this->z;
}