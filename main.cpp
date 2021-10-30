#include <iostream>
#include <vector>

using namespace std;
//----------------------------classe--------------------------------
class Fraction{
    public:
    Fraction(int a,int b);
    Fraction(int a);
    Fraction();
    Fraction addition(Fraction const& b)const;
    Fraction soustraction(Fraction const& b)const;
    Fraction produit(Fraction const& b)const;

    void affiche();
    private:
    int m_numerateur;
    int m_denominateur;
};

//-------------------------function----------------------------------
Fraction operator+(Fraction const& a,Fraction const& b);
Fraction operator*(Fraction const& a,Fraction const& b);
Fraction operator-(Fraction const& a,Fraction const& b);
int min(int a,int b);
vector<int> simplification(int& a,int& b);
//------------------------------main---------------------------------
int main(){
        Fraction frac1(4,5),frac2(9,5),frac3,frac4,frac6(54,4);
        frac3=frac1+frac2;
        frac3.affiche();
        frac4=frac2-frac1;
        frac4.affiche();
        Fraction frac5=frac3*frac4;
        frac5.affiche();
        (frac5+frac4).affiche();
        (frac5-frac4).affiche();
        frac6.affiche();
        
    return 0;
}

//---------------------def des classes-------------------------------

    Fraction::Fraction(int a,int b){
        m_numerateur=a;
        m_denominateur=b;
    }
    Fraction::Fraction(int a){
        m_numerateur=a;
        m_denominateur=1;
    }
    Fraction::Fraction(){
        m_numerateur=0;
        m_denominateur=1;
    }
    Fraction Fraction::addition(Fraction const& b)const{
        Fraction sum(0,1);
        if(m_denominateur==b.m_denominateur){
            sum.m_numerateur=m_numerateur+b.m_numerateur;
            sum.m_denominateur=m_denominateur;
        }else{
           Fraction a_mmdeno,b_mmdeno;
           a_mmdeno.m_denominateur=m_denominateur*b.m_denominateur;
           b_mmdeno.m_denominateur=a_mmdeno.m_denominateur;
           a_mmdeno.m_numerateur=m_numerateur*b.m_denominateur;
           b_mmdeno.m_numerateur=b.m_numerateur*m_denominateur;
           sum=a_mmdeno+b_mmdeno;
        }      
        return sum;
    }
    Fraction Fraction::soustraction(Fraction const& b)const{
        Fraction sum;
        if(m_denominateur==b.m_denominateur){
            sum.m_numerateur=m_numerateur-b.m_numerateur;
            sum.m_denominateur=m_denominateur;
        }else{
            Fraction a_mmdeno,b_mmdeno;
           a_mmdeno.m_denominateur=m_denominateur*b.m_denominateur;
           b_mmdeno.m_denominateur=a_mmdeno.m_denominateur;
           a_mmdeno.m_numerateur=m_numerateur*b.m_denominateur;
           b_mmdeno.m_numerateur=b.m_numerateur*m_denominateur;
           sum=a_mmdeno-b_mmdeno;
        }      
        return sum;
    }
    Fraction Fraction::produit(Fraction const& b)const{
        Fraction sum;
        sum.m_numerateur=m_numerateur*b.m_numerateur;
        sum.m_denominateur=m_denominateur*b.m_denominateur;
        return sum;
    }
    void Fraction::affiche(){
        int a=m_numerateur;
        int b=m_denominateur;
        vector<int> tab(2);
        tab=simplification(a,b);
        cout << tab[0] <<"/"<<tab[1]<<endl;
    }

    //-------------------------def des functions---------------------
    Fraction operator+(Fraction const&  a,Fraction const& b){
        a.addition(b);
    }
    Fraction operator*(Fraction const& a,Fraction const& b){
        a.produit(b);
    }
    Fraction operator-(Fraction const& a,Fraction const& b){
        a.soustraction(b);
    }
   
vector<int> simplification(int& a,int& b){
    int j=min(a,b);
    for (int i = 1; i <= j; i++)
    {
        if(a%i==0 && b%i==0){
            a/=i;
            b/=i;
        }   
    }
    vector<int> tab(0);
    tab.push_back(a);
    tab.push_back(b);
    return tab;
}
int min(int a,int b){
    if(a>b) return b;
    else return a;
}