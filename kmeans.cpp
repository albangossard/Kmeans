#include "kmeans.h"
#include <math.h>
#include <cmath>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void Kmean::init(){
    int listSelected[this->nbCluster];
    int j;
    bool indexNotSelected;
    for (int i=0; i<this->nbCluster; i++){
        indexNotSelected=false;
        while (!indexNotSelected){
            indexNotSelected=true;
            j = rand() % this->nbPts;
            for (int k=0; k<i; k++){
                if (j==listSelected[k]){
                    indexNotSelected=false;
                }
            }
        }
        listSelected[i]=j;
    }
    for (int i=0; i<this->nbCluster; i++){
        this->means[i].x = this->pts[listSelected[i]].x;
        this->means[i].y = this->pts[listSelected[i]].y;
    }
    cout<<"### init means ###"<<endl;
    for (int i=0; i<this->nbCluster; i++){
        cout<<this->means[i].x<<" "<<this->means[i].y<<endl;
    }
    cout<<endl;
}

void Kmean::recursive(int nIter){
    // if (n_iter==0){
    //     init(Pt * pts);
    // }
    double d,d2;
    int idClusterNearest;
    for (int i=0; i<this->nbPts; i++){
        d = dist(this->pts[i].x, this->pts[i].y, this->means[0].x, this->means[0].y);
        idClusterNearest=0;
        for (int j=1; j<this->nbCluster; j++){
            d2=dist(this->pts[i].x, this->pts[i].y, this->means[j].x, this->means[j].y);
            if (d2<d){
                d=d2;
                idClusterNearest=j;
            }
        }
        this->pts[i].id_cluster=idClusterNearest;
    }
    double xMeans[this->nbCluster];
    double yMeans[this->nbCluster];
    int nPerCluster[this->nbCluster];
    for (int j=0; j<this->nbCluster; j++){
        xMeans[j]=0;
        yMeans[j]=0;
        nPerCluster[j]=0;
    }
    for (int i=0; i<this->nbPts; i++){
        xMeans[this->pts[i].id_cluster]+=this->pts[i].x;
        yMeans[this->pts[i].id_cluster]+=this->pts[i].y;
        nPerCluster[this->pts[i].id_cluster]+=1;
    }
    bool converged=true;
    double eps=1e-7;
    for (int j=0; j<this->nbCluster; j++){
        if (nPerCluster[j]==0){
            cout<<"Warning : 0 pts in cluster "<<j<<endl; }
        xMeans[j]/=nPerCluster[j];
        yMeans[j]/=nPerCluster[j];
        // cout<<this->means[j].x<<"   "<<xMeans[j]<<endl;
        // cout<<this->means[j].y<<"   "<<yMeans[j]<<endl;
        if (abs(this->means[j].x-xMeans[j])>eps && abs(this->means[j].y-yMeans[j])>eps){
            // cout<<"Not converged yet"<<endl;
            converged=false;
        }
        this->means[j].x=xMeans[j];
        this->means[j].y=yMeans[j];
    }
    cout<<endl<<"################ Iteration "<<nIter<<" ################"<<endl;
    this->printClustering();
    if (nIter>=20){
        cout<<"Max iteration number reached !"<<endl;
    }else{
        if (!converged){
            this->recursive(nIter+1);
        }
    }
}

Kmean::Kmean(int nbPts, Pt * pts, int nbCluster){
    this->nbPts=nbPts;
    this->nbCluster=nbCluster;
    // this->pts = (Pt *) malloc(sizeof(Pt)*this->nbPts);
    this->pts=pts;
    this->means = (Cluster *) malloc(sizeof(Cluster)*this->nbCluster);
}

void Kmean::printClustering(){
    cout<<"### Clustering ###"<<endl;
    for (int j=0; j<this->nbCluster; j++){
        cout<<"Cluster "<<j<<"  centered in ("<<this->means[j].x<<", "<<this->means[j].y<<")"<<endl;
        for (int i=0; i<this->nbPts; i++){
            if (this->pts[i].id_cluster==j){
                cout<<"Pt "<<i<<"  ("<<this->pts[i].x<<", "<<this->pts[i].y<<")"<<endl;
            }
        }
    }
    cout<<endl;
}

int main(){
    int nbPts=10;
    int nbCluster=3;
    Pt * pts;
    pts = (Pt *) malloc(sizeof(Pt)*nbPts);
    pts[0].x=5; pts[0].y=0.5;
    pts[1].x=6; pts[1].y=2;
    pts[2].x=5; pts[2].y=2.5;
    pts[3].x=1; pts[3].y=4;
    pts[4].x=0; pts[4].y=3;
    pts[5].x=1.5; pts[5].y=4.5;
    pts[6].x=6; pts[6].y=6;
    pts[7].x=6; pts[7].y=5;
    pts[8].x=6; pts[8].y=7;
    pts[9].x=5; pts[9].y=6;
    Kmean a(nbPts,pts,nbCluster);
    a.init();
    a.recursive(0);
    return 0;
}
