#ifndef H_KMEAN
#define H_KMEAN

#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>

struct Pt{
    double x,y;
    int id_cluster;
};

struct Cluster{
    double x,y;
};

class Kmean{
public:
    int nbPts;
    int nbCluster;
    Pt * pts;
    Cluster * means;
    int recursive(int nIter);
    void init();
    Kmean(int nbPts, double * xPts, double * yPts, int nbCluster, int iterMax = 1000);
    void printClustering();
    int compute(double * xMeans, double * yMeans, double * idCluster);
};

#endif