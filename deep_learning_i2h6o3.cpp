//Input: 2
//Hidden: 6
//Output: 3

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "group_function.h"

int main(void)
{
	FILE* fp;

	//fopen_s(&fp, "deep_learning_i2h6o3.txt", "w+");
	fopen_s(&fp, "weight_bias_data.txt", "w+");

	struct values pal, vpal;
	//values pal;
	int j, k, m, n;
	
	//input data for training 
	double i[25][2] = { {25, 14}, {41, 33}, {44, 44 }, {33,41}, {14, 25}, {29, 22}, {43, 33}, {80, 90}, {33, 43}, {22, 29}, {35, 26}, {55, 35}, {55, 55}, {35, 55}, {26, 35}, {33, 25}, {44, 32}, {150, 150}, {32, 44}, {25, 33}, {38, 23}, {50, 36}, {90, 100}, {36, 50}, {23, 38} }; //L, R, S
	// target data
	double t[25][3] = { {1,0,0}, {0,1,0}, {0,1,0}, {0,1,0}, {0,0,1}, {1,0,0}, {0,1,0}, {0,1,0}, {0,1,0}, {0,0,1}, { 1,0,0}, {0,1,0}, {0,1,0}, {0,1,0}, {0,0,1}, { 1,0,0}, {0,1,0}, {0,1,0}, {0,1,0}, {0,0,1}, { 1,0,0}, {0,1,0}, {0,1,0}, {0,1,0}, {0,0,1} }; // L, R, S
	// each weight
	double w[30] = { 0.15, 0.25, 0.25, 0.30, 0.40, 0.50, 0.45, 0.55, -0.15, 0.25, -0.25, 0.31, 0.42, -0.50, 0.45, 0.48, 0.15, -0.25, 0.25, 0.30, 0.40, 0.50, 0.45, 0.25, -0.30, 0.25, 0.25, 0.30, 0.40, 0.50 }; // hidden layer
	double b[9] = { 0.35, 0.35, 0.60, 0.60, 0.15, -0.35, 0.20, -0.20, 0.35 }; // bias

	for (k = 0; k < epoch; k++)
	{
		for (m = 0; m < 25; m++)
		{
			h1_s = ( i[m][0] * w[0] + i[m][1] * w[1] ) / 250. + 1 * b[0]; //hidden layer for propagation
			h2_s = ( i[m][0] * w[2] + i[m][1] * w[3] ) / 250. + 1 * b[1];
			h3_s = ( i[m][0] * w[4] + i[m][1] * w[5] ) / 250. + 1 * b[2];
			h4_s = ( i[m][0] * w[6] + i[m][1] * w[7] ) / 250. + 1 * b[3];
			h5_s = ( i[m][0] * w[8] + i[m][1] * w[9] ) / 250. + 1 * b[4];
			h6_s = ( i[m][0] * w[10] + i[m][1] * w[11] ) / 250. + 1 * b[5];

			h1 = 1.0 / (1.0 + exp(-h1_s)); // sigmoid active function
			h2 = 1.0 / (1.0 + exp(-h2_s));
			h3 = 1.0 / (1.0 + exp(-h3_s));
			h4 = 1.0 / (1.0 + exp(-h4_s));
			h5 = 1.0 / (1.0 + exp(-h5_s));
			h6 = 1.0 / (1.0 + exp(-h6_s));

			o1_s = h1 * w[12] + h2 * w[13] + h3 * w[14] + h4 * w[15] + h5 * w[16] + +h6 * w[17] + 1 * b[6]; // output layer
			o2_s = h1 * w[18] + h2 * w[19] + h3 * w[20] + h4 * w[21] + h5 * w[22] + +h6 * w[23] + 1 * b[7];
			o3_s = h1 * w[24] + h2 * w[25] + h3 * w[26] + h4 * w[27] + h5 * w[28] + +h6 * w[29] + 1 * b[8];

			pal.o1 = 1.0 / (1.0 + exp(-o1_s));
			pal.o2 = 1.0 / (1.0 + exp(-o2_s));
			pal.o3 = 1.0 / (1.0 + exp(-o3_s));

			e1 = 0.5 * pow(pal.o1 - t[m][0], 2);
			e2 = 0.5 * pow(pal.o2 - t[m][1], 2);
			e3 = 0.5 * pow(pal.o3 - t[m][2], 2);
			Error = e1 + e2 + e3;

			De1E = 1;
			De2E = 1;
			De3E = 1;

			Do1e1 = pal.o1 - t[m][0];
			Do2e2 = pal.o2 - t[m][1];
			Do3e3 = pal.o3 - t[m][2];

			Do1E = Do1e1 * De1E;
			Do2E = Do2e2 * De2E;
			Do3E = Do3e3 * De3E;

			o1_b = pal.o1 * (1 - pal.o1) * Do1E;
			o2_b = pal.o2 * (1 - pal.o2) * Do2E;
			o3_b = pal.o3 * (1 - pal.o3) * Do3E;

			Dw13E = h1 * o1_b;
			Dw14E = h2 * o1_b;
			Dw15E = h3 * o1_b;
			Dw16E = h4 * o1_b;
			Dw17E = h5 * o1_b;
			Dw18E = h6 * o1_b;

			Dw19E = h1 * o2_b;
			Dw20E = h2 * o2_b;
			Dw21E = h3 * o2_b;
			Dw22E = h4 * o2_b;
			Dw23E = h5 * o2_b;
			Dw24E = h6 * o2_b;

			Dw25E = h1 * o3_b;
			Dw26E = h2 * o3_b;
			Dw27E = h3 * o3_b;
			Dw28E = h4 * o3_b;
			Dw29E = h5 * o3_b;
			Dw30E = h6 * o3_b;

			Db7E = 1 * o1_b;
			Db8E = 1 * o2_b;
			Db9E = 1 * o3_b;

			h1_b = h1 * (1 - h1) * (o1_b * w[12] + o2_b * w[18] + o3_b * w[24]); // for back propagation
			h2_b = h2 * (1 - h2) * (o1_b * w[13] + o2_b * w[19] + o3_b * w[25]);
			h3_b = h3 * (1 - h3) * (o1_b * w[14] + o2_b * w[20] + o3_b * w[26]);
			h4_b = h4 * (1 - h4) * (o1_b * w[15] + o2_b * w[21] + o3_b * w[27]);
			h5_b = h5 * (1 - h5) * (o1_b * w[16] + o2_b * w[22] + o3_b * w[28]);
			h6_b = h6 * (1 - h6) * (o1_b * w[17] + o2_b * w[23] + o3_b * w[29]);

			Dw1E = i[m][0] * h1_b;
			Dw2E = i[m][1] * h1_b;
			Dw3E = i[m][0] * h2_b;
			Dw4E = i[m][1] * h2_b;

			Dw5E = i[m][0] * h3_b;
			Dw6E = i[m][1] * h3_b;
			Dw7E = i[m][0] * h4_b;
			Dw8E = i[m][1] * h4_b;

			Dw9E = i[m][0] * h5_b;
			Dw10E = i[m][1] * h5_b;
			Dw11E = i[m][0] * h6_b;
			Dw12E = i[m][1] * h6_b;

			Db1E = 1 * h1_b;
			Db2E = 1 * h2_b;
			Db3E = 1 * h3_b;
			Db4E = 1 * h4_b;
			Db5E = 1 * h5_b;
			Db6E = 1 * h6_b;

			w[12] = w[12] - lr * Dw13E; //weights
			w[13] = w[13] - lr * Dw14E;
			w[14] = w[14] - lr * Dw15E;
			w[15] = w[15] - lr * Dw16E;
			w[16] = w[16] - lr * Dw17E;
			w[17] = w[17] - lr * Dw18E;

			w[18] = w[18] - lr * Dw19E;
			w[19] = w[19] - lr * Dw20E;
			w[20] = w[20] - lr * Dw21E;
			w[21] = w[21] - lr * Dw22E;
			w[22] = w[22] - lr * Dw23E;
			w[23] = w[23] - lr * Dw24E;

			w[24] = w[24] - lr * Dw25E;
			w[25] = w[25] - lr * Dw26E;
			w[26] = w[26] - lr * Dw27E;
			w[27] = w[27] - lr * Dw28E;
			w[28] = w[28] - lr * Dw29E;
			w[29] = w[29] - lr * Dw30E;

			b[6] = b[6] - lr * Db7E; // bias
			b[7] = b[7] - lr * Db8E;
			b[8] = b[8] - lr * Db9E;

			w[0] = w[0] - lr * Dw1E;
			w[1] = w[1] - lr * Dw2E;
			w[2] = w[2] - lr * Dw3E;
			w[3] = w[3] - lr * Dw4E;

			w[4] = w[4] - lr * Dw5E;
			w[5] = w[5] - lr * Dw6E;
			w[6] = w[6] - lr * Dw7E;
			w[7] = w[7] - lr * Dw8E;

			w[8] = w[8] - lr * Dw9E;
			w[9] = w[9] - lr * Dw10E;
			w[10] = w[10] - lr * Dw11E;
			w[11] = w[11] - lr * Dw12E;

			b[0] = b[0] - lr * Db1E;
			b[1] = b[1] - lr * Db2E;
			b[2] = b[2] - lr * Db3E;
			b[3] = b[3] - lr * Db4E;
			b[4] = b[4] - lr * Db5E;
			b[5] = b[5] - lr * Db6E;

			if (k % 2000 == 1)
			{
				printf("o1 = %f\n", pal.o1);
				printf("o2 = %f\n", pal.o2);
				printf("o3 = %f\n", pal.o3);
				printf("current epoch = %d\n", k);

				printf("\n");
			}

		}

	}

	printf("\n");
	//printf("current input data = %d,  Error = %f \n", m, Error);
	printf("o1 = %f, o2 = %f, o3 = %f, learning rate = %f \n", pal.o1, pal.o2, pal.o3, lr);
	//fprintf(fp, "\n");
	//fprintf(fp, "current input data = %d,  Error = %f \n", m, Error);
	//fprintf(fp, "o1 = %f, o2 = %f, o3 = %f, learning rate = %f \n", pal.o1, pal.o2, pal.o3, lr);

	for (j = 0; j < 30; j++)
	{
		printf("w[%d] = %f \n", j, w[j]);
		//fprintf(fp, "w[%d] = %f \n", j, w[j]);
		fprintf(fp, "%lf ", w[j]);
	}
	for (j = 0; j < 9; j++)
	{
		printf("b[%d] = %f \n", j, b[j]);
		//fprintf(fp, "b[%d] = %f \n ", j, b[j]);
		fprintf(fp, "%lf ", b[j]);
	}

	fclose(fp);
	return 0;
}

