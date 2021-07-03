#include<stdio.h>  // 갇힌 입자
#pragma warning(disable:4996)
double abs(double n) { return n * (n > 0 ? 1 : -1); }
double v[200005], vA[100005], vB[100005];


void init()
{
    v[0] = vA[0] = vB[0] = 0;
    for (int i = 1; i <= 100000; i++) v[2 * i - 1] = v[2 * i] = vA[i] = vB[i] = 0;
}
double f(double v, double vv, double k)
{
    return ((k - 1) / (k + 1)) * vv + (2 / (k + 1)) * v;
}
double g(double v, double vv, double k)
{
    return ((1 - k) / (1 + k)) * v + ((2 * k) / (k + 1)) * vv;
}
int main()
{
    FILE* output = fopen("output.csv", "w");
    FILE* output2 = fopen("output2.csv", "w");
    //if (output or output2) return -1;
    //while(true)
    for(double i = 2; i <= 5; i+=0.001)
    {
        init();
        double v0, k;
        //printf("k? ");
        //scanf("%lf", &k);
        k = i;
        v0 = 10000;
        //printf("%lf %lf\n", v0, k);

        int Q, ans = 0;
        //printf("Q? ");
        //scanf("%d",&Q);
        Q = 100000;

        v[0] = v0;

        fprintf(output, "===k = %.3lf===\n", k);

        for (int i = 1; i <= Q; i++)
        {
            if (abs(v[2 * i - 2]) < abs(vA[i - 1])) break;
            vA[i] = f(v[2 * i - 2], vA[i - 1], k);
            v[2 * i - 1] = g(v[2 * i - 2], vA[i - 1], k);

            if (abs(v[2 * i - 1]) < abs(vB[i - 1])) break;
            vB[i] = f(v[2 * i - 1], vB[i - 1], k);
            v[2 * i] = g(v[2 * i - 1], vB[i - 1], k);
        }

        fprintf(output, "%3c  , vB,v,vA,col,|%c\n", 'N', 'p');
        fprintf(output, "%03d  , %.3lf,%.3lf,%.3lf,%c,|vA(%lf) * %lfm + vB(%lf) * %lfm + v(%lf) * m = %lfm\n", 0, vB[0], v[0], vA[0], '-', vA[0], k, vB[0], k, v[0], (vB[0] + vA[0]) * k + v[0]);
        for (int i = 1; i <= Q; i++)
        {
            if (v[2 * i - 1]) fprintf(output, "%03d-1, %.3lf,%.3lf,%.3lf,%c,|vA(%lf) * %lfm + vB(%lf) * %lfm + v(%lf) * m = %lfm\n", i, vB[i - 1], v[2 * i - 1], vA[i], 'A', vA[i], k, vB[i - 1], k, v[2 * i - 1], (vB[i - 1] + vA[i]) * k + v[2 * i - 1]), ans++;
            if (v[2 * i]) fprintf(output, "%03d-2, %.3lf,%.3lf,%.3lf,%c,|vA(%lf) * %lfm + vB(%lf) * %lfm + v(%lf) * m = %lfm\n", i, vB[i], v[2 * i], vA[i], 'B', vA[i], k, vB[i], k, v[2 * i], (vB[i] + vA[i]) * k + v[2 * i]), ans++;
        }
        fprintf(output, "===%d===\n", ans);
        fprintf(output2, "%.3lf, %d\n",k, ans);
        //printf("===%d===\n", ans);
    }
}
