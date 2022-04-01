#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    MazeCell* position = start;
    bool spellbook = false;
    bool potion = false;
    bool wand = false;
    if (position->whatsHere==Item::SPELLBOOK)
        spellbook=true;
    else if (position->whatsHere==Item::POTION)
        potion=true;
    else if (position->whatsHere==Item::WAND)
        wand=true;
    for (char c: moves){
        if (position==nullptr)
            break;
        if (c == 'N')
            position = position->north;
        else if (c == 'S')
            position = position->south;
        else if (c == 'E')
            position = position->east;
        else if (c == 'W')
            position = position->west;
        if (position->whatsHere==Item::SPELLBOOK)
            spellbook=true;
        else if (position->whatsHere==Item::POTION)
            potion=true;
        else if (position->whatsHere==Item::WAND)
            wand=true;
        if (spellbook && potion && wand)
            return true; 
    }
    return false;
}
