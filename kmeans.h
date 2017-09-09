#ifndef H_KMEAN
#define H_KMEAN

#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>

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
    void recursive(int nIter);
    void init();
    Kmean(int nbPts, Pt * pts, int nbCluster);
    void printClustering();
};

#endif