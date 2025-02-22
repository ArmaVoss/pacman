#ifndef MAP_H
#define MAP_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

typedef enum {W, G, P, n, o, e, O, E, F} tile;

class Map{
    private:
    const int xExtent{33};
    const int yExtent{21};
    tile PacmanMap[28][31] =
    {
            {W,W,W,W,W,W,W,W,W,W,W,W,n,n,n,W,P,W,n,n,n,W,W,W,W,W,W,W,W,W,W},
            {W,o,o,o,o,W,W,O,o,o,o,W,n,n,n,W,n,W,n,n,n,W,o,o,o,o,O,o,o,o,W},
            {W,o,W,W,o,W,W,o,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,o,o,o,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,W,W,W,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,W,n,W,W,W,W,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W},
            {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,n,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
            {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,n,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,o,o,o,W,W,o,n,n,n,n,n,n,n,n,n,W,W,o,o,o,o,W,W,W,o,W},
            {W,o,W,W,o,W,W,o,W,W,o,W,W,n,W,W,W,W,W,n,W,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,W,W,o,W,W,o,W,W,n,W,W,n,n,W,n,W,W,o,W,W,o,W,W,W,o,W},
            {W,o,o,o,o,W,W,o,o,o,o,W,W,n,W,W,n,n,W,n,n,n,o,W,W,o,o,o,o,o,W},
            {W,o,W,W,W,W,W,n,W,W,W,W,W,n,W,W,n,n,G,n,W,W,W,W,W,o,W,W,W,W,W},
            {W,o,W,W,W,W,W,n,W,W,W,W,W,n,W,W,n,n,G,n,W,W,W,W,W,o,W,W,W,W,W},
            {W,o,o,o,o,W,W,o,o,o,o,W,W,n,W,W,n,n,W,n,n,n,o,W,W,o,o,o,o,o,W},
            {W,o,W,W,o,W,W,o,W,W,o,W,W,n,W,W,n,n,W,n,W,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,W,W,o,W,W,o,W,W,n,W,W,W,W,W,n,W,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,o,o,o,W,W,o,n,n,n,n,n,n,n,n,n,W,W,o,o,o,o,W,W,W,o,W},
            {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,n,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
            {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,n,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W},
            {W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,W,n,W,W,W,W,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,W,W,W,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,o,o,o,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
            {W,o,W,W,o,W,W,o,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
            {W,o,o,o,o,W,W,O,o,o,o,W,n,n,n,W,n,W,n,n,n,W,o,o,o,o,O,o,o,o,W},
            {W,W,W,W,W,W,W,W,W,W,W,W,n,n,n,W,P,W,n,n,n,W,W,W,W,W,W,W,W,W,W}
    };

    SDL_Surface* surface;

    public:
    int getXExtent() const;
    int getYExtent() const;
    SDL_Surface* getSurface();
    bool isInBounds(int i, int j);
    char getMapTile(int i, int j) const;
    Map();
};

#endif