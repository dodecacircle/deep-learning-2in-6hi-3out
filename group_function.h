
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


int epoch = 100000;
//double t1 = 0.01, t2 = 0.99, t3 = 0.99;
//double t1 = 1, t2 = 0, t3 = 0;
//double t1 = 0, t2 = 0, t3 = 1;
double h1, h2, h1_s, h2_s, h1_b, h2_b, h3, h4, h3_s, h4_s, h3_b, h4_b, h5, h6, h5_s, h6_s, h5_b, h6_b;
double o1_s, o2_s, o3_s, o1_b, o2_b, o3_b;

double e1, e2, e3, Error;
double De1E, De2E, De3E;
double Do1e1, Do2e2, Do3e3;
double Do1E, Do2E, Do3E; 

double Dw30E, Dw29E, Dw28E, Dw27E, Dw26E, Dw25E, Dw24E, Dw23E, Dw22E, Dw21E, Dw20E, Dw19E, Dw18E, Dw17E, Dw16E, Dw15E;
double Dw14E, Dw13E, Dw12E, Dw11E, Dw10E, Dw9E, Dw8E, Dw7E, Dw6E, Dw5E;
double Dw1E, Dw2E, Dw3E, Dw4E;
double Db1E, Db2E, Db3E, Db4E, Db5E, Db6E, Db7E, Db8E, Db9E;
double lr = 0.5;

