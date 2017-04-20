#include "quicksort.C"
#include <iostream>
#include <array>
#include <vector>
using namespace std;

typedef struct s_structure
{
	int houses;
	int radius;
} t_struct;

class Transmitter
{
	public:
		t_struct *s;
		vector<int> myVector;

		Transmitter();
		~Transmitter(){ cout << "destroyed" << endl;};

		void set_transmitter(int, int);
		void create_vector(int *);
};

Transmitter::Transmitter()
{
	s = (t_struct*)malloc(sizeof(t_struct));
};

void Transmitter::set_transmitter(int houses, int radius)
{
	s->houses = houses;
	s->radius = radius;
}

void ft_putarray(int *array, int size)
{
	while (size--)
		cout << *array++;
	cout << endl;
}

void ft_putvector(vector <int> *v, int max)
{
	vector<int>::iterator it;
	size_t iter = 0;
	while (iter < max)
		cout << (*v)[iter++] << endl;
	// cout << (*v)[0] << endl;
	// for(it=(*v).begin() ; it < (*v).end(); it++, iter++ ) {
 //    // found nth element..print and break.
 //    cout << *it << endl;
 //    }
}

void Transmitter::create_vector(int *array)
{
	int iter;
	int max;

	iter = -1;
	max = array[iter];
	while (++iter < s->houses)
		max = (max >= array[iter]) ? max : array[iter];
	iter = -1;
	myVector.reserve(max + 1);
	quicksort(array, 0, s->houses - 1);
	//ft_putarray(array, s->houses);
	while (++iter < s->houses)
		Transmitter::myVector[array[iter] - 1] = array[iter];
	ft_putvector(&myVector, max);
}

int main()
{
	int houses;
	int radius;
	int *array;
	int iter;

	cin >> houses;
	cin >> radius;
	iter = -1;
	Transmitter transmitter;
	array = (int*)malloc(sizeof(int) * houses);
	while (++iter < houses)
		cin >> array[iter];
	transmitter.set_transmitter(houses, radius);
	transmitter.create_vector(array);
	return (0);
}
