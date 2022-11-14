#include<iostream>
#include<queue>
#include<stack>

using namespace std ;

class Graph
{
    int **matrix ;
    int V ;

    public :

    Graph(int n)
    {
        V = n ;
        matrix = new int *[V] ;

        for(int i = 0 ; i < V ; i++)
        {
            matrix[i] = new int[V] ;
        }
    }

    void display()
    {
        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ; j < V ; j ++)
            {
                cout << matrix[i][j] << "\t" ;
            }
            cout << endl ;
        }
    }

    void addEdge(int u, int v)
    {
        matrix[u][v] = 1 ;
        matrix[v][u] = 1 ;
    }

    void bft()
    {
        bool *visited = new bool[V] ;

        queue<int> q ;
        q.push(0) ;

        while(!q.empty())
        {
            // remove
            int rn = q.front() ;
            q.pop() ;

            // something is already visited ignore
            if(visited[rn])
                continue ;

            // visited
            visited[rn] = true ;

            // print
            cout << rn << "\t" ;

            // nbrs
            for(int c = 0 ; c < V ; c ++)
            {
                if(matrix[rn][c] != 0 && !visited[c])
                {
                    q.push(c) ;
                }
            }
        }
    }

    void dft()
    {
        bool *visited = new bool[V] ;

        stack<int> s ;
        s.push(0) ;

        while(!s.empty())
        {
            // remove
            int rn = s.top() ;
            s.pop() ;

            // something is already visited ignore
            if(visited[rn])
                continue ;

            // visited
            visited[rn] = true ;

            // print
            cout << rn << "\t" ;

            // nbrs
            for(int c = 0 ; c < V ; c ++)
            {
                if(matrix[rn][c] != 0 && !visited[c])
                {
                    s.push(c) ;
                }
            }
        }
    }
} ;

int main()
{
    Graph g(7) ;

    g.addEdge(0,1) ;
    g.addEdge(1,2) ;
    g.addEdge(2,3) ;
    g.addEdge(3,0) ;
    g.addEdge(3,4) ;
    g.addEdge(4,5) ;
    g.addEdge(5,6) ;
    g.addEdge(4,6) ;

    // g.display() ;

    g.dft() ;


    return 0 ;
}

