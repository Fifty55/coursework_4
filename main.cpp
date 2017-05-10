
#include "Functioner.h"

using namespace std;

int main()
{
// Read data from file

unsigned int vertex_number,deminition,marker,i;

double z;

vector <vertex <double>* > node;

ifstream myfile ("triangulation#4.tri");

myfile>> vertex_number >> deminition >> marker;

for(i=0;i<vertex_number;i++)
{
    node.push_back( new vertex<double> (myfile));

    myfile>> z;
}

map<int, vector <int> > triangle_map;

vector <triangle*> triangle_data;

int triangles_number;

myfile>>triangles_number>> deminition>> marker;

for(i=0;i<triangles_number;i++)
{
    triangle_data.push_back(new triangle (myfile));

    triangle_map[triangle_data[i]->get_first_vertex()].push_back(triangle_data[i]->get_triangle_number());

    triangle_map[triangle_data[i]->get_second_vertex()].push_back(triangle_data[i]->get_triangle_number());

    triangle_map[triangle_data[i]->get_third_vertex()].push_back(triangle_data[i]->get_triangle_number());

    triangle_data[i] ->updata_area( calculate_area ( node[triangle_data[i]->get_first_vertex()],
                                                     node[triangle_data[i]->get_second_vertex()],
                                                     node[triangle_data[i]->get_third_vertex()] ) );
    triangle_data[i] ->calculate_centre ( node[triangle_data[i]->get_first_vertex()],
                                          node[triangle_data[i]->get_second_vertex()],
                                          node[triangle_data[i]->get_third_vertex()] );
}


myfile.close();
// Read finish
//-------------------------------------test-----------------------------------------//

ramp_functioner function_(2);
//cout<<triangle_data[1]->get_circumcentre().get_x()<<"\n";
//cout<<triangle_data[1]->get_circumcentre().get_y()<<"\n";
//cout<<triangle_data[1]->get_area ();

//cout<< function_.integration_method1(triangle_data[1])<<"\n";
//cout<< function_.integration_method2(node[triangle_data[1]->get_first_vertex()],node[triangle_data[1]->get_second_vertex()],node[triangle_data[1]->get_third_vertex()],triangle_data[1])<<"\n";
//cout<<triangle_map[4][2];
for(int j=0; j < triangle_data.size(); j++)
{
    if (triangle_data[j]->check_Delaunay(triangle_map,node,triangle_data)==0 )
    {
        cout<<" This is not a Delaunay triangulation \n";
        break;
    }

}
//bool with=triangle_data[1]->check_Delaunay(triangle_map,node,triangle_data);
//cout<<with;
//int a,b,c;
//double d;
//a=triangle_data [1]->get_first_vertex();
//b=triangle_data [1]->get_second_vertex();
//c=triangle_data [1]->get_third_vertex();

//d= calculate_area(node[1],node[2],node[3]);
//triangle w(1,*node[0],*node[1],*node[3],232.2,*node[3]);

//w.updata_circumcentre(node[2]);// why this doesn't work
//cout<<w.get_circumcentre();
//cout<<triangle_data[1]->get_area()<<"\n";
//cout<<triangle_data[1]->get_first_vertex();
//cout<<triangle_data[1]->get_second_vertex();
//cout<<triangle_data[1]->get_third_vertex();
//cout<<triangle_data[1] -> PointInTriangle(node[0],node[a],node[b],node[c]);


//cout<<*node[0];
// cout<<node[0];  why this doesn't work
//-------------------------------------test-end-----------------------------------------//


    return 0;
}

