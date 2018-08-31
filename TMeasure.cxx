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


#include "TMeasure.h"


TMeasure::TMeasure(){
  fx=0; fdx=0;
}

TMeasure::TMeasure(Double_t x,Double_t dx){
  fx=x; fdx=dx;
}

TMeasure operator +(TMeasure m1,TMeasure m2){
  TMeasure ans;
  ans.fx= m1.GetX() + m2.GetX();
  ans.fdx= TMath::Sqrt(m1.GetDx()*m1.GetDx() + m2.GetDx()*m2.GetDx());
  return ans;
}

TMeasure operator -(TMeasure m1,TMeasure m2){
  TMeasure ans;
  ans.fx= m1.GetX() - m2.GetX();
  ans.fdx= TMath::Sqrt(m1.GetDx()*m1.GetDx() + m2.GetDx()*m2.GetDx());
  return ans;
}

TMeasure operator *(TMeasure m1,TMeasure m2){
  TMeasure ans;
  ans.fx= m1.GetX()*m2.GetX();
  ans.fdx= TMath::Abs(m1.GetX()*m2.GetX())*TMath::Sqrt((m1.GetDx()/m1.GetX())*(m1.GetDx()/m1.GetX()) + (m2.GetDx()/m2.GetX())*(m2.GetDx()/m2.GetX()));
  return ans;
}

TMeasure operator *(Double_t a,TMeasure m1){
  TMeasure ans;
  ans.fx= a*m1.GetX();
  ans.fdx= TMath::Sqrt(a*a)*m1.GetDx();
  return ans;
}

TMeasure operator *(TMeasure m1,Double_t a){
  TMeasure ans;
  ans.fx= a*m1.GetX();
  ans.fdx= TMath::Sqrt(a*a)*m1.GetDx();
  return ans;
}

TMeasure operator /(TMeasure m1,TMeasure m2){
  TMeasure ans;
  ans.fx= m1.GetX()/m2.GetX();
  ans.fdx= TMath::Abs(m1.GetX()/m2.GetX())*TMath::Sqrt((m1.GetDx()/m1.GetX())*(m1.GetDx()/m1.GetX()) + (m2.GetDx()/m2.GetX())*(m2.GetDx()/m2.GetX()));
  return ans;
}

TMeasure Sin(TMeasure m1){
  TMeasure ans;
  ans.fx= TMath::Sin(m1.GetX());
  ans.fdx= TMath::Abs(TMath::Cos(m1.GetX()))*m1.GetDx();
  return ans;
}

TMeasure Cos(TMeasure m1){
  TMeasure ans;
  ans.fx= TMath::Cos(m1.GetX());
  ans.fdx= TMath::Abs(TMath::Sin(m1.GetX()))*m1.GetDx();
  return ans;
}

TMeasure Exp(TMeasure m1){
  TMeasure ans;
  ans.fx= TMath::Exp(m1.GetX());
  ans.fdx= TMath::Abs(TMath::Exp(m1.GetX()))*m1.GetDx();
  return ans;
}

TMeasure Ln(TMeasure m1){
  TMeasure ans;
  ans.fx= TMath::Log(m1.GetX());
  ans.fdx= m1.fdx/m1.GetX();
  return ans;
}

TMeasure Pow(TMeasure m1,Double_t n){
  TMeasure ans;
  ans.fx= TMath::Power(m1.GetX(),n);
  ans.fdx= TMath::Abs(n*TMath::Power(m1.GetX(),n-1))*m1.GetDx();
  return ans;
}

void TMeasure::Print(){
  cout<<fx<<" +- "<<fdx<<endl;
}
