#ifndef APP_H
#define APP_H



class App{


    public:
        App() {}
        ~App() {}
        int getTurn() {return turn;}
        void run();
        void incerementTurn() {turn+=1;}


    private:
        int turn = 1;

};


#endif