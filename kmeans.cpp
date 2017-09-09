#include "kmeans.h"

void Kmean::init(Pt * pts){
    std::list<int> listSelected;
    int j;
    for (int i=0; i<this->nbCluster; i++){
        // j = rand()
    }
}

void Kmean::recursive(Pt * pts, n_iter){
    // if (n_iter==0){
    //     init(Pt * pts);
    // }
}

Kmean::Kmean(){
    this->nbPts=10;
    this->nbCluster=3
    this->pts = (Pt *) malloc(sizeof(Pt)*this->nbPts);
    this->means = (Cluster *) malloc(sizeof(Cluster)*this->nbCluster);
}

int main(){
    pts = (double *) malloc(sizeof(Pt)*nb_pts);
    recursive(pts,0);
    return 0;
    Kmean a();
    a.init();
    a.recursive();
    return 0;
}
