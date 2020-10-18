/*Written By: Chirag Sawarn
**Dated: 18th October 2020
**Under: DSA Cracker Sheet
*/

/*Purpose: To find minimum and maximum elements of an array of given length
**Approach: if array is of one element:
                it is min and max.
            if array size > 1:
                if array size is even:
                    then zeroth and first element are set as min and max
                    iteration begins from 2
                else (array size is odd):
                    zeroth element is min as well as max
                    iteration begins from 1
                iteration
                    compare a[k] against a[k+1]
                        compare greater of two with max
                        compare lower of two with min

**Time Complexity: O(3n/2) which is better than linear search. Recursive call also follows same time complexity.
*/

/*Speciality:
** I have used a template to handle arrays of any datatype.
** I have assigned size of arrays dynamically as well as statically, using overloading of constructors.
*/

#include <iostream>
using namespace std;

template <class arr_type>
class Array{
    private:
        unsigned int size=10000;
        unsigned int insertion_bound;
        arr_type *p;
        arr_type min,max;
    public:
        Array(){
            p=new arr_type[size];
        }
        Array(unsigned int size){
            this->size=size;
            p=new arr_type[size];
        }
        void push_values(){
            try_again:
                cout<<"\nHow many values do you want to push : ";
                cin>>insertion_bound;
                cout<<"Start pushing:"<<endl;
                if(!(insertion_bound>size)){
                    for(unsigned int i=0;i<insertion_bound;++i)
                        cin>>*(p+i);
                }
                else{
                    cout<<"Insertion bound is beyond limits!\nTry again!"<<endl;
                    goto try_again;
                }
        }
        void print(){
            cout<<"\nThis is your array:"<<endl;
            for(int i=0;i<insertion_bound;++i)
                cout<<" "<<*(p+i);
        }
        void find_min_max(){
            //"i" is the iteration variable
            unsigned int i;
            if(insertion_bound==1)
                min=max=*p;
            else{
                if(insertion_bound%2==0){
                    if(*(p+1)>*(p)){
                        max=*(p+1);
                        min=*(p);
                    }
                    else{
                        max=*(p);
                        min=*(p+1);
                    }
                    i=2;
                }
                else{
                    min=max=*p;
                    i=1;
                }
                while(i<insertion_bound-1){
                    if(*(p+i)>*(p+i+1)){
                        if(*(p+i)>max)
                            max=*(p+i);
                        if(*(p+i+1)<min)
                            min=*(p+i+1);
                    }
                    else{
                        if(*(p+i)<min)
                            min=*(p+i);
                        if(*(p+i+1)>max)
                            max=*(p+i+1);
                    }
                    i+=2;
                }
            }
            cout<<"\nMinimum = "<<min<<"\nMaximum = "<<max<<endl;
        }
};

int main(){
    Array <int>a1(10);
    a1.push_values();
    a1.find_min_max();
    return 0;
}