#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
float point=5;
int main()
{string fileName; ifstream fin; fileName = "in.dat";
	char choice;int s=0; 
	float cnthr=0,cntd=0,cnts=0,cnte=0;//incrementals
	float cnthrl=0,cntdl=0,cntsl=0,cntel=0;//running totals
	float dummyValue=0, sleep=0,sl=0, heart=0, exersise=0, diastolic=0;//resting Heartrate
	float systolic=0, age=25, EHR=0,et=0;//exersising HR
	bool Gender=0, bedrest=NULL, maleb=0, femb=0, maleb1=0, femb1=0,di=0,sys=0;
//gender==1 ~male; gender ==0 ~female
//assume 25 yr old female
//sys/diastolic BP are measured in mmHg
if (fin.good()){fin.open(fileName);
	while(choice != 'x'){ fin >> choice; ///-----------
if (choice == 'S'){fin>>sleep;s++;sl+=sleep;}
else if (choice == 'H'){fin>>heart;cnthr++;cnthrl+=heart;
if(Gender){
if( maleb1==0 &&(heart<46 || 82<heart) ){maleb1=1;cout<<"You may want to talk to";
cout<<" your primary care physician,\nyour ";
cout<<"resting heart rate is abnormal."<<endl;}
}//male^
else{
if( femb1==0 &&(heart<53 || 85<heart) ){femb1=1;cout<<"You may want to talk to";
cout<<" your primary care physician,\nyour ";
cout<<"resting heart rate is abnormal."<<endl;}
}//female^
}
else if (choice == 'd'){fin>>diastolic;cntd++;cntdl+=diastolic;
if( di==0 &&(diastolic<40 || 90<diastolic) ){di=1;cout<<"You may want to talk to";
cout<<" your primary care physician,\nyour ";
cout<<"diastolic blood pressure is abnormal."<<endl;}
}
else if (choice == 'e'){fin>>exersise; et+=exersise;}
else if (choice == 's'){fin>>systolic;cnts++;cntsl+=systolic;
if( sys==0 &&(systolic<60 || 140<systolic) ){sys=1;cout<<"You may want to talk to";
cout<<" your primary care physician,\nyour ";
cout<<"systolic blood pressure is abnormal."<<endl;}
}
else if (choice == 'b'){fin>>bedrest;}///
else if (choice == 'E'){fin>>EHR;cnte++;cntel+=EHR;
if(Gender){
if( maleb==0 &&(EHR<98 || 135<EHR) ){maleb=1;cout<<"You may want to talk to";
cout<<" your primary care physician,\nyour ";
cout<<"exercising heart rate is abnormal."<<endl;}
}//male^
else{
if( femb==0 &&(EHR<92 || 127<EHR) ){femb=1;cout<<"You may want to talk to";
cout<<" your primary care physician,\nyour ";
cout<<"exercising heart rate is abnormal."<<endl;}
}//female^
}
else {fin>>dummyValue;}
	}///-----
}//forbidden area
/*bwaha*/ 
float avgS=sl/s; cout<<endl<<"Average hours slept each night is: "<<avgS<<endl;
if(3.5<avgS){point++;point++;point++;point++;}
//==============================
float avghr=cnthrl/cnthr; cout<<endl<<"Average resting heartrate: "<<avghr<<endl;
if(49.5<avghr && avghr<83.5){point++;point++;point++;point++;}
float avgehr=cntel/cnte; cout<<endl<<"Average exercising heartrate: "<<avgehr<<endl;
if(95<avgehr && avgehr<194.5){point++;point++;point++;point++;}
float avgdias=cntdl/cntd; cout<<endl<<"Average diastolic bloodpressure: "<<avgdias<<endl;
if(40<avgdias && avgdias<90){point++;point++;point++;point++;}
float avgsys=cntsl/cnts; cout<<endl<<"Average systolic bloodpressure: "<<avgsys<<endl;
if(60<avgsys && avgsys<140){point++;point++;point++;point++;}
//========================
if(!bedrest && 25<et){point++;}
if(bedrest && !(25<et)){point++;}
cout<<endl<<"points: "<<point<<endl;
cout << endl; fin.close();
	return 0;
}