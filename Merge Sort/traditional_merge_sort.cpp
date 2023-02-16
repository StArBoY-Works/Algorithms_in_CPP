/*  
      *******                                        *                                  
    *       ***      *                             **                                   
   *         **     **                             **                                   
   **        *      **                             **                                   
    ***           ********            ***  ****    **            ****    **   ****      
   ** ***        ********     ****     **** **** * ** ****      * ***  *  **    ***  *  
    *** ***         **       * ***  *   **   ****  *** ***  *  *   ****   **     ****   
      *** ***       **      *   ****    **         **   ****  **    **    **      **    
        *** ***     **     **    **     **         **    **   **    **    **      **    
          ** ***    **     **    **     **         **    **   **    **    **      **    
           ** **    **     **    **     **         **    **   **    **    **      **    
            * *     **     **    **     **         **    **   **    **    **      **    
  ***        *      **     **    **     ***        **    **    ******      *********    
 *  *********        **     ***** **     ***        *****       ****         **** ***   
*     *****                  ***   **                ***                           ***  
*                                                                           *****   *** 
 **                                                                       ********  **  
                                                                          *      ****    
               _oo0oo_                                                                                                                   
              o8888888o 
              88" . "88 
              (| -_- |) 
              0\  =  /0 
            ___/`---'\___ 
          .' \\|     |// '. 
         / \\|||  :  |||// \ 
        / _||||| -:- |||||- \ 
       |   | \\\  -  /// |   | 
       | \_|  ''\---/''  |_/ | 
       \  .-\__  '-'  ___/-. / 
     ___'. .'  /--.--\  `. .'___ 
  ."" '<  `.___\_<|>_/___.' >' "". 
 | | :  `- \`.;`\ _ /`;.`/ - ` : | | 
 \  \ `_.   \_ __\ /__ _/   .-` /  / 
=====`-.____`.___ \_____/___.-`___.-'===== 
               `=---=' 
*/

/*

Written By :-

    **        
     *****        
    *  ***        
       ***        
      *  **       
      *  **       
     *    **      
     *    **      
    *      **     
    *********     
   *        **    
   *        **    
  *****      **   
 *   ****    ** * 
*     **      **  MEYA CHAVAN
*                 
 **   

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl "\n";
#define debug(x) cout<< #x <<" "<< x <<endl;

void Merge_Sort(int * uns_arr, int low, int high, int size);
void Merging(int * uns_arr, int low, int high, int mid, int size);

int32_t main() 
{   
    clock_t start, end;
    int size;
    cin>>size;
    int * arr;

    arr = (int*)malloc(size * sizeof(int));

    for(int i = 0; i < size; ++i)
    {
	cout<<"Enter the ["<<i + 1<<"] Element of Array : ";
        cin>>arr[i];
    }

    cout<<"Before Sorting :- ";

    for(int i = 0; i < size; ++i)
    {
        cout<<arr[i]<<" ";
    }

    start = clock();
        
    Merge_Sort(arr, 0, size - 1, size);

    end = clock();

    cout<<"\nAfter Sorting :- ";

    for(int i = 0; i < size; ++i)
    {
        cout<<arr[i]<<" ";
    }

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by Program is : " << fixed << time_taken << setprecision(5) << " sec " << endl;
    return 0;
}

void Merge_Sort(int * uns_arr, int low, int high, int size)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        Merge_Sort(uns_arr, low, mid, size);
        Merge_Sort(uns_arr, mid + 1, high, size);
        Merging(uns_arr, low, high, mid, size);
    }
}

void Merging(int * uns_arr, int low, int high, int mid, int size)
{
    int u_s_arr = low; //Start of Unsorted Array (u_s_arr)
    int m_u_arr = mid + 1; //Next of Middle Element of Unsorted Array (m_u_arr)
    int s_s_arr = low; //Start of Sorted Array (s_s_arr)
    int e_u_arr = high; //End of Unsorted Array (e_u_arr)

    int * dup_arr; //Duplicate Array
:
    dup_arr = (int*)malloc(size * sizeof(int));

    while((u_s_arr <= mid) and (m_u_arr <= e_u_arr))
    {
        if(uns_arr[u_s_arr] < uns_arr[m_u_arr])
        {
            dup_arr[s_s_arr] = uns_arr[u_s_arr];
            u_s_arr++;
        }
        else
        {
            dup_arr[s_s_arr] = uns_arr[m_u_arr];
            m_u_arr++;
        }
        s_s_arr++;
    }

    if(u_s_arr > mid)
    {
        while(m_u_arr <= e_u_arr)
        {
            dup_arr[s_s_arr] = uns_arr[m_u_arr];
            m_u_arr++;
            s_s_arr++;
        }
    }
    else
    {
        while(u_s_arr <= mid)
        {
            dup_arr[s_s_arr] = uns_arr[u_s_arr];
            u_s_arr++;
            s_s_arr++;
        }
    }

    for(int m = low; m <= high; ++m)
    {
        uns_arr[m] = dup_arr[m];
    }
}
