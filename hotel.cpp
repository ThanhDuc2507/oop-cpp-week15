
#include <iostream>
#include <string>
using namespace std;

class Room {
protected:
    string id;
    int adults;
    int children;

public:
    Room() : id(""), adults(2), children(1) {}

    Room(string roomId, int adultCount, int childCount) {
        id = roomId;
        adults = adultCount;
        children = childCount;
    }

    virtual void displayInfo() = 0;

    string getId() const {
        return id;
    }

    int getAdults() const {
        return adults;
    }

    int getChildren() const {
        return children;
    }

    void setId(string roomId) {
        id = roomId;
    }

    void setAdults(int count) {
        adults = count;
    }

    void setChildren(int count) {
        children = count;
    }

    virtual ~Room() {}
};

class StandardRoom : public Room {
public:
    StandardRoom() : Room() {}

    StandardRoom(string roomId) : Room(roomId, 2, 1) {}

    void displayInfo() override {
        cout << "Standard Room | ID: " << id
             << " | Adults: " << adults
             << " | Children: " << children << endl;
    }
};

class DeluxeRoom : public Room {
private:
    int bedOption;

public:
    DeluxeRoom() : Room(), bedOption(1) {}

    DeluxeRoom(string roomId, int bed)
        : Room(roomId, 2, 1), bedOption(bed) {}

    int getBedOption() const {
        return bedOption;
    }

    void setBedOption(int bed) {
        bedOption = bed;
    }

    void displayInfo() override {
        cout << "Deluxe Room | ID: " << id
             << " | Adults: " << adults
             << " | Children: " << children;

        cout << " | Bed: "
             << (bedOption == 1 ? "1 Large Double Bed" : "2 Double Beds")
             << endl;
    }
};

class LuxuryRoom : public Room {
private:
    int bedOption;
    bool privateBathroom;

public:
    LuxuryRoom() : Room(), bedOption(1), privateBathroom(true) {}

    LuxuryRoom(string roomId, int bed)
        : Room(roomId, 2, 1), bedOption(bed), privateBathroom(true) {}

    int getBedOption() const {
        return bedOption;
    }

    bool hasPrivateBathroom() const {
        return privateBathroom;
    }

    void setBedOption(int bed) {
        bedOption = bed;
    }

    void setPrivateBathroom(bool status) {
        privateBathroom = status;
    }

    void displayInfo() override {
        cout << "Luxury Room | ID: " << id
             << " | Adults: " << adults
             << " | Children: " << children;

        cout << " | Bed: "
             << (bedOption == 1 ? "1 Large Double Bed" : "2 Double Beds");

        cout << " | Private Bathroom: "
             << (privateBathroom ? "Yes" : "No") << endl;
    }
};

int main() {
    StandardRoom standard[10];
    DeluxeRoom deluxe[10];
    LuxuryRoom luxury[10];

    for (int i = 0; i < 10; i++) {
        string number = (i < 9 ? "0" : "") + to_string(i + 1);

        standard[i].setId("S" + number);
        deluxe[i].setId("D" + number);
        luxury[i].setId("L" + number);

        deluxe[i].setBedOption((i % 2 == 0) ? 1 : 2);
        luxury[i].setBedOption((i % 2 == 0) ? 1 : 2);
    }

    Room* roomList[30];

    for (int i = 0; i < 10; i++) {
        roomList[i] = &standard[i];
        roomList[i + 10] = &deluxe[i];
        roomList[i + 20] = &luxury[i];
    }

    for (int i = 0; i < 30; i++) {
        roomList[i]->displayInfo();
    }

    return 0;
}
