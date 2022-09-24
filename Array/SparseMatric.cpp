#include<iostream>

using namespace std ;

class SparseMatrix
{
    // about the original array
    int row, col ;

    // size will keep a track of entries in your sparse matrix
    int size ;

    // 2d array
    int ** arr ;

    // cap
    int cap ;

    public :

    SparseMatrix(int tr, int tc)
    {
        row = tr ;
        col = tc ;
        size = 0 ;
        cap = 100 ;

        arr = new int *[cap] ;

        for(int i = 0 ; i < cap ; i++)
        {
            arr[i] = new int[3] ;
        }
    }

    void insert(int r, int c, int val)
    {
        if(r >= row || c >= col)
        {
            cout << "Wrong values" << endl ;
            return ;
        }

        arr[size][0] = r ;
        arr[size][1] = c ;
        arr[size][2] = val ;

        size++ ; 

    }

    void display()
    {
        cout << "Row\tColumn\tValue" << endl ;

        for(int i = 0 ; i < size ; i++)
        {
            cout << arr[i][0] << "\t" << arr[i][1] << "\t" << arr[i][2] << endl ;
        }
    }

    void addition(SparseMatrix o)
    {
        if(row != o.row || col != o.col)
        {
            cout << "Addition not possible" << endl ;
            return ;
        }

        SparseMatrix result (row, col) ;

        int i = 0 ;
        int j = 0 ;

        while(i < size && j < o.size)
        {

            // consume element from first sparse matrix
            if(arr[i][0] < o.arr[j][0] || (arr[i][0] == o.arr[j][0] && arr[i][1] < o.arr[j][1]))
            {
                result.insert(arr[i][0] , arr[i][1] , arr[i][2]) ;
                i ++ ;
            }

            // consume element from second sparse matrix
            else if(arr[i][0] > o.arr[j][0] || (arr[i][0] == o.arr[j][0] && arr[i][1] > o.arr[j][1]))
            {
                result.insert(o.arr[j][0] , o.arr[j][1] , o.arr[j][2]) ;
                j ++ ;
            }

            else
            {
                int addedvalue = arr[i][2] + o.arr[j][2] ;

                if(addedvalue != 0)
                {
                    result.insert(arr[i][0], arr[i][1], addedvalue) ;
                }

                i++ ;
                j++ ;
            }
        }

        // 2nd sm is over and elements are remaining in 1st sm
        while(i < size)
        {
            result.insert(arr[i][0] , arr[i][1] , arr[i][2]) ;
            i++ ;
        }

        // 1st sm is over and elements are remaining in 2nd sm
        while(j < o.size)
        {
            result.insert(arr[j][0] , arr[j][1] , arr[j][2]) ;
            j++ ;
        }

        result.display() ;

    }
} ;

int main()
{
    // SparseMatrix sm (5,4) ;

    // sm.insert(0,1,40) ;
    // sm.insert(1,2,30) ;
    // sm.insert(3,0,20) ;
    // sm.insert(4,0,10) ;

    // sm.display() ;

    SparseMatrix sm1 (5,5) ;
    sm1.insert(1,2,10) ;
    sm1.insert(1,4,12) ;
    sm1.insert(3,3,5) ;
    sm1.insert(4,1,15) ;
    sm1.insert(4,2,12) ;

    SparseMatrix sm2 (5,5) ;
    sm2.insert(1,3,8) ;
    sm2.insert(2,4,23) ;
    sm2.insert(3,3,9) ;
    sm2.insert(4,1,20) ;
    sm2.insert(4,2,25) ;

    sm1.addition(sm2) ;

}