#ifndef DATATYPES_H
#define DATATYPES_H

//position on the screen
struct Position{
    float x;
    float y; 
};

//used to determine where we are on the map, that way we dont turn
//where we can't
struct MapPosition{
    int x;
    int y;
};

typedef enum {W, G, P, n, o, e, O, E, F} tile;

typedef enum {
    NONE,
    WEST,
    EAST,
    NORTH,
    SOUTH
} Direction;

#endif