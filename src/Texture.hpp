#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
class Texture
{
    public:
        Texture(std::string texname);
    public:
        void Load(std::string filePath);
        void CreateTexture();
        std::string getFileName();
        unsigned int getID();
        unsigned int getWidth();
        unsigned int getHeight();
        unsigned char *getData();

    private:
        int width, height, numChannels;
        unsigned int ID;
        unsigned char *data;
        std::string filename;
        std::string texname; //potentially useful identifier, will remove if proven wrong
};

#endif