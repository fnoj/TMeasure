//This Code is a example of how to use the TMeasure class.

#include "TMeasure.h"
#include "TMeasure.cxx"

void Example(){
  TMeasure m1(3,0.1);
  TMeasure m2(2,0.1);
  TMeasure m3;
cout<<"m1 = "<<m1.GetX() <<" +- "<< m1.GetDx() <<"\t m2 = "<<m2.GetX() <<" +- "<< m2.GetDx() << endl;  
  m3 = m1+m2;
  cout<<"m1+m2= "; m3.Print();

  m3 = m1-m2;
  cout<<"m1-m2 = "; m3.Print();

  m3 = m1*m2;
  cout<<"m1*m2 = "; m3.Print();

  m3 = m1/m2;
  cout<<"m1/m2 = "; m3.Print();

  m3 = Sin(m1);
  cout<<"Sin(m1) = "; m3.Print();

  m3 = Cos(m1);
  cout<<"Cos(m1) = "; m3.Print();

  m3 =Sin(m1)/Cos(m1);
  cout<<"Tan(m1) = "; m3.Print();

  m3 =Exp(m1);
  cout<<"Exp(m1) = "; m3.Print();

  m3 =Pow(m1,2);
  cout<<"m1^2 = "; m3.Print();

  m3 =Pow(m1,2)*m2*Sin(m1);
  cout<<"m1^2*m2*Sin(m1)= "; m3.Print();

  m3 =m1*m2/m3;
  cout<<"m1*m2/m3= "; m3.Print();
  
  TMeasure m(20,0.1);
  TMeasure x(4.5,0.4);
  m3=m*976.4/x;
  m3.Print();
  m3=2*TMath::Pi()*Pow(m/m3,0.5);
  m3.Print();
}
