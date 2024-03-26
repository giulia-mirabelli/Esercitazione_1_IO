#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include <iomanip>

double map (double i)
{
    int a=1;
    int b=5;
    int c=-1;
    int d=2;
    i= c+(i-a)*(d-c)/(b-a);
    return i;
}

int main()
{
    double val =0;
    double meanValues=0;
    unsigned int N=0;

    std::string nameFile = "data.csv";
    std::ifstream fstr(nameFile);
    if (fstr.fail())
    {
        std::cerr << "file not found!" << std::endl;
        return 1;
    };
    std:: ofstream resultFile("result.csv");
    if (resultFile.fail())
    {
        std::cerr << "file not found" << std::endl;
        return 1;
    };

    double sum=0;
    fstr>>sum;
    sum = map(sum);
    int i=2;
    resultFile<<std::scientific <<"# N Mean \n"<<"1" <<" "<<std::setprecision(16)<<sum<<std::endl;

    while (fstr>>val)
    {
        val=map(val);
        N++;

        meanValues   = (val+sum)/(i);
        sum +=val;

        resultFile <<i << " " <<std::setprecision(16)<<meanValues<<std::endl;
        i++;
    };

    fstr.close();
    resultFile.close();

    return 0;
}
