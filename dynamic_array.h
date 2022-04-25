//
// Created by basya on 25.04.2022.
//

#ifndef CPP1_DYNAMIC_ARRAY_H
#define CPP1_DYNAMIC_ARRAY_H


#include <cstdlib>
#include <ostream>

class dynamic_array
{
private:
    int m_size;
    int m_capacity;
    int* m_data;

    //конструктор по умолчанию
    dynamic_array()
    {
        m_size = 1;
        m_capacity = 2;
        m_data = new int[m_size];
    }

    //конструктор по размеру
    dynamic_array(int size)
    {
        m_size = size;
        m_capacity = size;
        if (size != 0) {
            m_data = new int[size];
            for(int i = 0; i<size; i++){
                m_data[i]=0;
            }
        }
        else {
            m_data = 0;
        }
    }
       //конструктор по размеру и числу
    dynamic_array(int size, int n)
    {
        m_size = size;
        m_capacity = size;
        if (size != 0) {
            m_data = new int[size];
            for(int i = 0; i<size; i++){
                m_data[i]=n;
            }
        }
        else {
            m_data = 0;
        }
    }

    //деструктор
    ~dynamic_array()
    {
        if (m_data){
            delete[] m_data;
        }
    }
    //конструктор копирования
    dynamic_array(const dynamic_array & a)
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = NULL;
        if (m_size != 0)
            m_data = new int[m_size];
        else
            m_data = 0;
        for (int i = 0; i < m_size; ++i)
            m_data[i] = a.m_data[i];
    }
//// конструктор перемещения
//    dynamic_array(dynamic_array&& other): str(other.str), str(other.m_size) {
//
//        other.str = nullptr;
//        other.length = 0;
//
//    }
//Размер массива
    int get_size(){
        return m_size;
    }

//    dynamic_array resize(int new_size, const dynamic_array &a){
//       int* new_m_data = new dynamic_array(new_size);
//        int* new_m_data =  new int[new_size];
//        new_m_data = dynamic_array::dynamic_array(a);
//    }


   dynamic_array operator[] (int i)
    {
        return m_data[i];
    }

    friend std::ostream& operator<< (std::ostream& out, dynamic_array a)
    {
        for (int i = 0; i < a.get_size(); ++i)
            out << a[i] << " ";
        return out;
    }

    friend std::istream& operator>> (std::istream& in, dynamic_array a){
        for(int i = 0; i<a.get_size(); i++){
            in >> a[i];
        }
        return in;
    }

    friend bool operator== (dynamic_array a, dynamic_array b) {
        if (a.get_size() != b.get_size()) {
            throw std::invalid_argument("a.size != b.size");
        }
        int count = 0;
        for (int i = 0; i < a.get_size(); i++) {
            if (a[i] == b[i]) {
                count++;
            }
            if (count == a.get_size()) return true;
            else return false;
        }
    }

    friend bool operator!= (dynamic_array a, dynamic_array b) {
        if (a.get_size() != b.get_size()) {
            throw std::invalid_argument("a.size != b.size");
        }
        int count = 0;
        for (int i = 0; i < a.get_size(); i++) {
            if (a[i] == b[i]) {
                count++;
            }
            if (count != a.get_size()) return true;
            else return false;
        }
    }

////    friend dynamic_array operator+ (dynamic_array &a, dynamic_array &b){
//        //dynamic_array c = new dynamic_array(a.get_size()+b.get_size());
//        int *c = new int[a.get_size()+b.get_size()];
//        for (int i=0; i<a.get_size(); i++ ){
//            c[i]=
//        }
//    }


};


#endif //CPP1_DYNAMIC_ARRAY_H
