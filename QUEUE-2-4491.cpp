#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

const int  MAX_QUEUE = 5;

struct Queue{
    int depan;
    int belakang;
    string data[MAX_QUEUE];
};

//prototype fungsi 
void inisialisasi();
void enqueue(string data);
void dequeue();
void clear();
bool isEmpty();
bool isFull();
void print();

Queue queue;

int main(){
    //inisialisasi
    inisialisasi();

    int pilihanMenu;
    string data;

    do{
        cout<<">>> PILIHAN MENU QUEUE <<<"<<endl<<endl;
        cout<<"1. Menambah Item queue"<<endl;
        cout<<"2. Menghapus item queue"<<endl;
        cout<<"3. Menampilkan item queue"<<endl;
        cout<<"4. Mengosongkan queue"<<endl;
        cout<<"5. Selesai"<<endl<<endl;

        cout<<"Masukan piliahan Anda : "; cin>>pilihanMenu;
        cout<<endl;

        switch (pilihanMenu){
            case 1:
            	if(isFull()){
				cout<<" Queue sudah penuh !!!"<<endl<<endl;
				}else{
				cout<<"Masukan data : "; cin>>data;
            	enqueue(data);	
				}
            break;

            case 2:
            if(isEmpty()){
				cout<<" Queue masih kosong !!!"<<endl<<endl;
				}else{
				dequeue();	
				}
            break;

            case 3:
            if(isEmpty()){
				cout<<" Queue masih kosong !!!"<<endl<<endl;
				}else{
				print();	
				}
            break;

            case 4:
            if(isEmpty()){
				cout<<" Queue masih kosong !!!"<<endl<<endl;
				}else{
				clear();	
				}
            break;
            
            case 5:
            break;
            
        default  : 
        cout<<"Menu yang anda pilih tidak terdaftar " <<endl<<endl;     
        }
    }
     while (pilihanMenu !=5);
        cout<<endl;

        system("pause");
        return 0;
}

void inisialisasi(){
    queue.depan = queue.belakang  = -1;
}
void enqueue(string data){
    queue.depan=0;
    queue.belakang ++;
    queue.data[queue.belakang] = data;
    cout<<"Data berhasil ditambahkan"<<endl<<endl;
}
void dequeue(){
    cout<<"Data "<<queue.data[queue.depan]<<" sudah dihapus "<<endl<<endl;
    for(int i=queue.depan; i<=queue.belakang; i++){
    	queue.data[i] = queue.data[i+1];
	}
	queue.belakang--;
}

void clear(){
    queue.depan = queue.belakang = -1;
    cout<<"Queue sudah dikosongkan"<<endl<<endl;
}

bool isEmpty(){
    return (queue.belakang == -1);
}

bool isFull(){
    return (queue.belakang >= (MAX_QUEUE - 1));
}

void print(){
    cout<<"Isi queue :  ";
    for(int i = queue.depan ; i<=queue.belakang ; i++){
        cout<<queue.data[i]<<" ";
    }
    cout<<endl<<endl;
}
