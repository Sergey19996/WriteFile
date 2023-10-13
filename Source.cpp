#include <iostream>
#include <string>
#include <fstream>


using namespace std;


class Point
{
public:
	Point()
	{
		coll=x = y = z = 0;
	};

	Point(int x, int y, int z, bool collision)
	{

		this->x = x;
		this->y = y;
		this->z = z;
		this->coll = collision;
	}
	
	void Print()
	{
		cout << "X:= " << x << " " << "Y:== " << y <<"  "<< "Z:== " << z <<" " <<"Bool:= " << coll << endl;
	}

	 bool GetArray (int *Valuea, const int Size)
	{
		 if (counterTrue == true)
		 {


			 for (counter; counter < Size;)
			 {
				 int even = 0;

				 x = Valuea[counter];
				 counter++;
				 even++;
				 y = Valuea[counter];
				 counter++;
				 even++;
				 z = Valuea[counter];
				 counter++;
				 even++;
				coll = Valuea[counter];
				 if (counter == Size-1)
				 {
					 counterTrue = false;
					 counter = 0;
					 return true;
				 }
				 if (even %3==0)
				 {
					 counter++;
					 return true;
				 }
				 
			 }
			 
		 }
		 return false;
	}
private:
	int x;
	int y;
	int z;
	bool coll;
	bool counterTrue = true;
	int counter = 0;
protected:

};

 

int main()
{
	const int Size = 20;
	int  Arr[Size]
	{
		111,222,144,1,
		111,654,113,0,
		111,545,345,1,
		141,465,523,0,
		111,565,1543,1

	};
	Point test(432, 432, 234, true);

	Point Clean;
	//test.Print();
	//test.GetArray(Arr,Size);
	string path = "myfile.txt";
	ofstream fout;                    //ofstream responds for write
	
	
	/*fout.open(path, ofstream:: app);

	if (!fout.is_open())
	{


		cout << "error open file" << endl;
	}
	else
	{
		cout << "pass the number! " << endl;
		while (test.GetArray(Arr, Size))
		{
			fout.write((char*)&test, sizeof(test));
		}
		
	}
	fout.close();*/


	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error open file! " << endl;

	}
	else
	{
		cout << "File is Open" << endl;
		while (fin.read((char*)&Clean, sizeof(test)))
		{
			Clean.Print();
		}
		
	}
	
	fin.close();

	return 0;
}