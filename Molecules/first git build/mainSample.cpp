#include "mainSample.hpp"

int main(int argc, char const *argv[])
{
	
	ifstream inputFile;
	ifstream conFile;
	ofstream outputFile;
	string GARBAGE;
	// int N;
	// int numConform;
	// int initChoice;
	// int assignChoice;
	// int updateChoice;
	// int* centroids;
	// int point_number;
	// ClusterTable* clusterTable;
	// int** clusterAssign;
	// double** distance_matrix;
	// string choice;
	// string filename;
	Conf* myConf = new Conf();
	// Metrics* myMetric = new Metrics();
	// bool completeFlag = false;
	// bool first_time_lsh;
	// int L, k;
	// L = 5;
	// k = 4;
	// int hashCreationDone;
	//bool outParameter = false, inParameter = false, confParameter = false;

	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(20);
	srand (time(NULL));

	if (argc > 1)
	{
		if (argc % 2 == 0)
		{
			cout << "Missing the correct number of parameters" << endl;
			cout << "Suggested use: $./molecules –d <input file> -ο <output file>" << endl;
			return -1;
		}
		for (int i = 1; i < argc; i++)
		{
			if (strcmp(argv[i], "-d") == 0)
			{
				inputFile.open(argv[i+1]);	//Input file comes next on argv
				if (inputFile == NULL)
				{
					cout << "You've given a wrong input file. " << endl;
					exit(1);
				}
				else
				{
					cout << "File : " << argv[i+1] << " opened successfully!" << endl;
					//inParameter = true;
				}
				
				//Init_Metrics(myMetric, inputFile);
				Init_Conf(myConf, inputFile);
				i++;
			}
			else if (strcmp(argv[i], "-o") == 0)
			{
				outputFile.open(argv[i+1]);		//Output file comes next on argv
				if (outputFile == NULL)
				{
					cout << "You've given a wrong output file. " << endl;
					exit(1);
				}
				else
				{
					cout << "File : " << argv[i+1] << " opened successfully!" << endl;
					//outParameter = true;
				}

				i++;
			}
			// else if (strcmp(argv[i], "-complete") == 0)
			// {
			// 	completeFlag = true;
			// }
			else
			{
				cout << "You've given wrong input" <<endl;
				return -1;
			}
		}
	}


	cout << "Number of conformations : " << myConf->numConform << endl;
	cout << "Numbe of points in conformation : " << myConf->N << endl;


	return 0;
}