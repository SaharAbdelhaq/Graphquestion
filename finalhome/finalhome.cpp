#include<iostream>
using namespace std;
#define VV 6
#define N 6


int arrVertices[6][6];
int c1=0,c2=0,c3 = 0,c4 = 0,c5 = 0,c6 = 0;
int s,Power;
int adjMat[VV][VV];
int resMat[VV][VV];

//init matrix to 0
void init(int arrVertices[][6])
{
    int i, j;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++)
            arrVertices[i][j] = 0;
}

void printMatrixVer(int v) { // matrix
    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            cout << arrVertices[i][j] << " ";
        }
        cout << endl;
    }
}


void addEdge(int x, int y) {
    if (x == 1 || y == 1) 
       c1++;
    if (x == 2 || y == 2)
        c2++;
    if (x == 3 || y == 3)
        c3++;
    if (x == 4 || y == 4) 
        c4++;
    if (x == 5 || y == 5)
        c5++;
    if (x == 6 || y == 6) 
        c6++;
    arrVertices[x - 1][y - 1] = 1;
    arrVertices[y - 1][x - 1] = 1;

    //printMatrixAdj
    /*
        cout << " ------------------" << endl;
         for (int i = 1; i < V; i++) {
        for (int j = 1; j < V; j++)
            cout << arrVertices[i][j] << " ";
        cout << "\n";
    }
    */

}

void Multiply(int power) {
    for (int p = 1; p < power; p++) {

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    s += arrVertices[i][k] * adjMat[k][j];
                }
                resMat[i][j] = s;
                s = 0;
            }
        }
        for (int b = 0; b < 6; b++) {
            for (int d = 0; d < 6; d++) {
                adjMat[b][d] = resMat[b][d];
            }
        }
    }

}

void printMatrixAdj(int v) {
    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

void printtt(int arr[VV][VV])
{
    int i, j;
    for (i = 1; i < VV; i++)
    {
        for (j = 1; j < VV; j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}


//4 


int main(int argc, char* argv[]) {
    int x = 0, q;
    int PA, QA, NA;
    int RES[VV][VV];

    addEdge(2, 6);
    addEdge(2, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(1, 2);
    addEdge(3, 1);
    addEdge(5, 1);
    addEdge(5, 4);

   // printMatrixVer(VV);
    /*
    *
      int adj2[V][V] = {
        {0,1,1,0,1,0},
        {1,0,1,1,0,1},
        {1,1,0,1,1,0},
        {0,1,1,0,1,0},
        {1,0,1,1,0,0},
        {0,1,0,0,0,0},

    };
    */

    int adj[VV][VV] = {
       {0,1,1,0,1,0},
       {1,0,1,1,0,1},
       {1,1,0,1,1,0},
       {0,1,1,0,1,0},
       {1,0,1,1,0,0},
       {0,1,0,0,0,0},

    };

    cout << " - Questions :-) " << endl;
    cout << "1. Represent the  graph with an adjacency matrix " << endl;
    printMatrixVer(VV);

    cout << "2. Find the degrees of the vertices of the directed graph " << endl;

    while (1) {

        cout << "\n Enter number of vertex u want to know it's degree,enter 0 to exit this Question" << endl;
        cin >> x;
        if (x == 1)
            cout << c1 << endl;
        if (x == 2) 
            cout << c2 << endl;
        if (x == 3)
            cout << c3 << endl;
        if (x == 4)
            cout << c4 << endl;
        if (x == 5)
            cout << c5 << endl;
        if (x == 6)
            cout << c6 << endl;
        if (x == 0)
            break;
    }

    cout << "3. Find the nth powers of the adjacency matrix of the graph(press 0 to exit this Question  " << endl;
    
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            adjMat[i][j] = arrVertices[i][j];

    printMatrixAdj(6);
    cout << endl;

    while (1) {
        
        cout << "Enter nth power" << endl;
        cin >> Power;
        if (Power == 0)
            break;

        else if (Power == 1)
            printMatrixVer(6); //

        else {
            Multiply(Power);
            printMatrixAdj(6);
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    adjMat[i][j] = arrVertices[i][j];
        }

    }

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            adjMat[i][j] = arrVertices[i][j];

    cout << "Enter  V " << endl;
    cin >> PA;
    cout << "Enter K " << endl;
    cin >> QA;
    cout << "Enter length n " << endl;
    cin >> NA;
    // comute nextttt

    int PE = PA;
    int ME = QA;

    PE--;
    ME--;

    if (NA == 2) {
        for (int i = 0; i < 6; i++){
            for (int k = 0; k < 6; k++) {
                RES[i][k] = 0;

                for (int e = 0; e < 6; e++){
                    RES[i][k] += adjMat[i][e] * adjMat[e][k];
                }
            }
        }
        cout << "number of paths of " << PA << QA << " with length 2 is " << RES[PE][ME] << endl;
    }
    if (NA > 2) {

        for (int i = 0; i< NA; i++) {
            for (int j = 0;j < 6; j++){
                for (int k = 0; k < 6; k++){
                    RES[j][k] = 0;
                    for (int l = 0; l < 6; l++){
                        if (i== 0) {
                            RES[j][k] += adjMat[j][l] * adjMat[l][k];
                        }
                        else {
                            RES[j][k] += adjMat[j][l] * adjMat[l][k];

                        }
                    }
                }
            }
        }
        cout << "number of paths from src  " << PA << " to destenation " << QA << " of length " << NA << " is " << RES[PE][ME] << endl;
    }

   // DijkstraAlgo(adjMat,src,dest,k);

}