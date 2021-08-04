#pragma once

class Rectangle
{
public:
    Rectangle();
    ~Rectangle();
    int nWidth;
    int nLength;
    void nArea();
private:
};

class Cuboid : public Rectangle
{
public:
    int nHeight;
    void nVolume();
};
