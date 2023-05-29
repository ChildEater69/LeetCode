class ParkingSystem {
public:
    map<int,int> m;
    ParkingSystem(int big, int medium, int small) {
        //setting the spaces for every type of car
        m[0]=big;
        m[1]=medium;
        m[2]=small;
    }
    
    bool addCar(int carType) {
        //as we started 0 based index we -1 the carType value
        if(m[carType-1]>0){
            m[carType-1]--;
            return true;
        }
        return false;            
    }
};