
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include <string>

using namespace std;
	/**
	 * @class Vector
	 * @brief  To store data into Vector array
	 * @author Huan Lin Oh
	 * @version 01
	 * @date 07/03/2021
	 */

template <class T>

class MyVector
{	public:

    MyVector();

    MyVector(int size);

    ~MyVector();

    bool pushBack(const T &data);

    bool popBack();

    T at(int i);


	private:
		T *m_data; //variable for memory
		int m_size;//variable for size of memory
		int m_current;// variable for how much memory is provided in the program
};
    template <class T>
    MyVector<T>::MyVector()
    {
        m_data = new T[5];
        m_size = 5;
        m_current = 0;
    }

    template <class T>
    MyVector<T>::MyVector(int size)
    {
        m_data = new T[size];
        m_size = size;
        m_current = 0;
    }

    template <class T>
    MyVector<T>::~MyVector()
    {
        delete[] m_data;
    }

    template <class T>
    bool MyVector<T>::pushBack(const T &data)
    {
        if(m_current >= m_size)
        {
            m_size = m_size * 2;
            T *m_data_2 = new T[m_size];
            copy(m_data, m_data + m_current, m_data_2);

            delete[] m_data;
            m_data = m_data_2;

            m_data[m_current] = data;
            m_current++;
            return true;
        }

        else if (m_current < m_size)
        {
               m_data[m_current] = data;
               m_current++;
               return true;
        }
        else

        {
            return false;
        }
    }

    template <class T>
    bool MyVector<T>::popBack()
    {
        if (m_current==0)
        {
           cout << "Nothing to pop";
           return false;
        }
        else
        {
           cout << m_data[m_current];
           m_current--;
           return true;
        }
    }

    template <class T>
    T MyVector<T>::at(int i)
    {

    if(i >= 0 && i < m_current)
    {
        return m_data[i];
    }
        return m_data[0];
    }



#endif


