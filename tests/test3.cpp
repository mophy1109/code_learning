class A{
   int i;
};
class B{
   A *p;
public:
   B(){p=new A;}
   ~B(){delete p;}
};
void sayHello(B b){
}
int main(){
   B b;
   sayHello(b);
}