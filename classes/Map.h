#ifndef MAP_H
#define MAP_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

typedef enum {W, G, P, n, o, e, O, E, F} tile;


class Map{
    private:
    const int xExtent{28};
    const int yExtent{31};
    tile PacmanMap[31][28];
    void rotateLeft(tile original[28][31], tile transposed[31][28]);
    //we start at row = 14 + 15 / 2
    //col 8
    SDL_Texture* text;
    SDL_Surface* surface;

    public:
    int getXExtent() const;
    int getYExtent() const;
    SDL_Surface* getSurface();
    SDL_Texture* getTexture();
    void setTexture(SDL_Texture* texture);
    bool isInBounds(int i, int j);
    tile getMapTile(int i, int j) const;
    Map();
};

#endif