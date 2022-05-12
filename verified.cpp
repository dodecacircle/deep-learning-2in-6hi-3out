#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct values
{
	double o1, o2, o3; // only count on how many return values are
};

values verification(double i[], double w[], double b[])
{
	values t;
	double h1, h2, h1_s, h2_s, h3, h4, h3_s, h4_s, h5, h6, h5_s, h6_s;
	double o1_s, o2_s, o3_s;

	h1_s = i[0] * w[0] + i[1] * w[1] + 1 * b[0];
	h2_s = i[0] * w[2] + i[1] * w[3] + 1 * b[1];
	h3_s = i[0] * w[4] + i[1] * w[5] + 1 * b[2];
	h4_s = i[0] * w[6] + i[1] * w[7] + 1 * b[3];
	h5_s = i[0] * w[8] + i[1] * w[9] + 1 * b[4];
	h6_s = i[0] * w[10] + i[1] * w[11] + 1 * b[5];

	h1 = 1.0 / (1.0 + exp(-h1_s));
	h2 = 1.0 / (1.0 + exp(-h2_s));
	h3 = 1.0 / (1.0 + exp(-h3_s));
	h4 = 1.0 / (1.0 + exp(-h4_s));
	h5 = 1.0 / (1.0 + exp(-h5_s));
	h6 = 1.0 / (1.0 + exp(-h6_s));

	o1_s = h1 * w[12] + h2 * w[13] + h3 * w[14] + h4 * w[15] + h5 * w[16] + +h6 * w[17] + 1 * b[6];
	o2_s = h1 * w[18] + h2 * w[19] + h3 * w[20] + h4 * w[21] + h5 * w[22] + +h6 * w[23] + 1 * b[7];
	o3_s = h1 * w[24] + h2 * w[25] + h3 * w[26] + h4 * w[27] + h5 * w[28] + +h6 * w[29] + 1 * b[8];

	t.o1 = 1.0 / (1.0 + exp(-o1_s));
	t.o2 = 1.0 / (1.0 + exp(-o2_s));
	t.o3 = 1.0 / (1.0 + exp(-o3_s));

	return t;
}


int main(void)
{
	FILE* fp;
	fopen_s(&fp, "weight_bias_data.txt", "r");
	if (fp == NULL) {
		printf("Fail to open this file\n");
	}

	struct values pal, vpal;
	//values pal;
	int i;
	double w[30], b[9], data[39];
		
	// to verify 
	//double in[2] = { 25/250., 15/250. }; // left turn
	double in[2] = { 15 / 250., 35 / 250. }; // right turn 22, 29
	//double in[2] = { 80/250., 80/250. }; // straight turn
	
	for (i = 0; i < 39; i++) {
		fscanf_s(fp, "%lf \n", &data[i]); // the number of weight and bias = 30 + 9
	}
	for (i = 0; i < 30; i++) {
		w[i] = data[i];
	}
	for (i = 30; i < 39; i++) {
		b[i-30] = data[i];
	}

	// to verify
	vpal = verification(in, w, b);
	printf("i1 = %f, i2 = %f, o1= %f, o2= %f, o3= %f \n", in[0], in[1], vpal.o1, vpal.o2, vpal.o3);
	//fprintf(fp, "i1 = %f, i2 = %f, o1= %f, o2= %f, o3= %f \n", in[0], in[1], vpal.o1, vpal.o2, vpal.o3);

	return 0;
}

