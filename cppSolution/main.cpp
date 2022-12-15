#include <iostream>
#include <cstdlib>
//#include <windows.h>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;
//=================================================================
//
int tournamentS = 2, population_size = 100, offspring_size = 100, n = 10, u = 100;   //k, population size, offspring size, n 個體個數, μ 選擇個體數
int arrRandom[100], Num_Generation = 200, trials = 30; // random,generation
float realV_Gen_AVE = 0, realV_Tri_AVE = 0;
float parent_tour[100][10], parents[100][10], parents_cross[100][10];
float offspring_cross[100][10];
float survivor_all[200][11];                                                 // Survivor Selection
float crossoverR = 0.9, mutationR = 0.1; // pc,pm
float num = 418.982;

float sum[31][1000];

//=================================================================
//
void get_parent();
void tournament();

void uniform();
void W_arithmetic();
void resetting();

void survivor_sel();

void RDM();

//=================================================================
//
bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[10] < v2[10];
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
    for (int i = 0; i < population_size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            parent_tour[i][j] = rand() % 1024 - 512 + ((rand() % 1000 / 1000));
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

            for(int k = 0; k < n; k++)
            {
                sig += parent_tour[ind1][k] * sin( sqrt( abs( parent_tour[ind1][k])));
                adapt1 = num * n - sig;
                if(k == n - 1)
                {
                    if(j == 0 || adapt1 < adapt2)
                    {
                        adapt2 = adapt1;
                        ind2 = ind1;
                    }
                }
            }
        }
        for(int g = 0; g < n; g++)
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
//         for (int k = 0; k < n; k++)
//         {
//             sig += parent_tour[ind][k] * sin(sqrt(abs(parent_tour[ind][i])));
//             sigg += parent_tour[ind2][k] * sin(sqrt(abs(parent_tour[ind][i])));

//             // cout<<parent_str[ind][i]<<"\n";
//             // cout<<parent_str[ind2][i]<<"\n";
//             // cout<<"sig" << sig << "\n";
//         }
//         adapt = num * n - sig;
//         adapt2 = num * n - sigg;
//         if (adapt < adapt2)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 parents[i][j] = parent_tour[ind][j];
//             }
//         }
//         else
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 parents[i][j] = parent_tour[ind2][j];
//             }
//         }
//     }
// }

void uniform()
{
    int rndd, rnddd, prob, index;

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
                    ;
                    offspring_cross[i + 1][j] = parents[y][j];
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
    resetting();
}

void W_arithmetic()
{
    int rndd, rnddd, prob;
    float alpha = 0;

    RDM();

    rndd = rand() % 10 + 1;

    if (rndd >= 0 && rndd <= prob)
    {
        for (int i = 0; i < offspring_size; i += 2)
        {
            int x = arrRandom[i], y = arrRandom[i + 1];

            rnddd = rand() % 10;
            alpha = rnddd / 10;

            for (int j = 0; j < 10; j++)
            {
                if (rndd == 0)
                {
                    offspring_cross[i][j] = parents[x][j];
                    ;
                    offspring_cross[i + 1][j] = parents[y][j];
                    break;
                }
                offspring_cross[i][j] = alpha * parents[x][j] + (1 - alpha) * parents[y][j];
                offspring_cross[i + 1][j] = alpha * parents[y][j] + (1 - alpha) * parents[x][j];
            }
        }
    }
    resetting();
}

void resetting()
{
    int rnd, rndd, rnddd, prob;

    prob = mutationR * 10;

    for (int i = 0; i < offspring_size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rnd = rand() % 10;
            if (rnd > 0 && rnd <= prob)
            {
                // rndd = rand() % 10;
                rnddd = rand() % 1024 - 512;
                offspring_cross[i][j] = rnddd;
            }
        }
    }
}

void survivor_sel()
{
    int ind, ind2;
    float sig, sigg, adapt3 = 0, adapt4 = 0;

    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sig += parents[i][j] * sin(sqrt(abs(parents[i][j])));
            sigg += offspring_cross[i][j] * sin(sqrt(abs(offspring_cross[i][j])));

            survivor_all[i][j] = parents[i][j];
            survivor_all[i + u][j] = offspring_cross[i][j];

            // cout<<"第"<<i<<"個" << survivor[i][j]<<"\n";
            // cout<<"第"<<i+100<<"個" << survivor[i+100][j]<<"\n";
        }
        adapt3 = num * n - sig;
        adapt4 = num * n - sigg;

        survivor_all[i][10] = adapt3;
        survivor_all[i + u][10] = adapt4;

        sig = 0, sigg = 0;
        sig = 0, sigg = 0;
        adapt3 = 0, adapt4 = 0;
    }

    // cout<<"排序前:\n";
    // for(int i = 0; i<parent_size; i++)
    // {
    //     for(int j = 0; j<n+1; j++)
    //     {

    //         cout << i << ":" << survivor_all[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    // Initializing a single row
    vector<int> row(11, 0);
    // Initializing the 2-D vector
    vector<vector<int>> v(population_size * 2, row);

    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            v[i][j] = survivor_all[i][j];
            v[i + u][j] = survivor_all[i + u][j];
        }
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < population_size; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            survivor_all[i][j] = v[i][j];
            survivor_all[i + u][j] = v[i + u][j];

            if (j < n + 1)
            {
                parent_tour[i][j] = survivor_all[i][j];
            }
        }
        realV_Gen_AVE += survivor_all[i][10];
    }

    realV_Gen_AVE /= population_size;

    //cout << realV_Gen_AVE << "\t";
    //cout << endl;

    //=======================================================
    // for(int i=0; i<parent_size; i++)
    // {
    //     cout << survivor_all[i][10] << "\t";
    //     cout << endl;
    // }

    // // cout<<"\n";
    // // cout<<"排序後";
    // // cout<<"\n";

    // // for(int i=0; i<parent_size; i++)
    // // {
    // //     cout << survivor_all[i][10] << "\t" << survivor_all[i+100][10] << "\t";
    // //     cout << endl;
    // // }
    //=======================================================
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
            W_arithmetic();
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