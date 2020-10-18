/*Written By: Chirag Sawarn
**Dated: 18th October 2020
**Under: DSA Cracker Sheet
*/

/*Purpose: To reverse an array of given length
**Approach: We swap the elements from beginning and end of the subarray till we reach the midpoint.
**Complexity: O(n)
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
        unsigned int size=1000000;
        unsigned int insertion_bound;
        arr_type* p;
    public:
        //constructors
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
        void reverse(){
            unsigned int mid;
            //Since this is an integer division, it handles both odd and even insertion bounds.
            mid=insertion_bound/2;
            arr_type* q=p+insertion_bound-1;
            for(unsigned int i=0;i<mid;++i){
                //Swapping without auxillary space
                *(p+i)+=*(q-i);
                *(q-i)=*(p+i)-*(q-i);
                *(p+i)-=*(q-i);
            }
            cout<<"\n\nArray has been reversed!"<<endl;
        }
        void print(){
            cout<<"\nThis is your array:"<<endl;
            for(int i=0;i<insertion_bound;++i)
                cout<<" "<<*(p+i);
        }
};

int main(){
    Array <int>a1(10);
    Array <float>a2(11);
    //checking out integer array
    a1.push_values();
    a1.print();
    a1.reverse();
    a1.print();
    //checking out float array
    a2.push_values();
    a2.print();
    a2.reverse();
    a2.print();
    return 0;
}