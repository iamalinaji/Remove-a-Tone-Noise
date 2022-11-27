#include <stdio.h>
#include <stdlib.h>
#include "variables.h"
#define pi 3.14159265358979323846
extern double audiofile[];
extern double h[];
extern double filtered_audiofile[];

void convolve(double *p_coeffs, int p_coeffs_size,
              double *p_in, double *p_out)
{
    int i, j, k;
    double tmp;

    for (k = 0; k < outsize; k++) //  position in output
    {
        tmp = 0;
        for (i = 0; i < p_coeffs_size; i++) //  position in coefficients array
        {
            j = k - i; //  position in input

            if (j >= 0) //  bounds check for input buffer
            {
                tmp += p_coeffs[i] * p_in[j];
            }
        }

        p_out[k] = tmp;
    }
}

int main()
{
    convolve(h, 3, audiofile, filtered_audiofile);
    const char *filename = "file.txt";
    FILE *fp;
    fp = fopen(filename, "w");
    for (int i = 0; i < (sizeof(filtered_audiofile) / sizeof(filtered_audiofile[0])); i++)
    {
        fprintf(fp, "%f \n", filtered_audiofile[i]);
    }
    fclose(fp);
    return 0;
}