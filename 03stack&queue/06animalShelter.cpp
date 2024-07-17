// https://godbolt.org/z/77sqqoP6o

#include <bits/stdc++.h>

using namespace std;


class animal{
private:
    queue<int> dog, cat;
    int order;
public:
    animal(){
        order = 1;
    }
    int enque(string type){
        if(type=="dog"){
            dog.push(order);
            order++;
        }
        else if(type=="cat"){
            cat.push(order);
            order++;
        }
        return order-1;
    }
    int dequeAny(){
        int tmp;
        if(dog.front()>cat.front()){
            tmp = cat.front();
            cat.pop();
        }
        else{
            tmp = dog.front();
            dog.pop();
        }
        return tmp;
    }
    int dequeDog(){
        if(dog.empty()){
            printf("There is no more dogs!");
            getchar();
            exit(0);
        }
        int tmp = dog.front();
        dog.pop();
        return tmp;
    }
    int dequeCat(){
        if(cat.empty()){
            printf("There is no more cats!");
            getchar();
            exit(0);
        }
        int tmp = cat.front();
        cat.pop();
        return tmp;

    }
};

int main(){
    animal type;
    cout<<"Shelter received an dog with index "<<type.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<type.enque("cat")<<'\n';
    cout<<"Shelter received an cat with index "<<type.enque("cat")<<'\n';
    cout<<"Shelter received an dog with index "<<type.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<type.enque("cat")<<'\n';
    cout<<"Shelter received an dog with index "<<type.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<type.enque("cat")<<'\n';
    cout<<"Get an animal of any kind. The index is "<<type.dequeAny()<<'\n';
    cout<<"Get a dog. The index is "<<type.dequeDog()<<'\n';
    cout<<"Get a cat. The index is "<<type.dequeCat()<<'\n';
    cout<<"Get a dog. The index is "<<type.dequeDog()<<'\n';
    cout<<"Get a dog. The index is "<<type.dequeDog()<<'\n';
    cout<<"Get a dog. The index is "<<type.dequeDog()<<'\n';
}
