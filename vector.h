#include<iostream>


template<typename T>
class vector{
 
   private:
     T *arr;
     int cs;
     int ms;

   public:

   // constructor

     vector(int size=0)
     {
         ms=size;
         cs=0;
         arr= new T[ms];
     }

     vector(int size,int element)
     {
         this->ms=size;
         this->cs=size;
         arr=new T[ms];

         for(int i=0;i<ms;i++)
          arr[i]=element;
     }


     // copy constructor

     // not working

    //  vector(vector<T> &vec)
    //  {
    //      ms=vec.capacity();
    //      cs=vec.size();

    //      for(int i=0;i<cs;i++)
    //      arr[i]=vec[i];
    //  }



    // Destructor

    ~vector()
    {
        if(ms!=0)
        {
            // std::cout<<"Destructor called"<<std::endl;
            delete [] arr;
        }
    }


    // copy assignment operator

    void operator =(vector<T> &vec)
    {
        ms=vec.capacity();
        cs=vec.size();

        for(int i=0;i<cs;i++)
         arr[i]=vec[i];
    }

     // resizing the vector

      void reserve(int size)
     {
         if(cs==0)
         {
             ms=size;

             T *oldarr=arr;

             arr=new T[ms];

             delete oldarr;
         }
     }

     // methods

     void push_back(T ele)
     {
         if(cs==ms)
         {
             T *oldarr=arr;

             if(ms!=0)
             ms=2*ms;

             else ms++;

             arr=new T[ms];

             for(int i=0;i<cs;i++)
             {
               arr[i]=oldarr[i];
             }

             delete []oldarr;
         }

         arr[cs]=ele;
         cs++;

     }


     void pop_back()
     {
         cs--;
     }

     bool empty()
     {
         return cs==0;
     }


     T front()
     {
         return arr[0];
     }

     T back()
     {
         return arr[cs-1];
     }

     int size()
     {
         return cs;
     }

     int capacity()
     {
         return ms;
     }

     void erase(int i)
     {
         for(int idx=i;idx<cs-1;idx++)
         {
             arr[idx]=arr[idx+1];
         }

         cs--;
     }


     // operator overloading


     T& operator [](int i)
     {
         return arr[i];
     }


     // print vector

     void print()
     {
         for(int i=0;i<cs;i++)
          std::cout<<arr[i]<<" ";
     }


};

template<typename T>
std::ostream& operator << (std::ostream &output, vector<T> &v){
    // cout<<"In << operator"<<endl;
    v.print();
    return output;
}