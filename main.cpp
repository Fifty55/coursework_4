
#include "Functioner.h"

using namespace std;

int main()
{
// Read data from file

unsigned int vertex_number,deminition,marker,i;

double z;

vector <vertex <double>* > node;

ifstream myfile ("triangulation#2.tri");

myfile>> vertex_number >> deminition >> marker;

for(i=0;i<vertex_number;i++)
{
    node.push_back( new vertex<double> (myfile));

    myfile>> z;
}

map<int, vector <int>* > triangle_map;

vector <triangle*> triangle_data;

int triangles_number;

myfile>>triangles_number>> deminition>> marker;

for(i=0;i<triangles_number;i++)
{
    triangle_data.push_back(new triangle (myfile));
}

myfile.close();

//cout<< *node[1];
int a,b,c;
double d;
a=triangle_data [1]->get_first_vertex();
b=triangle_data [1]->get_second_vertex();
c=triangle_data [1]->get_third_vertex();

d= calculate_area(node[1],node[2],node[3]);
//triangle w(1,node[0],node[1],node[3],232.2);
cout<<d<<"\n";
cout<<triangle_data[1] -> PointInTriangle(node[0],node[a],node[b],node[c]);


//cout<<*node[0];
// cout<<node[0];  why this doesn't work

// Read finish

    return 0;
}
