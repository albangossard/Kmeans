#ifndef H_KMEAN
#define H_KMEAN

#include <iostream>
#include <list>

typedef int data;

struct Pt{
    double x,y;
    int id_cluster;
    data dat;
};

struct Cluster{
    double x,y;
};

class Kmean{
public:
    int nbPts;
    int nbCluster;
    // int nIter;
    Pt * pts;
    Cluster * means;
    void recursive();
    void init();
    Kmean();
}

#endif