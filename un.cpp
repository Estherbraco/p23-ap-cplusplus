int* create_tab(int m ){
    int* i=new int[m];
    return i ;
};
struct stack {
    int nb;
    int size;
    char*tab;
    stack(int n):nb(0),size(n),tab(new char[n]){};
};
// une méthode qui a le même nom que la classe est un constructeur  
int main(){
    stack s(3);
}
//&ri à la place de *pi réference comme une adresse mais plus simple à manipuler (comme un objet)
