#include <iostream>
#include <iostream>
#include "hash.h"
#include <string>
#include <cstdlib>

using namespace std;

hash::hash()
{
   for(int i = 0; i < TamanhoTabela; i++){
       TabelaHash[i] = new item;
       TabelaHash[i]->reservada = "vazio";
       TabelaHash[i]->prox = NULL;
   }
}

void hash::Inserir(string reservada)
{
   int indice = hash(reservada);

   if(TabelaHash[indice]->reservada == "vazio")
   {
       TabelaHash[indice]->reservada = reservada;
   }
   else{
       item* ptr = TabelaHash[indice];
       item* n = new item;
       n->reservada = reservada;
       n->prox = NULL;
       while(ptr->prox != NULL){//faz o ponteiro percorrer até o final da table
           ptr = ptr->prox;
       }
       ptr->prox = n;
   }
}

int hash::NumeroDeItensNaLista(int indice){
   int contagem = 0;

   if(TabelaHash[indice]->reservada=="vazio"){
       return contagem;
   }
   else{
       contagem++;
       item* ptr = TabelaHash[indice];
       while(ptr->prox != NULL){
           contagem++;
           ptr = ptr->prox;
       }
   }
   return contagem;
}


void hash::ImprimirTabela(){
   int numero;

   for(int i = 0;i < TamanhoTabela; i++){
       numero = NumeroDeItensNaLista(i);
       cout<<"-------------------\n";
       cout<<"indice = "<<i<<endl;
       cout<<TabelaHash[i]->reservada <<endl;
       cout<<"# de itens na neste indice: "<<numero<<endl;
       cout<<"-------------------\n";
   }
}

void hash::ImprimirItensNoIndice(int indice){
   item* ptr = TabelaHash[indice];

   if(ptr->reservada == "vazio"){
       cout<<"indice = "<<indice<<" esta vazio"<<endl;
   }
   else{
       cout<<"indice = "<<indice<<" tem os seguintes itens: "<<endl;
       while(ptr!=NULL){
           cout<<"-------------------\n";
           cout<<ptr->reservada <<endl;
           cout<<"-------------------\n";
           ptr = ptr->prox;
       }
   }
}

int hash::Hash(string chave){
   int hash = 0;
   int indice;


   for(int i = 0; i<chave.length();i++)
   {
       hash = hash + (int)chave[i];
   }

   indice = hash % TamanhoTabela;

   return indice;

}

void hash::BuscaPalavra(string reservada){
   int indice = hash(reservada);
   bool EncontrarPalavra = false;
   string palavra;

   item* ptr = TabelaHash[indice];
   while(ptr != NULL){        //percorrer a tabela
       if(ptr->reservada == reservada){
           EncontrarPalavra = true;
           palavra = ptr->reservada;
       }
       ptr=ptr->prox;
   }
   if(EncontrarPalavra == true){
       cout<<"A palavra esta na tabela"<<endl;
   }
   else{
       cout<<reservada<< " nao esta na tabela"<<endl;

   }
}

hash::~hash()
{
  item* ptr;
  for(int i=0;i<TamanhoTabela;i++)
  {
     while(TabelaHash[i] != NULL)
     {
        ptr = TabelaHash[i];
        TabelaHash[i] = TabelaHash[i]->prox;
        delete ptr;
     }
  }
}