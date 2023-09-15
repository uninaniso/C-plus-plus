#include <iostream>
#include <string>

using namespace std;

class Image {
private:
    unsigned short int width;
    unsigned short int height;
    string name;
    string extension;
    unsigned short int imageWeightInByte;

public:
    string format;
    string comment;
    string tags[100];
    unsigned short int rating;

    Image(unsigned short int inputWidth = 1000, unsigned short int inputHeight = 1000) {
        width = inputWidth;
        height = inputHeight;
        format = "";
        comment = "";
        tags;
        extension = ".jpg";
        name = "Image_01" + extension;
        rating = 0;
        imageWeightInByte = width * height * 3;
    }
    //GET
    unsigned short int getWidth() { return width; }
    unsigned short int getImageWeightInByte() { return imageWeightInByte; }
    string getName() { return name; }
    //SET
    void setWidth(unsigned short int inputWidth) { if (inputWidth > 500 && inputWidth < 10000) { width = inputWidth; } }

    void setName(string inputName) {
        int point = NULL;
        string stringNum[10] = { "0","1","2","3","4","5","6","7","8","9"};
        bool proccesStop = true;

        cout << "\n\n";

        for (int i = 0; i < 10; i++) {
            point = inputName.find(stringNum[i]);
            if (point != -1) {
                proccesStop = false;
                break;
            }
        }
        if (proccesStop)name = inputName;
    }
};

int main()
{
    Image first{ 640, 1280 };
    first.setName("name_94");
    cout << first.getName() << endl;
    first.setName("IvanZolo");
    cout << first.getName();
}