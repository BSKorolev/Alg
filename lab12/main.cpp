//Процесс сортировки начинается с последовательного чтения массива чисел из файла input.txt и записи этих чисел в файл output.txt. 
//Затем в цикле с переменной partSize от 1 до размера массива чисел происходит разделение массива на две части, записанные в файлы A.txt и B.txt. 
//Затем числа из этих двух файлов сравниваются и записываются в файл output.txt в порядке возрастания. Этот процесс повторяется, пока размер частей не достигнет размера массива.
// После этого файлы A.txt и B.txt удаляются.
#include <fstream>
#include <iostream>

int main() 
{
	std::ifstream in, in1, in2;
	std::ofstream out, out1, out2;
	int a, b = 0;
	int size = 0;				
	int countA, countB, count = 0;
	bool Afull, Bfull, flag = true;

	in.open("input.txt");
	out.open("output.txt");

	while (in >> a) 
	{		  
		out << a << " ";
		size++;
	}
	in.close();
	out.close();

	for (int partSize = 1; partSize < size; partSize *= 2)
	{ 
		in.open("output.txt");
		out1.open("A.txt");				     
		out2.open("B.txt");
		count = 0;
		while (in >> a) 
		{
			count++;
			if (flag)
				out1 << a << " ";
			else
				out2 << a << " ";

			if (count == partSize) 
			{
				count = 0;
				flag = !flag;
			}
		}
		in.close();
		out1.close();
		out2.close();

		in1.open("A.txt");
		in2.open("B.txt");
		out.open("output.txt");

		if (in1 >> a)				    
			Afull = true;
		else
			Afull = false;
		if (in2 >> b)
			Bfull = true;
		else
			Bfull = false;

		for (int i = 0; i < size; i += 2 * partSize)
		{	    
			countA = 0; countB = 0;
			while (countA < partSize && Afull && countB < partSize && Bfull)
				if (a < b)
				{
					out << a << " ";
					if (in1 >> a)
						Afull = true;
					else
						Afull = false;
					countA++;
				}
				else 
				{
					out << b << " ";
					if (in2 >> b)
						Bfull = true;
					else
						Bfull = false;
					countB++;
				}

			while (countA < partSize && Afull)
			{	    
				out << a << " ";
				if (in1 >> a)
					Afull = true;
				else
					Afull = false;
				countA++;
			}
			while (countB < partSize && Bfull) 
			{
				out << b << " ";
				if (in2 >> b)
					Bfull = true;
				else
					Bfull = false;
				countB++;
			}
		}
		in1.close();
		in2.close();
		out.close();
		remove("A.txt");		  
		remove("B.txt");
	}
	return 0;
}

