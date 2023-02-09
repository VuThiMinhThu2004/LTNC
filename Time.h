#ifndef TIME_H
#define TIME_H


class Time {
public:
    Time();
    ~Time();

    void start();
    void stop();
    int getTicks();
    void paused();
    void unpaused();
private:
    int start_tick;
    int paused_tick;

    bool is_paused;
    bool is_started;
};


#endif