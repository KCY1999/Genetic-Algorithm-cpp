#include <iostream>
#include <cstdlib>
//#include <windows.h>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iterator>
#include <sstream>
#include <string.h>

using namespace std;
using std::bitset;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;

// bool cmp(vector<int> v1, vector<int> v2){
//     return v1[4] < v2[4];
// }

// int main()
// {
//     constexpr int ROWS = 20;
//     constexpr int COLUMNS = 5;
//     int maze[ROWS][COLUMNS];
//     srand( time(NULL) );
//     int min = 1;
//     int max =100;

//     for(int row = 0; row < ROWS; row++) {
//         for(int i = 0; i < COLUMNS; i++) {
//             if (i==4)
//             {
//                 maze[row][i] = rand() % (max - min) + min;
//             }else if(i==1)
//             {
//               maze[row][i] = row+1;
//             }else{
//                maze[row][i] = i+1;
//             }
//         }
//     }

//     cout<<"print 排序前的\n";
//     for(int row = 0; row < ROWS; row++) {
//         for(int i = 0; i < COLUMNS; i++) {
//             cout << maze[row][i] << "\t";
//         }
//         cout << endl;
//     }

//     // Initializing a single row
//     vector<int> row(COLUMNS, 0);
//     // Initializing the 2-D vector
//     vector<vector<int>> v(ROWS, row) ;

//     for(int row = 0; row < ROWS; row++) {
//         for(int i = 0; i < COLUMNS; i++) {
//              v[row][i] = maze[row][i];
//         }
//     }
//     sort(v.begin(), v.end(), cmp);

//     for(int row = 0; row < ROWS; row++) {
//         for(int i = 0; i < COLUMNS; i++) {
//              maze[row][i] = v[row][i];
//         }
//     }

//     cout<<"print 排序過後的";
//     cout<<"\n";
//     for(int row = 0; row < ROWS; row++) {
//         for(int i = 0; i < COLUMNS; i++) {
//             cout << maze[row][i] << "\t";
//         }
//         cout << endl;
//     }

//     return 0;
// }

//=================================================================

string toBinary(int n)
{
    string r;
    while (n != 0)
    {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return r;
}

int Binary2Decimal(int num)
{
    if (num >= 10)
    {
        int dev = num / 10;
        int mod = num % 10;
        return Binary2Decimal(dev) * 2 + mod;
    }
    else
    {
        return num;
    }
}
//=================================================================

// int dec1 = 0, rem1=0, num1, base1 = 1;

// int a = 101;

// int main()
// {
//     while (a > 0)
//     {

//         rem1 = a % 10;
//         dec1 = dec1 + (rem1 * base1);
//         base1 = base1 * 2;
//         a = a / 10;
//     }
//     cout << dec1 << endl;
// }

//=================================================================
// using std::cout; using std::endl;
// using std::string; using std::bitset;

// string toBinary(int n)
// {
//     string r;
//     while (n != 0){
//         r += ( n % 2 == 0 ? "0" : "1" );
//         n /= 2;
//     }
//     return r;
// }

// int main() {
//     int number = -512, tmp = 0;
//     string tmpp;

//     bitset<10> bs2(number);
//     tmpp = bs2.to_string();

//     cout << "binary:  " << bs2 << endl;

// }
//=================================================================

// int Binary2Decimal(int num) {
// 	if (num >= 10) {
// 		int dev = num / 10;
// 		int mod = num % 10;
// 		return Binary2Decimal(dev) * 2 + mod;
// 	}
// 	else {
// 		return num;
// 	}
// }

// int main() {

//     string n = "1000000000";
//     string w = "0";
//     int x = 0, y;

//     while(x == 0)
//     {
//         // find_first_of()
//         size_t found1 = n.find_first_of(w);
//         if (found1 != n.npos)
//         {
//             if(found1 == 0)
//             {
//                 n.erase(0,1);
//                 cout << n <<endl;
//                 x = 0;
//             }
//         }
//         else
//         {
//             cout << n;
//             y = std::stoi(n);
//             cout << "Output:" << Binary2Decimal(y) << endl;
//             x = 1;
//         }
//     }
// }

//=================================================================
// using namespace std;

// string toBinary(int n)
// {
//     string r;
//     while (n != 0){
//         r += ( n % 2 == 0 ? "0" : "1" );
//         n /= 2;
//     }
//     return r;
// }

// int main()
// {

//     string tmp;
//     int tmpp;

//     // Initialization of bitset
//     bitset<10> b2(string("0000000000"));

//     //cout << b2 << " after applying flip function returns ";
//     tmp = b2.to_string();
//     cout <<"初始值:"<< tmp << endl;
//     for(int i=10;i>0;i--)
//     {
//         cout << b2.flip(i-1) << endl;
//     }
//     tmp = b2.to_string();
//     cout <<"最終值:"<< tmp << endl;

//     tmpp = std::stoi(tmp);
//     cout <<"轉換後"<< tmpp << endl;

//     return 0;
// }
//=================================================================
// int main() {
//     // Init
//     string s = "1000000000";
//     string w = "1";

//     // find_first_of()
//     size_t found1 = s.find_first_of(w);
//     if (found1 != s.npos)
//     {
//         s.erase(0,1);
//         cout << s <<endl;
//     }
//     else
//     {

//     }
//     return 0;
// }
//=================================================================
// int Binary2Decimal(int num) {
// 	if (num >= 10) {
// 		int dev = num / 10;
// 		int mod = num % 10;
// 		return Binary2Decimal(dev) * 2 + mod;
// 	}
// 	else {
// 		return num;
// 	}
// }

// int main() {
//     // Init
//     string s = "0100000001";
//     string w = "0";
//     int x = 0, y, z;

//     x -= 1;

//     while(x == 0)
//     {
//         size_t found1 = s.find_first_of(w);
//         if (found1 != s.npos)
//         {
//             if (found1 == 0)
//             {
//                 cout << s <<endl;
//                 s.erase(0,1);
//                 cout << s <<endl;
//             }
//             else
//             {
//                 cout << s << endl;
//                 y = std::stoi(s);
//                 x = 1;
//                 z = Binary2Decimal(y);
//                 cout << z << endl;
//             }
//         }

//     }
// }
//=================================================================
// int main()
// {
//     int x = 511, y = 512, z = 0 , mo = 0;
//     int rnd, rndd;
//     int tmp, tmpp;
//     int num1, num2;
//     string tmp1, tmp2, tmp3, tmp4;


//     int length1 = 0, length2 = 0;
//     int array1[10], array2[10];

//     bitset<10> i2b1(x);
//     bitset<10> i2b2(y);
//     tmp1 = i2b1.to_string();
//     tmp2 = i2b2.to_string();

//     tmp = std::stoi(tmp1);
//     tmpp = std::stoi(tmp2);

//     for(int i = 0; i < 10; i++)
//     {
//         array1[length1++] = tmp % 10;
//         tmp /= 10;

//         array2[length2++] = tmpp % 10;
//         tmpp /= 10;
//     }

//     cout << "parent1:";
//     for(int i=0;i<10;i++)
//     {
//         cout<< array1[i];
//     }
//     cout << endl;
//     cout << "parent2:";
//     for(int i=0;i<10;i++)
//     {
//         cout<< array2[i];
//     }
//     cout << endl;

//     rnd = rand() % 9 + 1;
//     rndd = rand() % 9 + 1;
//     while(rnd == rndd)
//     {
//         rndd = rand() % 9 + 1;
//     }
//     if(rnd < rndd)
//     {
//         for (int i = rnd; i >= 0; i--)
//         {
//             num1 = array1[length1 - i];
//             num2 = array2[length2 - i];

//             array1[length1 - i] = num2;
//             array2[length2 - i] = num1;
//         }
//         num1 = 0, num2 = 0; 
//         mo = 0;
//         for (int i = rndd-rnd; i > 0; i--)
//         {
//             num1 = array1[length1 - (rndd-mo)];
//             num2 = array2[length2 - (rndd-mo)];

//             array1[length1 - (rndd-mo)] = num2;
//             array2[length2 - (rndd-mo)] = num1;
//             mo+=1;
//         }
//     }
//     if(rnd > rndd)
//     {
//         for (int i = rndd; i >= 0; i--)
//         {
//             num1 = array1[length1 - i];
//             num2 = array2[length2 - i];

//             array1[length1 - i] = num2;
//             array2[length2 - i] = num1;
//         }
//         num1 = 0, num2 = 0;
//         mo = 0;
//         for (int i = rnd-rndd; i > 0; i--)
//         {
//             num1 = array1[length1 - (rnd-mo)];
//             num2 = array2[length2 - (rnd-mo)];

//             array1[length1 - (rnd-mo)] = num2;
//             array2[length2 - (rnd-mo)] = num1;
//             mo+=1;
//         }
//     }

//     cout << "os1:";
//     for(int i=length1-1; i>=0; i--)
//     {
//         string num_cstr(std::to_string(array1[i]));
//         tmp3 += num_cstr;
//     }
//     cout<< tmp3<<endl;
//     cout << "os2:";
//     for(int i=length2-1; i>=0; i--)
//     {
//         string num_cstr(std::to_string(array2[i]));
//         tmp4 += num_cstr;
//     }
//     cout<< tmp4;
// }
//=================================================================
// int main(){
//     srand(time(NULL));
//     int i, n1, n2, arrandom[100] = {0};   //將陣列所以成員初始為0
//     for(i = 0 ; i < 100 ; i++){
//         do{
//             n1 = rand() % 100;   //使用n存放亂數所生成的數字
//             n2 = rand()% 100;
//         }while(arrandom[n1-1] != 0 && arrandom[n2-1] != 0);  //使用n作為索引號，判斷counter[n-1]在陣列中是否為0，不是則繼續做迴圈
//         std::cout << n1 << std::endl;
//         std::cout << n2 << std::endl;
//         arrandom[n1-1]++ ;  //使用該亂數之後，將該亂數的位置存放值+1，表示使用過
//         arrandom[n2-1]++ ; 
//     }
// }

                // do
                // {
                //     n1 = rand() % 100;  
                //     n2 = rand() % 100;
                // }while(arrRandom2[n1-1] != 0 && arrRandom2[n2-1] != 0); 

                // arrRandom2[n1-1]++ ; 
                // arrRandom2[n2-1]++ ; 
                // //int x = arrRandom[i], y = arrRandom[i + 1];
                // int x = n1, y = n2;
//=================================================================
// int main()
// {
//     int rnd, index;
//     int arrRandom[100];

//     for (int i = 0; i < 100; i++)
//     {
//         arrRandom[i] = -1;
//     }

//     unsigned seed;
//     seed = (unsigned)time(NULL); // 取得時間序列
//     srand(seed);  

//     for (int rd_max = 0; rd_max < 100; rd_max++)
//     {
//         rnd = rand() % 100;
//         index = 0;
//         while (index <= rd_max) //不重複隨機數
//         {
//             if (rnd != arrRandom[index])
//             {
//                 if (index == rd_max)
//                 {
//                     arrRandom[index] = rnd;
//                     index = 100;
//                 }
//                 else
//                     index++;
//             }
//             else
//             {
//                 rnd = rand() % 100;
//                 index = 0;
//             }
//         }
//     }
//     return 0;
// }


// void tournamentK()
// {
//     int j;
//     int ind, ind_best;
//     float fitness, fitness_best;

//     for(int u = 0; u < parent_size; u++)
//     {
//         for(int i = 0; i < k; i++)
//         {
//             ind = rand() % parent_size;
//             fitness = y_origin * n;

//             j = 0;
//             for(int j = 0; j < n; j++)
//             {
//                 fitness -= parent[ind][j] * sin( sqrt( abs( parent[ind][j])));
//                 if(j == n - 1)  //適應值取小或設定初值
//                 {
//                     if(i == 0 || fitness < fitness_best)
//                     {
//                         fitness_best = fitness;
//                         ind_best = ind;
//                     }
//                 }
//             }
//         }
//         for(int i = 0; i < n; i++)
//         {
//             tournament[u][i] = parent[ind_best][i];
//             /*cout << tournament[u][i] << "\t";
//             if((i + 1) % 10 == 0)
//             {
//                 cout << endl;
//             }*/
//         }
//     }
// }
