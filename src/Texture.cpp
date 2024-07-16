#include "Texture.hpp"
#include <stb_image.h>
#include <filesystem>
#include <iostream>
#include <glad/glad.h>

Texture::Texture(std::string texname)
{
    //could also check if file exists here?
    this->data = nullptr;
    this->width = this->height = this->numChannels = 0;
    this->texname = texname;
}

void Texture::Load(std::string filePath)
{
    std::filesystem::path pathName = filePath.c_str();
    if(!(std::filesystem::exists(pathName))){
        std::cout << pathName.c_str() << " does not exist" << std::endl;
        return;
    }
    //check file type to determine whether to flip image
    this->data = stbi_load(getFileName().c_str(), &this->width, &this->height, &this->numChannels, 0);
    if(getData() == nullptr) //test this out
    {
        std::cout << "Failed to load texture" << std::endl;
    }
}

void Texture::CreateTexture()
{
    //check if data member has 'data' 
    if(getData() == nullptr)
    {
        std::cout << "Texture Data is Null" << std::endl;
        return;
    }
    glGenTextures(1, &this->ID);
    glBindTexture(GL_TEXTURE_2D, getID());
    //tex params, check to see if these are what i'd want
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, getWidth(), getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, getData());
    glGenerateMipmap(GL_TEXTURE_2D);
}

std::string Texture::getFileName()
{
    return this->filename;
}

unsigned int Texture::getID()
{
    return this->ID;
}

unsigned int Texture::getWidth()
{
    return this->width;
}

unsigned int Texture::getHeight()
{
    return this->height;
}

unsigned char *Texture::getData()
{
    return this->data;
}

