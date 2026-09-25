#include <iostream>
#include <conio.h>
using namespace std;

//void change(int& a) {
//	a++;
//}
//
//int& max(int& a, int& b) {
//	if (a>b)
//	{
//		return a;
//	}
//	else
//	{
//		return b;
//	}
//}

//int main()
//{
//
//	int a = 5;//variable
//	int* pa = &a;//pointer
//	int& la = a;//link
//
//	cout << "a=" << a << endl;
//	cout << "pa=" << pa << endl;
//	cout << "*pa=" << *pa << endl;
//	cout << "la=" << la << endl;
//
//	int b = 10;
//	int* pb=nullptr;
//	pb = &b;
//	int& lb = b;
//	cout << "lb=" << lb << endl;
//	cout << "lb=" << lb << endl;
//
//	cout << "a=" << a << endl;
//	change(a);
//
//	max(a, b) = 100;//<----- prikol
//	cout << "a=" << a << endl;
//
//	cout << "b=" << b << endl;
//	int& max1 = max(a, b);
//	cout << "max=" << max1 << endl;
//}

//void test() {
//	const int size = 10;
//	int arr[size];
//}
//void test2() {
//	int size = 10;
//	cin >> size;
//	int* arr=new int[size];
//	delete[]arr;
//}
//
//int* createArr(int size) {
//	int* arr = new int[size];
//	return arr;
//}
//
//void fillArr(int* arr, int size) {
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 100;
//	}
//}
//
//void showArr(int* arr, int size) {
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//int* addNew(int* arr, int* size, int num) {
//	int* temp = new int[*size + 1];
//	for (int i = 0; i < *size; i++)
//	{
//		temp[i] = arr[i];
//	}
//	temp[*size] = num;
//	delete[]arr;
//	arr = temp;
//	(*size)++;
//	return arr;
//}

//void main() {
//	//dynamic memory
//	srand(time(0));
//
//
//
//	
//
//
//
//
//
//	//int a = 10;//stack
//	//int* pa=new int(15);//heap
//	//int* pb = new int;
//	//int* pc=nullptr;
//
//	//*pb = 5;
//	//pc = new int(12);
//
//	//cout << "pa=" << pa<<endl;
//	//cout << "pb=" << pb<<endl;
//	//cout << "pc=" << pc<<endl;
//
//	//cout << "*pa=" << *pa<<endl;
//	//cout << "*pb=" << *pb<<endl;
//	//cout << "*pc=" << *pc<<endl;
//
//	//delete pc;
//	//pc = new int(55);
//
//	//cout << "*pc=" << *pc << endl;
//
//
//	 int size = 10;
//	//cout << "enter size" << endl;
//	 int* arr = createArr(size);
//	 fillArr(arr, size);
//	 showArr(arr, size);
//	
//	//showArr(arr, size);
//
//	/*delete pa;
//	delete pb;
//	delete pc; */
//
//	int num;
//	char choice = 'y';
//	while (true)
//	{
//		cout << "do you want to ad number?[y|n]";
//		choice = _getch();
//
//		if (choice == 'n')break;
//		cout << "enter num: ";
//		cin >> num;
//		arr = addNew(arr, &size, num);
//		system("cls");//clear console
//		showArr(arr, size);
//	}
//}

int* createArr(int size) {
	int* arr = new int[size];
	return arr;
}

void fillArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void printArr(int* arr, int* size) {
	for (int i = 0; i < *size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* deleteLast(int* arr, int* size) {
	int* temp = new int[*size - 1];
	for (int i = 0; i < *size - 1; i++)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	(*size)--;
	return temp;
}

int* deleteInd(int* arr, int* size) {
	int index;
	cout << "enter index to delete: ";
	cin >> index;

	if (index < 0 or index >= *size)
	{
		cout << "Wrong index!" << endl;
		return arr;
	}

	int* temp = new int[*size - 1];

	for (int i = 0; i < *size - 1; i++)
	{
		if (i < index)
		{
			temp[i] = arr[i];
		}
		else
		{
			temp[i] = arr[i + 1];
		}
	}

	delete[] arr;
	(*size)--;

	return temp;
}

int* insertEl(int* arr, int* size) {
	int* temp = new int[*size + 1];

	int index;
	cout << "enter index to insert: ";
	cin >> index;
	int value;
	cout << "enter value to insert: ";
	cin >> value;

	for (int i = 0; i < *size+1; i++)
	{
		if (i < index)
		{
			temp[i] = arr[i];
		}
		else if (i == index)
		{
			temp[i] = value;
		}
		else
		{
			temp[i] = arr[i - 1];
		}
	}

	delete[] arr;
	(*size)++;
	return temp;
}



void main() {
	srand(time(0));

	//1
	// 
		//int* la = new int(15);
		//float* lb = new float(0.1);
		//double* lc = new double(0.12);

		//cout << "la=" << *la << endl;
		//cout << "lb=" << *lb << endl;
		//cout << "lc=" << *lc << endl;

		//double dobutok = *la * *lb * *lc;
		//cout << "dobutok=" << dobutok << endl;


		//delete la;
		//delete lb;
		//delete lc;
		// 
	//2size-1 in new arr to delete

	int size = 5;
	int* arr = createArr(size);
	fillArr(arr, size);
	printArr(arr, &size);
	arr=deleteLast(arr, &size);
	arr=deleteInd(arr, &size);
	printArr(arr, &size);

	arr=insertEl(arr, &size);
	printArr(arr, &size);



	delete[]arr;
}