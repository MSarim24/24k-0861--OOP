#include <iostream>
#include <vector>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double fileSize;
public:
    MediaFile(string path, double size) : filePath(path), fileSize(size) {}
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolution;
public:
    VisualMedia(string path, double size, int res) : MediaFile(path, size), resolution(res) {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, double size, int rate) : MediaFile(path, size), sampleRate(rate) {}
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double size, int res, int rate)
        : MediaFile(path, size), VisualMedia(path, size, res), AudioMedia(path, size, rate) {}
    
    void play() override {
        cout << "Playing video: " << filePath << endl;
    }
    void stop() override {
        cout << "Stopping video: " << filePath << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double size, int res) : MediaFile(path, size), VisualMedia(path, size, res) {}
    void play() override {
        cout << "Displaying image: " << filePath << endl;
    }
    void stop() override {
        cout << "Hiding image: " << filePath << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double size, int rate) : MediaFile(path, size), AudioMedia(path, size, rate) {}
    void play() override {
        cout << "Playing audio: " << filePath << endl;
    }
    void stop() override {
        cout << "Stopping audio: " << filePath << endl;
    }
};

int main() {
    vector<MediaFile*> mediaLibrary;
    
    VideoFile video("movie.mp4", 1024.5, 1080, 44100);
    ImageFile image("photo.jpg", 500.2, 720);
    AudioFile audio("song.mp3", 300.1, 44100);
    
    mediaLibrary.push_back(&video);
    mediaLibrary.push_back(&image);
    mediaLibrary.push_back(&audio);
    
    for (MediaFile* media : mediaLibrary) {
        media->play();
        media->stop();
    }
    return 0;
}
