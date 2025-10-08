#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;



int preci=0;

int praxeis(int iprotos,int ideuteros,int itritos,
            long double mpr,long double mdt,long double mtrt,
            long double fdkpr,long double fdkdt,long double ftrt,
            int st,long double tmp_up)
{
        long double pros;
        long double afair;
        long double fract,intpt;
        long double xst;
        if(st==0){
            pros=ftrt+fdkdt;
            fract=modf(pros,&intpt);
        }
        if(st==1 && fdkdt==0 && ftrt!=0){
            pros=1-(abs(ftrt));
            fract=modf(pros,&intpt);
        }
       cout<<std::setprecision(preci)<<mpr << " :: " <<std::setprecision(preci)<< iprotos << " " <<std::setprecision(preci)<< fdkpr <<" || ";
       cout<<std::setprecision(preci)<<mdt << " :: " <<std::setprecision(preci)<< ideuteros << " " <<std::setprecision(preci)<< fdkdt <<" || ";
       cout<<std::setprecision(preci)<<mtrt << " :: "<<std::setprecision(preci)<< itritos << " " <<std::setprecision(preci)<< ftrt <<"\n";
       if(st==0){
                cout<<"@state " << st << " ------------> " <<std::setprecision(preci)<< pros << " ::== "<<std::setprecision(preci)<< ftrt << " + " <<std::setprecision(preci)<< fdkdt <<"\n";
       }
       if(st==1 && fdkdt==0 && ftrt!=0){
                cout<<"@state " << st << " ------------> " <<std::setprecision(preci)<< pros << " ::== " << 1 << " " <<std::setprecision(preci)<< ftrt <<"\n";
       }
       if(tmp_up!=0 && fdkpr!=0){
                xst=abs(fdkpr)+abs(tmp_up);
                fract=modf(xst,&intpt);
       cout<<std::setprecision(preci)<<xst << " ::== " <<std::setprecision(preci)<< fdkpr << " + " <<std::setprecision(preci)<< abs(tmp_up) << "\n";
       cout<<std::setprecision(preci)<<xst << " ::== " <<std::setprecision(preci)<< intpt << " " <<std::setprecision(preci)<< fract <<"\n";
       }
       cout<<"\n";
       return 0;
}



int main(int argc,char** argv)
{
    cout<<"give me a dotted number , a non dotted number , precision \n";
    long double dmnb;
    long double nonmb;
    long double akrone=1;
    string dmb;
    dmb.clear();
    dmnb=stold(argv[1]);
    dmb+=argv[1];
    cout<<std::setprecision(preci)<<dmnb << " " <<std::setprecision(preci)<< dmb <<"\n";
    string nnmb;
    nnmb.clear();
    nnmb+=argv[2];
    nonmb=stold(argv[2]);
    cout<<std::setprecision(preci)<<nonmb << " " <<std::setprecision(preci)<< nnmb <<"\n";
    preci=stoi(argv[3]);
    long double xar[100];int xr=0;
    long double xl=10;
    xar[xr]=nonmb;xr+=1;
    long double mxl;
    long double fractpart,intpart;
    long double frp,intpr;
    long double fp,ipr;
    long double rstf;
    long double ddmnb;
    int dm=0;int ldm=0;int dml=0;
    for(int i=0;i<=dmb.size()-1;i++){
        ldm+=1;
        if(dmb.at(i)=='.'){dm=i;}
    }
    dml=ldm-dm;
    dml=dml-1;
    long double xp;
    xp=pow(10,dml);
    ddmnb=dmnb*xp;
    cout<<std::setprecision(preci)<<"new undotted " <<std::setprecision(preci)<< ddmnb <<"\n";
    for(int i=1;i<=nnmb.size();i++){
       xl=pow(10,i);
       mxl=(long double)nonmb/(long double)xl;
       xar[xr]=(long double)mxl; xr+=1;
    }
    long double tmpup;
    for(int i=0;i<=xr-1;i++){
        cout<<"\n";
        rstf=xar[i]-dmnb;
        fractpart=modf(rstf,&intpart);
        frp=modf(xar[i],&intpr);
        fp=modf(dmnb,&ipr);
        cout<<"------------------------------------------------------------\n";
        cout<<"@i " << i << " :: " <<std::setprecision(preci)<< xar[i] << " - " <<std::setprecision(preci)<< dmnb <<" ::== " <<std::setprecision(preci)<< rstf <<" \n";
        praxeis(intpr,ipr,intpart,xar[i],dmnb,rstf,frp,fp,fractpart,0,0);
        tmpup=fractpart;
        rstf=xar[i]-ddmnb;
        fractpart=modf(rstf,&intpart);
        frp=modf(xar[i],&intpr);
        fp=modf(ddmnb,&ipr);
        cout<<std::setprecision(preci)<<xar[i] << " - " <<std::setprecision(preci)<< ddmnb <<" ::== " <<std::setprecision(preci)<< rstf <<" \n";
        praxeis(intpr,ipr,intpart,xar[i],ddmnb,rstf,frp,fp,fractpart,1,tmpup);
        cout<<"------------------------------------------------------------\n";
    }
    cout<<"\n";
    cout<<"\n";
    return 0;
}
