#ifndef TEXTURE_HPP
#define TEXTURE_HPP

// #include <iostream>
class Texture
{
    public:
        Texture(const char *texName);
    public:
        unsigned char *LoadTexture();

    private:
        const int width, height, numChannels, desiredChannels, ID;
        // const std::string texName;
    
    

}

#endif