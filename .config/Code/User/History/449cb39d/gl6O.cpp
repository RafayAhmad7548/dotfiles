struct keyinfo{
    bool pressedOnce;
    long long time;
    keyinfo() : pressedOnce(false), time(0){}
    virtual void single_press() = 0;
};

struct shift_info : public keyinfo{
    void single_press(){

    }
    void double_press(){

    }
};