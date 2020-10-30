#ifndef VECTOR_H
#define VECTOR_H
#include <bits/stdc++.h>
using namespace std;
template <typename Array> class Vector
{
public:
//�Ĵ��캯��---------------------------------------------
    Vector(int size=0,const Array num=0);//���캯��
    Vector(const Vector<Array> &A);//��������
    virtual ~Vector();//��������
    Vector<Array> & operator=(const Vector &V);//��ֵ����

//����(�޸�)����----------------------------------------
    Vector<Array> & SetVector(); //ֵ�޸�
    void ShowVector() const; //����չʾ
    void ShowD() const; //չʾά��
    int GetD() const; //���ά��
    double Mod() const; //ȡģ��
    Vector<Array> & Normalize();//��λ��
    bool Empty() const;//ȷ�������Ƿ�Ϊ��
//��������-----------------------------------------------
    Array operator[](const int pos);//ȡֵ
    Vector<Array> & Resize(const int Num);//�ߴ��޸�
    Vector<Array> & Append(const Array a_num=0);//��ĩβ���һ������
    Vector<Array> & Pop();//ɾ��ĩβ��һ������
    int Find(const Array f_num) const;//���Ҳ����������������е�λ�ã����û�������Ϊ-1

//���㺯��-----------------------------------------------
    Vector<Array> & Plus(const Vector<Array> &vec); //�����������(�����Ȳ�ͬʱ�޷����)
    Vector<Array> & Plus(int pos,Array a_num); //�����е�pos�����ݼ�a_num(��0��ʼ)
    Vector<Array> & ImPlus(const Vector<Array> &vec);   //��������ǿ�����(�����Ȳ�ͬʱ�������)

    Vector<Array>  operator+(const Vector<Array> &vec); //����+�����
    Vector<Array>  operator+(const Array Num); //����+�����
    Vector<Array> & operator+=(const Vector<Array> &vec); //����+=�����
    Vector<Array> & operator+=(const Array Num); //����+=�����

    Vector<Array>  operator-(const Vector<Array> &vec); //����-�����
    Vector<Array>  operator-(const Array Num); //����-�����
    Vector<Array> & operator-=(const Vector<Array> &vec); //����-=�����
    Vector<Array> & operator-=(const Array Num); //����-=�����

    Array operator*(const Vector<Array> &vec);//����*�����,���
    Vector<Array>  operator*(const Array Num); //����*�������ÿ������Num
    Vector<Array> & operator*=(const Array Num); //����*=�����

    friend Vector operator+(const Array Num,Vector<Array> &vec)
    {
        return vec+Num;   //+��Ԫ����
    }
    friend Vector operator*(const Array Num,Vector<Array>&vec)
    {
        return vec*Num;
    }

//��Ա����--------------------------------------------------
private:
    Array *a;
    int num;
};
template <typename Array>
ostream&  operator<<(ostream&  out,Vector<Array>& t)     // ���������������ʵ��
{
    if(t.GetD()==0)
        out<<"Nothing to output";
    else
    {
        out<<"[ ";
        for(int i=0; i<t.GetD(); i++)
            out<<t[i]<<(i==t.GetD()-1?" ]":" , ");  //������Ԫ����������ʽ���
    }
    return out;
}

template <typename Array>
Vector<Array>::Vector(int size,const Array num_):num(size)    //���캯��������һ����ʼֵΪnum_��ά��Ϊsize�����飬ʹ����ð�ű��ʽ����ʼ��
{
    num=(num>0)?num:0;  // С�ڵ���0�ľ�����0
    a=new Array[num];
    for(int i=0; i<num; i++)
        a[i]=num_;  //�����ֵ
}

template <typename Array>
Vector<Array>::Vector(const Vector<Array> &A) //�������
{
    num=A.num;
    if(num>0)
    {
        a=new Array[num];
        for(int i=0; i<num; i++)
            a[i]=A.a[i];
    }
}
template <typename Array>
Vector<Array>::~Vector()    //��������
{
    if(a!=NULL)
        delete [] a;
}
template <typename Array>
Vector<Array>& Vector<Array> :: operator=(const Vector &V)  //��ֵ���캯��
{
    if(num!=V.num)
    {
        if(a!=NULL)
            delete [] a;
        a=new Array[num=V.num];
    }
    for(int i=0; i<num; i++)
        a[i]=V.a[i];
    return *this;
}
template <typename Array>
Vector<Array>& Vector<Array> :: SetVector()     //Ϊ�������¸�ֵ
{
    if(num!=0&&a!=NULL)
        for(int i=0; i<num; cin>>a[i],i++);
    return *this;
}
template <typename Array>
void Vector<Array> ::ShowVector() const     //������������ֹ�����ݵ��޸�
{
    if(num!=0&&num!=1)
        for(int i=0; i<num; i++)
        {
            if(i==0)
                cout<<"[ "<<a[i]<<" , ";
            else if(i==num-1)
                cout<<a[i]<<" ]"<<endl;
            else
                cout<<a[i]<<" , ";
        }
    else if (num==1)
        cout<<"[ "<<a[0]<<" ]"<<endl;
    else cout<<"The Dimension of this Vector is 0."<<endl;
    return ;
}
template <typename Array>
void Vector<Array> ::ShowD() const
{
    cout<<"The Dimension of this Vector is: "<<num<<endl;
}
template <typename Array>
int Vector<Array> ::GetD() const
{
    return num;
}
template <typename Array>
Vector<Array> & Vector<Array> ::Resize(const int Num)
{
    {
        if(Num==0&&num!=0)  //Ҫ�޸ĵ���ά�ȣ�ֱ��ɾ���ռ�
        {
            delete [] a;
            a=NULL;
            num=Num;
            return *this;
        }
        else if(Num>num)
        {
            Array * num_=new Array[num];    //����һ����ʱ����ռ�
            for(int i=0; i<num; num_[i]=a[i],i++);  //���ø���ʱ�ռ䱣������
            delete [] a;
            a=new Array[Num];   //���´���
            for(int i=0; i<Num; i++)
                a[i]=(i<num?num_[i]:0);//Ĭ��Ϊ0���
            num=Num;
            delete [] num_;
            return *this;
        }
        else if(Num<num)
        {
            Array* num_=new Array[Num];
            for(int i=0; i<Num; i++)
                num_[i]=a[i];
            delete [] a;
            a=new Array[Num];   //�ȼ���ɾ���˶���Ĳ���
            for(int i=0; i<Num; i++)
                a[i]=num_[i];
            delete [] num_;
            num=Num;
            return *this;
        }
        else if(num==Num)
            cout<<"Nothing to operate."<<endl;
        return *this;//���ǵ��˵�Num<0�����������������������ʱ��ֱ�ӷ��ء�
    }
}
template <typename Array>
Array Vector<Array> ::operator[](int pos)
{
    if(pos<num&&pos>=0)
        return a[pos];
    else
        throw(int)-1;
}
template <typename Array>
double Vector<Array>::Mod() const
{

    double sum=0;
    if(num==0)throw(int) -1;
    for(int i=0; i<num; i++)
        sum+=a[i]*a[i];
    return sqrt((double)sum);
}
template <typename Array>
Vector<Array> & Vector<Array>::Normalize()
{
    Array mods=this->Mod(); //����Mod����
    if(num==0) throw(int)-1; //��ά��Ϊ0ʱ�����쳣
    for(int i=0; i<this->num; i++)
        this->a[i]=this->a[i]/mods;
    return *this;
}
template <typename Array>
bool Vector<Array>::Empty() const   //��������Ƿ�Ϊ��
{
    if (num==0)
        return true;
    else
        return false;
}

template <typename Array>
Vector<Array> & Vector<Array> ::Append(const Array a_num)//��ĩβ���һ������
{
    if(this->Empty())
    {
        delete [] a;
        a=new Array [1];
        a[0]=a_num;
        num++;
        return *this;
    }
    Array *num_ =new Array[num+1];
    for(int i=0; i<num+1; i++)
        num_[i]=(i<num?a[i]:a_num);
    delete [] a;
    num++;
    a=new Array [num];
    for(int i=0; i<num; i++)
        a[i]=num_[i];
    delete [] num_;
    return *this;
}

template <typename Array>
Vector<Array>  & Vector<Array> ::Pop()//ɾ��ĩβ��һ������
{
    if(num==0)
    {
        cout<<"Can't be Pop anymore!"<<endl;
        return *this;
    }
    Array *num_ =new Array[num-1];
    for(int i=0; i<num-1; i++)
        num_[i]=a[i];
    delete [] a;
    num-=1;
    a=new Array [num];
    for(int i=0; i<num; i++)
        a[i]=num_[i];
    delete [] num_;
    return *this;
}
template <typename Array>
int Vector<Array> ::Find(const Array f_num) const//���Ҳ����������������е�λ�ã����û�������Ϊ-1
{
    for(int i=0; i<num; i++)
        if(a[i]==f_num)
            return i;
    return -1;
}

template <typename Array>
Vector<Array> & Vector<Array>:: Plus(const Vector &vec)
{
    if(num==vec.num&&num!=0)
    {
        for(int i=0; i<num; i++)
            a[i]+=vec.a[i];
    }
    else
        cout<<"Can't plus this two Vector! "<<endl;
    return *this;
}

template <typename Array>
Vector<Array> & Vector<Array>::Plus(int pos,Array a_num)
{
    if(pos>=num||pos<0)
        cout<<"illegel index "<<endl;
    else
        a[pos]+=a_num;
    return *this;
}

template <typename Array>
Vector<Array> & Vector<Array>::ImPlus(const Vector &vec)
{
    if(num==0)
        cout<<"Can't plus \"vec\" to Vector!"<<endl;
    else
    {
        for(int i=0; i<(vec.num<=num?vec.num:num); i++)
            a[i]+=vec.a[i];
    }
    return *this;
}

template <typename Array>
Vector<Array>  Vector<Array>::operator+(const Vector &vec)
{

    if(num==vec.num&&num!=0)
    {
        Vector<Array> temp(num);
        for(int i=0; i<num; i++)
            temp.a[i]=vec.a[i]+a[i];
        return temp;
    }
    else
    {
        cout<<"Can't plus this two Vector! "<<endl;
        throw(int)-1;
    }
}

template <typename Array>
Vector<Array>  Vector<Array>::operator+(const Array Num)
{

    if(num!=0)
    {
        Vector<Array> temp(num);
        for(int i=0; i<num; i++)
            temp.a[i]=Num+a[i];
        return temp;
    }
    else
        cout<<"Can't plus this num! "<<endl;
    throw(int)-1;

}

template <typename Array>
Vector<Array> & Vector<Array>::operator+=(const Vector &vec)
{
    if(num==vec.num&&num!=0)
    {
        for(int i=0; i<num; i++)
            a[i]+=vec.a[i];
    }
    else
        cout<<"Can't plus this two Vector! "<<endl;
    return *this;
}

template <typename Array>
Vector<Array> & Vector<Array>::operator+=(const Array Num)
{
    if(num!=0)
    {
        for(int i=0; i<num; i++)
            a[i]+=Num;
        return *this;
    }
    else
    {
        cout<<"Can't plus this two Vector! "<<endl;
        throw(int)-1;
    }

}


template <typename Array>
Vector<Array>  Vector<Array>::operator-(const Vector &vec)
{

    if(num==vec.num&&num!=0)
    {
        Vector<Array> temp(num);
        for(int i=0; i<num; i++)
            temp.a[i]=a[i]-vec.a[i];
        return temp;
    }
    else
    {
        cout<<"Can't minus this two Vector! "<<endl;
        throw(int)-1;
    }
}

template <typename Array>
Vector<Array>  Vector<Array>::operator-(const Array Num)
{

    if(num!=0)
    {
        Vector<Array> temp(num);
        for(int i=0; i<num; i++)
            temp.a[i]=a[i]-Num;
        return temp;
    }
    else
        cout<<"Can't minus this num! "<<endl;
    throw(int)-1;

}

template <typename Array>
Vector<Array> & Vector<Array>::operator-=(const Vector &vec)
{
    if(num==vec.num&&num!=0)
    {
        for(int i=0; i<num; i++)
            a[i]-=vec.a[i];
    }
    else
        cout<<"Can't minus this two Vector! "<<endl;
    return *this;
}

template <typename Array>
Vector<Array> & Vector<Array>::operator-=(const Array Num)
{
    if(num!=0)
    {
        for(int i=0; i<num; i++)
            a[i]-=Num;
        return *this;
    }
    else
    {
        cout<<"Can't minus this two Vector! "<<endl;
        throw(int)-1;
    }

}

template <typename Array>
Vector<Array>  Vector<Array>::operator*(const Array Num)
{

    if(num!=0)
    {
        Vector<Array> temp(num);
        for(int i=0; i<num; i++)
            temp.a[i]=a[i]*Num;
        return temp;
    }
    else
        cout<<"Can't Multiply this num! "<<endl;
    throw(int)-1;

}

template <typename Array>
Array Vector<Array>::operator*(const Vector &vec)
{
    Array sum=0;
    if(num==vec.num&&num!=0)
    {
        for(int i=0; i<num; i++)
            sum+=(a[i]*vec.a[i]);
        return sum;
    }
    else
    {
        cout<<"These two Vector can't be multiplied!"<<endl;
        throw(int)-1;
    }
}

template <typename Array>
Vector<Array> & Vector<Array>::operator*=(const Array Num)
{
    if(num!=0)
    {
        for(int i=0; i<num; i++)
            a[i]*=Num;
        return *this;
    }
    else
    {
        cout<<"Can't multiply this two Vector! "<<endl;
        throw(int)-1;
    }

}
#endif // VECTOR_H
