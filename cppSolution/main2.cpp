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

using namespace std;
using std::bitset;
using std::cout;
using std::endl;
using std::string;

//=================================================================
//
int tournamentS = 2, population_size = 100, offspring_size = 100, L = 100, LL, u = 100; //K, population size(μ), offspring size, L=個體個數, LL=L開根號
int arrRandom[100], Num_Generation = 500, trials = 20;  // random, generation, trials
int realV_Gen_AVE = 0, realV_Tri_AVE = 0;
float parent_tour[100][10], parents[100][10], parents_cross[100][10];
float offspring_cross[100][10];
float survivor_all[200][11];                                                  // Survivor Selection
float crossoverR = 0.5, mutationR = 0.01; // pc, pm
float num = 418.982;

float sum[31][500];

//=================================================================
//
void get_parent();

void tournament();

void uniform();
void two_p();
void bit_flip();

void survivor_sel();

void RDM();

//=================================================================

bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[10] < v2[10];
}

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

void RDM()
{
    int rnd, index;

    for (int i = 0; i < population_size; i++)
    {
        arrRandom[i] = -1;
    }

    unsigned seed;
    seed = (unsigned)time(NULL); // 取得時間序列
    srand(seed);

    for (int rd_max = 0; rd_max < population_size; rd_max++)
    {
        rnd = rand() % 100;
        index = 0;
        while (index <= rd_max) //不重複隨機數
        {
            if (rnd != arrRandom[index])
            {
                if (index == rd_max)
                {
                    arrRandom[index] = rnd;
                    index = population_size;
                }
                else
                    index++;
            }
            else
            {
                rnd = rand() % 100;
                index = 0;
            }
        }
    }
}

void get_parent()
{
    LL = sqrt(L);
    for (int i = 0; i < population_size; i++)
    {
        for (int j = 0; j < LL; j++)
        {
            parent_tour[i][j] = rand() % 1024 - 512;
            // cout<<parent_str[i][j]<<"\n";
        }
    }
}

void tournament()
{
    int ind1, ind2;
    float sig, adapt1, adapt2;

    for(int i = 0; i < u; i++)
    {
        for(int j = 0; j < tournamentS; j++)
        {
            ind1 = rand() % population_size;
            sig = 0;

            for(int k = 0; k < LL; k++)
            {
                sig += parent_tour[ind1][k] * sin( sqrt( abs( parent_tour[ind1][k])));
                adapt1 = num * LL - sig;
                if(k == LL - 1)
                {
                    if(j == 0 || adapt1 < adapt2)
                    {
                        adapt2 = adapt1;
                        ind2 = ind1;
                    }
                }
            }
        }
        for(int g = 0; g < LL; g++)
        {
            parents[i][g] = parent_tour[ind2][g];
        }
    }
}

// void tournament()
// {
//     int ind, ind2;
//     float sig, sigg, adapt, adapt2;

//     for (int i = 0; i < population_size; i++)
//     {
//         ind = (rand() % 100);
//         ind2 = (rand() % 100);
//         for (int k = 0; k < LL; k++)
//         {
//             sig += parent_tour[ind][k] * sin(sqrt(abs(parent_tour[ind][i])));
//             sigg += parent_tour[ind2][k] * sin(sqrt(abs(parent_tour[ind][i])));
//         }
//         adapt = num * LL - sig;
//         adapt2 = num * LL - sigg;
//         if (adapt < adapt2)
//         {
//             for (int j = 0; j < LL; j++)
//             {
//                 parents[i][j] = parent_tour[ind][j];
//             }
//         }
//         else
//         {
//             for (int j = 0; j < LL; j++)
//             {
//                 parents[i][j] = parent_tour[ind2][j];
//             }
//         }
//     }
// }

void uniform()
{
    int rndd, rnddd, prob, b1 = 0;

    RDM();

    rndd = rand() % 10 + 1;
    prob = crossoverR * 10;

    if (rndd >= 0 && rndd <= prob)
    {
        for (int i = 0; i < offspring_size; i += 2)
        {
            int x = arrRandom[i], y = arrRandom[i + 1];

            for (int j = 0; j < 10; j++)
            {
                if (rndd == 0)
                {
                    offspring_cross[i][j] = parents[x][j];
                    offspring_cross[i + 1][j] = parents[y][j];
                    b1 = 1;
                    break;
                }

                rnddd = rand() % 2;
                if (rnddd == 0) // do
                {
                    offspring_cross[i][j] = parents[x][j];
                    offspring_cross[i + 1][j] = parents[y][j];
                }
                else
                {
                    offspring_cross[i][j] = parents[y][j];
                    offspring_cross[i + 1][j] = parents[x][j];
                }
            }
        }
    }
    bit_flip();
}

void two_p()
{
    int n1, n2;
    int rnd, rndd, rnddd, prob, nt1 = 0, nt2 = 0, mo = 0, b1 = 0;
    int tmp, tmpp, num1, num2;
    int length1 = 0, length2 = 0;
    int bin1, bin2, dec1, dec2;
    int array1[10], array2[10];
    string tmp1, tmp2, tmp3, tmp4;
    string num_cstr1, num_cstr2;

    RDM();

    rndd = rand() % 10;
    prob = crossoverR * 10;

    if (rndd >= 0 && rndd <= prob)
    {
        for (int i = 0; i < offspring_size; i += 2)
        {
            int x = arrRandom[i], y = arrRandom[i + 1];

            for (int j = 0; j < 10; j++)
            {
                if (rndd == 0)
                {
                    offspring_cross[i][j] = parents[x][j];
                    ;
                    offspring_cross[i + 1][j] = parents[y][j];
                    b1 = 1;
                    break;
                }

                nt1 = parents[x][j];
                nt2 = parents[y][j];
                if (parents[x][j] < 0)
                {
                    nt1 = 0;
                    nt1 -= parents[x][j];
                }
                if (parents[y][j] < 0)
                {
                    nt2 = 0;
                    nt2 -= parents[y][j];
                }
                if (parents[x][j] > 0 && parents[y][j] > 0)
                {
                    nt1 = parents[x][j];
                    nt2 = parents[y][j];
                }

                bitset<10> i2b1(nt1);
                bitset<10> i2b2(nt2);

                tmp1 = i2b1.to_string();
                tmp2 = i2b2.to_string();

                tmp = std::stoi(tmp1);
                tmpp = std::stoi(tmp2);

                length1 = 0, length2 = 0;

                for (int i = 0; i < 10; i++)
                {
                    array1[length1++] = tmp % 10;
                    tmp /= 10;

                    array2[length2++] = tmpp % 10;
                    tmpp /= 10;
                }
                rnd = rand() % 9 + 1;
                rnddd = rand() % 9 + 1;
                while (rnd == rnddd)
                {
                    rnddd = rand() % 9 + 1;
                }

                if (rnd < rnddd)
                {
                    for (int i = rnd; i >= 0; i--)
                    {
                        num1 = array1[length1 - i];
                        num2 = array2[length2 - i];

                        array1[length1 - i] = num2;
                        array2[length2 - i] = num1;
                    }
                    num1 = 0, num2 = 0;
                    mo = 0;
                    for (int i = rnddd - rnd; i > 0; i--)
                    {
                        num1 = array1[length1 - (rnddd - mo)];
                        num2 = array2[length2 - (rnddd - mo)];

                        array1[length1 - (rnddd - mo)] = num2;
                        array2[length2 - (rnddd - mo)] = num1;
                        mo += 1;
                    }
                }

                if (rnd > rnddd)
                {
                    for (int i = rnddd; i >= 0; i--)
                    {
                        num1 = array1[length1 - i];
                        num2 = array2[length2 - i];

                        array1[length1 - i] = num2;
                        array2[length2 - i] = num1;
                    }
                    num1 = 0, num2 = 0;
                    mo = 0;
                    for (int i = rnd - rnddd; i > 0; i--)
                    {
                        num1 = array1[length1 - (rnd - mo)];
                        num2 = array2[length2 - (rnd - mo)];

                        array1[length1 - (rnd - mo)] = num2;
                        array2[length2 - (rnd - mo)] = num1;
                        mo += 1;
                    }
                }

                tmp3 = "", tmp4 = "";
                for (int i = 10; i > 0; i--)
                {
                    num_cstr1 = (std::to_string(array1[i - 1]));
                    tmp3 += num_cstr1;
                }

                for (int i = 10; i > 0; i--)
                {
                    num_cstr2 = (std::to_string(array2[i - 1]));
                    tmp4 += num_cstr2;
                }
                bin1 = std::stoi(tmp3);
                bin2 = std::stoi(tmp4);

                dec1 = Binary2Decimal(bin1);
                dec2 = Binary2Decimal(bin2);

                if (parents[x][j] < 0)
                {
                    dec1 = 0 - dec1;
                }
                if (parents[y][j] < 0)
                {
                    dec2 = 0 - dec2;
                }

                offspring_cross[i][j] = dec1;
                offspring_cross[i + 1][j] = dec2;
            }
        }
    }
    bit_flip();
}

void bit_flip()
{
    int rnd, bin, nt = 0, tmp, prob, x = 0, decimal = 0, b = 0;
    string tmpp, w = "0";

    prob = mutationR * 100;

    for (int i = 0; i < offspring_size; i++)
    {
        rnd = rand() % 100;

        for (int j = 0; j < LL; j++) // 10個基因
        {
            b = 0;

            if (offspring_cross[i][j] < 0)
            {
                nt = 0;
                nt -= offspring_cross[i][j];
            }
            else
            {
                nt = offspring_cross[i][j];
            }
            bitset<10> i2b(nt);

            // tmpp = i2b.to_string();
            // bitset<10> i2bb(tmpp);

            for (int k = 10; k > 0; k--) // 1個基因10個字(二進制) 每個字都要獨立判斷是否突變
            {
                if (rnd > 0 && rnd <= prob)
                {
                    i2b.flip(k - 1);
                }
                if (rnd == 0)
                {
                    b = 1;
                    break;
                }
            }

            if (b == 1)
            {
                break;
            }
            tmpp = i2b.to_string(); //二進制mutation結果

            for(int g=0;g<10;g++) //二轉十
            {
                size_t found1 = tmpp.find_first_of(w);
                if (found1 != tmpp.npos)
                {
                    if (found1 == 0 && tmpp != "0000000000")
                    {
                        // cout << tmpp <<endl;
                        tmpp.erase(0, 1);
                        // cout << tmpp <<endl;
                    }
                    else
                    {
                        // cout << tmpp << endl;
                        tmp = std::stoi(tmpp);
                        decimal = Binary2Decimal(tmp);

                        if (nt < 0)
                        {
                            decimal = 0 - decimal;
                            offspring_cross[i][j] = decimal;
                        }
                        else
                        {
                            offspring_cross[i][j] = decimal;
                        }
                        break;
                    }
                }
            }
            b = 0;
        }
    }
}

void survivor_sel()
{
    int ind, ind2;
    float sig, sigg, adapt3 = 0, adapt4 = 0;

    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < LL; j++)
        {
            sig += parents[i][j] * sin(sqrt(abs(parents[i][j])));
            sigg += offspring_cross[i][j] * sin(sqrt(abs(offspring_cross[i][j])));

            survivor_all[i][j] = parents[i][j];
            survivor_all[i + u][j] = offspring_cross[i][j];

            // cout<<"第"<<i<<"個" << survivor[i][j]<<"\n";
            // cout<<"第"<<i+100<<"個" << survivor[i+100][j]<<"\n";
        }
        adapt3 = num * LL - sig;
        adapt4 = num * LL - sigg;

        survivor_all[i][10] = adapt3;
        survivor_all[i + u][10] = adapt4;

        sig = 0, sigg = 0;
        adapt3 = 0, adapt4 = 0;
    }

    // Initializing a single row
    vector<int> row(11, 0);
    // Initializing the 2-D vector
    vector<vector<int>> v(population_size * 2, row);

    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < LL + 1; j++)
        {
            v[i][j] = survivor_all[i][j];
            v[i + u][j] = survivor_all[i + u][j];
        }
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < population_size; i++)
    {
        for (int j = 0; j < LL + 1; j++)
        {
            survivor_all[i][j] = v[i][j];
            survivor_all[i + u][j] = v[i + u][j];

            if (j < LL + 1)
            {
                parent_tour[i][j] = survivor_all[i][j];
            }
        }
        realV_Gen_AVE += survivor_all[i][10];
    }

    realV_Gen_AVE /= population_size;

    // cout << realV_Gen_AVE << "\t";
    // cout << endl;
}

//=================================================================
//
int main()
{
    unsigned clk;
    clk = (unsigned)time(NULL); // 取得時間序列
    srand(clk);                 // 以時間序列當亂數種子

    for (int i = 0; i < trials; i++)
    {
        get_parent();
        //cout << "第" << i+1 << "輪\n";
        for (int j = 0; j < Num_Generation; j++)
        {
            //cout << "第" << j + 1 << "代\n";
            tournament();
            //uniform();
            two_p();
            survivor_sel();
            sum[i][j] = realV_Gen_AVE;
        }
    }
    for (int i = 0; i < Num_Generation; i++)
    {
        for (int j = 0; j < trials; j++)
        {
            sum[trials][i] += sum[j][i];
        }
        sum[trials][i] /= trials;
        cout << sum[trials][i] << endl;
    }
}