//
// Created by User on 2021/3/7.
//

#ifndef RUNNINGLION_DATABASE_H
#define RUNNINGLION_DATABASE_H

#include <fstream>

using namespace std;

template<class T>
class Database {
public:
    Database();
    void run();
private:
    fstream database;
    char fName[20];
    ostream& print(ostream&);
    void add(T&);
    bool find(const T&);
    void modify(const T&);
    friend ostream& operator<<(ostream& out, Database& db){
        return db.print(out);
    }
};

#endif //RUNNINGLION_DATABASE_H
