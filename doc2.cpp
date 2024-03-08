void swap(int *x,int *y){
    int aux = *x;
    *x=*y ;
    *y=aux;
}
int main(){
    int a =17;
    int b=82;
    swap(&a,&b);
    (a==82) and (b==17)
}
