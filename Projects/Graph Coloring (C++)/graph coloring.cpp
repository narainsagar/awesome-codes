
#include <iostream>
#include <fstream>
using namespace std;

int MaxDegreeInNN();
int MaxDegreeVertex();
void UpdateNN(int ColorNumber);
int FindSuitableY(int, int &);
// this program will work with graphs
// of which number of vertices is smaller or equal to 100
const int MAX = 100;
// necessary variables
// n is the number of vertices of the graph
int n;
// a[n][n] is the adjacency matrix of the graph
// a[i][j] = 1 if i-th and j-th vertices are adjacent
int a[MAX][MAX];
// array color[n] stores the colors of the vertices
// color[i] = 0 if we 've not colored it yet
int color[MAX];
// array degree[n] stores the degrees of the vertices
int degree[MAX];
// array NN[] stores all the vertices that is not adjacent to current vertex
int NN[MAX];
// NNCount is the number of that set
int NNCount;
// unprocessed is the number of vertices with which we 've not worked
int unprocessed;
// processing function
void Coloring()
{
    int x, y;
    int ColorNumber = 0;
    int VerticesInCommon = 0;
    while (unprocessed > 0) // while there is an uncolored vertex
    {
        x = MaxDegreeVertex(); // find the one with maximum degree
        ColorNumber++;
        color[x] = ColorNumber; // give it a new color
        unprocessed--;
        UpdateNN(ColorNumber); // find the set of non-neighbors of x
        while (NNCount > 0)
        {
            // find y, the vertex has the maximum neighbors in common with x
            // VerticesInCommon is this maximum number
            y = FindSuitableY(ColorNumber, VerticesInCommon);
            // in case VerticesInCommon = 0
            // y is determined that the vertex with max degree in NN
            if (VerticesInCommon == 0)
                y = MaxDegreeInNN();
            // color y the same to x
            color[y] = ColorNumber;
            unprocessed--;
            UpdateNN(ColorNumber);
            // find the new set of non-neighbors of x
        }
    }
}
// function that reads input from file named "input.txt" in the same folder
void GetInput()
{
    //ifstream in("input.txt");
    cout << "\n\tEnter the Number of Vertices " << endl;
    cin >> n; // read the number of vertices first
              //cout<<"\n\tEnter the Number of Adjacent Matrix"<<endl;
              //cin>>n;
    cout << "\n\tEnter the Number of Adjacent Matrix" << endl;
    for (int i = 0; i < n; i++) // then read the adjacency matrix
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j]; // read the element one by one
    }
    // in.close();
}

// initializing function
void Init()
{
    for (int i = 0; i < n; i++)
    {
        color[i] = 0;  // be sure that at first, no vertex is colored
        degree[i] = 0; // count the degree of each vertex
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1) // if i-th vertex is adjacent to another
                degree[i]++;  // increase its degree by 1
    }
    NNCount = 0; // number of element in NN set
    unprocessed = n;
    //cout << unprocessed;
}

// this function finds the unprocessed vertex of which degree is maximum
int MaxDegreeVertex()
{
    int max = -1;
    int max_i;
    for (int i = 0; i < n; i++)
        if (color[i] == 0)
            if (degree[i] > max)
            {
                max = degree[i];
                max_i = i;
            }
    return max_i;
}

// this function is for UpdateNN function
// it reset the value of scanned array
void scannedInit(int scanned[MAX])
{
    for (int i = 0; i < n; i++)
        scanned[i] = 0;
}

// this function updates NN array
void UpdateNN(int ColorNumber)
{
    NNCount = 0;
    // firstly, add all the uncolored vertices into NN set
    for (int i = 0; i < n; i++)
        if (color[i] == 0)
        {
            NN[NNCount] = i;
            NNCount++; // when we add a vertex, increase the NNCount
        }
    // then, remove all the vertices in NN that
    // is adjacent to the vertices colored ColorNumber
    for (int i = 0; i < n; i++)
        if (color[i] == ColorNumber) // find one vertex colored ColorNumber
            for (int j = 0; j < NNCount; j++)
                while (a[i][NN[j]] == 1)
                // remove vertex that adjacent to the found vertex
                {
                    NN[j] = NN[NNCount - 1];
                    NNCount--; // decrease the NNCount
                }
}

// this function will find suitable y from NN
int FindSuitableY(int ColorNumber, int &VerticesInCommon)
{
    int temp, tmp_y, y;
    // array scanned stores uncolored vertices
    // except the vertex is being processing
    int scanned[MAX];
    VerticesInCommon = 0;
    for (int i = 0; i < NNCount; i++) // check the i-th vertex in NN
    {
        // tmp_y is the vertex we are processing
        tmp_y = NN[i];
        // temp is the neighbors in common of tmp_y
        // and the vertices colored ColorNumber
        temp = 0;
        scannedInit(scanned);
        //reset scanned array in order to check all
        //the vertices if they are adjacent to i-th vertex in NN
        for (int x = 0; x < n; x++)
            if (color[x] == ColorNumber) // find one vertex colored ColorNumber
                for (int k = 0; k < n; k++)
                    if (color[k] == 0 && scanned[k] == 0)
                        if (a[x][k] == 1 && a[tmp_y][k] == 1)
                        // if k is a neighbor in common of x and tmp_y
                        {
                            temp++;
                            scanned[k] = 1; // k is scanned
                        }
        if (temp > VerticesInCommon)
        {
            VerticesInCommon = temp;
            y = tmp_y;
        }
    }
    return y;
}

// find the vertex in NN of which degree is maximum
int MaxDegreeInNN()
{
    int tmp_y; // the vertex has the current maximum degree
    int temp, max = 0;
    for (int i = 0; i < NNCount; i++)
    {
        temp = 0;
        for (int j = 0; j < n; j++)
            if (color[j] == 0 && a[NN[i]][j] == 1)
                temp++;
        if (temp > max) // if the degree of vertex NN[i] is higher than tmp_y's one
        {
            max = temp; // assignment NN[i] to tmp_y
            tmp_y = NN[i];
        }
    }
    if (max == 0) // so all the vertices have degree 0
        return NN[0];
    else // exist a maximum, return it
        return tmp_y;
}

// print out the output
void PrintOutput()
{
    for (int i = 0; i < n; i++)
        // element i-th of array color stores the color of (i+1)-th vertex
        cout << "Vertex " << i + 1
             << " is colored " << color[i] << endl;
}

// main function
int main()
{
    //  Init();
    GetInput();    // read the input adjacency matrix from file
    Init();        // initialize the data : degree, color array ..
    Coloring();    // working function
    PrintOutput(); // print the result onto the console lines
    system("pause");
}
