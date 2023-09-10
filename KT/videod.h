#ifndef VIDEOD_H
#define VIDEOD_H

#include <string>

class Video {
private:
    std::string videoNimi{};
    std::string esitlus{};
    int videoPikkus{};

public:
    Video() = default;
    Video(std::string m_videoNimi, std::string m_esitlus, int videoPikkus);

};

class Film{

};

class Pleier {

};

#endif