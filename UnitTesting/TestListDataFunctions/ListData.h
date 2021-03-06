#ifndef LIST_DATA
#define LIST_DATA

#include "Headers.h"
#include "Node.h"
#include "MathFunctions.h"
#include "Returns.h"
#include "Hash.h"

template <typename T>
class ListData
{
	public:
		ListData();
		~ListData();
        Node<T>* ReturnHead();
        Node<T>* getNode();
		void PrintData();
		void Insert(T item, int itemno, std::string itemName);
		void initEuclideanList(Conf* myConf, ifstream& inputFile, double** distanceMatrix, int k, int L, int* dataLengthPointNumber, int* hashCreationDone, Hash<double* >* hashTableList, int* centroids, int** clusterAssign);
		void initCosineList(Conf* myConf, ifstream& inputFile, double** distanceMatrix, int k, int L, int* dataLengthPointNumber, int* hashCreationDone, Hash<double* >* hashTableList, int* centroids, int** clusterAssign);
		void initDBHManagement(Conf* myConf, ifstream& inputFile, double** distanceMatrix, int k, int L, int* dataLength, int* hashCreationDone, Hash<double>* hashTableList, int* centroids, int** clusterAssign);
		void initHammingLSHManagement(Conf* myConf, ifstream& inputFile, double** distanceMatrix, int k, int L, int* dataLength, int* hashCreationDone, Hash<bitset<64> >* hashTableList, int* centroids, int** clusterAssign);
		int Distance(T item1, T item2);
		bool ExistsOnce(int itemno, Node<T>* header);
		bool Exists(int itemno, Node<T>* header_out);
		double CosineDistance(double p1[], double p2[], int size);
		bool HammingDuplicate(T item);
		bool HammingB2BDuplicate(T item);
		bool EuclideanDuplicate(T item, int size);
		void ListInsertionVector(std::ifstream& inputFile, Metrics* myMetric);
		void DistanceMatrixComputationVector(Metrics* myMetric, double** distance_matrix);
		void ListInsertionDB(std::ifstream& inputFile, Metrics* myMetric);
		void DistanceMatrixComputationDB(std::ifstream& inputFile, Metrics* myMetric, double** distance_matrix);
		void ListInsertionHamming(std::ifstream& inputFile, Metrics* myMetric);
		double DistanceB2BHamming(T item1, T item2);
		void DistanceMatrixComputationHamming(Metrics* myMetric, double** distance_matrix);
		
	private:
		Node<T>* header;
};


#endif // !LIST_DATA_HAMMING