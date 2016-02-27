///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                Copyright (C) 2016   John Suárez                       //
//                https://github.com/fnoj/TMeasure                       //
//                                                                       //
// This program is free software; you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation; either version 2 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// This program is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details:                          //
//                                                                       //
//          http://www.gnu.org/copyleft/gpl.html                         //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <TMath.h>

using namespace std;

class TMeasure{
 
public:

  TMeasure();  
  TMeasure(Double_t,Double_t);
  friend TMeasure operator + (TMeasure,TMeasure);  
  friend TMeasure operator - (TMeasure,TMeasure);  
  friend TMeasure operator * (TMeasure,TMeasure);  
  friend TMeasure operator * (Double_t,TMeasure); 
  friend TMeasure operator * (TMeasure,Double_t); 
  friend TMeasure operator / (TMeasure,TMeasure);  
  friend TMeasure Sin (TMeasure);
  friend TMeasure Cos (TMeasure);
  friend TMeasure Exp (TMeasure);
  friend TMeasure Pow (TMeasure,Double_t);
  friend TMeasure Ln (TMeasure);

  Double_t GetX(){return fx;}
  Double_t GetDx(){return fdx;}
  void SetX(Double_t x){fx=x;}
  void SetDx(Double_t dx){fdx=dx;}
  void Print(){}

private:
  Double_t fx;
  Double_t fdx;

};
