class ParkingSystem{
    private:
    int numBig;
    int numMed;
    int numSmall;

    int bigCars;
    int medCars;
    int smallCars;

    public: 
    ParkingSystem(int big, int medium, int small){
        numBig = big;
        numMed = medium;
        numSmall = small;
        bigCars = 0;
        medCars = 0;
        smallCars = 0;
    }

    bool addCar(int carType){
        switch(carType){
            case 1:
                cout << "wanting to add big, nr of big spaces: " << bigCars << endl;
                if(bigCars < numBig){
                    bigCars++;
                    return true;
                }
                return false;
            case 2:
                if(medCars < numMed){
                    medCars++;
                    return true;
                }
                return false;
            case 3:
                if(smallCars < numSmall){
                    smallCars++;
                    return true;
                }
                return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */