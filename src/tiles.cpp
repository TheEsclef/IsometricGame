#include "tiles.h"

std::vector<Texture2D> InitializeTiles()
{
    std::vector<Texture2D> Textures;
    std::vector<Image> images =
        {LoadImage("sprites/grass0.png"),
         LoadImage("sprites/grass1.png"),
         LoadImage("sprites/grass2.png"),
         LoadImage("sprites/grass3.png")};
    
    
    for (Image image : images){
        Textures.push_back(LoadTextureFromImage(image));
        UnloadImage(image);      
    }

    return Textures;
};