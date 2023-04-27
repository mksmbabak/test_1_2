#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class ElectronicDevice {
public:
    ElectronicDevice(string brand, string model) : brand_(brand), model_(model){}
    void display(){
        cout << "Brand - " << brand_ << "; Model - " << model_ << endl;
    }


protected:
    string brand_;
    string model_;
};

class SmartWatch : public ElectronicDevice{
public:
    SmartWatch(string brand, string model, bool hasGPS) : ElectronicDevice(brand, model), hasGPS_(hasGPS){}
    void display(){
        ElectronicDevice::display();
        cout << "GPS - " << hasGPS_ << endl;
    }


private:
    bool hasGPS_;


};

class Smartphone :public ElectronicDevice{
public:
    Smartphone(string brand, string model, int storageCapacity) : ElectronicDevice(brand, model), storageCapacity_(storageCapacity){}
    void display(){
        ElectronicDevice::display();
        cout << "Storage Capacity - " << storageCapacity_ << " gb" << endl;
    }


private:
    int storageCapacity_;
};

class Laptop : public ElectronicDevice{
public:
    Laptop (string brand, string model, int ramSize) : ElectronicDevice(brand, model), ramSize_(ramSize){}
    void display(){
        ElectronicDevice::display();
        cout << "RAM size - " << ramSize_ << endl;
    }


private:
    int ramSize_;
};

class GamingLaptop : public Laptop{
public:
    GamingLaptop(string brand, string model, int ramSize, string gpuModel) : Laptop(brand, model, ramSize), gpuModel_(gpuModel){}
    void display(){
        Laptop::display();
        cout << "GPU model - " << gpuModel_ << endl;
    }
private:
    string gpuModel_;
};

class Store{
public:
    void addDevice(std::unique_ptr<ElectronicDevice> device){
        devices.push_back(move(device));
    }
//    void displayDevices(){
//        for(auto device : devices){

//        }
//    }

private:
    vector<unique_ptr<ElectronicDevice>> devices;
};

int main()
{
    Store store;
    Laptop laptop("h", "p", 23);
    laptop.display();
}
